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
  if ((*(Process *)this).priority <(*(Process *)that).priority){
    return 1;
  }
  if ((*(Process *)this).priority > (*(Process *)that).priority){
    return -1;
  }
  if ((*(Process *)this).arrival_time < (*(Process *)that).arrival_time){
    return -1;
  }
	else {
    return 1;
  }
  return 0;
}

int my_comparerforArrivalTime(const void *this, const void *that)
{
	 if ((*(Process *)this).arrival_time <(*(Process *)that).arrival_time){
    return -1;
  }
  if ((*(Process *)this).arrival_time >(*(Process *)that).arrival_time){
    return 1;
  }
	return 0;
  
}


int main(int argc, char *argv[])
{

	if (argc < 2) {
		   fprintf(stderr, "Usage: ./func-ptr <input-file-path>\n");
		   fflush(stdout);
		   return 1;
	}

	/*******************/
	/* Parse the input */
	/*******************/
	FILE *input_file = fopen(argv[1], "r");
	if (!input_file) {
		   fprintf(stderr, "Error: Invalid filepath\n");
		   fflush(stdout);
		   return 1;
	}

	Process *processes = parse_file(input_file);

	/*******************/
	/* sort the input  */
	/*******************/
	Comparer process_comparerforPriority = &my_comparerforPriority;
  Comparer process_comparerforArrivalTime = &my_comparerforArrivalTime;


#if DEBUG
	for (int i = 0; i < P_SIZE; i++) {
		    printf("%d (%d, %d) ",
				processes[i].pid,
				processes[i].priority, processes[i].arrival_time);
	}
	printf("\n");
#endif

	qsort(processes, P_SIZE, sizeof(Process), process_comparerforPriority);

	/**************************/
	/* print the sorted data  */
	/**************************/
  printf("sorted based on priority\n");
	for (int i = 0; i < P_SIZE; i++) {
		    printf("%d (%d, %d)\n",
				processes[i].pid,
				processes[i].priority, processes[i].arrival_time);
	}
  
  qsort(processes, P_SIZE, sizeof(Process), process_comparerforArrivalTime);
  printf("sorted based on arrival times\n");
  for (int i = 0; i < P_SIZE; i++) {
		    printf("%d (%d, %d)\n",
				processes[i].pid,
				processes[i].priority, processes[i].arrival_time);
	}
	fflush(stdout);
	fflush(stderr);

	/************/
	/* clean up */
	/************/
	free(processes);
	fclose(input_file);
	return 0;
}