


struct CTextStack * render_trigonometric_calculator(char *result){
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->$open(s,HTML,"lang=\"en\"");
        s->open(s,HEAD);
                       create_basic_enntrys(s);

                       
        s->close(s,HEAD);
        s->open(s,BODY);
            create_link(s,"Basic Calculator","/basic");
            s->auto$close(s,BR,"");
            create_link(s,"Square/Square root","/sq");
           s->$open(s,DIV,R"(class="center")");
                s->open(s,H3);
                    s->segment_text(s,"Trigonometric");
                s->close(s,H3);
                s->$open(s,FORM,R"(action="/trigonometric_calculate" method="POST" )");

                    s->auto$close(s,INPUT,R"( name="angle" placeholder='angle' )");
                    s->auto$close(s,BR,"");

                    create_button(s,"SIN");
                    create_button(s,"COS");
                    create_button(s,"TAN");

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