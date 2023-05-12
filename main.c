
#include "main_sever.c"

int main(){

    

        for(int i=3000;i< 4000;i++){
            cweb_run_server(i,main_sever,CWEB_DEFAULT_TIMEOUT,CWEB_SAFTY_MODE);
    }
 
 
    return 0;
}