#include "BingoSectionManager.h"

BingoSectionManager::BingoSectionManager()
:SectionManager()
{
    block_determination = new BlockDetermination();
    circle_decision = new CircleDecision();
    route_decision = block_determination;
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

void BingoSectionManager::StateChange(RouteDecision *routeDecision)    //状態遷移
{
    if (route_decision == circle_decision)
    {
        route_decision = block_determination; 
    }
    else
    {
        route_decision = circle_decision;
    }
}

void BingoSectionManager::init()    //初期化
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

/*void BingoSectionManager::s_addSection()
{
    for (n = 0; wp[n].flag != -1; n++)    //取得したパラメータを全て区間に変換し終えるまで
    {
        section = new Section();    //クリエイトメッセージ
        mWalker = section->selectWalker(n);    //走法の生成の依頼
        mWalker->setParam(wp[n].speed, wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp);    //パラメータを設定する
        mJudge = section->selectJudge(n);    //判定の生成を依頼
        mJudge->setParam(wp[n].speed, wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp);    //パラメータを設定する
        addSection(new Section());    //生成下区間をaddSectionへ渡す
    }
}*/

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

    //状態遷移
    StateChange(routeDecision);
}