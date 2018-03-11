#ifndef MERGESORT_H
#define MERGESORT_H

//插入排序 排序[l..r]区间
template<typename T>
void insertSort(T arr[], int l, int r){
    int j;
    for(int i =l+1; i <= r; ++i){
        T val = arr[i];
        for(j = i; j > l && val < arr[j-1]; --j){
            arr[j] = arr[j-1];
        }
        arr[j] = val;
    }
}


//合并[l..m-1] 和　[m..r]　为有序区间
template<typename T>
void __merge(T arr[], int l, int m, int r){
    T* aux = new T[r-l+1];//申请辅助空间，这里前闭后闭的区间所以要+1，如果是其他的请酌情考虑
//    T aux[r-l+1];
    for(int i = l; i <= r; ++i){
        aux[i-l] = arr[i];
    }

    int i = l, j = m+1;
    for(int k = l; k <= r; ++k){
        if( i >m ){
            arr[k] = aux[j-l];
            ++j;
        }
        else if(j > r){
            arr[k] = aux[i-l];
            ++i;
        }
        else if(aux[i-l] > aux[j-l]){
            arr[k] = aux[j-l];
            ++j;
        }
        else{
            arr[k] = aux[i-l];
            ++i;
        }
    }
    delete[] aux;
}

//排序[l..r]的前闭后闭区间
template<typename T>
void __mergeSortUD(T arr[], int l, int r){
    if(r-l <= 30){
        insertSort(arr, l, r);
        return;
    }
    int mid = (r-l)/2 + l; //避免越界
    __mergeSortUD(arr, l, mid);
    __mergeSortUD(arr, mid+1, r);
    if(arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSortUD(T arr[], int n){
    __mergeSortUD(arr,0,n-1);
}

#endif // MERGESORT_H
