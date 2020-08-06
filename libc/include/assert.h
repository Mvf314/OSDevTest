#ifndef _ASSERT_H
#define _ASSERT_H 1

#include <stdio.h>

#define static_assert _Static_assert

#ifdef NDEBUG
#define assert(ignore) ((void)0)
#else
#define assert(expr) (void) ((expr ? : printf("Assertion failed: %s, function %s, file %s, line %h\n", #expr, __func__, __FILE__, __LINE__)))
#endif

#endif
