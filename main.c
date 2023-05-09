
#include "dependencies/CWebStudio.h"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

   cweb_send_text("aaaa",200);
}

CWEB_START_MACRO(5000, main_sever)
