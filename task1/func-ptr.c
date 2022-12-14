#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

#include "process.h"
#include "util.h"

#define DEBUG 0			//change this to 1 to enable verbose output

/**
 * Signature for an function pointer that can compare
 * You need to cast the input into its actual 
 * type and then compare them according to your
 * custom logic
 */
typedef int (*Comparer) (const void *a, const void *b);

/**
 * compares 2 processes
 * You can assume: 
 * - Process ids will be unique
 * - No 2 processes will have same arrival time
 */
int my_comparerforPriority(const void *this, const void *that)
{
	//TODO: IMPLEMENT ME!
  int compare(const void *this, const void *that) {
  // Compare the priorities of the two processes.
  if ((*(Process *)this).priority <(*(Process *)that).priority){
    return 1; // Return 1 if the first process has a higher priority.
  }
  if ((*(Process *)this).priority > (*(Process *)that).priority){
    return -1; // Return -1 if the second process has a higher priority.
  }
  // If the priorities are the same, compare the arrival times of the processes.
  if ((*(Process *)this).arrival_time < (*(Process *)that).arrival_time){
    return -1; // Return -1 if the first process arrived earlier.
  }
  else {
    return 1; // Return 1 if the second process arrived earlier or at the same time.
  }
  return 0; // If none of the previous conditions are met, return 0.
}


int my_comparerforArrivalTime(const void *this, const void *that) {
  // Compare the arrival times of the two processes.
  if ((*(Process *)this).arrival_time <(*(Process *)that).arrival_time){
    return -1; // Return -1 if the first process arrived earlier.
  }
  if ((*(Process *)this).arrival_time >(*(Process *)that).arrival_time){
    return 1; // Return 1 if the second process arrived earlier.
  }
  return 0; // If the arrival times are the same, return 0.
}

int main(int argc, char *argv[]) {
  // Check if the input file path was provided as a command line argument.
  if (argc < 2) {
    fprintf(stderr, "Usage: ./func-ptr <input-file-path>\n");
    fflush(stdout);
    return 1;
  }
}


	/*******************/
/* Parse the input */
/*******************/
FILE *input_file = fopen(argv[1], "r");
if (!input_file) {
  // Check if the input file was successfully opened.
  fprintf(stderr, "Error: Invalid filepath\n");
  fflush(stdout);
  return 1;
}

// Parse the input file and store the process information in an array of Process structs.
Process *processes = parse_file(input_file);

/*******************/
/* sort the input  */
/*******************/
// Define function pointers for comparing processes by priority and arrival time.
Comparer process_comparerforPriority = &my_comparerforPriority;
Comparer process_comparerforArrivalTime = &my_comparerforArrivalTime;

#if DEBUG
  // Print the processes in the array, if debugging is enabled.
  for (int i = 0; i < P_SIZE; i++) {
    printf("%d (%d, %d) ",
      processes[i].pid,
      processes[i].priority, processes[i].arrival_time);
  }
  printf("\n");
#endif

	// Sort the processes in the array using the my_comparerforPriority function.
qsort(processes, P_SIZE, sizeof(Process), process_comparerforPriority);

/**************************/
/* print the sorted data  */
/**************************/
// Print the sorted processes based on their priorities.
printf("sorted based on priority\n");
for (int i = 0; i < P_SIZE; i++) {
  printf("%d (%d, %d)\n",
    processes[i].pid,
    processes[i].priority, processes[i].arrival_time);
}

// Sort the processes in the array using the my_comparerforArrivalTime function.
qsort(processes, P_SIZE, sizeof(Process), process_comparerforArrivalTime);

// Print the sorted processes based on their arrival times.
printf("sorted based on arrival times\n");
for (int i = 0; i < P_SIZE; i++) {
  printf("%d (%d, %d)\n",
    processes[i].pid,
    processes[i].priority, processes[i].arrival_time);
}

// Flush the standard output and error streams.
fflush(stdout);
fflush(stderr);

/************/
/* clean up */
/************/

	return 0;
}
