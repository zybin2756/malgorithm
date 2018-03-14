#include <iostream>
#include "Tools/sorttesthelper.h"
#include "sort/selectsort.h"
#include "sort/bubblesort.h"
#include "sort/insertsort.h"
#include "sort/shellsort.h"
#include "sort/mergesort.h"
#include "sort/quicksort.h"

#include "question.h"

using namespace std;

int main()
{
    int n = 10;
    cout << "----------test random----------:" << endl;
    while(n < 100){ //
    
        int* arr1 = SortTestHelper::createRandomArray(1,n,n);
//        int* arr2 = SortTestHelper::crateNealySortArray(n, 10);
//        int* arr3 = SortTestHelper::createRandomArray(1,10,n);
        int* arr2 = SortTestHelper::copyArray(arr1, n);
//        int* arr3 = SortTestHelper::copyArray(arr1, n);
//        int* arr4 = SortTestHelper::copyArray(arr1, n);

        SortTestHelper::sortTest("quicksort2ways", quicksort, arr1, n);
        SortTestHelper::sortTest("quicksort3ways", quicksort3ways, arr2, n);
//        SortTestHelper::sortTest("mergeSortUD", mergeSortUD, arr3, n);
//
//        cout << "--------------------------------------" << endl;
        delete[] arr1;
        delete[] arr2;
//        delete[] arr3;
//        delete[] arr4;
        n*=10;
        cout << "--------------------------------------" << endl;
    }

    return 0;
}
