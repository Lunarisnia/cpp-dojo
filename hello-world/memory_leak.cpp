#include <iostream>

int main() {
    while (true) {
        int* myArray = new int[1000]; // Allocate memory on the heap
        // No deallocation of memory, causing a memory leak
        // Imagine this loop running indefinitely
    }

    return 0;
}