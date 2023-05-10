
#include "dependencies/CWebStudio.h"
#include "render_interface.c"



struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *route = request->route;

    //means that the button were cliced
    if(strcmp(route,"/calculate") == 0){
            char *num1 = request->get_param(request,"num1");
            char *num2 = request->get_param(request,"num2");
            char *operator = request->get_param(request,"operator");

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
            struct CTextStack *stack = render_interface(result);
            return cweb_send_rendered_CTextStack_cleaning_memory(
                    stack,
                    200
            );
    }




    struct CTextStack *stack = render_interface(NULL);

        return cweb_send_rendered_CTextStack_cleaning_memory(
                stack,
                200
            );
}

CWEB_START_MACRO(5001, main_sever)
