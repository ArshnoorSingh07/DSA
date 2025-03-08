#include <iostream>
using namespace std;

// void merge(int arr[], int lb, int mid, int ub) {
//     int size =ub-lb+1;
//     int b[size];
//     int i=lb,j=mid+1,k=0;
//     while (i<=mid && j<=ub) {
//         if (arr[i] <= arr[j]) {
//             b[k++] = arr[i++];
//         } 
//         else{
//             b[k++] = arr[j++];
//         }
//     }
//     while (i <= mid) {
//         b[k++] = arr[i++];
//     }

//     while (j <= ub) {
//         b[k++] = arr[j++];
//     }

//     for (int m = 0; m < size; m++) {
//         arr[lb+m] = b[m];
//     }
// }

// void mergesort(int arr[], int lb, int ub) {
//     if (lb<ub) {
//         int mid = (lb + ub) / 2;
//         mergesort(arr, lb, mid);
//         mergesort(arr, mid + 1, ub);
//         merge(arr, lb, mid, ub);
//     }
// }

// int main() {
//     int arr[] = {38, 27, 43, 3, 9, 82, 10};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original array: ";
//     for (int i = 0; i < size; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     mergesort(arr, 0, size - 1);

//     cout << "Sorted array: ";
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }
//or.........................................................(prefer this not the notes wala)
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
