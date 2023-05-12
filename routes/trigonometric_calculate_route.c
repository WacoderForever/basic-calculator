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

struct CwebHttpResponse * trigonometric_calculate_route(struct CwebHttpRequest *request){


    char *angle = request->get_param(request,"angle");
    char *operator = request->get_param(request,"operator");

    //transform num1 to int
    double angle_float=atof(angle);
    //transform num2 to int;

    //transform result to int
    double result_int;

    if(strcmp(operator,"SIN")== 0){
        result_int = sin(angle_float);
    }
    if(strcmp(operator,"COS")== 0){
        result_int = cos(angle_float);
    }
    if(strcmp(operator,"TAN")== 0){
        result_int = tan (angle_float);
    }

    char result[30];
    sprintf(result,"The Result is:<br>%f",result_int);
    struct CTextStack *stack = render_trigonometric_calculator(result);
    return cweb_send_rendered_CTextStack_cleaning_memory(
            stack,
            200
    );
}

