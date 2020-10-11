#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define RANGE_MAX 1000

void print_list(int* array, int n)
{
   for (int i = 0; i < n; i++)
      printf("%d\t", array[i]);
   printf("\n");
}

void random_elements(int* array, int n) 
{
   /* Intializes random number generator */
   srand(time(0));

   for (int i = 0; i < n; i++)
      array[i] = rand() % RANGE_MAX;
}

void selection_sort(int* array, int n)
{
   int i, j, min_pos, tmp;

   // finding minimum element (n-1) times
   for (i = 0; i < (n - 1); i++) {
      min_pos = i;
      for (j = i + 1; j < n; j++) {
         if (array[min_pos] > array[j])
            min_pos = j;
      }
      if (min_pos != i) {
         tmp = array[i];
         array[i] = array[min_pos];
         array[min_pos] = tmp;
      }
   }
}

int main(int argc, char *argv[])
{
   int n = 10;
   if (argc == 2)
      n = atoi(argv[1]);

   //printf("Enter number of elements: ");
   //scanf("%d", &n);
   
   int* array = (int *) malloc(n * sizeof(int));
   
   random_elements(array, n);

   printf("List before sorting:\n");
   print_list(array, n);

   selection_sort(array, n);

   printf("Sorted list in ascending order:\n");
   print_list(array, n);

   return 0;
}