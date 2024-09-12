/* cfg1_out.c */
#define TOPPERS_CFG1_OUT
#include "kernel/kernel_int.h"
#include "target_timer.h"
#include "tTask_tecsgen.h"
#include "tISR_tecsgen.h"
#include "tInitializeRoutine_tecsgen.h"
#include "tTerminateRoutine_tecsgen.h"
#include "platform.h"
#include "brick_dri.h"
#include "api.cfg.h"
#include "app.h"

#ifdef INT64_MAX
  typedef int64_t signed_t;
  typedef uint64_t unsigned_t;
#else
  typedef int32_t signed_t;
  typedef uint32_t unsigned_t;
#endif

#include "target_cfg1_out.h"

#if defined(SIL_ENDIAN_BIG) && defined(SIL_ENDIAN_LITTLE)
#error Both SIL_ENDIAN_BIG and SIL_ENDIAN_LITTLE are defined.
#endif
#if !defined(SIL_ENDIAN_BIG) && !defined(SIL_ENDIAN_LITTLE)
#error Neither SIL_ENDIAN_BIG nor SIL_ENDIAN_LITTLE is defined.
#endif

const uint32_t TOPPERS_magic_number = 0x12345678;
const uint32_t TOPPERS_sizeof_signed_t = sizeof(signed_t);

const unsigned_t TOPPERS_cfg_CHAR_BIT = (unsigned_t)(CHAR_BIT);
const signed_t TOPPERS_cfg_SCHAR_MAX = (signed_t)(SCHAR_MAX);
const signed_t TOPPERS_cfg_SCHAR_MIN = (signed_t)(SCHAR_MIN);
const unsigned_t TOPPERS_cfg_UCHAR_MAX = (unsigned_t)(UCHAR_MAX);
const signed_t TOPPERS_cfg_CHAR_MAX = (signed_t)(CHAR_MAX);
const signed_t TOPPERS_cfg_CHAR_MIN = (signed_t)(CHAR_MIN);
const signed_t TOPPERS_cfg_SHRT_MAX = (signed_t)(SHRT_MAX);
const signed_t TOPPERS_cfg_SHRT_MIN = (signed_t)(SHRT_MIN);
const unsigned_t TOPPERS_cfg_USHRT_MAX = (unsigned_t)(USHRT_MAX);
const signed_t TOPPERS_cfg_INT_MAX = (signed_t)(INT_MAX);
const signed_t TOPPERS_cfg_INT_MIN = (signed_t)(INT_MIN);
const unsigned_t TOPPERS_cfg_UINT_MAX = (unsigned_t)(UINT_MAX);
const signed_t TOPPERS_cfg_LONG_MAX = (signed_t)(LONG_MAX);
const signed_t TOPPERS_cfg_LONG_MIN = (signed_t)(LONG_MIN);
const unsigned_t TOPPERS_cfg_ULONG_MAX = (unsigned_t)(ULONG_MAX);
#if defined(USE_EXTERNAL_ID)
const signed_t TOPPERS_cfg_USE_EXTERNAL_ID = (signed_t)(true);
#endif
#if defined(SIL_ENDIAN_BIG)
const signed_t TOPPERS_cfg_SIL_ENDIAN_BIG = (signed_t)(true);
#endif
#if defined(SIL_ENDIAN_LITTLE)
const signed_t TOPPERS_cfg_SIL_ENDIAN_LITTLE = (signed_t)(true);
#endif
const unsigned_t TOPPERS_cfg_TA_NULL = (unsigned_t)(TA_NULL);
const unsigned_t TOPPERS_cfg_TA_ACT = (unsigned_t)(TA_ACT);
const unsigned_t TOPPERS_cfg_TA_NOACTQUE = (unsigned_t)(TA_NOACTQUE);
const unsigned_t TOPPERS_cfg_TA_TPRI = (unsigned_t)(TA_TPRI);
const unsigned_t TOPPERS_cfg_TA_WMUL = (unsigned_t)(TA_WMUL);
const unsigned_t TOPPERS_cfg_TA_CLR = (unsigned_t)(TA_CLR);
const unsigned_t TOPPERS_cfg_TA_CEILING = (unsigned_t)(TA_CEILING);
const unsigned_t TOPPERS_cfg_TA_STA = (unsigned_t)(TA_STA);
const unsigned_t TOPPERS_cfg_TA_NONKERNEL = (unsigned_t)(TA_NONKERNEL);
const unsigned_t TOPPERS_cfg_TA_ENAINT = (unsigned_t)(TA_ENAINT);
const unsigned_t TOPPERS_cfg_TA_EDGE = (unsigned_t)(TA_EDGE);
const unsigned_t TOPPERS_cfg_TNFY_HANDLER = (unsigned_t)(TNFY_HANDLER);
const unsigned_t TOPPERS_cfg_TNFY_SETVAR = (unsigned_t)(TNFY_SETVAR);
const unsigned_t TOPPERS_cfg_TNFY_INCVAR = (unsigned_t)(TNFY_INCVAR);
const unsigned_t TOPPERS_cfg_TNFY_ACTTSK = (unsigned_t)(TNFY_ACTTSK);
const unsigned_t TOPPERS_cfg_TNFY_WUPTSK = (unsigned_t)(TNFY_WUPTSK);
const unsigned_t TOPPERS_cfg_TNFY_SIGSEM = (unsigned_t)(TNFY_SIGSEM);
const unsigned_t TOPPERS_cfg_TNFY_SETFLG = (unsigned_t)(TNFY_SETFLG);
const unsigned_t TOPPERS_cfg_TNFY_SNDDTQ = (unsigned_t)(TNFY_SNDDTQ);
const unsigned_t TOPPERS_cfg_TENFY_SETVAR = (unsigned_t)(TENFY_SETVAR);
const unsigned_t TOPPERS_cfg_TENFY_INCVAR = (unsigned_t)(TENFY_INCVAR);
const unsigned_t TOPPERS_cfg_TENFY_ACTTSK = (unsigned_t)(TENFY_ACTTSK);
const unsigned_t TOPPERS_cfg_TENFY_WUPTSK = (unsigned_t)(TENFY_WUPTSK);
const unsigned_t TOPPERS_cfg_TENFY_SIGSEM = (unsigned_t)(TENFY_SIGSEM);
const unsigned_t TOPPERS_cfg_TENFY_SETFLG = (unsigned_t)(TENFY_SETFLG);
const unsigned_t TOPPERS_cfg_TENFY_SNDDTQ = (unsigned_t)(TENFY_SNDDTQ);
const signed_t TOPPERS_cfg_TMIN_TPRI = (signed_t)(TMIN_TPRI);
const signed_t TOPPERS_cfg_TMAX_TPRI = (signed_t)(TMAX_TPRI);
const signed_t TOPPERS_cfg_TMIN_DPRI = (signed_t)(TMIN_DPRI);
const signed_t TOPPERS_cfg_TMAX_DPRI = (signed_t)(TMAX_DPRI);
const signed_t TOPPERS_cfg_TMIN_ISRPRI = (signed_t)(TMIN_ISRPRI);
const signed_t TOPPERS_cfg_TMAX_ISRPRI = (signed_t)(TMAX_ISRPRI);
const unsigned_t TOPPERS_cfg_TBIT_FLGPTN = (unsigned_t)(TBIT_FLGPTN);
const unsigned_t TOPPERS_cfg_TMAX_MAXSEM = (unsigned_t)(TMAX_MAXSEM);
const unsigned_t TOPPERS_cfg_TMAX_RELTIM = (unsigned_t)(TMAX_RELTIM);
const signed_t TOPPERS_cfg_TMIN_INTPRI = (signed_t)(TMIN_INTPRI);
const signed_t TOPPERS_cfg_TMAX_INTPRI = (signed_t)(TMAX_INTPRI);
const signed_t TOPPERS_cfg_TMIN_TSKID = (signed_t)(TMIN_TSKID);
const signed_t TOPPERS_cfg_TMIN_SEMID = (signed_t)(TMIN_SEMID);
const signed_t TOPPERS_cfg_TMIN_FLGID = (signed_t)(TMIN_FLGID);
const signed_t TOPPERS_cfg_TMIN_DTQID = (signed_t)(TMIN_DTQID);
const signed_t TOPPERS_cfg_TMIN_PDQID = (signed_t)(TMIN_PDQID);
const signed_t TOPPERS_cfg_TMIN_MTXID = (signed_t)(TMIN_MTXID);
const signed_t TOPPERS_cfg_TMIN_MPFID = (signed_t)(TMIN_MPFID);
const signed_t TOPPERS_cfg_TMIN_CYCID = (signed_t)(TMIN_CYCID);
const signed_t TOPPERS_cfg_TMIN_ALMID = (signed_t)(TMIN_ALMID);
#if defined(USE_TSKINICTXB)
const signed_t TOPPERS_cfg_USE_TSKINICTXB = (signed_t)(true);
#endif
#if defined(OMIT_INITIALIZE_INTERRUPT)
const signed_t TOPPERS_cfg_OMIT_INITIALIZE_INTERRUPT = (signed_t)(true);
#endif
#if defined(USE_INHINIB_TABLE)
const signed_t TOPPERS_cfg_USE_INHINIB_TABLE = (signed_t)(true);
#endif
#if defined(USE_INTINIB_TABLE)
const signed_t TOPPERS_cfg_USE_INTINIB_TABLE = (signed_t)(true);
#endif
#if defined(OMIT_INITIALIZE_EXCEPTION)
const signed_t TOPPERS_cfg_OMIT_INITIALIZE_EXCEPTION = (signed_t)(true);
#endif
#if defined(DEFAULT_ISTK)
const unsigned_t TOPPERS_cfg_DEFAULT_ISTK = (unsigned_t)(DEFAULT_ISTK);
#endif
#if defined(TARGET_TSKATR)
const unsigned_t TOPPERS_cfg_TARGET_TSKATR = (unsigned_t)(TARGET_TSKATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_TSKATR = (unsigned_t)(0);
#endif
#if defined(TARGET_INTATR)
const unsigned_t TOPPERS_cfg_TARGET_INTATR = (unsigned_t)(TARGET_INTATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_INTATR = (unsigned_t)(0);
#endif
#if defined(TARGET_INHATR)
const unsigned_t TOPPERS_cfg_TARGET_INHATR = (unsigned_t)(TARGET_INHATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_INHATR = (unsigned_t)(0);
#endif
#if defined(TARGET_ISRATR)
const unsigned_t TOPPERS_cfg_TARGET_ISRATR = (unsigned_t)(TARGET_ISRATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_ISRATR = (unsigned_t)(0);
#endif
#if defined(TARGET_EXCATR)
const unsigned_t TOPPERS_cfg_TARGET_EXCATR = (unsigned_t)(TARGET_EXCATR);
#else
const unsigned_t TOPPERS_cfg_TARGET_EXCATR = (unsigned_t)(0);
#endif
#if defined(TARGET_MIN_STKSZ)
const unsigned_t TOPPERS_cfg_TARGET_MIN_STKSZ = (unsigned_t)(TARGET_MIN_STKSZ);
#else
const unsigned_t TOPPERS_cfg_TARGET_MIN_STKSZ = (unsigned_t)(1);
#endif
#if defined(TARGET_MIN_ISTKSZ)
const unsigned_t TOPPERS_cfg_TARGET_MIN_ISTKSZ = (unsigned_t)(TARGET_MIN_ISTKSZ);
#else
const unsigned_t TOPPERS_cfg_TARGET_MIN_ISTKSZ = (unsigned_t)(1);
#endif
#if defined(CHECK_STKSZ_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_STKSZ_ALIGN = (unsigned_t)(CHECK_STKSZ_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_STKSZ_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_INTPTR_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_INTPTR_ALIGN = (unsigned_t)(CHECK_INTPTR_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_INTPTR_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_INTPTR_NONNULL)
const signed_t TOPPERS_cfg_CHECK_INTPTR_NONNULL = (signed_t)(true);
#endif
#if defined(CHECK_FUNC_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_FUNC_ALIGN = (unsigned_t)(CHECK_FUNC_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_FUNC_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_FUNC_NONNULL)
const signed_t TOPPERS_cfg_CHECK_FUNC_NONNULL = (signed_t)(true);
#endif
#if defined(CHECK_STACK_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_STACK_ALIGN = (unsigned_t)(CHECK_STACK_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_STACK_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_STACK_NONNULL)
const signed_t TOPPERS_cfg_CHECK_STACK_NONNULL = (signed_t)(true);
#endif
#if defined(CHECK_MPF_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_MPF_ALIGN = (unsigned_t)(CHECK_MPF_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_MPF_ALIGN = (unsigned_t)(1);
#endif
#if defined(CHECK_MPF_NONNULL)
const signed_t TOPPERS_cfg_CHECK_MPF_NONNULL = (signed_t)(true);
#endif
#if defined(CHECK_MB_ALIGN)
const unsigned_t TOPPERS_cfg_CHECK_MB_ALIGN = (unsigned_t)(CHECK_MB_ALIGN);
#else
const unsigned_t TOPPERS_cfg_CHECK_MB_ALIGN = (unsigned_t)(1);
#endif
const unsigned_t TOPPERS_cfg_sizeof_void_ptr = (unsigned_t)(sizeof(void*));
const unsigned_t TOPPERS_cfg_sizeof_uint_t = (unsigned_t)(sizeof(uint_t));
const unsigned_t TOPPERS_cfg_sizeof_size_t = (unsigned_t)(sizeof(size_t));
const unsigned_t TOPPERS_cfg_sizeof_intptr_t = (unsigned_t)(sizeof(intptr_t));
const unsigned_t TOPPERS_cfg_sizeof_ID = (unsigned_t)(sizeof(ID));
const unsigned_t TOPPERS_cfg_sizeof_FP = (unsigned_t)(sizeof(FP));
const unsigned_t TOPPERS_cfg_sizeof_INTNO = (unsigned_t)(sizeof(INTNO));
const unsigned_t TOPPERS_cfg_sizeof_INHNO = (unsigned_t)(sizeof(INHNO));
const unsigned_t TOPPERS_cfg_sizeof_EXCNO = (unsigned_t)(sizeof(EXCNO));
const unsigned_t TOPPERS_cfg_sizeof_TASK = (unsigned_t)(sizeof(TASK));
const unsigned_t TOPPERS_cfg_sizeof_TMEHDR = (unsigned_t)(sizeof(TMEHDR));
const unsigned_t TOPPERS_cfg_sizeof_ISR = (unsigned_t)(sizeof(ISR));
const unsigned_t TOPPERS_cfg_sizeof_INTHDR = (unsigned_t)(sizeof(INTHDR));
const unsigned_t TOPPERS_cfg_sizeof_EXCHDR = (unsigned_t)(sizeof(EXCHDR));
const unsigned_t TOPPERS_cfg_sizeof_INIRTN = (unsigned_t)(sizeof(INIRTN));
const unsigned_t TOPPERS_cfg_sizeof_TERRTN = (unsigned_t)(sizeof(TERRTN));
const unsigned_t TOPPERS_cfg_sizeof_NFYHDR = (unsigned_t)(sizeof(NFYHDR));
const unsigned_t TOPPERS_cfg_sizeof_TINIB = (unsigned_t)(sizeof(TINIB));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_tskatr = (unsigned_t)(offsetof(TINIB,tskatr));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_exinf = (unsigned_t)(offsetof(TINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_task = (unsigned_t)(offsetof(TINIB,task));
const unsigned_t TOPPERS_cfg_offsetof_TINIB_ipriority = (unsigned_t)(offsetof(TINIB,ipriority));
#if !defined(USE_TSKINICTXB)
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stksz = (unsigned_t)(offsetof(TINIB,stksz));
#endif
#if !defined(USE_TSKINICTXB)
const unsigned_t TOPPERS_cfg_offsetof_TINIB_stk = (unsigned_t)(offsetof(TINIB,stk));
#endif
const unsigned_t TOPPERS_cfg_sizeof_SEMINIB = (unsigned_t)(sizeof(SEMINIB));
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_sematr = (unsigned_t)(offsetof(SEMINIB,sematr));
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_isemcnt = (unsigned_t)(offsetof(SEMINIB,isemcnt));
const unsigned_t TOPPERS_cfg_offsetof_SEMINIB_maxsem = (unsigned_t)(offsetof(SEMINIB,maxsem));
const unsigned_t TOPPERS_cfg_sizeof_FLGPTN = (unsigned_t)(sizeof(FLGPTN));
const unsigned_t TOPPERS_cfg_sizeof_FLGINIB = (unsigned_t)(sizeof(FLGINIB));
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_flgatr = (unsigned_t)(offsetof(FLGINIB,flgatr));
const unsigned_t TOPPERS_cfg_offsetof_FLGINIB_iflgptn = (unsigned_t)(offsetof(FLGINIB,iflgptn));
const unsigned_t TOPPERS_cfg_sizeof_DTQINIB = (unsigned_t)(sizeof(DTQINIB));
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqatr = (unsigned_t)(offsetof(DTQINIB,dtqatr));
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_dtqcnt = (unsigned_t)(offsetof(DTQINIB,dtqcnt));
const unsigned_t TOPPERS_cfg_offsetof_DTQINIB_p_dtqmb = (unsigned_t)(offsetof(DTQINIB,p_dtqmb));
const unsigned_t TOPPERS_cfg_sizeof_PDQINIB = (unsigned_t)(sizeof(PDQINIB));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqatr = (unsigned_t)(offsetof(PDQINIB,pdqatr));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_pdqcnt = (unsigned_t)(offsetof(PDQINIB,pdqcnt));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_maxdpri = (unsigned_t)(offsetof(PDQINIB,maxdpri));
const unsigned_t TOPPERS_cfg_offsetof_PDQINIB_p_pdqmb = (unsigned_t)(offsetof(PDQINIB,p_pdqmb));
const unsigned_t TOPPERS_cfg_sizeof_MTXINIB = (unsigned_t)(sizeof(MTXINIB));
const unsigned_t TOPPERS_cfg_offsetof_MTXINIB_mtxatr = (unsigned_t)(offsetof(MTXINIB,mtxatr));
const unsigned_t TOPPERS_cfg_offsetof_MTXINIB_ceilpri = (unsigned_t)(offsetof(MTXINIB,ceilpri));
const unsigned_t TOPPERS_cfg_sizeof_MPFINIB = (unsigned_t)(sizeof(MPFINIB));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpfatr = (unsigned_t)(offsetof(MPFINIB,mpfatr));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blkcnt = (unsigned_t)(offsetof(MPFINIB,blkcnt));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_blksz = (unsigned_t)(offsetof(MPFINIB,blksz));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_mpf = (unsigned_t)(offsetof(MPFINIB,mpf));
const unsigned_t TOPPERS_cfg_offsetof_MPFINIB_p_mpfmb = (unsigned_t)(offsetof(MPFINIB,p_mpfmb));
const unsigned_t TOPPERS_cfg_sizeof_CYCINIB = (unsigned_t)(sizeof(CYCINIB));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycatr = (unsigned_t)(offsetof(CYCINIB,cycatr));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_exinf = (unsigned_t)(offsetof(CYCINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_nfyhdr = (unsigned_t)(offsetof(CYCINIB,nfyhdr));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cyctim = (unsigned_t)(offsetof(CYCINIB,cyctim));
const unsigned_t TOPPERS_cfg_offsetof_CYCINIB_cycphs = (unsigned_t)(offsetof(CYCINIB,cycphs));
const unsigned_t TOPPERS_cfg_sizeof_ALMINIB = (unsigned_t)(sizeof(ALMINIB));
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_almatr = (unsigned_t)(offsetof(ALMINIB,almatr));
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_exinf = (unsigned_t)(offsetof(ALMINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_ALMINIB_nfyhdr = (unsigned_t)(offsetof(ALMINIB,nfyhdr));
const unsigned_t TOPPERS_cfg_sizeof_ISRINIB = (unsigned_t)(sizeof(ISRINIB));
const unsigned_t TOPPERS_cfg_offsetof_ISRINIB_isratr = (unsigned_t)(offsetof(ISRINIB,isratr));
const unsigned_t TOPPERS_cfg_offsetof_ISRINIB_exinf = (unsigned_t)(offsetof(ISRINIB,exinf));
const unsigned_t TOPPERS_cfg_offsetof_ISRINIB_p_isr_queue = (unsigned_t)(offsetof(ISRINIB,p_isr_queue));
const unsigned_t TOPPERS_cfg_offsetof_ISRINIB_isr = (unsigned_t)(offsetof(ISRINIB,isr));
const unsigned_t TOPPERS_cfg_offsetof_ISRINIB_isrpri = (unsigned_t)(offsetof(ISRINIB,isrpri));
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_sizeof_INHINIB = (unsigned_t)(sizeof(INHINIB));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INHINIB_inhno = (unsigned_t)(offsetof(INHINIB,inhno));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INHINIB_inhatr = (unsigned_t)(offsetof(INHINIB,inhatr));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INHINIB_int_entry = (unsigned_t)(offsetof(INHINIB,int_entry));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_sizeof_INTINIB = (unsigned_t)(sizeof(INTINIB));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INTINIB_intno = (unsigned_t)(offsetof(INTINIB,intno));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INTINIB_intatr = (unsigned_t)(offsetof(INTINIB,intatr));
#endif
#if !defined(OMIT_INITIALIZE_INTERRUPT)
const unsigned_t TOPPERS_cfg_offset_INTINIB_intpri = (unsigned_t)(offsetof(INTINIB,intpri));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_sizeof_EXCINIB = (unsigned_t)(sizeof(EXCINIB));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_offset_EXCINIB_excno = (unsigned_t)(offsetof(EXCINIB,excno));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_offset_EXCINIB_excatr = (unsigned_t)(offsetof(EXCINIB,excatr));
#endif
#if !defined(OMIT_INITIALIZE_EXCEPTION)
const unsigned_t TOPPERS_cfg_offset_EXCINIB_exc_entry = (unsigned_t)(offsetof(EXCINIB,exc_entry));
#endif
const unsigned_t TOPPERS_cfg_SIGINT = (unsigned_t)(SIGINT);
const unsigned_t TOPPERS_cfg_SIGKILL = (unsigned_t)(SIGKILL);
const unsigned_t TOPPERS_cfg_SIGBUS = (unsigned_t)(SIGBUS);
const unsigned_t TOPPERS_cfg_SIGSEGV = (unsigned_t)(SIGSEGV);
const unsigned_t TOPPERS_cfg_SIGSTOP = (unsigned_t)(SIGSTOP);
const unsigned_t TOPPERS_cfg_SIGUSR2 = (unsigned_t)(SIGUSR2);
const unsigned_t TOPPERS_cfg_SIGIO = (unsigned_t)(SIGIO);

#define TDOM_APP 1

#line 11 "../../target/raspi_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_1 = 1;
#line 11 "../../target/raspi_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_iniatr_1 = (unsigned_t)(TA_NULL);

#line 12 "../../target/raspi_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_2 = 2;
#line 12 "../../target/raspi_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_teratr_2 = (unsigned_t)(TA_NULL);

#line 13 "../../target/raspi_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_3 = 3;
#line 13 "../../target/raspi_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_3 = (unsigned_t)(INTNO_TIMER);
#line 13 "../../target/raspi_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_3 = (unsigned_t)(TA_ENAINT | INTATR_TIMER);
#line 13 "../../target/raspi_gcc/target_timer.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_3 = (signed_t)(INTPRI_TIMER);

#line 14 "../../target/raspi_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_static_api_4 = 4;
#line 14 "../../target/raspi_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhno_4 = (unsigned_t)(INHNO_TIMER);
#line 14 "../../target/raspi_gcc/target_timer.cfg"
const unsigned_t TOPPERS_cfg_valueof_inhatr_4 = (unsigned_t)(TA_NULL);

#line 2 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_5 = 5;
#define TSKID_tTask_LogTask_Task	(<>)
#line 2 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_5 = (unsigned_t)(TA_ACT);
#line 2 "./gen/tecsgen.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_5 = (signed_t)(3);
#line 2 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_5 = (unsigned_t)(131072);

#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_6 = 6;
#define SEMID_tSemaphore_SerialPort1_ReceiveSemaphore	(<>)
#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_6 = (unsigned_t)(TA_NULL);
#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_6 = (unsigned_t)(0);
#line 3 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_6 = (unsigned_t)(1);

#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_7 = 7;
#define SEMID_tSemaphore_SerialPort1_SendSemaphore	(<>)
#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_sematr_7 = (unsigned_t)(TA_NULL);
#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_isemcnt_7 = (unsigned_t)(1);
#line 4 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_maxsem_7 = (unsigned_t)(1);

#line 5 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_8 = 8;
#line 5 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_8 = (unsigned_t)(29);
#line 5 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_intatr_8 = (unsigned_t)(TA_ENAINT | TA_EDGE);
#line 5 "./gen/tecsgen.cfg"
const signed_t TOPPERS_cfg_valueof_intpri_8 = (signed_t)(TMAX_INTPRI);

#line 7 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_9 = 9;
#define ISRID_tISR_SIOPortTarget1_ISRInstance	(<>)
#line 7 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_isratr_9 = (unsigned_t)(TA_NULL);
#line 7 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_intno_9 = (unsigned_t)(SIGIO);
#line 7 "./gen/tecsgen.cfg"
const signed_t TOPPERS_cfg_valueof_isrpri_9 = (signed_t)(1);

#line 9 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_10 = 10;
#line 9 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_iniatr_10 = (unsigned_t)(TA_NULL);

#line 11 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_11 = 11;
#line 11 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_teratr_11 = (unsigned_t)(TA_NULL);

#line 12 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_static_api_12 = 12;
#line 12 "./gen/tecsgen.cfg"
const unsigned_t TOPPERS_cfg_valueof_teratr_12 = (unsigned_t)(TA_NULL);

#if !defined(BUILD_MODULE)

#line 8 "../../target/raspi_gcc/platform/platform.cfg"
const unsigned_t TOPPERS_cfg_static_api_13 = 13;
#define EV3_INIT_TASK	(<>)
#line 8 "../../target/raspi_gcc/platform/platform.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_13 = (unsigned_t)(TA_ACT);
#line 8 "../../target/raspi_gcc/platform/platform.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_13 = (signed_t)(TPRI_INIT_TASK);
#line 8 "../../target/raspi_gcc/platform/platform.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_13 = (unsigned_t)(STACK_SIZE);

#if !defined(OMIT_DEFAULT_EXCHDR)

#endif

#line 7 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_static_api_14 = 14;
#line 7 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_iniatr_14 = (unsigned_t)(TA_NULL);

#line 14 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_static_api_15 = 15;
#define BTN_CLICK_FLG	(<>)
#line 14 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_flgatr_15 = (unsigned_t)(TA_CLR);
#line 14 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_iflgptn_15 = (unsigned_t)(0);

#line 16 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_static_api_16 = 16;
#define BRICK_BTN_TSK	(<>)
#line 16 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_16 = (unsigned_t)(TA_NULL);
#line 16 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_16 = (signed_t)(TMIN_APP_TPRI);
#line 16 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_16 = (unsigned_t)(STACK_SIZE);

#line 19 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_static_api_17 = 17;
#define BRICK_BTN_CYC	(<>)
#line 19 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycatr_17 = (unsigned_t)(TA_NULL);
#line 19 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_nfymode_17 = (unsigned_t)(TNFY_HANDLER);
#line 19 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_cyctim_17 = (unsigned_t)(10000);
#line 19 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycphs_17 = (unsigned_t)(0);

#line 21 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_static_api_18 = 18;
#define CONSOLE_BTN_CLICK_FLG	(<>)
#line 21 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_flgatr_18 = (unsigned_t)(TA_CLR);
#line 21 "../../target/raspi_gcc/drivers/brick/brick_dri.cfg"
const unsigned_t TOPPERS_cfg_valueof_iflgptn_18 = (unsigned_t)(0);

#endif

#line 3 "../common/ev3api/ev3api.cfg"
const unsigned_t TOPPERS_cfg_static_api_19 = 19;
#define APP_INIT_TASK	(<>)
#line 3 "../common/ev3api/ev3api.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_19 = (unsigned_t)(TA_ACT);
#line 3 "../common/ev3api/ev3api.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_19 = (signed_t)(TPRI_APP_INIT_TASK);
#line 3 "../common/ev3api/ev3api.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_19 = (unsigned_t)(STACK_SIZE);

#line 7 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_20 = 20;
#define MAIN_TASK	(<>)
#line 7 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_20 = (unsigned_t)(TA_ACT);
#line 7 "tmp_app.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_20 = (signed_t)(MAIN_PRIORITY);
#line 7 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_20 = (unsigned_t)(STACK_SIZE);

#line 9 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_21 = 21;
#define TRACER_TASK	(<>)
#line 9 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_21 = (unsigned_t)(TA_NULL);
#line 9 "tmp_app.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_21 = (signed_t)(TRACER_PRIORITY);
#line 9 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_21 = (unsigned_t)(12288);

#line 12 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_22 = 22;
#define POLLING_TASK	(<>)
#line 12 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_22 = (unsigned_t)(TA_NULL);
#line 12 "tmp_app.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_22 = (signed_t)(POLLING_PRIORITY);
#line 12 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_22 = (unsigned_t)(STACK_SIZE);

#line 13 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_23 = 23;
#define RCV_TASK	(<>)
#line 13 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_23 = (unsigned_t)(TA_NULL);
#line 13 "tmp_app.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_23 = (signed_t)(TRACER_PRIORITY+2);
#line 13 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_23 = (unsigned_t)(STACK_SIZE);

#line 14 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_24 = 24;
#define SEND_RCV_TASK	(<>)
#line 14 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_24 = (unsigned_t)(TA_NULL);
#line 14 "tmp_app.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_24 = (signed_t)(TRACER_PRIORITY+2);
#line 14 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_24 = (unsigned_t)(STACK_SIZE);

#line 15 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_25 = 25;
#define SEND_RCV_TASK2	(<>)
#line 15 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_25 = (unsigned_t)(TA_NULL);
#line 15 "tmp_app.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_25 = (signed_t)(TRACER_PRIORITY+2);
#line 15 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_25 = (unsigned_t)(STACK_SIZE);

#line 16 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_26 = 26;
#define PIPE_OPEN_TASK	(<>)
#line 16 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_26 = (unsigned_t)(TA_NULL);
#line 16 "tmp_app.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_26 = (signed_t)(TRACER_PRIORITY+2);
#line 16 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_26 = (unsigned_t)(STACK_SIZE);

#line 17 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_27 = 27;
#define SEND_TASK	(<>)
#line 17 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_27 = (unsigned_t)(TA_NULL);
#line 17 "tmp_app.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_27 = (signed_t)(TRACER_PRIORITY+3);
#line 17 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_27 = (unsigned_t)(STACK_SIZE);

#line 18 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_28 = 28;
#define THREAD_TASK	(<>)
#line 18 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_tskatr_28 = (unsigned_t)(TA_NULL);
#line 18 "tmp_app.cfg"
const signed_t TOPPERS_cfg_valueof_itskpri_28 = (signed_t)(TRACER_PRIORITY+1);
#line 18 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_stksz_28 = (unsigned_t)(STACK_SIZE);

#line 20 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_29 = 29;
#define TRACER_CYC	(<>)
#line 20 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycatr_29 = (unsigned_t)(TA_NULL);
#line 20 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_nfymode_29 = (unsigned_t)(TNFY_ACTTSK);
#line 20 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cyctim_29 = (unsigned_t)(10000U);
#line 20 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycphs_29 = (unsigned_t)(0U * 1000U);

#line 21 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_30 = 30;
#define POLLING_CYC	(<>)
#line 21 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycatr_30 = (unsigned_t)(TA_NULL);
#line 21 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_nfymode_30 = (unsigned_t)(TNFY_ACTTSK);
#line 21 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cyctim_30 = (unsigned_t)(10000U);
#line 21 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycphs_30 = (unsigned_t)(1U * 5000U);

#line 22 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_31 = 31;
#define SEND_RCV_CYC	(<>)
#line 22 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycatr_31 = (unsigned_t)(TA_NULL);
#line 22 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_nfymode_31 = (unsigned_t)(TNFY_ACTTSK);
#line 22 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cyctim_31 = (unsigned_t)(500U * 1000U);
#line 22 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycphs_31 = (unsigned_t)(1U * 5000U);

#line 23 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_32 = 32;
#define SEND_RCV_CYC2	(<>)
#line 23 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycatr_32 = (unsigned_t)(TA_NULL);
#line 23 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_nfymode_32 = (unsigned_t)(TNFY_ACTTSK);
#line 23 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cyctim_32 = (unsigned_t)(500U * 1000U);
#line 23 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_valueof_cycphs_32 = (unsigned_t)(1U * 5000U);

#line 29 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_33 = 33;

#line 30 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_34 = 34;

#line 31 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_35 = 35;

#line 32 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_36 = 36;

#line 33 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_37 = 37;

#line 34 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_38 = 38;

#line 35 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_39 = 39;

#line 36 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_40 = 40;

#line 37 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_41 = 41;

#line 38 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_42 = 42;

#line 39 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_43 = 43;

#line 40 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_44 = 44;

#line 41 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_45 = 45;

#line 42 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_46 = 46;

#line 43 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_47 = 47;

#line 44 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_48 = 48;

#line 45 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_49 = 49;

#line 46 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_50 = 50;

#line 47 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_51 = 51;

#line 48 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_52 = 52;

#line 49 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_53 = 53;

#line 50 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_54 = 54;

#line 51 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_55 = 55;

#line 52 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_56 = 56;

#line 53 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_57 = 57;

#line 54 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_58 = 58;

#line 55 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_59 = 59;

#line 56 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_60 = 60;

#line 57 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_61 = 61;

#line 58 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_62 = 62;

#line 59 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_63 = 63;

#line 60 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_64 = 64;

#line 61 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_65 = 65;

#line 62 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_66 = 66;

#line 63 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_67 = 67;

#line 64 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_68 = 68;

#line 65 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_69 = 69;

#line 66 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_70 = 70;

#line 67 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_71 = 71;

#line 68 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_72 = 72;

#line 69 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_73 = 73;

#line 70 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_74 = 74;

#line 71 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_75 = 75;

#line 72 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_76 = 76;

#line 73 "tmp_app.cfg"
const unsigned_t TOPPERS_cfg_static_api_77 = 77;

