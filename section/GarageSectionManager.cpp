#include "GarageSectionManager.h"
#include "Section.h"
#include "util.h"

GarageSectionManager::GarageSectionManager():
  SectionManager()
{

}
void GarageSectionManager::init()
{
  if(_EDGE==0){

    wp = array[0];
  }
  else{
    wp = array[1];
  }

  init(wp);
}

void GarageSectionManager::setWalker(Section *sc)
{
	Walker *walk = sc->selectWalker(wp[n].walk);
    static char buf[100][256];

  switch (wp[n].walk)
  {
  case Section::VIRTUAL2:
    ((VirtualLineTracer2 *)walk)->setAbsTurnAngle(wp[n].absangle);
    ((VirtualLineTracer2 *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp);
    break;
  case Section::WALKER:
    /*sprintf(buf[n],"setWalker setParam %f,%f",wp[n].forward, wp[n].turn);
    msg_log(buf[n]);*/
    // ((SimpleWalker *)walk)->setParam(wp[n].forward, wp[n].turn,true);
    if(wp[n].forward != 0)
      ((SimpleWalker *)walk)->setCommandV(wp[n].forward, wp[n].turn);
    else
      ((SimpleWalker *)walk)->setCommand(wp[n].forward, wp[n].turn);
    break;
  case Section::VIRTUAL:
    ((VirtualLineTracer *)walk)->setRound(wp[n].round);
    ((VirtualLineTracer *)walk)->setParam(wp[n].speed, wp[n].kp, wp[n].ki, wp[n].kd, wp[n].angleTarget, wp[n].anglekp); //(20,2, 0.2, 0,1,1)
    break;
  case Section::TRACER:
    ((LineTracer *)walk)->setParam(wp[n].speed, wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd); //(30, 0 ,  30, 0.2, 0.1 )
    ((LineTracer *)walk)->setEdgeMode(wp[n]._EDGE);
    break;
	case Section::TAIL:
    /*sprintf(buf[n],"Section %f,%f,%f,%f",wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd);
    msg_log(buf[n]);*/
		((TailWalker *)walk)->setPwm(wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd);
    break;
  case Section::ARM:
    ((ArmWalker *)walk)->setPwm(wp[n].target, wp[n].kp, wp[n].ki, wp[n].kd);
    break;
  }
}

/*
void GarageSectionManager::setJudge(Section *sc)
{
	Judge *judge = sc->selectJudge(wp[n].judge);

  switch (wp[n].judge)
  {
  case Section::TURNANGLE:
    ((TurnAngleJudge *)judge)->setupdate(wp[n].jflag);
    ((TurnAngleJudge *)judge)->setFinishAngle(wp[n].fangle);
    break;
  case Section::LENGTH:
    ((LengthJudge *)judge)->setupdate(wp[n].jflag);
    ((LengthJudge *)judge)->setFinLength(wp[n].flength);
    break;
  case Section::BRIGHTNESS:
    ((BrightnessJudge *)judge)->setBrightness(wp[n].bright1, wp[n].bright2);
    break;
  case Section::COLOR:
    ((ColorJudge *)judge)->setColor(wp[n].color1, wp[n].color2);
    break;
	case Section::TAILANGLE:
		((TailAngleJudge *)judge)->setFinAngle(wp[n].fangle);
		break;
  case Section::ARMANGLE:
		((ArmAngleJudge *)judge)->setFinAngle(wp[n].fangle);
    break;
  case Section::STOP:
    ((Stop *)judge)->setCount(wp[n].count);
    break;
  }
}*/