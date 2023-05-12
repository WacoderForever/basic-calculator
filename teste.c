#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

double sin(double x) {
    double result = 0.0;
    int sign = 1;
    for (int n = 1; n <= 10; n += 2) {
        result += sign * power(x, n) / factorial(n);
        sign *= -1;
    }
    return result;
}

double cos(double x) {
    double result = 0.0;
    int sign = 1;
    for (int n = 0; n <= 10; n += 2) {
        result += sign * power(x, n) / factorial(n);
        sign *= -1;
    }
    return result;
}

double tan(double x) {
    return sin(x) / cos(x);
}



int main(){
    double angle_float=atof("0.5");
    double result_int = sin (angle_float);
    printf("%f",result_int);
    return 0;
}