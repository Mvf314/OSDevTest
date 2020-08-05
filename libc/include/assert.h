#ifndef _ASSERT_H
#define _ASSERT_H 1

#include <stdio.h>

#define static_assert _Static_assert

#ifdef NDEBUG
#define assert(ignore) ((void)0)
#else
#define assert(expr) (void) printf((expr) ? "Assert success\n" : "Assert fail\n")
#endif

#endif
