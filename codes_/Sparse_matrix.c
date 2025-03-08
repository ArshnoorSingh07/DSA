#include <stdio.h>
int main() {
    int arr[3][3], z = 0, nz = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter the element at position [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The matrix is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 0) {
                z++;
            } else {
                nz++;
            }
        }
    }

    if (nz > z) {
        printf("Not a sparse matrix\n");
    } 
    else {
        int s[nz][3];
        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] != 0) {
                    s[k][0] = i;
                    s[k][1] = j;
                    s[k][2] = arr[i][j];
                    k++;
                }
            }
        }
        printf("The sparse matrix representation is:\n");
        for (int i = 0; i < nz; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", s[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
