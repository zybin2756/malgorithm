#ifndef SHELLSORT_H
#define SHELLSORT_H
#include <math.h>

//测试用主函数
/*
int main()
{
    int n = 10;
    while(n <= 10000000){

//        int* arr1 = SortTestHelper::createRandomArray(1,n,n);
        int* arr1 = SortTestHelper::crateNealySortArray(n, 10);
        int* arr2 = SortTestHelper::copyArray(arr1, n);
        int* arr3 = SortTestHelper::copyArray(arr1, n);
        int* arr4 = SortTestHelper::copyArray(arr1, n);
        SortTestHelper::sortTest("d/3+1 ", shellSort, arr1, n);
        SortTestHelper::sortTest("Sedgewick ", shellSort1, arr2, n);
        SortTestHelper::sortTest("Hibbard ", shellSort2, arr3, n);
        SortTestHelper::sortTest("Knuth ", shellSort3, arr4, n);
        cout << "--------------------------------------" << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        n*=10;
    }
    return 0;
}
*/

template<typename T>
void shellSort(T arr[], int n){
    int increment = n;
    int j;
    do{
        increment = increment/3 + 1;
        for(int i = increment; i < n; ++i){
            if(arr[i] < arr[i-increment]){
                T val = arr[i];
                for(j = i-increment; j >= 0 && val < arr[j]; j-=increment){
                        arr[j+increment] = arr[j];
                }
                arr[j+increment] = val;
            }
        }
    }while(increment > 1);

}

int createSedgewick(int* incrementSeq, int n){
    int i, startup1 =0 , startup2 = 2;
    incrementSeq[0] = 1;
    for(i=1; i<n && incrementSeq[i-1] < n; i++)
    {
        if(i%2==0)
        {
            incrementSeq[i] = 9*pow(4, startup1) - 9*pow(2, startup1) +1;
            startup1++;
        }
        else
        {
            incrementSeq[i] = pow(4, startup2) - 3*pow(2, startup2) +1;
            startup2++;
        }
    }
    return i; // 排序轮数，每轮都使用（比上一轮）缩小的增量序列
}

int createHibbard(int* incrementSeq, int n){
    int i = 1;
    incrementSeq[0] = 1;
    for(; i < n && incrementSeq[i-1] < n; ++i){
        incrementSeq[i] = 2*incrementSeq[i-1] + 1;
    }
    return i;
}

int createKnuth(int* incrementSeq, int n){
    int i = 1;
    incrementSeq[0] = 1;
    for(; i < n && incrementSeq[i-1] < n; ++i){
        incrementSeq[i] = 3*incrementSeq[i-1] + 1;
    }
    return i;
}

void shellSort1(int arr[], int n){
    int incrementSeq[255] = {0};
    int len = createSedgewick(incrementSeq,n);

    int increment = len;
    int j;
    do{
        increment = incrementSeq[--len];
        for(int i = increment; i < n; ++i){
            if(arr[i] < arr[i-increment]){
                int val = arr[i];
                for(j = i - increment;j >= 0 && val < arr[j]; j-=increment){
                    arr[j+increment] = arr[j];
                }
                arr[j+increment] = val;
            }
        }
    }while(len > 0);
}

void shellSort2(int arr[], int n){
    int incrementSeq[255] = {0};
    int len = createHibbard(incrementSeq,n);
    int increment = len;
    int j;
    do{
        increment = incrementSeq[--len];
        for(int i = increment; i < n; ++i){
            if(arr[i] < arr[i-increment]){
                int val = arr[i];
                for(j = i - increment;j >= 0 && val < arr[j]; j-=increment){
                    arr[j+increment] = arr[j];
                }
                arr[j+increment] = val;
            }
        }
    }while(len > 0);
}

void shellSort3(int arr[], int n){
    int incrementSeq[255] = {0};
    int len = createKnuth(incrementSeq,n);

    int increment = len;
    int j;
    do{
        increment = incrementSeq[--len];
        for(int i = increment; i < n; ++i){
            if(arr[i] < arr[i-increment]){
                int val = arr[i];
                for(j = i - increment;j >= 0 && val < arr[j]; j-=increment){
                    arr[j+increment] = arr[j];
                }
                arr[j+increment] = val;
            }
        }
    }while(len > 0);
}


#endif // SHELLSORT_H
