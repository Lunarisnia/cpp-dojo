void functionExample() {
    int x = 10; // x is stored in the stack memory
}

void functionExampleHeap() {
    int* p = new int; // dynamically allocated int in heap memory
    *p = 10;
    // more code
    delete p; // deallocate memory
}