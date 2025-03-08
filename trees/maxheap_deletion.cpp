#include <iostream>
using namespace std;
void deleteRoot(int heap[], int &size) {
    if (size == 0) {
        cout << "Heap is empty. Nothing to delete." << endl;
        return;
    }
    heap[1] = heap[size];
    size--;
    int index = 1;

    while (index <= size) {
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        if (leftChild <= size && heap[leftChild]>heap[index]) {
            swap(heap[index],heap[leftChild]);
            index = leftChild;
        }
        else if (rightChild <= size && heap[rightChild] > heap[index]) {
            swap(heap[index],heap[rightChild]);
            index = rightChild;
        }
        else{
            return;
        }
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
    heap[++size] = 30;
    heap[++size] = 20;
    heap[++size] = 15;
    heap[++size] = 5;
    heap[++size] = 10;

    cout << "Max Heap before deletion: ";
    printHeap(heap, size);
    deleteRoot(heap, size);
    cout << "Max Heap after deleting root: ";
    printHeap(heap, size);

    return 0;
}
