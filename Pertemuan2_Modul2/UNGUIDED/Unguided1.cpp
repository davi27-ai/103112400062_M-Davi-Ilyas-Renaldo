#include <iostream>
using namespace std;

const int SIZE = 3;

void tampilMatriks(int M[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void jumlahMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}


void kurangMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void kaliMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[SIZE][SIZE] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int B[SIZE][SIZE] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int C[SIZE][SIZE];
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---" << endl;
        cout << "1. Penjumlahan matriks" << endl;
        cout << "2. Pengurangan matriks" << endl;
        cout << "3. Perkalian matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahMatriks(A, B, C);
                cout << "\nHasil Penjumlahan Matriks:\n";
                tampilMatriks(C);
                break;
            case 2:
                kurangMatriks(A, B, C);
                cout << "\nHasil Pengurangan Matriks:\n";
                tampilMatriks(C);
                break;
            case 3:
                kaliMatriks(A, B, C);
                cout << "\nHasil Perkalian Matriks:\n";
                tampilMatriks(C);
                break;
            case 4:
                cout << "\nKeluar dari program.\n";
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}
