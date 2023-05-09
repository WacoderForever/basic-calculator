
#include "dependencies/CWebStudio.h"
#include "render_interface.c"



struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *route = request->route;

    //means that the button were cliced
    if(strcmp(route,"/calculate") == 0){
            char *num1 = request->get_param(request,"num1");
            char *num2 = request->get_param(request,"num2");
            printf("-----------------------------\n");
            printf("num1 : %s\n",num1);
            printf("num2 : %s\n",num2);
    }


    struct CTextStack *stack = render_interface();

    cweb_send_rendered_CTextStack_cleaning_memory(
                stack,
                200
            );
}

CWEB_START_MACRO(5003, main_sever)
