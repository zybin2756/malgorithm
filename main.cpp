#include <iostream>
#include "Tools/sorttesthelper.h"
#include "sort/selectsort.h"
#include "sort/bubblesort.h"
#include "sort/insertsort.h"
#include "sort/shellsort.h"
#include "sort/mergesort.h"
#include "sort/quicksort.h"

using namespace std;

int main()
{
    int n = 10;
    while(n < 100000000){ //
    
//        int* arr1 = SortTestHelper::createRandomArray(1,n,n);
        int* arr1 = SortTestHelper::crateNealySortArray(n, 10);
        int* arr2 = SortTestHelper::copyArray(arr1, n);
//        int* arr3 = SortTestHelper::copyArray(arr1, n);
//        int* arr4 = SortTestHelper::copyArray(arr1, n);
//        SortTestHelper::printArray(arr1, n);
        SortTestHelper::sortTest("quicksort", quicksort, arr1, n);
        SortTestHelper::sortTest("mergeSortDU ", mergeSortDU, arr2, n);
//        SortTestHelper::printArray(arr1, n);
        cout << "--------------------------------------" << endl;
        delete[] arr1;
//        delete[] arr2;
//        delete[] arr3;
//        delete[] arr4;
        n*=10;
    }
    return 0;
}
