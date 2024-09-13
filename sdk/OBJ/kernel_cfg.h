/* kernel_cfg.h */
#ifndef TOPPERS_KERNEL_CFG_H
#define TOPPERS_KERNEL_CFG_H

#define TNUM_TSKID	13
#define TSKID_tTask_LogTask_Task	1
#define EV3_INIT_TASK	2
#define BRICK_BTN_TSK	3
#define APP_INIT_TASK	4
#define MAIN_TASK	5
#define TRACER_TASK	6
#define POLLING_TASK	7
#define RCV_TASK	8
#define SEND_RCV_TASK	9
#define SEND_RCV_TASK2	10
#define PIPE_OPEN_TASK	11
#define SEND_TASK	12
#define THREAD_TASK	13

#define TNUM_SEMID	2
#define SEMID_tSemaphore_SerialPort1_ReceiveSemaphore	1
#define SEMID_tSemaphore_SerialPort1_SendSemaphore	2

#define TNUM_FLGID	2
#define BTN_CLICK_FLG	1
#define CONSOLE_BTN_CLICK_FLG	2

#define TNUM_DTQID	0

#define TNUM_PDQID	0

#define TNUM_MTXID	0

#define TNUM_MPFID	0

#define TNUM_CYCID	5
#define BRICK_BTN_CYC	1
#define TRACER_CYC	2
#define POLLING_CYC	3
#define SEND_RCV_CYC	4
#define SEND_RCV_CYC2	5

#define TNUM_ALMID	0

#define TNUM_ISRID	1
#define ISRID_tISR_SIOPortTarget1_ISRInstance	1

#endif /* TOPPERS_KERNEL_CFG_H */
