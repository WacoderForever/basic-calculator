
#include "dependencies/CWebStudio.h"
#include "interface/general.c"

#include "interface/render_basic_calculator.c"
#include "interface/render_trigonometric_calculator.c"
#include "interface/render_sq_calculator.c"
#include "routes/basic_route.c"
#include "routes/basic_calculate_route.c"
#include "routes/trigonometric_route.c"
#include "routes/trigonometric_calculate_route.c"
#include "routes/sq_route.c"
#include "routes/sq_calculate_route.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    request->read_content(request,2000);
    char *route = request->route;

    //means that the button were clicked

    if(strcmp(route,"/trigonometric") == 0){
        return trigonometric_route(request);
    }

    else if(strcmp(route,"/trigonometric_calculate") == 0){
        return trigonometric_calculate_route(request);
    }
    else if(strcmp(route,"/sq")){
        return sq_route(request);
    }
    else if(strcmp(route,"/sq_calculate")){
        return sq_calculate_route(request);
    }
    
    else if(strcmp(route,"/basic_calculate") == 0){
        return basic_calculate_route(request);
    }

    else{
        return basic_route(request);
    }

}
            
