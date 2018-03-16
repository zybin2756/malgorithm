#ifndef MAXHEAP_H
#define MAXHEAP_H

template<typename Item>
class MaxHeap{
private:
    Item* data;
    int count;
    int capacity;

public:
    MaxHeap(int capacity){
        this->data = new Item[capacity+1];
        this->count = 0;
        this->capacity = capacity;
    }

    MaxHeap(Item arr[], int n){
        this->data = new Item[n+1];
        this->count = n;
        this->capacity = n;
        for(int i =1; i <= n; ++i){
            this->data[i] = arr[i-1];
        }

        for(int i = count/2; i >= 1; --i){
            this->shiftDown(i);
        }
    }

    ~MaxHeap(){
        delete[] data;
    }

    bool isEmpty(){
        return count == 0;
    }

    int size(){
        return count;
    }

    void insert(Item ele){
        if(count > capacity)
        {
            cout << 1 << endl;
            this->remalloc();
        }
        data[++count] = ele;
        this->shiftUp(count);
    }

    Item pop(){
        assert(count > 0);
        swap(data[1], data[count--]);
        shiftDown(1);
        return data[count+1];
    }

    void printData(){
        for(int i = 1; i <= count; ++i){
            cout << data[i] << " ";
        }
        cout << endl;
    }

private:
    void shiftUp(int k){
        while(k > 1 && data[k] > data[k/2]){
            swap(data[k/2],data[k]);
            k/=2;
        }
    }

    void shiftDown(int k){
        while(2*k < count){
            int j = 2*k;
            if(j+1 <= count && data[j] < data[j+1]){
                j+=1;
            }
            if(data[k] > data[j])
                break;

            swap(data[k], data[j]);
            k = j;
        }
    }

    void remalloc(){
        capacity*=2;
        Item* new_data = new Item[capacity+1];
        for(int i =1; i <= count; ++i){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
};





template<typename T>
void __heapSort1(T arr[], int n, bool asc=true){
    MaxHeap<T> heap = MaxHeap<T>(n);
    for(int i = 0; i < n; ++i){
        heap.insert(arr[i]);
    }

    if(asc){
        //升序
        for(int i = n; i > 0; --i){
            arr[i-1] = heap.pop();
        }
    }else{

        //降序
        for(int i = 0; i < n; ++i){
            arr[i] = heap.pop();
        }
    }
}

template<typename T>
void heapSort1(T arr[], int n){
    __heapSort1(arr, n);
}

template<typename T>
void __heapSort2(T arr[], int n, bool asc=true){
    MaxHeap<T> heap = MaxHeap<T>(arr, n);

    if(asc){
        //升序
        for(int i = n; i > 0; --i){
            arr[i-1] = heap.pop();
        }
    }else{

        //降序
        for(int i = 0; i < n; ++i){
            arr[i] = heap.pop();
        }
    }
}
template<typename T>
void heapSort2(T arr[], int n){
    __heapSort2(arr, n);
}


#endif // MAXHEAP_H
