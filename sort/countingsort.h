#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

void countingsort(int arr[], int n){
    int maxVal = arr[0];
    for(int i = 1; i < n; ++i){
        if(arr[i] > maxVal){
            maxVal = arr[i];
        }
    }

    int* count_arr = new int[maxVal+1];
    for(int i = 0; i < maxVal+1; ++i){
        count_arr[i] = 0;
    }
    for(int i = 0; i < n; ++i){
        ++count_arr[arr[i]];
    }

    for(int i = 1; i < maxVal+1; ++i){
        count_arr[i]+=count_arr[i-1];
    }

    int* temp_arr =  new int[n];
    for(int i = 0; i < n; ++i){
        count_arr[arr[i]]--;
        temp_arr[count_arr[arr[i]]] = arr[i];
    }

    for(int i = 0; i < n; ++i){
        arr[i] = temp_arr[i];
    }

    delete[] temp_arr;
    delete[] count_arr;
}

#endif // COUNTINGSORT_H
