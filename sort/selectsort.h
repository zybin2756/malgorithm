#ifndef SELECTSORT_H
#define SELECTSORT_H

//选择排序
template<typename T>
void selectSort(T arr[], int n){
    for(int i = 0; i < n; ++i)
    {
        int min = i;
        for(int j = i+1;  j < n; ++j){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }
}

#endif // SELECTSORT_H
