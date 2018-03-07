#ifndef BUBBLESORT_H
#define BUBBLESORT_H



/*
冒泡排序由于要进行很多次数据交换,所以即使它是o(n2)的算法，但是效率还是比选择排序差的
此处用了优化，如果没检测到有数据交换证明已经有序了，避免了多余循环
n:10
0.00000000 s
n:100
0.00000000 s
n:1000
0.00000000 s
n:10000
0.76000000 s
n:100000
89.59000000 s

采用优化 在内循环中进行升序和降序遍历各一次，可以提高效率，即 鸡尾酒排序 见 bubbleSort1
n:10
0.00000000 s
n:100
0.00000000 s
n:1000
0.00000000 s
n:10000
0.63000000 s
n:100000
69.68000000 s
*/
template <typename T>
void bubbleSort(T arr[], int n){
    bool hasSwaped = true;
    for(int i = 0; i < n && hasSwaped; ++i){
        hasSwaped = false;
        for(int j = n-1; j > i; --j){
            if(arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
                hasSwaped = true;
            }
        }
    }

}

template <typename T>
void bubbleSort1(T arr[], int n){
    bool hasSwaped = true;
    for(int i = 0; i < n && hasSwaped; ++i){
        hasSwaped = false;
        for(int j = n-1; j > i; --j){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
                hasSwaped = true;
            }
        }

        for(int j = i; j < n-i-1; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                hasSwaped = true;
            }
        }
    }
}

#endif // BUBBLESORT_H
