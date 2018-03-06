#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H
#include <ctime>
#include <iostream>
#include <string>
#include <cassert>
#include <stdlib.h>

using namespace std;
namespace SortTestHelper {
    template<typename T>
    bool isSorted(T arr[], int n){
        for(int i = 1; i < n; ++i){
            if(arr[i] < arr[i-1])
                return false;
        }
        return true;
    }

    template<typename T>
    void sortTest(string name, void (*sort)(T arr[], int n), T arr[], int n){
        clock_t start_time = clock();
        sort(arr, n);
        clock_t end_time = clock();
        assert(SortTestHelper::isSorted(arr, n));
        cout << ((double)end_time - start_time)/CLOCKS_PER_SEC << " s" << endl;
    }

    template<typename T>
    void printArray(T arr[], int n){
        for(int i = 0; i < n; ++i){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int* createRandomArray(int rangeL, int rangeR, int n){
        srand(time(NULL));
        int* arr = new int[n];
        for(int i = 0; i < n; ++i){
            arr[i] = rand() % (rangeR - rangeL) + rangeL;
        }
        return arr;
    }

    int* crateNealySortArray(int n, int swapTimes){
        srand(time(NULL));
        int* arr = new int[n];
        for(int i = 0; i < n; ++i){
            arr[i] = i;
        }
        while(swapTimes-- > 0){
            int s = rand()%n;
            int e = rand()%n;
            swap(arr[s], arr[e]);
        }
        return arr;
    }
}

#endif // SORTTESTHELPER_H
