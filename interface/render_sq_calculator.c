

struct CTextStack * render_sq_calculator(char *result){
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->$open(s,HTML,"lang=\"en\"");
        s->open(s,HEAD);
            s->auto$close(s,LINK,R"(rel="stylesheet" href="/static/style2.css")");
            s->open(s,TITLE);
                s->segment_text(s,"Square/Square root");
            s->close(s,TITLE);

        s->close(s,HEAD);
        s->open(s,BODY);
        create_link(s,"Trigonometric","/trigonometric");
        s->auto$close(s,BR,"");
        create_link(s,"Basic Calculator","/basic");
           s->$open(s,DIV,R"(class="center")");
                s->open(s,H3);
                    s->segment_text(s,"Square/Square root");
                s->close(s,H3);
                s->$open(s,FORM,R"(action="/sq_calculate" method="POST" )");
                    s->auto$close(s,BR,"");
                        s->auto$close(s,INPUT,R"( name="number" placeholder='number' )");
                    s->auto$close(s,BR,"");

                        create_button(s,"Square");
                        s->auto$close(s,BR,"");
                        create_button(s,"Square root");
                s->close(s,FORM);

        if(result!=NULL){
            s->open(s,H3);
                s->segment_text(s,result);
            s->close(s,H3);
        }
        s->close(s,DIV);
        s->close(s,BODY);
    s->close(s,HTML);
    return s;
}