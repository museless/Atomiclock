/*---------------------------------------------
 *     modification time: 2016.12.30 11:20
 *     mender: Muse
-*---------------------------------------------*/

/*---------------------------------------------
 *     file: satomic.h 
 *     creation time: 2016-07-11 12:57:45
 *     author: Muse 
-*---------------------------------------------*/

/*---------------------------------------------
 *       Source file content Five part
 *
 *       Part Zero:  Include
 *       Part One:   Define 
 *       Part Two:   Typedef
 *       Part Three: Struct
 *
 *       Part Four:  Function
 *
-*---------------------------------------------*/

/*---------------------------------------------
 *             Part Zero: Include
-*---------------------------------------------*/

#include <stdbool.h>


/*---------------------------------------------
 *            Part Two: Typedef
-*---------------------------------------------*/

typedef int MATOS;


/*---------------------------------------------
 *            Part Four: Function
-*---------------------------------------------*/

#define mato_init(ato, set) \
        ato = set

#define mato_inc(ato) \
        __sync_fetch_and_add(&ato, 1)

#define mato_add(ato, inc) \
        __sync_fetch_and_add(&ato, (inc))

#define mato_dec(ato) \
        __sync_fetch_and_sub(&ato, 1)

#define mato_sub(ato, sub) \
        __sync_fetch_and_sub(&ato, (sub))

#define mato_inc_and_test(ato) \
        ((__sync_fetch_and_sub(&ato, 1) - 1) ? false : true)

#define mato_add_and_test(ato, inc) \
        ((__sync_fetch_and_add(&ato, (inc)) + inc) ? false : true)

#define mato_dec_and_test(ato) \
        ((__sync_fetch_and_sub(&ato, 1) - 1) ? false : true)

#define mato_sub_and_test(ato, sub) \
        ((__sync_fetch_and_sub(&ato, (sub)) - sub) ? false : true)

#define mato_lock(ato) \
        while (!mato_dec_and_test((ato))) \
            mato_inc((ato));

#define mato_unlock(ato) \
        mato_inc((ato))

