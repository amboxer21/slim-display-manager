#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 1024

int main(int argc, char *argv) {

    int retval; 
    fd_set rfds;
    struct timeval tv;
    char buf[BUFFSIZE];

    while(1) {

        tv.tv_sec = 5;
        tv.tv_usec = 0;
        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);

        retval = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);
        if(FD_ISSET(STDIN_FILENO, &rfds)) {
            if(fgets(buf,BUFFSIZE, stdin)) {
                printf("%s\n",buf);
                if(strncmp(buf, "showme", 6) == 0) {
                    //Unhide login UI logic goes here
                    printf("Unhiding login UI.\n");
                    //exit(0);
                }
                else if(strncmp(buf, "hideme", 6) == 0) {
                    //Hide login UI logic goes here
                    printf("Hiding login UI.\n");
                    //exit(0);
                }
            }
        }
    }

    return 0;
}
