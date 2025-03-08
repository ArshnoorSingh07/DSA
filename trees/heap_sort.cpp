#include <iostream>
using namespace std;

void heapify(int heap[], int size, int index) {
    int largest = index;
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;

    if (leftChild <= size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }
    if (rightChild <= size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        swap(heap[largest], heap[index]);
        heapify(heap, size, largest);
    }
}

void heapSort(int heap[], int size) {
    int n = size;
    while (n > 1) {
        swap(heap[1], heap[n]);
        n--;
        heapify(heap, n, 1);
    }
}

void printHeap(int heap[], int size) {
    for (int i = 1; i <= size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int heap[] = {-1, 10, 15, 30, 40, 50, 100, 40};
    int size = 7;

    cout << "Before sorting: ";
    printHeap(heap, size);
    for (int i = size / 2; i > 0; i--) {
        heapify(heap, size, i);
    }
    heapSort(heap, size);
    cout << "After sorting: ";
    printHeap(heap, size);

    return 0;
}
