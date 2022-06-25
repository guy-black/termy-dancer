#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "ANSI-color-codes.h"


int main () {
//  main variables
    //number of frames in animation
    int numFrames = 31;
    //lines per frame (including the frame delimiter line)
    //actual frame is only lines-1 lines long
    int linespf = 16;
    //total number of lines
    int totalLines = linespf * numFrames;
    //list of all lines in the animation
    char lines [totalLines] [75];
    //current frame
    int currFrame = 1;

// fpointer to connect to file
    FILE * fpointer = fopen("animation", "r");

// loading animation file into the program
    int i;
    for (i=0; i<totalLines; i++){
        fgets (lines[i], 75, fpointer);
        lines[i] [strcspn(lines[i], "\n")] = 0;
    }

// close connection to file since we're done with it now
    fclose(fpointer);

// given a frame and line number, print that line to stdout
    void printLine (int framnum, int linenum) {
        if (framnum > numFrames){
            printLine ((framnum - numFrames), linenum);
        } else {
        printf ("%s", lines [(framnum-1)*(linespf)+linenum-1]);
        }
    }

// given a frame number render a whole full colored frame
    void renderFrame (int framnum) {
        system("clear");
        int j;
        for (j=1; j<linespf; j++){
            printf (RED);
            printLine (framnum, j);
            printf (GRN);
            printLine ((framnum + 5), j);
            printf (YEL);
            printLine ((framnum + 10), j);
            printf (BLU);
            printLine ((framnum + 15), j);
            printf (MAG);
            printLine ((framnum + 20), j);
            printf (CYN);
            printLine ((framnum + 25), j);
            //if (j==(linespf-1)){
            //    printf ("%s", reset);
            //}else{
            printf ("%s\n", reset);
            //}
            //idk how to make the new line not there on the last line
        }
        struct timespec ts = {0, 100000000L };

        nanosleep (&ts, NULL);
    }

    while (1) {
        renderFrame (currFrame);
        if (currFrame == numFrames){
            currFrame = 1;
        } else {
            currFrame++;
        }
    }



    return 0;
}
