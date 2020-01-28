//
//  SortingComparison.cpp
//  SortTest
//
//  Created by Tiziana Ligorio on 10/4/19.
//  Course project, Hunter Collegge, CSci 235 - Software Design and Analysis II
//  Sorting functions implementation adapted from Big C++, Late Objects, Wiley
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.
//
// ********** ADD YOUR CONTRIBUTION INFORMATION HERE!!! ******************


#include "SortingComparison.hpp"


//parameterized constructor allocate values_ with array_size
SortingComparison::SortingComparison(size_t array_size): SIZE(array_size), values_(new int[SIZE]){}



/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/



/*************** SELECTION SORT + HELPER **************************/

/**
 @post Gets the position of the smallest element in an array range.
 @param a the array
 @param from the beginning of the range
 @param to the end of the range
 @return the position of the smallest element in
 the range a[from]...a[to]
 */
int SortingComparison::minPosition(int a[], int from, int to, int& comparisoncount)
{
    //comparisoncount = 0;
    int min_pos = from;
    for (int i = from + 1; i <= to; i++){
        comparisoncount++;
        if (a[i] < a[min_pos]){
          min_pos = i;
        }
    }
    return min_pos;
}


/**
 @post Sorts an array in ascending order using the selection sort algorithm.
 @return the number of comparisons made by the algorithm
 */
int SortingComparison::selectionSort(int a[], size_t size)
{
    int comparisoncount = 0;
    for (int i = 0; i < size; i++)
    {
        // Find the position of the minimum
        int min_pos = minPosition(a, i, static_cast<int>(size - 1), comparisoncount);
        // Swap the next element and the minimum
        std::swap(a[i], a[min_pos]);
    }


    //return -1;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
    return comparisoncount;
}




/*************** INSERTION SORT **************************/


/**
 @post Sorts an array in ascending order using insertion sort.
 @param a the array to sort
 @param size of the array
 @return the number of comparisons of two  array elements made by the algorithm
 */
int SortingComparison::insertionSort(int a[], size_t size)
{
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        int next = a[i];
        // Move all larger elements up
        int j = i;
        if(a[j - 1] <= next){
          count++;
        }
        while (j > 0 && a[j - 1] > next)
        {
            a[j] = a[j - 1];
            j--;
            count++;
        }
        // Insert the element
        a[j] = next;
        //count++;
    }


    //return -1;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
    return count;
}


/************************* MERGE SORT + HELPER **************************/

/**
 @post Merges two adjacent subarrays.
 @param a the array with the elements to merge
 @param from the start of the first subarray
 @param mid the end of the first subarray
 @param to the end of the second subarray
 */
void SortingComparison::merge(int a[], int from, int mid, int to, int& comparisoncount1)
{
    int n = to - from + 1; // Size of the range to be merged
    // Merge both halves into a temporary array temp_array
    int* temp_array = new int[n];

    int i1 = from;
    // Next element to consider in the first half
    int i2 = mid + 1;
    // Next element to consider in the second half
    int j = 0; // Next open position in temp_array

    // Compare elements in subarrays for merging
    // As long as neither i1 nor i2 is past the end,
    // move the smaller element into temp_array

    while (i1 <= mid && i2 <= to)
    {
        if (a[i1] < a[i2])
        {
            comparisoncount1++;
            temp_array[j] = a[i1];
            i1++;
        }
        else
        {
           temp_array[j] = a[i2];
            i2++;
            comparisoncount1++;
        }
        j++;
    }


    // Note that only one of the two while loops below is executed

    // Copy any remaining entries of the first half
    while (i1 <= mid)
    {
        temp_array[j] = a[i1];
        comparisoncount1++;
        i1++;
        j++;

    }
    // Copy any remaining entries of the second half
    while (i2 <= to)
    {
        temp_array[j] = a[i2];
        i2++;
        j++;
        comparisoncount1++;
    }

    // Copy back from the temporary array
    for (j = 0; j < n; j++)
    {
        a[from + j] = temp_array[j];
    }

    delete[] temp_array;
}

/**
 @post Sorts the elements in a range of a array.
 @param a the array with the elements to sort
 @param from the first position in the range to sort
 @param to the last position in the range to sort (included)
 @return the number of comparisons made by the algorithm
 */
int SortingComparison::mergeSort(int a[], int from, int to)
{
    int comparisoncount1 = 0;
    if (from == to) {
      return 0;
    }
    int mid = (from + to) / 2;
    // Recursively sort the first and the second half
    comparisoncount1 = comparisoncount1 + mergeSort(a, from, mid);    //each time mergecount is called, it returnss a value and gets set back to 0
    comparisoncount1 = comparisoncount1 + mergeSort(a, mid + 1, to);  //we want to store the value each time and increment it and change it, instead of resetting it
    merge(a, from, mid, to, comparisoncount1);

    return comparisoncount1;
    //return -1;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
}


/************************* QUICK SORT + HELPER**************************/
/**
   Partitions a portion of an array.
   @param a the array to partition
   @param from the first index of the portion to be partitioned
   @param to the last index of the portion to be partitioned
   @return the last index of the first partition
*/
int SortingComparison::partition(int a[], int from, int to, int& comparisoncount2)
{
   int pivot = a[from];
   int i = from - 1; //index of data item being compared from left
   int j = to + 1;   //index of data item being compared from right

   while (i < j)    // as long as i and j did not cross (meet)
   {
      comparisoncount2++;
      i++;
      while (a[i] < pivot){//increment i until a[i] >= pivot
          i++;
          comparisoncount2++;
      }
      j--;     //IS THIS SUPPOSED TO BE OUTSIDE !!!! ! !  ! ! ! ! !
      while (a[j] > pivot){ //decrement j until a[j] <= pivot
          j--;
          comparisoncount2++;
      }
      comparisoncount2++; 
      if (i < j){
          std::swap(a[i], a[j]);
          //comparisoncount2++;
      }
   }
   return j; // the pivot index
}

/**
   @post Sorts an array in ascending order using quick sort.
   @param a the array to sort
   @param from the first index of the portion to be sorted
   @param to the last index of the portion to be sorted
  @return the number of comparisons made by the algorithm
*/
int SortingComparison::quickSort(int a[], int from, int to)
{
    int comparisoncount2 = 0;
    if (from >= to){return 0;}

    int p = partition(a, from, to, comparisoncount2);
    comparisoncount2 = comparisoncount2 + quickSort(a, from, p);
    comparisoncount2 = comparisoncount2 + quickSort(a, p + 1, to);


    //return -1;  //******* MODIFY TO RETURN THE NUMBER OF COMPARISONS
    return comparisoncount2;
}


void SortingComparison::runComparison(data_distribution array_type){
    if(array_type == RANDOM){
    srand(static_cast<unsigned>(time(0)));
      for(int i = 0; i < SIZE; i++){
        values_[i] = rand() % SIZE;
      }
    }

    if(array_type == INCREASING){
      for(int i = 0; i < SIZE; i++){
        values_[i] = i;
      }
    }

    if(array_type == DECREASING){
      for(int i = 0; i < SIZE; i++){
        values_[i] = SIZE - i;
      }
  }

    int newarray[SIZE];
    for(int i = 0; i < SIZE; i++){
      newarray[i] = values_[i];
    }

    int newarray1[SIZE];
    for(int i = 0; i < SIZE; i++){
      newarray1[i] = values_[i];
    }

    int newarray2[SIZE];
    for(int i = 0; i < SIZE; i++){
      newarray2[i] = values_[i];
    }

    int newarray3[SIZE];
    for(int i = 0; i < SIZE; i++){
      newarray3[i] = values_[i];
    }

    std::cout << "Selection sort comparisons: " << selectionSort(newarray, SIZE) << std::endl << std::endl;
    std::cout << "Insertion sort comparisons: " << insertionSort(newarray1, SIZE) << std::endl << std::endl;
    std::cout << "Merge sort comparisons: " << mergeSort(newarray2,0,SIZE - 1) << std::endl << std::endl;
    std::cout << "Quick sort comparisons: " << quickSort(newarray3,0,SIZE - 1) << std::endl << std::endl;



}


/*****************************************************************/
/******************  TEST FUNCTION *******************************/
/*****************************************************************/



  //*************  IMPLEMENT runComparison HERE!!!! ************//
