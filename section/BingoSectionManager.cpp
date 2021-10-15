#include "BingoSectionManager.h"
#include "RouteDecision.h"

RouteDecision *BingoSectionManager::circle_decision;
RouteDecision *BingoSectionManager::block_decision;
BingoArea *BingoSectionManager::bingo_area;

BingoSectionManager::BingoSectionManager()
:SectionManager()
{
    //RouteDecision *r = new RouteDecision();
    circle_decision = new CircleDecision();
    block_decision = new BlockDetermination();
    bingo_area = new BingoArea();
    rdState = block_decision;
}

void BingoSectionManager::setWalker(Section *sc)    //パラメータを設定する
{

  Walker *walk = sc->selectWalker(wp[n].walk);

  switch (wp[n].walk)
  {
  case Section::VIRTUAL2:
   // syslog(LOG_NOTICE,"VIRTUAL2:%d %d",(int)wp[n].speed,(int)wp[n].kp);
    ((VirtualLineTracer2 *)walk)->setAbsTurnAngle(wp[n].absangle);
     ((VirtualLineTracer2 *)walk)->setvangle(wp[n].vangle);
    ((VirtualLineTracer2 *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp);

    break;
  case Section::WALKER:

    ((SimpleWalker *)walk)->setCommand(wp[n].forward, wp[n].turn);

    break;
  case Section::VIRTUAL:
//syslog(LOG_NOTICE,"VIRTUAL:%d",(int)wp[n].round);
    ((VirtualLineTracer *)walk)->setRound(wp[n].round);
    ((VirtualLineTracer *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp); //(20,2, 0.2, 0,1,1)

    break;
  case Section::TRACER:

    ((LineTracer *)walk)->setParam(wp[n].speed, wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd); //(30, 0 ,  30, 0.2, 0.1 )
    ((LineTracer *)walk)->setEdgeMode(wp[n]._EDGE);

    break;
  }
}

void BingoSectionManager::setJudge(Section *sc)    //パラメータを設定する
{
    Judge *judge = sc->selectJudge(wp[n].judge);
    Judge *aJudge;
    switch (wp[n].judge)
    {
    case Section::TURNANGLE:
        ((TurnAngleJudge *)judge)->setupdate(wp[n].jflag);
        ((TurnAngleJudge *)judge)->setFinishAngle(wp[n].fangle);
        break;
    case Section::LENGTH:
        ((LengthJudge *)judge)->setFinLength(wp[n].flength);
        ((LengthJudge *)judge)->setupdate(wp[n].jflag);
        break;
    case Section::BRIGHTNESS:
        ((BrightnessJudge *)judge)->setBrightness(wp[n].bright1, wp[n].bright2);
        break;
    case Section::COLOR:
        ((ColorJudge *)judge)->setColor(wp[n].color1, wp[n].color2);
        aJudge = sc->createAbnormalJudge();
        ((LengthJudge *)aJudge)->setFinLength(30);
        ((LengthJudge *)aJudge)->setupdate(Judge::UPDATE);
        break;
        case Section::STOP:
        ((Stop *)judge)->setCount(wp[n].count);
        break;
    }
}

//bool BingoSectionManager::run()    //走行する(色々間違えているので修正必要)
//{
    //走行するメソッドの振る舞いがよくわかない
    /*ルート決定がわかったよってパラメータを投げる事で実行されるメソッド
    */
    //bool ex = false;
    //int block_num;    //ブロックナンバー
    //int circle_num;    //サークルナンバー

    //switch(mState)
    //{
        //case black_block:
            //mState = pass_block;    //状態を黒ブロック処理中からブロックまで移動に更新
        //case pass_block:/*運搬ブロック決定*/    //運搬ブロック決定
            /* ブロックがなくなっているか判定
            なくなっていれば終了 */
            //if (/*全ブロック終了？*/) return ex;
            //block_num = CurrentState->route_decision();    //ルートを決定する
            //route_decision->pass_param(block_num, &param);    //移動パラメータを問い合わせる
            //route_decision->pass_Color(block_num, &color);    //通過座標の色情報を問い合わせる

            //s_addSection();    //区間の追加
            //StateChange(CurrentState);    //状態遷
            //mState = carry_block;    //状態を運搬ブロック決定からブロック運搬中に更新
        //case carry_block/*質問箇所*/:    //ブロック運搬先決定中
            //circle_num = CurrentState->route_decision();    //ルートを決定する
            /*変数変えたほうがいいかも*///route_decision->pass_param(circle_num, &param);   //移動パラメータを問い合わせる
            /*変数変えたほうがいいかも*///route_decision->pass_Color(circle_num, &color);   //通過座標の色情報を問い合わせる
            //s_addSection();    //区間の追加
            //StateChange(CurrentState);    //状態遷移
            //mState = pass_block;    //ブロック運搬中から運搬ブロック決定更新
    //}


    //return ex;
//}

bool BingoSectionManager::run()
{
    bool ex=false;

    switch(mState)
    {
        case INIT:
            printf("test");
            block_num = rdState->routeDecision();
            if(block_num == 0)
            {
              ex = true;
              break;
            }
            rdState->passParam(p);
            chengeToSenpai();
            init();
            mStateChange(RUN);
            break;
        case RUN:
            printf("test2");
            ex = exe_run();

            if (ex == true)
            {
                mStateChange(INIT);
            }
            ex = false;
            break;
    }
    return ex;
}

bool BingoSectionManager::exe_run()
{
    if(mSection[mSectionIdx]==nullptr)
        return true;
    //if(mSectionIdx==0)
    // msg_log("0");
    //if(mSectionIdx==1)
    // msg_log("1");
    if(mSection[mSectionIdx]->run())
    {
        if(mSection[mSectionIdx]->getAbnormalFlag() == 1)
        {
            ETRoboc_notifyCompletedToSimulator();
        }
        mSectionIdx++;
    }

       
    return false;
}

void BingoSectionManager::rdStateChange(RouteDecision *rd_state)    //状態遷移
{
    rdState = rd_state;
}

void BingoSectionManager::mStateChange(State m_state)
{
    mState = m_state;
}

void BingoSectionManager::init()    //初期化
{
    //区間生成実行
    /*for (n = 0; wp[n].flag != -1; n++)    //取得したパラメータを全て区間に変換し終えるまで
    {
        Section *sc = new Section();

        setWalker(sc);
        setJudge(sc);

        addSection(sc);
    }*/
}

// void BingoSectionManager::s_addSection()
// {
//     for (n = 0; wp[n].flag != -1; n++)    //取得したパラメータを全て区間に変換し終えるまで
//     {
//         sc = new Section();    //クリエイトメッセージ
//         mWalker = sc->selectWalker(n);    //走法の生成の依頼
//         mWalker->setParam(wp[n].speed, wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp);    //パラメータを設定する
//         mJudge = sc->selectJudge(n);    //判定の生成を依頼
//         mJudge->setParam(wp[n].speed, wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp);    //パラメータを設定する
//         addSection(new Section());    //生成した区間をaddSectionへ渡す
//     }
// }

void BingoSectionManager::running()    //実行する
{
    //区間生成実行
    for (n = 0; wp[n].flag != -1; n++)    //取得したパラメータを全て区間に変換し終えるまで
    {
        sc = new Section();
        setWalker(sc);
        setJudge(sc);

        addSection(sc);
    }
}

void BingoSectionManager::chengeToSenpai()
{
    for(int i = 0; p[i].front != -1; i++)
    {
        
        wp[i] = {0, p[i].mwalker, p[i].mjudge, p[i].speed, 0, 30, 0.1, 0, 1, 1, 0, p[i].radius, p[i].front, p[i].turn, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0.5, 0};
        switch(p[i].mwalker)
        {
            case Section::WALKER:
                wp[i].kd = 0.5;
                break;
            case Section::TRACER:
                wp[i].kd = 0.8;
                break;
            case Section::VIRTUAL:
                wp[i].kd = 0.3;
                break;
        }
        switch(p[i].mjudge)
        {
            case Section::LENGTH:
                wp[i].flength = p[i].atai;
                break;
            case Section::TURNANGLE:
                wp[i].fangle = p[i].atai;
                break;
            case Section::BRIGHTNESS:
                wp[i].bright1 = -0.5;
                wp[i].bright2 = 0;
                break;
            case Section::COLOR:
                switch(p[i].mcolor)
                {
                    case BLUE:
                        wp[i].color1 = 220;
                        break;
                    case RED:
                        wp[i].color1 = 350;
                        break;
                    case GREEN:
                        wp[i].color1 = 156;
                        break;
                    case YELLOW:
                        wp[i].color1 = 60;
                        break;
                }
                break;
        }
    }
}

int BingoSectionManager::getBlockNum()
{
  return block_num;
}

void BingoSectionManager::initBingo()
{
	bingo_area->initBingo();
}
