mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
	SpeedSectionManager.o\
	util.o \
	Measure.o \
	Brightness.o \
	MyColorSensor.o \
	Polling.o \
	Length.o \
	TurnAngle.o \
	Odometry.o \
	Velocity.o \
	HsvHue.o \
	HsvSatu.o \
	PID.o \
	SimpleWalker.o \
	SpeedControl.o \
	Walker.o \
	LineTracer.o \
	LowPassFilter.o \
	Scene.o \
	Section.o \
	SectionManager.o \
	Judge.o\
	TurnAngleJudge.o\
	ColorJudge.o\
	LengthJudge.o\
	BrightnessJudge.o\
	XPosition.o\
	YPosition.o\
	MyGyroSensor.o\
	MySonarSensor.o\
	VirtualLineTracer.o\
	VirtualLineTracer2.o\
	SlalomSectionManager.o\
	TailWalker.o\
	TailAngle.o\
	TailAngleJudge.o\
	ArmWalker.o\
	ArmAngle.o\
	ArmAngleJudge.o\
	AnglerVelocity.o\
	GyroAngle.o\
	GarageSectionManager.o\
	Stop.o\
	GyroJudge.o \
	SonerJudge.o \
	BingoState.o \
	BingoStateCarry.o \
	BingoStateMove.o \
	BlockSectionManager.o \
	Area.o \
	BlockPlace.o \
	CrossCircle.o \
	Runner.o \
	BlackLine.o \
	Block.o \
	BlockCircle.o \
	SonerStatusJudge.o \
	ColorStatusJudge.o \
	TurnWalker.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)app $(mkfile_path)unit  $(mkfile_path)device $(mkfile_path)walker $(mkfile_path)section $(mkfile_path)judge $(mkfile_path)bingo

INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)device \
	-I$(mkfile_path)walker \
	-I$(mkfile_path)section \
	-I$(mkfile_path)judge \
	-I$(mkfile_path)bingo \
	-I$(ETROBO_HRP3_WORKSPACE)/etroboc_common

# COPTS += -fno-use-cxa-atexit
COPTS += -std=c++11
