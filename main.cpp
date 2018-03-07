#include <iostream>
#include "Tools/sorttesthelper.h"
#include "sort/selectsort.h"
#include "sort/bubblesort.h"
#include "sort/insertsort.h"
using namespace std;

int main()
{
    int n = 10;
    while(n <= 1000000){
    
//        int* arr1 = SortTestHelper::createRandomArray(1,n,n);
        int* arr1 = SortTestHelper::crateNealySortArray(n, 10);
//        int* arr2 = SortTestHelper::copyArray(arr1, n);
        SortTestHelper::sortTest("insertSort", insertSort2, arr1, n);
        delete[] arr1;
//        delete[] arr2;

        n*=10;
    }
    return 0;
}
