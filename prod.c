#include "main_sever.c"

int main(){

 
    cweb_run_server(80,main_sever,CWEB_DEFAULT_TIMEOUT,CWEB_SAFTY_MODE);
 
    return 0;
}