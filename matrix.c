#include "matrix.h"

int main() {
    startAnalysis();
    return 0;
}

void startAnalysis(){
    void (*funcList[])() = {rowMajor_read, colMajor_read, rowMajor_write, colMajor_write};
    struct timespec timeBefore, timeAfter;
    double averageTimes[4] = {0};

    int i = 0, j;
    for(; i < 4; i++)
        for(j = 0; j < COUNT_AVG; j++) {
            clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &timeBefore);
            (*funcList[i])();
            clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &timeAfter);
            averageTimes[i] +=  (((double)(timeAfter.tv_sec - timeBefore.tv_sec)) +
                                ((double)(timeAfter.tv_nsec - timeBefore.tv_nsec))/BILLION)/COUNT_AVG;
        }
    printResults(averageTimes);
}


void printResults(double* timeArray);


void rowMajor_write(){
    register int row, col;
    for(row = 0; row < ROW_COUNT; row++)
        for(col = 0; col < COL_COUNT; col++)
            testArray[row][col] = WRITE_CHAR;
}


void rowMajor_read(){
    register int row, col;
    register volatile char temp __attribute__((unused));
    for(row = 0; row < ROW_COUNT; row++)
        for(col = 0; col < COL_COUNT; col++)
            temp = testArray[row][col];
}


void colMajor_write(){
    register int row, col;
    for(col = 0; col < COL_COUNT; col++)
        for(row = 0; row < ROW_COUNT; row++)
            testArray[row][col] = WRITE_CHAR;
}


void colMajor_read(){
    register int row, col;
    register volatile char temp __attribute__((unused));
    for(col = 0; col < COL_COUNT; col++)
        for(row = 0; row < ROW_COUNT; row++)
            temp = testArray[row][col];
}


void printResults(double* timeArray){
    printf("\n\nAnalysis type\t|\tTime Taken, S\n");
    printf("---------------------------------\n");
    printf("Row Major Read\t|\t%.4f\n", timeArray[RMR_INDEX]);
    printf("Col Major Read\t|\t%.4f\n", timeArray[CMR_INDEX]);
    printf("Row Major Write\t|\t%.4f\n", timeArray[RMW_INDEX]);
    printf("Col Major Write\t|\t%.4f\n", timeArray[CMW_INDEX]);
    puts("\n");
}



