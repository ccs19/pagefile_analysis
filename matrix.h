#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdio.h>
#include <time.h>

#define COL_COUNT   4096    //page size
#define ROW_COUNT   20480   // Total size ~ 80MB
#define WRITE_CHAR  '&'
#define COUNT_AVG   10
#define BILLION     1000000000

#define RMR_INDEX   0
#define CMR_INDEX   1
#define RMW_INDEX   2
#define CMW_INDEX   3

static volatile char testArray[ROW_COUNT][COL_COUNT] = { {0} };

/** FUNCTION: startAnalysis
*
*   Entry point for analysis. This function calls the various matrix
*   access functions and takes time measurements.
*
*/
void startAnalysis();



/** FUNCTION: printResults
*
*   Prints a formatted table with the run-time analysis results
*
*   @param  timeArray   The array of time results from run-time analysis
*/
void printResults(double* timeArray);



/** FUNCTION: rowMajor_write
*
*   Writes to the global test array using row-major access
*
*/
void rowMajor_write();


/** FUNCTION: rowMajor_read
*
*  Reads from the global test array data using row-major access
*
*/
void rowMajor_read();



/** FUNCTION: colMajor_write
*
*  Writes to the global test array data using column-major access
*
*/
void colMajor_write();


/** FUNCTION: colMajor_read
*
*  Reads the global test array data using column-major access
*
*/
void colMajor_read();



#endif //_MATRIX_H