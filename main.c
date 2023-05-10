
#include "dependencies/CWebStudio.h"
#include "render_interface.c"



struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *route = request->route;

    //means that the button were cliced
    if(strcmp(route,"/calculate") == 0){
            char *num1 = request->get_param(request,"num1");
            char *num2 = request->get_param(request,"num2");
            char *operator = request->get_param(request,"operator");
            char *result;
            //transform num1 to int
            int num1_int=atoi(num1);
            //transform num2 to int;
            int num2_int=atoi(num2);
            //transform result to int
            int result_int=atoi(result);
            if(operator=='+'){
               result_int=num1_int+num2_int;
               char text[30];
               sprintf(text,"The result is %d",result_int); 
               struct CTextStack *stack = render_interface(text);
            }
            if(operator=='-'){
               result_int=num1_int-num2_int; 
               char text[30];
               sprintf(text,"The result is %d",result_int); 
               struct CTextStack *stack = render_interface(text);
            }
            if(operator=='x'){
               result_int=num1_int*num2_int; 
               char text[30];
               sprintf(text,"The result is %d",result_int); 
               struct CTextStack *stack = render_interface(text);
            }
            if(operator=='/'){
               result_int=num1_int/num2_int; 
               char text[30];
               sprintf(text,"The result is %d",result_int); 
               struct CTextStack *stack = render_interface(text);
            }
            

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

CWEB_START_MACRO(5008, main_sever)
