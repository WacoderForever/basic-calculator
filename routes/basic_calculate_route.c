

struct CwebHttpResponse * basic_calculate_route(struct CwebHttpRequest *request){
  
 
    char *num1 = request->get_param(request,"num1");
    char *num2 = request->get_param(request,"num2");
    char *operator = request->get_param(request,"operator");

    if(num1 == NULL || num2 == NULL || operator == NULL){
        struct CTextStack *stack = render_basic_calculator(NULL);
        return cweb_send_rendered_CTextStack_cleaning_memory(
                stack,
                200
        );
    }

    //transform num1 to int
    float num1_float=atof(num1);
    //transform num2 to int;
    float num2_float=atof(num2);
    //transform result to int
    float result_float;

    if(strcmp(operator,"+")== 0){
        result_float = num1_float + num2_float;
    }
    if(strcmp(operator,"-")== 0){
        result_float = num1_float - num2_float;
    }
    if(strcmp(operator,"x")== 0){
        result_float = num1_float * num2_float;
    }
    if(strcmp(operator,"/")== 0){
        result_float = num1_float / num2_float;
    }
    char result[30];
    sprintf(result,"The Result is:<br>%f",result_float);
    struct CTextStack *stack = render_basic_calculator(result);
    return cweb_send_rendered_CTextStack_cleaning_memory(
            stack,
            200
    );
}

