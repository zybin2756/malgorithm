#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

void countingSort(int arr[], int n){
    int maxVal = 0;
    for(int i = 0; i < n; ++i){
        if( arr[i] > maxVal){
            maxVal = arr[i];
        }
    }

    int* count = new int[maxVal+1];
    for(int i =0; i <= maxVal; ++i){
        count[i] = 0;
    }


    for(int i = 0; i < n; ++i){
        count[arr[i]]+=1;
    }


    for(int i = 1; i < n; ++i){
        count[i]+=count[i-1];
    }

    int* temp = new int[n];
    for(int i = 0; i < n; ++i){
        count[arr[i]]--;
        temp[count[arr[i]]] = arr[i];
    }

    for(int i = 0; i < n; ++i){
        arr[i] = temp[i];
    }

    delete[] temp;
    delete[] count;
}

#endif // COUNTINGSORT_H
