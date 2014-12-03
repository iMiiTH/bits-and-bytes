#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

int* merge_sort(int* given_array, int array_size);
int* first_half(int* given_array, int array_size);
int* second_half(int* given_array, int array_size);
int* combine_arrays(int* array1, int array1_length, int* array2, int array2_length);
void print_array(int* output_array, int array_size);

#define ARRAY_SIZE 100000000

int main() 
{
   time_t start_time = time(NULL);
   printf("Creating array of %d items... ", ARRAY_SIZE); fflush(stdout);
   int *arr;
   int i;

   arr = malloc(sizeof(int) * ARRAY_SIZE);
   printf("done! \n");
   putchar('\n');

   printf("Populating array with %d elements...", ARRAY_SIZE); fflush(stdout);
   for(i = 0; i<ARRAY_SIZE; i++) {
      arr[i] = rand() % ARRAY_SIZE;
   } 
   printf("done! \n");
   putchar('\n');

   time_t start_sort_time = time(NULL);

   printf("Starting sorting %d elements...", ARRAY_SIZE); fflush(stdout);
   //print_array(arr, ARRAY_SIZE);

   int *sorted_array = merge_sort(arr, ARRAY_SIZE);

   printf("done!\n");
   putchar('\n');
   printf("Sorted %d elements in %ld seconds.\n", ARRAY_SIZE, time(NULL)-start_time);
   printf("Total time: %ld\n", time(NULL)-start_time);

      return 0; 
   //print_array(sorted_array, ARRAY_SIZE);
}

int* merge_sort(int* given_array, int array_size)
{
   int *combined_array;
   //base cases
   if(array_size <= 1) {
      return given_array;
   } else if(given_array[0] > given_array[1]) {
         int temp = given_array[0];
         given_array[0] = given_array[1];
         given_array[1] = temp;
   }
   //divide the array into two halves
   int *first_half_array = first_half(given_array, array_size);
   int *second_half_array = second_half(given_array, array_size);

   //merge sort the two halves
   first_half_array = merge_sort(first_half_array, array_size/2); 
   if(array_size % 2 != 0 ) 
      second_half_array = merge_sort(second_half_array, (array_size / 2 ) + 1 );
   else 
      second_half_array = merge_sort(second_half_array, array_size/2);

   //combine the two halves by selecting the lowest element of the two arrays
   if(array_size % 2 != 0 ) { 
      combined_array = combine_arrays(first_half_array, array_size / 2, second_half_array , array_size / 2 + 1);
      //print_array(second_half_array, array_size / 2 + 1 );
   } else {
      //print_array(second_half_array, array_size / 2);
      combined_array = combine_arrays(first_half_array, array_size / 2, second_half_array, array_size / 2);
   }

   free(first_half_array);
   free(second_half_array);
   free(given_array);

   //return the array
   return combined_array;
}

int* first_half(int* given_array, int array_size)
{
   int *return_array = malloc(sizeof(int) * array_size/2 );
   memcpy(return_array, given_array, sizeof(int) * (array_size / 2));

   return return_array;
}
int* second_half(int* given_array, int array_size)
{
   int *return_array;

   if(array_size%2 != 0) {
      return_array = malloc(sizeof(int) * (array_size / 2 + 1));
      memcpy(return_array, given_array+array_size/2, sizeof(int) * (array_size/2+1) );
   } else {
      return_array = malloc(sizeof(int) * (array_size / 2));
      memcpy(return_array, given_array+array_size/2, sizeof(int) * (array_size/2));
   }

   return return_array;
}

int* combine_arrays(int* array1, int array1_length, int* array2, int array2_length)
{
   int i;
   int a, b;
   int *combined_array = calloc((array1_length+array2_length), sizeof(int));
   int arr1Counter = 0;
   int arr2Counter = 0;

   for(i = 0; i < (array1_length+array2_length); i++) {
      if(arr1Counter < array1_length) {
         a = *array1;
      } else { 
         a = INT_MAX;
      }
      if(arr2Counter < array2_length) {
         b = *array2;
      } else  {
         b = INT_MAX;
      }

      if(a < b) {
         combined_array[i] = a;
         array1++; arr1Counter++;
      } else {
         combined_array[i] = b;
         array2++; arr2Counter++;
      }
   }
   return combined_array;
}

void print_array(int* output_array, int array_size)
{
   int i;
   putchar('[');
   for(i = 0; i < array_size; i++) {
      printf("%2d, ", output_array[i]);
   } printf("\b\b] \n");
}
