#include "matrix.h"

int main() {
    startAnalysis();
    return 0;
}

void startAnalysis(){
    //void (*funcList[])() = {rowMajor_write, colMajor_write, rowMajor_read, colMajor_read };
    struct timespec timeBefore, timeAfter;
    double averageTimes[4] = {0};

    int i = 0, j;




    //ROW READ

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &timeBefore);

    register int row, col;
    register volatile char temp __attribute__((unused));
    for(row = 0; row < ROW_COUNT; row++)
        for(col = 0; col < COL_COUNT; col++)
            temp = testArray[row][col];




    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &timeAfter);
    averageTimes[0] +=  (((double)(timeAfter.tv_sec - timeBefore.tv_sec)) +
    ((double)(timeAfter.tv_nsec - timeBefore.tv_nsec))/BILLION)/COUNT_AVG;



    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &timeBefore);

    //END ROW READ



    //COL READ
    //register int row, col;
    //register volatile char temp __attribute__((unused));
    for(col = 0; col < COL_COUNT; col++)
        for(row = 0; row < ROW_COUNT; row++)
            temp = testArray[row][col];




    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &timeAfter);
    averageTimes[1] +=  (((double)(timeAfter.tv_sec - timeBefore.tv_sec)) +
            ((double)(timeAfter.tv_nsec - timeBefore.tv_nsec))/BILLION)/COUNT_AVG;

    //END COL READ


    //ROW WRITE
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &timeBefore);


    //register int row, col;
    for(row = 0; row < ROW_COUNT; row++)
        for(col = 0; col < COL_COUNT; col++)
            testArray[row][col] = WRITE_CHAR;





    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &timeAfter);
    averageTimes[2] +=  (((double)(timeAfter.tv_sec - timeBefore.tv_sec)) +
            ((double)(timeAfter.tv_nsec - timeBefore.tv_nsec))/BILLION)/COUNT_AVG;

    //END ROW WRITE



    //COL WRITE
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &timeBefore);


    //register int row, col;
    for(col = 0; col < COL_COUNT; col++)
        for(row = 0; row < ROW_COUNT; row++)
            testArray[row][col] = WRITE_CHAR;



    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &timeAfter);
    averageTimes[3] +=  (((double)(timeAfter.tv_sec - timeBefore.tv_sec)) +
            ((double)(timeAfter.tv_nsec - timeBefore.tv_nsec))/BILLION)/COUNT_AVG;


    //END COL WRITE






    printResults(averageTimes);
}


void printResults(double* timeArray);


void rowMajor_write(){

}


void rowMajor_read(){

}


void colMajor_write(){

}


void colMajor_read(){

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

