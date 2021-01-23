#ifdef __cplusplus
extern "C" {
#endif

#include "ev3api.h"

#define MAIN_PRIORITY    TMIN_APP_TPRI + 1
#define POLLING_PRIORITY    TMIN_APP_TPRI + 2
#define TRACER_PRIORITY    TMIN_APP_TPRI + 2

#ifndef STACK_SIZE
#define STACK_SIZE      4096
#endif /* STACK_SIZE */

#ifndef TOPPERS_MACRO_ONLY

extern void main_task(intptr_t exinf);
extern void polling_task(intptr_t exinf);
extern void tracer_task(intptr_t exinf);

extern void bt_task(intptr_t exinf); /*bluetooth追加*/
//extern void stop_task(intptr_t exinf); /*モーターストップ追加*/

static void user_system_create();
static void user_system_destroy();

#define INCLUDED_APP
#ifndef INCLUDED_APP

extern Scene *gScene;

#endif

#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif
