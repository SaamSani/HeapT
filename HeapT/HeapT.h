#ifndef HEAPT_H  
#define HEAPT_H


#include <stdexcept>

template <typename T> 
class HeapT {
public:
    //Constructor to initialize heap with a given capacity
    HeapT(int initialCapacity) {
        data = new T[initialCapacity]; 
        capacity = initialCapacity;   
        currentSize = 0;               
    }

    //Copy constructor to create a deep copy of another heap
    HeapT(const HeapT& other) {
        capacity = other.capacity;
        currentSize = other.currentSize;
        data = new T[capacity];       //Allocate new memory for copied data
        for (int i = 0; i < currentSize; i++) {
            data[i] = other.data[i];  //Copy each element from the other heap
        }
    }

    //Destructor to free allocated memory
    ~HeapT() {
        delete[] data;  
    }

    //Assignment operator for deep copying another heap
    HeapT& operator=(const HeapT& other) {
        if (this == &other) {
            return *this;  
        }
        delete[] data;  //Free existing data

        //Copy the other heap's properties and data
        capacity = other.capacity;
        currentSize = other.currentSize;
        data = new T[capacity];
        for (int i = 0; i < currentSize; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    //Insert method to add a value and maintain heap order
    void insert(const T& val) {
        if (currentSize >= capacity) {
            throw std::runtime_error("Heap is full");
        }
        data[currentSize] = val;    //Place new value at the end
        BubbleUp(currentSize);      //Move it up to restore heap order
        ++currentSize;              //Increment the heap size
    }

    //Remove method to remove and return the smallest (root) element
    T remove() {
        if (currentSize == 0) {
            throw std::runtime_error("Heap is empty");
        }
        T min_root = data[0];            //Store the root (smallest element)
        data[0] = data[--currentSize];   //Replace root with last element
        BubbleDown(0);                   //Move the new root down to restore order
        return min_root;                
    }

    //Merge method to combine two heaps and return a new heap
    HeapT merge(const HeapT& other) const {
        HeapT mergeHeap(this->currentSize + other.currentSize);  //New heap with combined capacity
        for (int i = 0; i < this->currentSize; i++) {
            mergeHeap.insert(this->data[i]);  //Insert elements from this heap
        }
        for (int i = 0; i < other.currentSize; i++) {
            mergeHeap.insert(other.data[i]);  //Insert elements from the other heap
        }
        return mergeHeap;  
    }

    // Peek method to return the smallest element without removing it
    T peek() const {
        if (currentSize == 0) {
            throw std::runtime_error("Heap is empty");
        }
        return data[0];  // Root element is the smallest in a min-heap
    }

    // Size method to return the current number of elements in the heap
    int size() const {
        return currentSize;
    }

private:
    T* data;            
    int capacity;        
    int currentSize;     

    void BubbleUp(int index);    
    void BubbleDown(int index);  
};

//BubbleUp: Move an element up to restore heap order
template <typename T>
void HeapT<T>::BubbleUp(int i) {
    int parent = (i - 1) / 2;  //Calculate parent index
    if (i > 0 && data[i] < data[parent]) {  //If current element is smaller than its parent
        T temp = data[i];
        data[i] = data[parent];   //Swap with parent
        data[parent] = temp;

        BubbleUp(parent);  //Recursive call to continue bubbling up if needed
    }
}

//BubbleDown: Move an element down to restore heap order
template <typename T>
void HeapT<T>::BubbleDown(int i) {
    int left = (2 * i) + 1;   //Calculate left child index
    int right = (2 * i) + 2;  //Calculate right child index
    int smallest = i;         //Assume current element is the smallest

    //Check if the left child exists and is smaller
    if (left < currentSize && data[left] < data[smallest]) {
        smallest = left;
    }
    
    //Check if the right child exists and is smaller than the current smallest
    if (right < currentSize && data[right] < data[smallest]) {
        smallest = right;
    }

    //If the smallest element is not the current element, swap and recurse
    if (smallest != i) {
        T temp = data[i];
        data[i] = data[smallest];
        data[smallest] = temp;

        BubbleDown(smallest);  //Recursive call to continue bubbling down if needed
    }
}


#endif