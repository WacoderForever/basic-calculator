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

void create_basic_enntrys(struct CTextStack *s){
            char *fav_icon_link = smart_static_ref("favicon.png");
                s->auto$close(s,LINK,"rel=\"shortcut icon\" href=\"%s\"",fav_icon_link);
            free(fav_icon_link);

            char *style_link = smart_static_ref("style.css");
                s->auto$close(s,LINK,"rel=\"stylesheet\" href=\"%s\"",style_link);
            free(style_link);

};

