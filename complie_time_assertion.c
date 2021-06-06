/*
 * What is “:-!!” in C code?  ( https://stackoverflow.com/q/9229601 )
 */

# include <stdio.h>



# define    COMPILE_TIME_ASSERT_ZERO(e)    {                   \
    int __compile_time_assert_zero__                           \
        __attribute__((unused)) =                              \
        (sizeof(struct { int : -!!(e); }));                    \
}


struct {
    int x1 : 8;
    int x2 : 8;
    int    : 0;
    int x3 : 8;
} raw;

struct {
    int x1 : 8;
    int x2 : 8;
    int    : 8;
    int x3 : 8;
} raw2;


int main()
{
    /* int pass = sizeof(struct { int : -!!( 0 ); });   // compiles fine */
    /* int fail = sizeof(struct { int : -!!( 1 ); });   // fails to compile */

    COMPILE_TIME_ASSERT_ZERO((0));

    printf("%d\n", sizeof(raw));
    printf("%d\n", sizeof(raw2));

return 0;
}