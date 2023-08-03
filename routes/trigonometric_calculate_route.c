#include <math.h>
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

struct CwebHttpResponse * trigonometric_calculate_route(struct CwebHttpRequest *request){


    char *angle = request->get_param(request,"angle");
    char *operator = request->get_param(request,"operator");

    //transform num1 to int
    double angle_float=atof(angle);
    //transform num2 to int;

    //transform result to int
    double result_int;
    double deg=57.29577951;

    if(strcmp(operator,"SIN")== 0){
        result_int = sin(angle_float/deg);
    }
    if(strcmp(operator,"COS")== 0){
        result_int = cos(angle_float/deg);
    }
    if(strcmp(operator,"TAN")== 0){
        result_int = tan (angle_float/deg);
    }

    char result[30];
    sprintf(result,"The Result is:<br>%.3f",result_int);
    struct CTextStack *stack = render_trigonometric_calculator(result);
    return cweb_send_rendered_CTextStack_cleaning_memory(
            stack,
            200
    );
}

