#include "SpeedSectionManager.h"
#include "Section.h"

<<<<<<< Updated upstream
SpeedSectionManager::SpeedSectionManager()
{
    // test用初期化
 #if defined(MAKE_RIGHT)
      const int _EDGE = LineTracer::LEFTEDGE;
=======
SpeedSectionManager::SpeedSectionManager() : SectionManager()
{}

  void SpeedSectionManager::setWalker(Section * sc)
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

      ((SimpleWalker *)walk)->setCommandV(wp[n].forward, wp[n].turn);

      break;
    case Section::VIRTUAL:

      ((VirtualLineTracer *)walk)->setRound(wp[n].round);
      ((VirtualLineTracer *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp); //(20,2, 0.2, 0,1,1)

      break;
    case Section::TRACER:
      ((LineTracer *)walk)->setParam(wp[n].speed, wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp); //(30, 0 ,  30, 0.2, 0.1 )
      ((LineTracer *)walk)->setEdgeMode(wp[n]._EDGE);

      break;
    case Section::ARM:

      ((ArmWalker *)walk)->setPwm(wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd);

      break;
    case Section::TAIL:
      /*sprintf(buf[n],"Section %f,%f,%f,%f",wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd);
      msg_log(buf[n]);*/
      ((TailWalker *)walk)->setPwm(wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd);
      break;
    }
  }

  void SpeedSectionManager::setJudge(Section * sc)
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
    case Section::ARMANGLE:
      ((ArmAngleJudge *)judge)->setFinAngle(wp[n].fangle);
      break;
	  case Section::TAILANGLE:
		  ((TailAngleJudge *)judge)->setFinAngle(wp[n].fangle);
		  break;
    case Section::SONER:
      ((SonerJudge *)judge)->setLength(wp[n].flength,1);
      break;
    }
  }
  void SpeedSectionManager::init()
  {

    static char buf[256];
//    sprintf(buf, "%d,EDGE", _EDGE);
//    msg_log(buf);

#if defined(MAKE_RIGHT)
      wp = array[1];
>>>>>>> Stashed changes
#else
      const int _EDGE = LineTracer::RIGHTEDGE;
#endif
    Section *sc = new Section();
    
    // LineTracer テスト
    LineTracer* tracer = (LineTracer*)sc->selectWalker(Section::TRACER);

    tracer->setParam(25, 0 ,  30, 0.2, 0.1 );
    tracer->setEdgeMode(_EDGE);

    /*
    // SimpleWalkerテスト
    SimpleWalker* walker = (SimpleWalker*)sc->selectWalker(Section::WALKER);
    walker->setCommand(10,10);
    */
    addSection(sc);

}

bool SpeedSectionManager::run()
{
    if(mSection[mSectionIdx]->run())
        return true;

    return false;
}