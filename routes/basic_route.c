//
// Created by jurandi on 12-05-2023.
//

struct CwebHttpResponse *basic_route(struct CwebHttpRequest *request ){

    struct CTextStack *stack = render_basic_calculator(NULL);

    return cweb_send_rendered_CTextStack_cleaning_memory(
            stack,
            200
    );
}