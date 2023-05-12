

void create_button(struct CTextStack *s,const char *name){
    s->$open(s,BUTTON,R"(name="operator" value="%s")",name);
        s->segment_text(s,name);
    s->close(s,BUTTON);
}

struct CTextStack * render_interface(char *result){
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->$open(s,HTML,"lang=\"en\"");
        s->open(s,HEAD);
            s->auto$close(s,LINK,R"(rel="stylesheet" href="/static/style.css")");
            s->open(s,TITLE);
                s->segment_text(s,"My First Calculator");   
            s->close(s,TITLE);

        s->close(s,HEAD);
        s->open(s,BODY);

           s->$open(s,DIV,R"(class="center")");
                s->open(s,H3);
                    s->segment_text(s,"My First Calculator");
                s->close(s,H3);
                s->$open(s,FORM,R"(action="/calculate" method="POST" )");
                    s->auto$close(s,INPUT,R"( name="num1" placeholder='num1' )");
                    s->auto$close(s,BR,"");
                        s->auto$close(s,INPUT,R"( name="num2" placeholder='num2' )");
                    s->auto$close(s,BR,"");
                    create_button(s,"+");
                    create_button(s,"-");
                    create_button(s,"x");
                    create_button(s,"/");

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