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
 * @file Stats.h
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

#ifndef __STATS_H__
#define __STATS_H__

/*************************************************************************
 * print_array(): Given an array of data and its length length, it prints*
 * the array to the screen.						 *
 * parameters: *A Pointer to Array of chars				 *
 * 		N Number of elements in the Array			 *
 *************************************************************************/

void print_array(unsigned char *A, unsigned int N);

/*************************************************************************
 * sort_array(): Given an array of data and its length length, it sorts  *
 * the array elements in a descending order  				 *
 * parameters: *A Pointer to Array of chars				 *
 * 		N Number of elements in the Array			 *
 *************************************************************************/

void sort_array(unsigned char *A, unsigned int N);

/*************************************************************************
 * find_maximum(): Given an array of data and its length length, it finds*
 * the maximum value among its elements.				 *
 * parameters: *A Pointer to Array of chars				 *
 * 		N Number of elements in the Array			 *
 * Return    : 	the maximum value.					 *
 *************************************************************************/

unsigned char find_maximum(unsigned char *A, unsigned int N);

/*************************************************************************
 * find_minimum(): Given an array of data and its length length, it finds*
 * the minimum value among its elements.				 *
 * parameters: *A Pointer to Array of chars				 *
 * 		N Number of elements in the Array			 *
 * Return    : 	the minimum value.					 *
 *************************************************************************/

unsigned char find_minimum(unsigned char *A, unsigned int N);

/***************************************************************************
 * find_mean(): Given an array of data and its length length, it calculates*
 * the mean value of all its elements.					   *
 * parameters: *A Pointer to Array of chars				   *
 * 		N Number of elements in the Array			   *
 * Return    : 	the mean value, rounded to the nearst integer.		   *
 ***************************************************************************/

unsigned char find_mean(unsigned char *A, unsigned int N);

/*************************************************************************
 * find_median(): Given an array of data and its length length, it finds *
 * the median value of all its elements.				 *
 * parameters: *A Pointer to Array of chars				 *
 * 		N Number of elements in the Array			 *
 * Return    : 	the median value, rounded to the nearst integer.	 *
 *************************************************************************/

unsigned char find_median(unsigned char *A, unsigned int N);

/*************************************************************************
 * print_statistics(): Given an array of data and its length length, it  *
 * prints out the results (Max, Min, Mean, Median) to the screen.	 *
 * parameters: *A Pointer to Array of chars				 *
 * 		N Number of elements in the Array			 *
 *************************************************************************/

void print_statistics(unsigned char *A, unsigned int N);

/*************************************************************************
 * swap(): Given pointers for two elements in the memory stack, it swaps *
 *	   swaps them.							 *
 * parameters: *A, *B Pointers to memory stack locations		 *			 *
 *************************************************************************/

void swap ( unsigned char *A, unsigned char *B );

/*************************************************************************
 * max_addr(): Given an array of data and its length length, it finds    *
 * the address pointer for maximum value among its elements.		 *
 * parameters: *A Pointer to Array of chars				 *
 * 		N Number of elements in the Array			 *
 * Return    : 	the address pointer to maximum value.			 *
 *************************************************************************/

unsigned char * max_addr(unsigned char *A, unsigned int N);

#endif /* __STATS_H__ */
