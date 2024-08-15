USE_RASPIKE_ART=1

mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

LDFLAGS += -L/usr/lib/arm-linux-gnueabihf

LIBS += \
		-l opencv_core \
		-l opencv_videoio \
		-l opencv_imgcodecs \

APPL_LIBS +=

APPL_COBJS += \


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
	TailAngle.o\
	TailAngleJudge.o\
	ArmWalker.o\
	ArmAngle.o\
	ArmAngleJudge.o\
	AnglerVelocity.o\
	GyroAngle.o\
	Stop.o\
	GyroJudge.o \
	SonerJudge.o \
	SonerStatusJudge.o \
	ColorStatusJudge.o \
	TurnWalker.o \
	BlockSectionManager.o \
	ColorStatus_RJudge.o \
	PositionJudge.o\
	thread_main.o

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
	-I$(ETROBO_HRP3_WORKSPACE)/etroboc_common \
	-I/usr/include/opencv4

# COPTS += -fno-use-cxa-atexit
COPTS += -std=c++11 -pthread
