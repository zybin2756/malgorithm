#include <iostream>
#include "Tools/sorttesthelper.h"
#include "sort/selectsort.h"
#include "sort/bubblesort.h"
#include "sort/insertsort.h"
#include "sort/shellsort.h"
#include "sort/mergesort.h"
#include "sort/quicksort.h"
#include "sort/countingSort.h"
#include "sort/radixsort.h"
#include "sort/maxheap.h"

using namespace std;

int main()
{
    int n = 10;

    while(n < 1000000000){ //
    
        int* arr1 = SortTestHelper::createRandomArray(1,n,n);
//        int* arr1 = SortTestHelper::crateNealySortArray(n, 10);
//        int* arr3 = SortTestHelper::createRandomArray(1,10,n);
        int* arr2 = SortTestHelper::copyArray(arr1, n);
//        int* arr3 = SortTestHelper::copyArray(arr1, n);
//        int* arr4 = SortTestHelper::copyArray(arr1, n);
        SortTestHelper::sortTest("heapSort2", heapSort2, arr1, n);
        SortTestHelper::sortTest("heapSort1", heapSort1, arr2, n);
//        SortTestHelper::sortTest("radixSort", radixSort, arr1, n);
//        SortTestHelper::sortTest("countingSort", countingSort, arr3, n);
//        SortTestHelper::printArray(arr1, n);
        n*=10;
        cout << "--------------------------------------" << endl;
        delete[] arr1;
        delete[] arr2;
    }

    return 0;
}
