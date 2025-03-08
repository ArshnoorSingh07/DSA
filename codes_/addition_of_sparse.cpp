#include <iostream>
using namespace std;

void inputMatrix(int matrix[][3], int &nzero) {
    cout << "Enter number of rows, columns, and non-zero elements: ";
    cin >> matrix[0][0] >> matrix[0][1] >> nzero;
    for (int i = 1; i <= nzero; i++) {
        cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
    }
}

void displayMatrix(int matrix[][3], int nzero) {
    for (int i = 0; i <= nzero; i++) {
        cout << matrix[i][0] << " " << matrix[i][1] << " " << matrix[i][2] << endl;
    }
}

void addSparseMatrices(int smat1[][3], int smat2[][3], int result[][3], int nzero1, int nzero2) {
    int i = 1, j = 1, k = 1;
    result[0][0] = smat1[0][0];
    result[0][1] = smat1[0][1];
    while (i <= nzero1 && j <= nzero2) {
        if (smat1[i][0] < smat2[j][0]) {
            result[k][0] = smat1[i][0];
            result[k][1] = smat1[i][1];
            result[k][2] = smat1[i][2];
            i++;
        } else if (smat1[i][0] > smat2[j][0]) {
            result[k][0] = smat2[j][0];
            result[k][1] = smat2[j][1];
            result[k][2] = smat2[j][2];
            j++;
        } else {
            if (smat1[i][1] < smat2[j][1]) {
                result[k][0] = smat1[i][0];
                result[k][1] = smat1[i][1];
                result[k][2] = smat1[i][2];
                i++;
            } else if (smat1[i][1] > smat2[j][1]) {
                result[k][0] = smat2[j][0];
                result[k][1] = smat2[j][1];
                result[k][2] = smat2[j][2];
                j++;
            } else {
                result[k][0] = smat1[i][0];
                result[k][1] = smat1[i][1];
                result[k][2] = smat1[i][2] + smat2[j][2];
                i++;
                j++;
            }
        }
        k++;
    }
    while (i <= nzero1) {
        result[k][0] = smat1[i][0];
        result[k][1] = smat1[i][1];
        result[k][2] = smat1[i][2];
        i++;
        k++;
    }
    while (j <= nzero2) {
        result[k][0] = smat2[j][0];
        result[k][1] = smat2[j][1];
        result[k][2] = smat2[j][2];
        j++;
        k++;
    }
    result[0][2] = k - 1;
}

int main() {
    int smat1[50][3], smat2[50][3], result[50][3];
    int nzero1, nzero2;
    inputMatrix(smat1, nzero1);
    inputMatrix(smat2, nzero2);
    addSparseMatrices(smat1, smat2, result, nzero1, nzero2);
    displayMatrix(result, result[0][2]);
    return 0;
}
