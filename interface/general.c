//
// Created by jurandi on 12-05-2023.
//



void create_button(struct CTextStack *s,const char *name){
    s->$open(s,BUTTON,R"(name="operator" value="%s")",name);
    s->segment_text(s,name);
    s->close(s,BUTTON);
}
void create_link(struct CTextStack *s,const char *name, const char *link){
    s->$open(s,A,R"(href="%s")",link);
        s->$open(s,BUTTON,R"(class="link_button")");
            s->segment_text(s,name);
        s->close(s,BUTTON);
    s->close(s,A);
}