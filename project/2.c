/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Jun 2020 08:46:18 PM CST
 ************************************************************************/
#include <stdio.h>
#include <math.h>
 
// tgmath.h 宏 cbrt 的可能实现
#define cbrt(X) _Generic((X), \
    long double: cbrtl, \
    default: cbrt,  \
    float: cbrtf  \
)(X)
 
int main(void) {
    double x = 8.0;
    const float y = 3.375;
    printf("cbrt(8.0) = %f\n", cbrt(x)); // 选择默认的 cbrt
    printf("cbrtf(3.375) = %f\n", cbrt(y)); // 将 const float 转换成 float，
    // 然后选择 cbrtf
}
