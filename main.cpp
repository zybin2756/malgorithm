#include <iostream>
#include "Tools/sorttesthelper.h"
#include "sort/selectsort.h"
using namespace std;

int main()
{
    int n = 10000;
    int* arr1 = SortTestHelper::createRandomArray(1,n,n);
    SortTestHelper::sortTest("selectSort", selectSort, arr1, n);
    delete arr1;
    return 0;
}
