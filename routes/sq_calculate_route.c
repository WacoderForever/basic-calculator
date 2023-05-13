struct CwebHttpResponse *sq_calculate_route(struct CwebHttpRequest *request){
    char *number= request -> get_param(request,"number");
    char *operator= request -> get_param(request,"operator");
    if((number==NULL)||(operator== NULL)){
        return NULL;
    }
    
    //transform number to float
    float number_float=atof(number);
    float result;
    if(strcmp(operator,"Square")==0){
        result=number_float*number_float;
    }
    if(strcmp(operator,"Square root")==0){
        result=number_float;
    }
    char result1[30];
    sprintf(result1,"The result is <br>%f",result);
    struct CTextStack *stack = render_sq_calculator(result1);
    return cweb_send_rendered_CTextStack_cleaning_memory(
            stack,
            200
    );

}