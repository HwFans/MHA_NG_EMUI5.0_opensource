
// Set up the 128-bit shadow memory test, by defining the
// required vector-copy function, and then including the
// template.

#define VECTOR_BYTES 16

static __attribute__((noinline))
void vector_copy ( void* dst, void* src )
{
  __asm__ __volatile__(
     "movups (%1), %%xmm7 ; movups %%xmm7, (%0)"
     : /*OUT*/ : /*IN*/ "r"(dst), "r"(src) : "memory","xmm7"
  );
}

// Include the test body, which refers to the above function
#include "../common/sh-mem-vec128.tmpl.c"
