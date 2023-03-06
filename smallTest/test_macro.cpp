#define STR_VALUE(arg)      #arg
#define FUNCTION_NAME(name) STR_VALUE(name)

#define TEST_FUNC      test_func
#define TEST_FUNC_NAME FUNCTION_NAME(TEST_FUNC)

#define A 3
#define B 4

#define GLUE_X_Y(x,y) x##y
#define GLUE_X_Y_EXPAND(x,y) GLUE_X_Y(x,y)

#define MY_CHAR(param) ;

#define MACRO_CHECK_EXPAND(x) MACRO_CHECK(x)

#define MACRO_TRACE(fmt, ...) \
    printf("%s %s (%d) -> ", __FILE__, __PRETTY_FUNCTION__, __LINE__); \
    printf(fmt, ##__VA_ARGS__);\

#define MACRO_CHECK(ensure) if(!(ensure)) \
{ \
    MACRO_TRACE("Check ERROR: %sn", #ensure);\ 
}\

#include <stdio.h>
#include <iostream>

static void TEST_FUNC(void)
{
    printf("In function %s\n", TEST_FUNC_NAME);
}

int funcA(int a,int b)
{
    return a - b;
}

int main(void)
{
    // puts(TEST_FUNC_NAME);
    // TEST_FUNC();

    // std::cout << FUNCTION_NAME(zzz)<<std::endl;
    // std::cout << GLUE_X_Y(1,3)<<std::endl;

    MACRO_CHECK(funcA(40,30)<0)
    return(0);
}

