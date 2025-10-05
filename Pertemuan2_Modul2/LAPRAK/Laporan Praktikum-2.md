# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua) </h1>
<p align="center">M-Davi-Ilyas-Renaldo - 103112400062</p>

## Dasar Teori
Array adalah struktur data yang menyimpan sejumlah elemen dengan tipe data yang sama dalam urutan tertentu. Array satu dimensi digunakan untuk menyimpan data linear yang diakses menggunakan satu indeks, misalnya A[i]. Struktur ini efisien untuk akses langsung karena elemen disimpan berurutan di memori, tetapi memiliki ukuran tetap sehingga kurang fleksibel [Poliban Press, 2023].

Array dua dimensi merupakan perluasan dari array satu dimensi yang terdiri dari baris dan kolom, mirip dengan bentuk tabel atau matriks. Elemen array dua dimensi diakses dengan dua indeks, yaitu A[i][j]. Struktur ini banyak digunakan dalam perhitungan matematis, penyimpanan data berbentuk tabel, dan pemrosesan citra [UNIKOM, 2017].

Array dan pointer memiliki hubungan erat dalam bahasa C/C++. Nama array pada dasarnya merupakan pointer yang menunjuk ke elemen pertamanya. Dengan demikian, operasi seperti *(arr + i) setara dengan arr[i]. Pointer memungkinkan manipulasi data array secara langsung melalui alamat memori, serta mendukung alokasi dinamis untuk array berdimensi ganda [Syarif, 2013].

## Guided 

### 1. Array 1 dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while (j < 5) {
        cout << "Isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }

    return 0;
}
```
program ini merupakan program sederhana Array 1 dimensi. Pengguna diminta memasukkan nilai ke setiap elemen, kemudian setelah memasukkan nilai program akan menampilkan kembali nilai-nilai yang dimasukkan tadi bersama dengan indeks nya.

### 2. Array 2 dimensi

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2x2
    for (int i = 0; i < 2; i++){                        //perulangan baris
        for(int j = 0; j < 2; j++){                     //perulangan kolom
            for(int k = 0; k < 2; k++){         //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "hasil perkalian : " << endl;
    tampilkanHasil(arrD);
    return 0;
    
}
```
program ini merupakan program sederhana Array 2 dimensi yang dapat melakukan perkalian dan penjumlahan dua matriks berukuran 2x2.

### 3. Arrnpointer

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int*ptr=arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; i++){
        cout<<"eleem array ke-0"<< i+1<<"menggunakan pointer"<<*(ptr+i)<<endl;
    }

    //mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; i++){
        cout<<"Elemen array ke-"<< i+1 <<"menggunakan indeks"<<arr[i]<<endl;
    }
    return 0;
    
}
```
Program ini merupakan program yang dapat mengakses elemen array menggunakan pointer dan indeks dengan hasil yang sama.

### 4. Fungsi Prosedur

```C++
#include<iostream>
using namespace std;

int cariMAX(int arr[], int ukuran) {
    int max = arr[0]; // Inisialisasi nilai maksimum dengan elemen pertama
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update nilai maksimum jika ditemukan elemen yang lebih besar
        }
    }
    return max;
}

void operasiAritmatika(int arr[], int ukuran){
    int totaljumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totaljumlah += arr[i];
    }  
    cout << "Total Penjumlahan: " << totaljumlah << endl;
    
    int totalkali = 1;
    for(int i = 0; i < ukuran; i++){
        totalkali *= arr[i];
    }
    cout << "Total Perkalian: " << totalkali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i << ": ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMAX(arr, ukuran) << endl;
    
    operasiAritmatika(arr, ukuran);
    return 0;
}
```
program ini merupakan program untuk mencari nilai maksimum serta dapat melakukan operasi penjumlahan dan perkalian pada elemen array.

### Output Unguided 1 : Menu Program Matriks

```C++
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
```

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan2_Modul2/LAPRAK/Output-Unguided1.png)

program ini merupakan program yang menampilkan menu operasi penjumlahan, pengurangan, perkalian matriks 3x3. pengguna diminta untuk memilih menu yang mana kemudian program akan menampilkan hasilnya.

### 2. Konversi angka 0-100 menjadi teks

```C++
#include <iostream>
using namespace std;

int main() {
    int panjang = 10, lebar = 5, luas = 0;
    int keliling = 0;

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << panjang << endl;
    cout << "Lebar Baru: " << lebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan2_Modul2/LAPRAK/Output-Unguided2.png)

program ini merupakan program yang menggunakan pointer untuk menghitung luas dan keliling persegi panjang.

## Kesimpulan
Setelah mengikuti dan mempelajari praktikum pada modul ini saya menyimpulkan bahwa array merupakan struktur data yang digunakan untuk menyimpan sekumpulan elemen dengan tipe data yang sama, dan setiap elemen diakses menggunakan indeks. Pada array satu dimensi, data disusun secara linear, sedangkan array dua dimensi digunakan untuk merepresentasikan data berbentuk tabel atau matriks. Kemudian penggunaan pointer pada program untuk mengakses dan memanipulasi elemen array secara langsung melalui alamat memori, sehingga meningkatkan efisiensi dalam pengolahan data.

## Referensi
Politeknik Negeri Banjarmasin. (2023). Struktur Data pada Logika dan Algoritma Pemrograman. Poliban Press.
https://press.poliban.ac.id/uploads/file/9786237694854.pdf
Universitas Komputer Indonesia (UNIKOM). (2017). Modul Bab VIII: Array.
https://repository.unikom.ac.id/34644/1/Bab%20VIII%20-%20Array.pdf
Syarif, M. H. (2013). Modul VI: Array 2 Dimensi, Pointer dan Struktur. STEI ITB.
https://blog.mhdsyarif.com/wp-content/uploads/2013/11/Modul_VI_ARRAY-2-DIMENSI-POINTER-DAN-STRUKTUR.pdf
