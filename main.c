
#include "dependencies/CWebStudio.h"
#include "render_interface.c"



struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){


    struct CTextStack *stack = render_interface();
    cweb_send_rendered_CTextStack_cleaning_memory(
                stack,
                200
            );
}

CWEB_START_MACRO(5003, main_sever)
