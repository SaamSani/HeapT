# HeapT Class and `largestm` Template Function

This project implements a **HeapT** class, a template-based Min-Heap data structure, and a standalone template function called `largestm` to find the `m` largest elements from a given vector. The project demonstrates advanced usage of templates, memory management, and efficient algorithms for priority queue operations.

---

## Features

### **HeapT Class**
1. **Dynamic Min-Heap**:
   - Implements a min-heap using a dynamically allocated array.
   - Efficient insertion, removal, and heap property maintenance.

2. **Template Support**:
   - Generic class for storing any comparable data type.

3. **Key Methods**:
   - **Constructor**: Initializes the heap with a specified capacity.
   - **Copy Constructor**: Creates a deep copy of another heap.
   - **Destructor**: Manages memory cleanup for dynamic allocation.
   - **Assignment Operator**: Allows deep copy and self-assignment handling.
   - **Insert**: Adds an element to the heap while maintaining heap order.
   - **Remove**: Removes and returns the root element (smallest).
   - **Peek**: Returns the smallest element without removal.
   - **Merge**: Combines two heaps into a new heap.
   - **Size**: Returns the current number of elements in the heap.

4. **Heap Operations**:
   - **Bubble Up**: Restores heap property after insertion.
   - **Bubble Down**: Restores heap property after removal.

---

### **`largestm` Template Function**
1. **Purpose**:
   - Extracts the `m` largest elements from an unsorted vector and returns them in descending order.

2. **Key Features**:
   - Uses the **HeapT** class for efficient extraction.
   - Ensures a time complexity of \(O(n \log m)\), where \(n\) is the size of the vector.
   - Handles edge cases like `m = 0` or when `m` exceeds the vector's size.

3. **Parameters**:
   - `const std::vector<T> &V`: Input vector of elements of type `T`.
   - `int m`: Number of largest elements to extract.

4. **Return**:
   - A vector containing the `m` largest elements in descending order.

---

## Code Overview

### **HeapT.h**
Defines the `HeapT` template class, implementing the following:
- Constructors and memory management.
- Min-heap operations (`insert`, `remove`, `peek`).
- Helper functions for heap property maintenance (`BubbleUp`, `BubbleDown`).

### **largestm.h**
Defines the `largestm` template function:
- Leverages `HeapT` to store the `m` largest elements.
- Efficiently maintains the heap's size at `m` during the process.

---

## How to Use

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/heap-and-largestm.git
   cd heap-and-largestm
