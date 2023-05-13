struct CwebHttpResponse *sq_route(struct CwebHttpRequest *request ){

    struct CTextStack *stack = render_sq_calculator(NULL);

    return cweb_send_rendered_CTextStack_cleaning_memory(
            stack,
            200
    );
}