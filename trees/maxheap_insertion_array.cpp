#include <iostream>
using namespace std;
void insert(int heap[], int &size, int value) {
    if (size >= 100) {
        cout << "Heap overflow! Can't insert more elements." << endl;
        return;
    }
    size++;
    heap[size] = value;
    int index = size;
    while (index > 1) {
        int parent = index / 2;
        if (heap[index] <= heap[parent]){
            break;
        }
        swap(heap[index], heap[parent]);
        index = parent;
    }
}

void printHeap(int heap[], int size) {
    if (size == 0) {
        cout << "Heap is empty." << endl;
        return;
    }
    for (int i = 1; i <= size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int heap[101];
    int size = 0;

    insert(heap, size, 10);
    insert(heap, size, 20);
    insert(heap, size, 5);
    insert(heap, size, 15);
    insert(heap, size, 30);

    cout << "Max Heap after insertions: ";
    printHeap(heap, size);

    return 0;
}
