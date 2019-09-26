/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file Stats.c 
 * @brief
 * This project is made to calculate some basic statistical data for a given
 * array with determined size. as an assignment for Embedded systems course.
 * Use: Enter the elements of the data array and its size, Complie and run the
 * 	program using GNU GCC.
 * Output: print out of the data array elements, and the basic statistical
 * 	data (Maximum, Minimum, Mean, Median).
 *
 * @author Yehia Khalaf
 * @date 25/9/2019
 *
 */



#include <stdio.h>
#include <math.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array(test,SIZE);
  print_statistics(test, SIZE);

  printf("\n The Array after sorting:\n -------------------------\n");
  print_array(test,SIZE);
}

Element find_maximum(unsigned char *A, unsigned int N) {
/*take 1st element as max
  increment pointer
  count from 2nd element to Nth element and search for the max.
  return max value*/
	Element max;
	max.value= *A;
	max.index= 0;
	A++;
	for (int i=2; i<=N; i++) {
		if ( *A >= max.value ) {
			max.value = *A;
			max.index = i-1;
		}
		A++;
	}
	return max;
}

unsigned char find_minimum(unsigned char *A, unsigned int N) {
/*take 1st element as min
  increment pointer
  count from 2nd element to Nth element and search for the min.
  return min value*/
	unsigned char min=*A;
	A++;
	for (int i=2; i<=N; i++) {
		if ( *A <= min )
			min = *A;
		A++;
	}
	return min;
}


unsigned char find_mean(unsigned char *A, unsigned int N) {
/*take 1st element as sum
  increment pointer
  count from 2nd element to Nth element and add each  element to sum.
  devide by N to get mean --> and round to neasrt integer.
  return mean*/

	unsigned long int sum = *A;
	A++;
	for (int i=2; i<=N; i++) {
		sum += *A;
		A++;
	}
	unsigned char mean = round(((float)sum)/N);
	return mean;
}

void swap ( unsigned char *A, unsigned char *B ) {
/*swap two elements in memory stack to be used in sort function
  take 1st element in a temporary location.
  copy 2nd element to 1st element
  copy the temporary location to 2nd element */
	unsigned char temp = *A;
	*A=*B;
	*B=temp;

}

void sort_array(unsigned char *A, unsigned int N) {
/*find the max element within search area M (initially M=N).
  swap max element with element pointed out by pointer (initially pointer --> 1st element)
  increment the pointer
  decrement array search area M
  repeat till Nth element */
	Element Max;
	unsigned char *B;
	B = A;
	unsigned int M = N;
	for (int i=1; i<N; i++) {
		Max= find_maximum( B, M ); 
		swap ( (B+Max.index), B);
		B++;
		M--;
	}
}


unsigned char find_median(unsigned char *A, unsigned int N) {
/*sort the array using sort_array().
  if N is odd --> take the middle element as the median
  if N is even --> take the average of the 2 middle elements as the median, rounded
  to nearst integer.
  return median.*/
	sort_array(A, N);
	unsigned char med;
	if ( (N%2)==0 ) {
		A += ((N/2)-1);
		med = round((*A + *(A+1))/((float)2));
	}
	else {
		A += ((N-1)/2);
		med = *A;
	}
	return med;
}


void print_array(unsigned char *A, unsigned int N) {
/*count from element index 0 till index N-1:
  print (Element [i] = value pointed out by pointer)
  increment pointer */
	printf ( "\n\nArray Data: \n------------\n");
	for ( int i=0; i<=N-1; i++) {
		printf ( " Element [%d] = %d \n", i, *A);
		A++;
	}
}


void print_statistics(unsigned char *A, unsigned int N) {
/* calculate statistics by using the defined functions above.
   print results.*/
	Element MAX = find_maximum(A, N);
	unsigned char MIN = find_minimum(A, N);
	unsigned char MEAN = find_mean(A, N);
	unsigned char MEDIAN = find_median(A, N);
	printf( "Maximum = %d \n", MAX.value);
	printf( "Minimum = %d \n", MIN);
	printf( "Mean    = %d \n", MEAN);
	printf( "Median  = %d \n\n", MEDIAN);
}
