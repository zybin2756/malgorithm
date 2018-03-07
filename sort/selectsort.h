#ifndef SELECTSORT_H
#define SELECTSORT_H



/*
n:10
0.00000000 s
n:100
0.00000000 s
n:1000
0.00000000 s
n:10000
0.30000000 s
n:100000
30.95000000 s
百万级数据就不测试了，时间太爆炸 大概是 3000s 50分钟阿哦 ..
所以 o(n2) 级别的算法排序大量数据会炸的
*/
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
