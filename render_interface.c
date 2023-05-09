

struct CTextStack * render_interface(){
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);


    s->$open(s,HTML,"lang=\"en\"");
        s->open(s,HEAD);
        s->close(s,HEAD);
        s->open(s,BODY);

                s->auto$close(s,INPUT,R"( name="num1" )");
                s->auto$close(s,BR,"");
                    s->auto$close(s,INPUT,R"( name="num2" )");
                s->auto$close(s,BR,"");
                s->open(s,BUTTON);
                    s->segment_text(s,"Click Here");
                s->close(s,BUTTON);
        s->close(s,BODY);
    s->close(s,HTML);
    return s;
}