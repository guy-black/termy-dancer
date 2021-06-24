#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ANSI-color-codes.h"


int main () {
    printf("wait for it\n");
    sleep(3);
    system ("clear");
    printf("tada\n");
    return 0;
}
