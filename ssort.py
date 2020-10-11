import random
import sys

RANGE_MAX = 1000

def print_list(array, n):
   for i in range(n):
      print(str(array[i]) + '\t', end='')
   print()


def random_elements(array, n):
   for i in range(n):
      array[i] = random.randrange(RANGE_MAX)


def selection_sort(array, n):
   # finding minimum element (n-1) times
   for i in range(n - 1):
      min_pos = i
      for j in range(i + 1, n):
         if array[min_pos] > array[j]:
            min_pos = j
      if min_pos != i:
         tmp = array[i]
         array[i] = array[min_pos]
         array[min_pos] = tmp


if __name__ == "__main__":
   n = 10
   if len(sys.argv) == 2:
      n = int(sys.argv[1])
   #print("n = " + str(n))
   array = [0] * n
   
   random_elements(array, n)

   print("List before sorting:")
   print_list(array, n)

   selection_sort(array, n)

   print("Sorted list in ascending order:")
   print_list(array, n)

