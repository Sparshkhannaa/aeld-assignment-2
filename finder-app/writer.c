#include <syslog.h>
#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc,char **argv){

    char *filepath = NULL;
    char *writestr = NULL;

    if (argc >= 3){
        filepath = argv[1];
        writestr = argv[2]; 
    }
    openlog("a2", LOG_PID | LOG_CONS, LOG_USER);
    syslog(LOG_INFO,  "a2 utility created");
    if(filepath == NULL || writestr == NULL){
        syslog(LOG_ERR, "arguments not provided correctly!");
        return 1;
    }
    FILE* f = fopen(filepath, "w");
    if (f == NULL){
        syslog(LOG_ERR, "unable to find the file!");
        return 1;
    }
    fprintf(f, "%s" ,writestr);
    syslog(LOG_INFO, "String %s written to file %s",writestr,filepath);
    fclose(f);
    return 0;

}
    