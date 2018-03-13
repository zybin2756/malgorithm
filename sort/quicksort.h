#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "../Tools/sorttesthelper.h"

//插入排序 排序[l..r]区间
//template<typename T>
//void insertSort(T arr[], int l, int r){
//    int j;
//    for(int i =l+1; i <= r; ++i){
//        T val = arr[i];
//        for(j = i; j > l && val < arr[j-1]; --j){
//            arr[j] = arr[j-1];
//        }
//        arr[j] = val;
//    }
//}

template<typename T>
int __partion(T arr[], int l, int r){
    int j = l;
    T val = arr[l];
    for(int i = l+1; i <= r; ++i){
        if(val > arr[i]){
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
int __partion1(T arr[], int l, int r){
    swap(arr[l],arr[rand()%(r-l+1) + l]);

    int j = l;
    T val = arr[l];
    for(int i = l+1; i <= r; ++i){
        if(val > arr[i]){
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r){
    if(l >= r){
        insertSort(arr, l, r);
        return;
    }

    int m = __partion1(arr, l, r);
    __quickSort(arr, l, m-1);
    __quickSort(arr, m+1, r);
}

template<typename T>
void quicksort(T arr[], int n){
    __quickSort(arr, 0, n-1);
}

#endif // QUICKSORT_H
