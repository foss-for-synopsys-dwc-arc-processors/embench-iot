/* Board support for generic ARC board

   SPDX-License-Identifier: GPL-3.0-or-later */

#include <support.h>
#include <stdio.h>
#include <stdio.h>

#ifdef __GNUC__
#define _sr __builtin_arc_sr
#define _lr __builtin_arc_lr
#endif


#define RESET_TIMER0 _sr(0x00, 0x21)
#define READ_TIMER0 _lr(0x21)
#define INIT_TIMER0 \
do { \
_sr (0xffffffff, 0x23); \
_sr (0x03, 0x33); \
} while (0);

#define HZ 1000000
static long  begin_time, end_time, user_time;

void
initialise_board ()
{
  __asm__ volatile ("nop" : : : "memory");
  // INIT_TIMER0;
  //RESET_TIMER0;
}

void __attribute__ ((noinline)) __attribute__ ((externally_visible))
start_trigger ()
{
  __asm__ volatile ("nop" : : : "memory");
  //RESET_TIMER0;
  begin_time = clock ();
}

void __attribute__ ((noinline)) __attribute__ ((externally_visible))
stop_trigger ()
{
  unsigned int end;
  __asm__ volatile ("nop" : : : "memory");
  
  //end = READ_TIMER0;
  //printf ("Total cycles: %ld\n", end);
  //RESET_TIMER0;
  end_time = clock();

  user_time = end_time - begin_time;
  printf ("User time %ld, HZ = %ld\n", user_time, (long) HZ);

}
