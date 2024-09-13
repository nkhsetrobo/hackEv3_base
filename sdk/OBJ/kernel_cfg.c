/* kernel_cfg.c */
#include "kernel/kernel_int.h"
#include "kernel_cfg.h"

#if !(TKERNEL_PRID == 0x0007U && (TKERNEL_PRVER & 0xf000U) == 0x3000U)
#error The kernel does not match this configuration file.
#endif

/*
 *  Include Directives
 */

#include "target_timer.h"
#include "tTask_tecsgen.h"
#include "tISR_tecsgen.h"
#include "tInitializeRoutine_tecsgen.h"
#include "tTerminateRoutine_tecsgen.h"
#include "platform.h"
#include "brick_dri.h"
#include "api.cfg.h"
#include "app.h"

/*
 *  Task Management Functions
 */

#define TNUM_STSKID	13
const ID _kernel_tmax_tskid = (TMIN_TSKID + TNUM_TSKID - 1);
const ID _kernel_tmax_stskid = (TMIN_TSKID + TNUM_STSKID - 1);

static STK_T _kernel_stack_TSKID_tTask_LogTask_Task[COUNT_STK_T(131072)] __attribute__((aligned(16)));
static STK_T _kernel_stack_EV3_INIT_TASK[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
static STK_T _kernel_stack_BRICK_BTN_TSK[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
static STK_T _kernel_stack_APP_INIT_TASK[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
static STK_T _kernel_stack_MAIN_TASK[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
static STK_T _kernel_stack_TRACER_TASK[COUNT_STK_T(12288)] __attribute__((aligned(16)));
static STK_T _kernel_stack_POLLING_TASK[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
static STK_T _kernel_stack_RCV_TASK[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
static STK_T _kernel_stack_SEND_RCV_TASK[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
static STK_T _kernel_stack_SEND_RCV_TASK2[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
static STK_T _kernel_stack_PIPE_OPEN_TASK[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
static STK_T _kernel_stack_SEND_TASK[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
static STK_T _kernel_stack_THREAD_TASK[COUNT_STK_T(STACK_SIZE)] __attribute__((aligned(16)));
const TINIB _kernel_tinib_table[TNUM_STSKID] = {
	{ (TA_ACT), (intptr_t)(&tTask_INIB_tab[0]), (TASK)(tTask_start), INT_PRIORITY(3), ROUND_STK_T(131072), _kernel_stack_TSKID_tTask_LogTask_Task },
	{ (TA_ACT), (intptr_t)(0), (TASK)(ev3_main_task), INT_PRIORITY(TPRI_INIT_TASK), ROUND_STK_T(STACK_SIZE), _kernel_stack_EV3_INIT_TASK },
	{ (TA_NULL), (intptr_t)(0), (TASK)(brick_button_task), INT_PRIORITY(TMIN_APP_TPRI), ROUND_STK_T(STACK_SIZE), _kernel_stack_BRICK_BTN_TSK },
	{ (TA_ACT), (intptr_t)(0), (TASK)(_app_init_task), INT_PRIORITY(TPRI_APP_INIT_TASK), ROUND_STK_T(STACK_SIZE), _kernel_stack_APP_INIT_TASK },
	{ (TA_ACT), (intptr_t)(0), (TASK)(main_task), INT_PRIORITY(MAIN_PRIORITY), ROUND_STK_T(STACK_SIZE), _kernel_stack_MAIN_TASK },
	{ (TA_NULL), (intptr_t)(0), (TASK)(tracer_task), INT_PRIORITY(TRACER_PRIORITY), ROUND_STK_T(12288), _kernel_stack_TRACER_TASK },
	{ (TA_NULL), (intptr_t)(0), (TASK)(polling_task), INT_PRIORITY(POLLING_PRIORITY), ROUND_STK_T(STACK_SIZE), _kernel_stack_POLLING_TASK },
	{ (TA_NULL), (intptr_t)(0), (TASK)(recieve_task), INT_PRIORITY(TRACER_PRIORITY+2), ROUND_STK_T(STACK_SIZE), _kernel_stack_RCV_TASK },
	{ (TA_NULL), (intptr_t)(0), (TASK)(send_rcv_task), INT_PRIORITY(TRACER_PRIORITY+2), ROUND_STK_T(STACK_SIZE), _kernel_stack_SEND_RCV_TASK },
	{ (TA_NULL), (intptr_t)(0), (TASK)(send_rcv_task2), INT_PRIORITY(TRACER_PRIORITY+2), ROUND_STK_T(STACK_SIZE), _kernel_stack_SEND_RCV_TASK2 },
	{ (TA_NULL), (intptr_t)(0), (TASK)(pipe_open_task), INT_PRIORITY(TRACER_PRIORITY+2), ROUND_STK_T(STACK_SIZE), _kernel_stack_PIPE_OPEN_TASK },
	{ (TA_NULL), (intptr_t)(0), (TASK)(send_task), INT_PRIORITY(TRACER_PRIORITY+3), ROUND_STK_T(STACK_SIZE), _kernel_stack_SEND_TASK },
	{ (TA_NULL), (intptr_t)(0), (TASK)(thread_task), INT_PRIORITY(TRACER_PRIORITY+1), ROUND_STK_T(STACK_SIZE), _kernel_stack_THREAD_TASK }
};

TOPPERS_EMPTY_LABEL(TINIB, _kernel_atinib_table);

TCB _kernel_tcb_table[TNUM_TSKID];

const ID _kernel_torder_table[TNUM_STSKID] = { 
	TSKID_tTask_LogTask_Task, EV3_INIT_TASK, BRICK_BTN_TSK, APP_INIT_TASK, MAIN_TASK, TRACER_TASK, POLLING_TASK, RCV_TASK, SEND_RCV_TASK, SEND_RCV_TASK2, PIPE_OPEN_TASK, SEND_TASK, THREAD_TASK
};

/*
 *  Semaphore Functions
 */

#define TNUM_SSEMID	2
const ID _kernel_tmax_semid = (TMIN_SEMID + TNUM_SEMID - 1);
const ID _kernel_tmax_ssemid = (TMIN_SEMID + TNUM_SSEMID - 1);

const SEMINIB _kernel_seminib_table[TNUM_SSEMID] = {
	{ (TA_NULL), (0), (1) },
	{ (TA_NULL), (1), (1) }
};

TOPPERS_EMPTY_LABEL(SEMINIB, _kernel_aseminib_table);

SEMCB _kernel_semcb_table[TNUM_SEMID];

/*
 *  Eventflag Functions
 */

#define TNUM_SFLGID	2
const ID _kernel_tmax_flgid = (TMIN_FLGID + TNUM_FLGID - 1);
const ID _kernel_tmax_sflgid = (TMIN_FLGID + TNUM_SFLGID - 1);

const FLGINIB _kernel_flginib_table[TNUM_SFLGID] = {
	{ (TA_CLR), (0) },
	{ (TA_CLR), (0) }
};

TOPPERS_EMPTY_LABEL(FLGINIB, _kernel_aflginib_table);

FLGCB _kernel_flgcb_table[TNUM_FLGID];

/*
 *  Dataqueue Functions
 */

#define TNUM_SDTQID	0
const ID _kernel_tmax_dtqid = (TMIN_DTQID + TNUM_DTQID - 1);
const ID _kernel_tmax_sdtqid = (TMIN_DTQID + TNUM_SDTQID - 1);

TOPPERS_EMPTY_LABEL(const DTQINIB, _kernel_dtqinib_table);

TOPPERS_EMPTY_LABEL(DTQINIB, _kernel_adtqinib_table);

TOPPERS_EMPTY_LABEL(DTQCB, _kernel_dtqcb_table);

/*
 *  Priority Dataqueue Functions
 */

#define TNUM_SPDQID	0
const ID _kernel_tmax_pdqid = (TMIN_PDQID + TNUM_PDQID - 1);
const ID _kernel_tmax_spdqid = (TMIN_PDQID + TNUM_SPDQID - 1);

TOPPERS_EMPTY_LABEL(const PDQINIB, _kernel_pdqinib_table);

TOPPERS_EMPTY_LABEL(PDQINIB, _kernel_apdqinib_table);

TOPPERS_EMPTY_LABEL(PDQCB, _kernel_pdqcb_table);

/*
 *  Mutex Functions
 */

#define TNUM_SMTXID	0
const ID _kernel_tmax_mtxid = (TMIN_MTXID + TNUM_MTXID - 1);
const ID _kernel_tmax_smtxid = (TMIN_MTXID + TNUM_SMTXID - 1);

TOPPERS_EMPTY_LABEL(const MTXINIB, _kernel_mtxinib_table);

TOPPERS_EMPTY_LABEL(MTXINIB, _kernel_amtxinib_table);

TOPPERS_EMPTY_LABEL(MTXCB, _kernel_mtxcb_table);

/*
 *  Fixed-sized Memorypool Functions
 */

#define TNUM_SMPFID	0
const ID _kernel_tmax_mpfid = (TMIN_MPFID + TNUM_MPFID - 1);
const ID _kernel_tmax_smpfid = (TMIN_MPFID + TNUM_SMPFID - 1);

TOPPERS_EMPTY_LABEL(const MPFINIB, _kernel_mpfinib_table);

TOPPERS_EMPTY_LABEL(MPFINIB, _kernel_ampfinib_table);

TOPPERS_EMPTY_LABEL(MPFCB, _kernel_mpfcb_table);

/*
 *  Cyclic Notification Functions
 */

#define TNUM_SCYCID	5
const ID _kernel_tmax_cycid = (TMIN_CYCID + TNUM_CYCID - 1);
const ID _kernel_tmax_scycid = (TMIN_CYCID + TNUM_SCYCID - 1);

static void
_kernel_nfyhdr_TRACER_CYC(intptr_t exinf)
{
	(void) act_tsk((ID) exinf);
}

static void
_kernel_nfyhdr_POLLING_CYC(intptr_t exinf)
{
	(void) act_tsk((ID) exinf);
}

static void
_kernel_nfyhdr_SEND_RCV_CYC(intptr_t exinf)
{
	(void) act_tsk((ID) exinf);
}

static void
_kernel_nfyhdr_SEND_RCV_CYC2(intptr_t exinf)
{
	(void) act_tsk((ID) exinf);
}

const CYCINIB _kernel_cycinib_table[TNUM_SCYCID] = {
	{ (TA_NULL), (intptr_t)(0), (NFYHDR)(brick_button_cyc), (10000), (0) },
	{ (TA_NULL), (intptr_t)(TRACER_TASK), _kernel_nfyhdr_TRACER_CYC, (10000U), (0U * 1000U) },
	{ (TA_NULL), (intptr_t)(POLLING_TASK), _kernel_nfyhdr_POLLING_CYC, (10000U), (1U * 5000U) },
	{ (TA_NULL), (intptr_t)(SEND_RCV_TASK), _kernel_nfyhdr_SEND_RCV_CYC, (500U * 1000U), (1U * 5000U) },
	{ (TA_NULL), (intptr_t)(SEND_RCV_TASK2), _kernel_nfyhdr_SEND_RCV_CYC2, (500U * 1000U), (1U * 5000U) }
};

TOPPERS_EMPTY_LABEL(CYCINIB, _kernel_acycinib_table);

TOPPERS_EMPTY_LABEL(T_NFYINFO, _kernel_acyc_nfyinfo_table);

CYCCB _kernel_cyccb_table[TNUM_CYCID];

/*
 *  Alarm Notification Functions
 */

#define TNUM_SALMID	0
const ID _kernel_tmax_almid = (TMIN_ALMID + TNUM_ALMID - 1);
const ID _kernel_tmax_salmid = (TMIN_ALMID + TNUM_SALMID - 1);

TOPPERS_EMPTY_LABEL(const ALMINIB, _kernel_alminib_table);

TOPPERS_EMPTY_LABEL(ALMINIB, _kernel_aalminib_table);

TOPPERS_EMPTY_LABEL(T_NFYINFO, _kernel_aalm_nfyinfo_table);

TOPPERS_EMPTY_LABEL(ALMCB, _kernel_almcb_table);

/*
 *  Interrupt Management Functions
 */

const uint_t _kernel_tnum_isr_queue = 1;

const ISR_ENTRY _kernel_isr_queue_list[1] = {
	{ 29, &(_kernel_isr_queue_table[0]) }
};

QUEUE _kernel_isr_queue_table[1];

void
_kernel_inthdr_29(void)
{
	_kernel_call_isr(&(_kernel_isr_queue_table[0]));
}

#define TNUM_SISRID	1
const ID _kernel_tmax_isrid = (TMIN_ISRID + TNUM_ISRID - 1);
const ID _kernel_tmax_sisrid = (TMIN_ISRID + TNUM_SISRID - 1);

const ISRINIB _kernel_isrinib_table[TNUM_SISRID] = {
	{ (TA_NULL), (intptr_t)(&tISR_INIB_tab[0]), (&(_kernel_isr_queue_table[0])), (ISR)(tISR_start), (1) }
};

TOPPERS_EMPTY_LABEL(ISRINIB, _kernel_aisrinib_table);

ISRCB _kernel_isrcb_table[TNUM_ISRID];

const ID _kernel_isrorder_table[TNUM_SISRID] = { 
	ISRID_tISR_SIOPortTarget1_ISRInstance
};

/*
 *  CPU Exception Management Functions
 */

#define TNUM_DEF_EXCNO	0
const uint_t _kernel_tnum_def_excno = TNUM_DEF_EXCNO;

TOPPERS_EMPTY_LABEL(const EXCINIB, _kernel_excinib_table);

/*
 *  Stack Area for Non-task Context
 */

static STK_T _kernel_istack[COUNT_STK_T(DEFAULT_ISTKSZ)] __attribute__((aligned(16)));
const size_t _kernel_istksz = ROUND_STK_T(DEFAULT_ISTKSZ);
STK_T *const _kernel_istk = _kernel_istack;

#ifdef TOPPERS_ISTKPT
STK_T *const _kernel_istkpt = TOPPERS_ISTKPT(_kernel_istack, ROUND_STK_T(DEFAULT_ISTKSZ));
#endif /* TOPPERS_ISTKPT */

/*
 *  Memory Area Allocated by Kernel
 */

const size_t _kernel_kmmsz = 0;
MB_T *const _kernel_kmm = NULL;

/*
 *  Time Event Management
 */

TMEVTN   _kernel_tmevt_heap[1 + TNUM_TSKID + TNUM_CYCID + TNUM_ALMID];

/*
 *  Module Initialization Function
 */

void
_kernel_initialize_object(void)
{
	_kernel_initialize_task();
	_kernel_initialize_semaphore();
	_kernel_initialize_eventflag();
	_kernel_initialize_cyclic();
	_kernel_initialize_isr();
	_kernel_initialize_interrupt();
	_kernel_initialize_exception();
}

/*
 *  Initialization Routine
 */

void
_kernel_call_inirtn(void)
{
	((INIRTN)(_kernel_target_timer_initialize))((intptr_t)(0));
	((INIRTN)(tInitializeRoutine_start))((intptr_t)(&tInitializeRoutine_INIB_tab[0]));
	((INIRTN)(initialize_brick_dri))((intptr_t)(NULL));
}

/*
 *  Termination Routine
 */

void
_kernel_call_terrtn(void)
{
	((TERRTN)(tTerminateRoutine_start))((intptr_t)(&tTerminateRoutine_INIB_tab[1]));
	((TERRTN)(tTerminateRoutine_start))((intptr_t)(&tTerminateRoutine_INIB_tab[0]));
	((TERRTN)(_kernel_target_timer_terminate))((intptr_t)(0));
}

/*
 *  Target-dependent Definitions (Mac OS X)
 */

#define TNUM_DEF_INHNO	2
const uint_t _kernel_tnum_def_inhno = TNUM_DEF_INHNO;

INTHDR_ENTRY(INHNO_TIMER, _kernel_target_timer_handler, INTPRI_TIMER)
INTHDR_ENTRY(29, _kernel_inthdr_29, TMAX_INTPRI)

const INHINIB _kernel_inhinib_table[TNUM_DEF_INHNO] = {
	{ (INHNO_TIMER), (TA_NULL), (FP)(INT_ENTRY(INHNO_TIMER, _kernel_target_timer_handler)), (INTPRI_TIMER) },
	{ (29), (TA_NULL), (FP)(INT_ENTRY(29, _kernel_inthdr_29)), (TMAX_INTPRI) }
};

const sigset_t _kernel_sigmask_table[8] = {
	{ {UINT32_C(0x6ffbd2bd), 0} },
	{ {UINT32_C(0x7ffbd2bd), 0} },
	{ {UINT32_C(0x7ffbf2bd), 0} },
	{ {UINT32_C(0x7ffbf2bd), 0} },
	{ {UINT32_C(0x7ffbf2bd), 0} },
	{ {UINT32_C(0x7ffbf2bd), 0} },
	{ {UINT32_C(0x7ffbf2bd), 0} },
	{ {UINT32_C(0x7ffbf2bd), 0} }
};

const sigset_t	_kernel_sigmask_disint_init = { { UINT32_C(0x00000000) ,0}};

