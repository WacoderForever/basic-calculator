

struct CwebHttpResponse * trigonometric_calculate_route(struct CwebHttpRequest *request){


    char *angle = request->get_param(request,"angle");
    char *operator = request->get_param(request,"operator");

    //transform num1 to int
    float angle_float=atof(angle);
    //transform num2 to int;

    //transform result to int
    float result_float;

    if(strcmp(operator,"SIN")== 0){
        result_float = 1 + angle_float;
    }
    if(strcmp(operator,"COS")== 0){
        result_float = 2 + angle_float;
    }
    if(strcmp(operator,"TAN")== 0){
        result_float = 3 + angle_float;
    }

    char result[30];
    sprintf(result,"The Result is:<br>%f",result_float);
    struct CTextStack *stack = render_trigonometric_calculator(result);
    return cweb_send_rendered_CTextStack_cleaning_memory(
            stack,
            200
    );
}

