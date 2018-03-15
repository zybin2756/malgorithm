#ifndef RADIXSORT_H
#define RADIXSORT_H

void radixSort(int arr[], int n){
    int* temp = new int[n];
    int bit = 1; //基数用于取“资讯”

    //找到最大值以便确认 循环次数
    int maxVal = arr[0];
    for(int i = 1; i < n; ++i){
        maxVal = max(arr[i], maxVal);
    }

    while(maxVal / bit){

        int radix[10];
        for(int i = 0; i < 10; ++i){
            radix[i] = 0;
        }

        //根据取出来的“资讯”，分配桶
        for(int i = 0; i < n; ++i){
            ++radix[arr[i]/bit%10];
        }

        //累加确认索引
        for(int i = 1; i < 10; ++i){
            radix[i] += radix[i-1];
        }

        //xs
        for(int i = 0; i < n; ++i){
            temp[--radix[arr[i]/bit%10]] = arr[i];
        }

        for(int i = 0; i < n; ++i){
            arr[i] = temp[i];
        }

        bit*=10;
    }

    delete[] temp;
}

#endif // RADIXSORT_H
