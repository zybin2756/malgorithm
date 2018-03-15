#include <iostream>
#include "Tools/sorttesthelper.h"
#include "sort/selectsort.h"
#include "sort/bubblesort.h"
#include "sort/insertsort.h"
#include "sort/shellsort.h"
#include "sort/mergesort.h"
#include "sort/quicksort.h"
<<<<<<< HEAD
#include "sort/countingSort.h"
#include "sort/radixsort.h"
#include "sort/maxheap.h"
=======
#include "sort/countingsort.h"
>>>>>>> 060e9f36f715398db9a3cebc31f922a997d4a46f

using namespace std;

int main()
{
    int n = 10;
<<<<<<< HEAD

    while(n < 1000000000){ //
    
        int* arr1 = SortTestHelper::createRandomArray(1,n,n);
//        int* arr2 = SortTestHelper::crateNealySortArray(n, 10);
//        int* arr3 = SortTestHelper::createRandomArray(1,10,n);
//        int* arr2 = SortTestHelper::copyArray(arr1, n);
//        int* arr3 = SortTestHelper::copyArray(arr1, n);
//        int* arr4 = SortTestHelper::copyArray(arr1, n);
        SortTestHelper::sortTest("heapSort", heapSort, arr1, n);
//        SortTestHelper::sortTest("radixSort", radixSort, arr1, n);
//        SortTestHelper::sortTest("countingSort", countingSort, arr3, n);
//        SortTestHelper::printArray(arr1, n);
=======
    cout << "----------test random----------:" << endl;
    while(n < 1000000000){ //
    
        int* arr1 = SortTestHelper::createRandomArray(1,n,n);
//        int* arr1 = SortTestHelper::crateNealySortArray(n, 10);
//        int* arr1 = SortTestHelper::createRandomArray(1,10,n);
//        int* arr2 = SortTestHelper::copyArray(arr1, n);
//        int* arr3 = SortTestHelper::copyArray(arr1, n);
//        int* arr4 = SortTestHelper::copyArray(arr1, n);

        SortTestHelper::sortTest("countingSort", countingsort, arr1, n);
>>>>>>> 060e9f36f715398db9a3cebc31f922a997d4a46f
//        SortTestHelper::sortTest("quicksort3ways", quicksort3ways, arr2, n);
//        SortTestHelper::sortTest("mergeSortUD", mergeSortUD, arr3, n);
//
//        cout << "--------------------------------------" << endl;
        delete[] arr1;
//        delete[] arr2;
//        delete[] arr3;
//        delete[] arr4;
        n*=10;
        cout << "--------------------------------------" << endl;
    }

    return 0;
}
