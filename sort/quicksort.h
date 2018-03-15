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

//随机
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


//二路
template<typename T>
int __partion2(T arr[], int l, int r){
    swap(arr[l],arr[rand()%(r-l+1) + l]);

    int i = l+1, j = r;
    T val = arr[l];
    while(i <= j){
        for(;i <= j && arr[i] < val; ++i);
        for(;j >= i && arr[j] > val; --j);
        if( j < i) break;
        swap(arr[i++],arr[j--]);
    }
    swap(arr[l], arr[j]);

    return j;
}

//三路
template<typename T>
int __partion3(T arr[], int l, int r, int &gt){
    swap(arr[l], arr[rand()%(r-l+1) + l]);
    T val = arr[l];
    int lt = l, i = l+1;
    gt=r+1;
    while(i < gt){
        if( val < arr[i]){
            swap(arr[--gt], arr[i]);
        }
        else if( val > arr[i]){
            swap(arr[++lt], arr[i++]);
        }else{
            ++i;
        }
    }
    swap(arr[lt], arr[l]);
    return lt;
}
template<typename T>
void __quickSort3(T arr[], int l, int r){
    if(r-l <= 15){
        insertSort(arr, l, r);
        return;
    }
    int gt = 0;
    int m = __partion3(arr, l, r, gt);
    __quickSort3(arr, l, m-1);
    __quickSort3(arr, gt, r);
}

template<typename T>
void quicksort3ways(T arr[], int n){
    __quickSort3(arr, 0, n-1);
}


template<typename T>
void __quickSort(T arr[], int l, int r){
    if(r-l <= 15){
        insertSort(arr, l, r);
        return;
    }

    int m = __partion2(arr, l, r);
    __quickSort(arr, l, m-1);
    __quickSort(arr, m+1, r);
}


template<typename T>
void quicksort(T arr[], int n){
    __quickSort(arr, 0, n-1);
}

#endif // QUICKSORT_H
