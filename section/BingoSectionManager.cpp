#include "BingoSectionManager.h"
#include "RouteDecision.h"
#include "stdlib.h"

RouteDecision *BingoSectionManager::circle_decision;
RouteDecision *BingoSectionManager::block_decision;
BingoArea *BingoSectionManager::bingo_area;

BingoSectionManager::BingoSectionManager()
:SectionManager()
{
    bingo_area = new BingoArea();
    //wp = (wParam3 *)malloc(sizeof(wParam3) * 100);    //領域確保
}

void BingoSectionManager::setWalker(Section *sc)    //パラメータを設定する
{
    //printf("wp[%d].walk = %d\n",n,wp[n].walk);
    Walker *walk = sc->selectWalker(wp[n].walk);

    switch (wp[n].walk)
    {
    	case Section::VIRTUAL2:
    		// syslog(LOG_NOTICE,"VIRTUAL2:%d %d",(int)wp[n].speed,(int)wp[n].kp);
    		((VirtualLineTracer2 *)walk)->setAbsTurnAngle(wp[n].absangle);
     		//((VirtualLineTracer2 *)walk)->setvangle(wp[n].vangle);
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

bool BingoSectionManager::run()
{
    bool ex=false;
    switch(mState)
    {
        case INIT:
            num = rdState->routeDecision();
            if(num == 0)
            {
              ex = true;
              break;
            }
			//rdSateにnumの座標どこ？って聞きたい
            rdState->passParam(p);
            reset();
            chengeToSenpai();
			running();
            mStateChange(RUN);
            break;
        case RUN:
            ex = exe_run();

            if (ex == true)
            {
				rdState->finishRun();
				//rdStateChange(rdState);
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
    {
        return true;
    }
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
	mState = INIT;
    circle_decision = new CircleDecision();
    block_decision = new BlockDetermination();
    rdState = block_decision;
}

void BingoSectionManager::running()    //実行する
{
    //区間生成実行
    for (n = 0; wp[n].flag != -1; n++)    //取得したパラメータを全て区間に変換し終えるまで
    {
        printf("n = %d\n", n);
        sc = new Section();
        setWalker(sc);
        setJudge(sc);

		sc->changeAcc(5);	//加速度変更

        addSection(sc);
    }
}

void BingoSectionManager::chengeToSenpai()
{
    int i;
    for(i = 0; p[i].front != -1; i++)
    {
        wp[i] = {0, p[i].mwalker, p[i].mjudge, p[i].speed, 0, p[i].kp, p[i].ki, p[i].kd, 1, 1, p[i].radius, p[i].radius, p[i].front, p[i].turn, p[i].edge, Judge::UPDATE, 0, 0, 0, 0, 0, 0.5, 0};
		/*-----------------デバッグ-----------------*/
        switch(p[i].mwalker)
        {
            case Section::WALKER:
			    printf("WALKER!!\n");
                break;
            case Section::TRACER:
			    printf("TRACER!!\n");
                break;
            case Section::VIRTUAL:
			    printf("VIRTUAL!!\n");
                break;
            case Section::VIRTUAL2:
                printf("VIRTUAL2!!\n");
                break;
        }
		/*------------------------------------------*/
        switch(p[i].mjudge)
        {
            case Section::LENGTH:
				printf("LENGTH!!\n");
                wp[i].flength = p[i].atai;
                break;
            case Section::TURNANGLE:
				printf("TURNANGLE!!\n");
                wp[i].fangle = p[i].atai;
                break;
            case Section::BRIGHTNESS:
				printf("BRIGHTNESS!!\n");
                wp[i].bright1 = -0.5;
                wp[i].bright2 = 0;
                break;
			case Section::STOP:
				printf("STOP!!\n");
				wp[i].count = p[i].atai;
				break;
            case Section::COLOR:
				printf("COLOR!!\n");
                switch(p[i].mcolor)
                {
                    case BLUE:
						printf("blue\n");
                        wp[i].color1 = 220;
                        break;
                    case RED:
                        wp[i].color1 = 350;
						printf("red\n");
                        break;
                    case GREEN:
                        wp[i].color1 = 156;
						printf("green\n");
                        break;
                    case YELLOW:
                        wp[i].color1 = 60;
						printf("yellow\n");
                        break;
                }
                break;
		}
		/*pidの値を具体的に設定するか判定*/
	}
   	wp[i] = {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0};
}

int BingoSectionManager::getBlockNum()
{
  	return num;
}

void BingoSectionManager::initBingo()
{
	bingo_area->initBingo();
	init();
}
