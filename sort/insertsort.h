#ifndef INSERTSORT_H
#define INSERTSORT_H


/*
  此处为最原始的插入排序
  针对无序数组
insertSort n:10
0.00000000 s
insertSort n:100
0.00000000 s
insertSort n:1000
0.00000000 s
insertSort n:10000
0.48000000 s
insertSort n:100000
48.03000000 s

    针对近乎有序的数组
insertSort n:10
0.00000000 s
insertSort n:100
0.00000000 s
insertSort n:1000
0.00000000 s
insertSort n:10000
0.29000000 s
insertSort n:100000
28.19000000 s

tip1: 已经发现某个序列是有序的时候，有必要再遍历前面的序列吗？
    没必要，发现不满足交换元素的条件时，其实可以结束该论循环了，详情见 insertSort1。



*/
template<typename T>
void insertSort(T arr[], int n){
    for(int i = 1; i < n; ++i){
        for(int j = i; j > 0; --j){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

/*


测试数据： 一个随机数组
    int* arr1 = SortTestHelper::createRandomArray(1,n,n);
    SortTestHelper::sortTest("insertSort", insertSort1, arr1, n);
    delete[] arr1;

insertSort n:10
0.00000000 s
insertSort n:100
0.00000000 s
insertSort n:1000
0.00000000 s
insertSort n:10000
0.33000000 s
insertSort n:100000
33.57000000 s

测试数据： 近乎有序的数组
    int* arr1 = SortTestHelper::crateNealySortArray(n, 10);
    SortTestHelper::sortTest("insertSort", insertSort1, arr1, n);
    delete[] arr1;

insertSort n:10
0.00000000 s
insertSort n:100
0.00000000 s
insertSort n:1000
0.00000000 s
insertSort n:10000
0.00000000 s
insertSort n:100000
0.01000000 s

通过这个优化在近乎有序的序列上进行排序时候，用插入排序可以起到飞的速度。

tip2: 每次交换数据需要进行3次赋值操作，这里会消耗很多资源。如何简化？
    我们可以改成记录插入位置，交换数组改成直接赋值的形式，见 insertSort2。
*/
template<typename T>
void insertSort1(T arr[], int n){
    for(int i = 1; i < n; ++i){
        for(; j > 0 && arr[j] < arr[j-1]; --j){
            swap(arr[j], arr[j-1]);
        }
    }
}

/*
测试数据： 一个随机数组
    int* arr1 = SortTestHelper::createRandomArray(1,n,n);
    SortTestHelper::sortTest("insertSort", insertSort2, arr1, n);
    delete[] arr1;

sertSort n:10
0.00000000 s
insertSort n:100
0.00000000 s
insertSort n:1000
0.00000000 s
insertSort n:10000
0.15000000 s
insertSort n:100000
15.77000000 s

测试数据： 近乎有序的数组
    int* arr1 = SortTestHelper::crateNealySortArray(n, 10);
    SortTestHelper::sortTest("insertSort", insertSort2, arr1, n);
    delete[] arr1;

insertSort n:10
0.00000000 s
insertSort n:100
0.00000000 s
insertSort n:1000
0.00000000 s
insertSort n:10000
0.00000000 s
insertSort n:100000
0.00000000 s
insertSort n:1000000
0.05000000 s

对于随机序列，通过优化减少赋值的次数， 可以明显的优化排序的效率。
*/
template<typename T>
void insertSort2(T arr[], int n){
    for(int i = 1; i < n; ++i){
        int val = arr[i];
        int j = i;
        for(; j > 0 && val < arr[j-1]; --j){
            arr[j] = arr[j-1];
        }
        arr[j] = val;
    }
}
#endif // INSERTSORT_H
