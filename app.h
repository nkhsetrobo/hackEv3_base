#if 1
#ifdef __cplusplus
extern "C" {
#endif

#include "ev3api.h"
#include "target_test.h"


#define MAIN_PRIORITY    TMIN_APP_TPRI + 1
#define POLLING_PRIORITY    TMIN_APP_TPRI + 2
#define TRACER_PRIORITY    TMIN_APP_TPRI + 2

#define HIGH_PRIORITY   9           /* 並行実行されるタスクの優先度 */
#define MID_PRIORITY    10
#define LOW_PRIORITY    11


#ifndef STACK_SIZE
#define STACK_SIZE      12288
#endif /* STACK_SIZE 4096 */

#ifndef TOPPERS_MACRO_ONLY

extern void main_task(intptr_t exinf);
extern void polling_task(intptr_t exinf);
extern void tracer_task(intptr_t exinf);
extern void recieve_task(intptr_t unused);

static void user_system_create();
static void user_system_destroy();

#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif

#endif



#if 0
#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ターゲット依存の定義
 */
#include "ev3api.h"

#include "target_test.h"

/*
 *  各タスクの優先度の定義
 */

#define MAIN_PRIORITY   5           /* メインタスクの優先度 */
                                    /* HIGH_PRIORITYより高くすること */

#define HIGH_PRIORITY   9           /* 並行実行されるタスクの優先度 */
#define MID_PRIORITY    10
#define LOW_PRIORITY    11

#define TRACER_PRIORITY    TMIN_APP_TPRI + 2

/*
 *  ターゲットに依存する可能性のある定数の定義
 */

#ifndef TASK_PORTID
#define TASK_PORTID     1           /* 文字入力するシリアルポートID */
#endif /* TASK_PORTID */

#ifndef STACK_SIZE
#define STACK_SIZE      4096        /* タスクのスタックサイズ */
#endif /* STACK_SIZE */

/*
 *  関数のプロトタイプ宣言
 */
#ifndef TOPPERS_MACRO_ONLY

extern void main_task(intptr_t exinf);
extern void bt_task(intptr_t exinf);
extern void tracer_task(intptr_t unused);


static void user_system_create();
static void user_system_destroy();

#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif

#endif
