
#include "dependencies/CWebStudio.h"
#include "render_interface.c"



struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    char *route = request->route;

    //means that the button were cliced
    if(strcmp(route,"/calculate") == 0){
            char *num1 = request->get_param(request,"num1");
            char *num2 = request->get_param(request,"num2");
            char *operator = request->get_param(request,"operator");
            char *result="THG";
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

CWEB_START_MACRO(5006, main_sever)
