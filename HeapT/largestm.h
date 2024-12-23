#ifndef LARGESTM_H
#define LARGESTM_H

#include <vector>
#include "HeapT.h"

template <typename T>
std::vector<T> largestm(const std::vector<T> &V, int m) {
    int DesireM = m;
   
    //If m is 0 or the vector is empty, return an empty result
    if (DesireM == 0 || V.empty()) {
        return {};
    }

    //If m is larger than the vector size, set DesireM to the size of the vector
    if (DesireM > V.size()) {
        DesireM = V.size();
    }

    //Initialize a min-heap with capacity DesireM
    HeapT<T> minHeap(DesireM);

    //Process each element in the vector
    for (const T& val : V) {
        if (minHeap.size() < DesireM) {
            //Insert directly if the heap is not yet full
            minHeap.insert(val);
        } else {
            //Replace the smallest element if the current value is larger
            if (val > minHeap.peek()) {
                minHeap.remove();
                minHeap.insert(val);
            }
        }
    }

    //Collect the m largest elements from the heap
    std::vector<T> result;
    while (minHeap.size() > 0) {
        result.push_back(minHeap.remove());
    }

    //Reverse the result vector to get descending order
    int front = 0;
    int back = result.size() - 1;
    while (front < back) {
        T temp = result[front];
        result[front] = result[back];
        result[back] = temp;
        front++;
        back--;
    }

    return result;
}


#endif 