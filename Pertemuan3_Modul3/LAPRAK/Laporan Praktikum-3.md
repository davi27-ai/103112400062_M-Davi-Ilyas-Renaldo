# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">M-Davi-Ilyas-Renaldo - 103112400062</p>

## Dasar Teori
## 1. Abstract Data Type (ADT)
Abstract Data Type (ADT) merupakan konsep penting dalam pemrograman yang memisahkan antara definisi logis suatu tipe data dengan implementasi fisiknya. ADT berfokus pada apa yang dilakukan suatu tipe data, bukan bagaimana cara melakukannya. Dalam bahasa C++, ADT dapat diimplementasikan menggunakan struct atau class, di mana keduanya berisi data dan fungsi untuk memproses data tersebut Penerapan ADT membantu dalam abstraksi data, enkapsulasi, dan modularitas, sehingga program menjadi lebih efisien dan mudah dikelola Pada praktikum ini, konsep ADT diterapkan melalui pembuatan program yang menggunakan struct mahasiswa dan pelajaran sebagai representasi data abstrak, di mana setiap operasi dilakukan melalui fungsi terpisah seperti inputMhs(), rata2(), create_pelajaran(), dan tampil_pelajaran().

## 2. Struct dalam C++
struct atau struktur digunakan untuk mengelompokkan beberapa variabel dengan tipe data berbeda ke dalam satu kesatuan. Dengan menggunakan struct, data yang memiliki hubungan logis dapat disatukan menjadi satu tipe data baru. Dalam praktikum ini, struct mahasiswa menyimpan data seperti nama, NIM, dan nilai, sedangkan struct pelajaran menyimpan nama dan kode mata pelajaran. Struct ini menjadi dasar dari penerapan Abstract Data Type, karena membungkus data terkait dalam satu entitas terpisah. Selain itu, penggunaan struct juga membantu dalam membangun program yang lebih terstruktur dan terorganisir, terutama ketika dikombinasikan dengan fungsi untuk mengelola data tersebut.

## 3. Fungsi dan Modularitas Program
Fungsi adalah blok kode yang digunakan untuk menjalankan tugas tertentu dan dapat dipanggil berulang kali dari bagian lain program. Penggunaan fungsi menjadikan program bersifat modular, artinya dapat dibagi menjadi bagian-bagian kecil yang memiliki tanggung jawab spesifik. Dalam laporan ini, fungsi digunakan untuk melakukan berbagai operasi seperti: Menginput dan menghitung rata-rata nilai mahasiswa, Menghitung nilai akhir mahasiswa dari bobot UTS, UAS, dan tugas, Membuat dan menampilkan data mata pelajaran, Menukar nilai pada matriks menggunakan fungsi tukarArray dan tukarPointer.

## 4. Array dan Pointer
Array merupakan struktur data yang menyimpan sekumpulan elemen dengan tipe data yang sama dalam satu variabel. Dalam laporan ini digunakan array dua dimensi (3x3) untuk menyimpan data dalam bentuk matriks. Pointer, di sisi lain, merupakan variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, program dapat memanipulasi nilai secara langsung di memori, sehingga operasi seperti pertukaran data dapat dilakukan lebih efisien. Pada praktikum ini, pointer diterapkan dalam fungsi tukarPointer untuk menukar nilai dua variabel secara langsung melalui alamat memorinya. Hal ini memperlihatkan bagaimana pointer berperan penting dalam efisiensi dan fleksibilitas pengelolaan memori di C++.

## Guided 

### 1. Data mahasiswa dengan struct
#### mahasiswa.h
```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

struct mahasiswa{
    char nim[10];
    int nilai1,nilai2;
};
void inputMhs(mahasiswa&m);
float rata2(mahasiswa m);

#endif
```
#### mahasiswa.cpp
```C++
#include<iostream>
#include"mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa&m){
    cout<<"input NIM:";
    cin>>m.nim;
    cout<<"input nilai1:";
    cin>>m.nilai1;
    cout<<"input nilai2:";
    cin>>m.nilai2;
}

float rata2(mahasiswa m){
    return(float)(m.nilai1+m.nilai2)/2;
}
```
#### main.cpp
```C++
#include<iostream>
#include"mahasiswa.h"
#include<cstdlib>

using namespace std;

int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout<<"Rata-rata nilai adalah:"<<rata2(mhs)<<endl;
    system("pause");

    return 0;
}
```
Program C++ ini memanfaatkan struct dan fungsi untuk mengelola data mahasiswa, dengan pembagian kode ke dalam tiga berkas terpisah: Mahasiswa.h (deklarasi struct), Mahasiswa.cpp (implementasi fungsi), dan main.cpp (program utama).

## Unguided 

### 1. Data nilai mahasiswa

```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3f*uts + 0.4f*uas + 0.3f*tugas;
}

int main() {
    Mahasiswa m[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (1-10): ";
    cin >> n;
    if (n < 1) return 0;
    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << (i+1) << endl;
        cout << "Nama  : ";
        cin >> m[i].nama;     
        cout << "NIM   : ";
        cin >> m[i].nim;
        cout << "UTS   : ";
        cin >> m[i].uts;
        cout << "UAS   : ";
        cin >> m[i].uas;
        cout << "Tugas : ";
        cin >> m[i].tugas;

        m[i].nilaiAkhir = hitungNilaiAkhir(m[i].uts, m[i].uas, m[i].tugas);
    }
    
    cout << "\n=== Daftar Nilai Akhir ===\n";
    for (int i = 0; i < n; i++) {
        cout << (i+1) << ". "
             << m[i].nim << "     "
             << m[i].nama << "     "
             << m[i].uts << "   "
             << m[i].uas << "   "
             << m[i].tugas << "   "
             << "   " << m[i].nilaiAkhir << "\n";
    }
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan3_Modul3/LAPRAK/Output-Unguided1.png)

Program ini digunakan untuk mengelola data nilai mahasiswa. Pengguna dapat memasukkan informasi beberapa mahasiswa berupa nama, NIM, dan nilai, kemudian program akan menghitung nilai akhir berdasarkan bobot UTS, UAS, dan tugas, lalu menampilkan hasil perhitungannya.

### 2. Implementasi ADT data mata pelajaran

```C++
#include <iostream>
#include <string>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodeMapel);
void tampil_pelajaran(pelajaran pel);

pelajaran create_pelajaran(string namaMapel, string kodeMapel) {
    pelajaran pel;
    pel.namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "kode mapel : " << pel.kodeMapel << endl;
}

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan3_Modul3/LAPRAK/Output-Unguided2.png)

Program ini memperlihatkan penerapan struct dan fungsi dalam pengelolaan data mata pelajaran. Struct Pelajaran digunakan untuk menyimpan nama serta kode mata pelajaran, kemudian data tersebut diinisialisasi dan ditampilkan melalui fungsi yang terpisah.

### 3. pertukaran elemen matriks

```C++
#include <iostream>
using namespace std;

void tampilkanArray(const int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {

    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int baris, kolom;

    cout << "Array A Awal:" << endl;
    tampilkanArray(arrayA);
    cout << "Array B Awal:" << endl;
    tampilkanArray(arrayB);
    cout << endl;

    cout << "Masukkan posisi yang akan ditukar:" << endl;
    cout << "Baris (0-2): ";
    cin >> baris;
    cout << "Kolom (0-2): ";
    cin >> kolom;

    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        cout << "\nMenukar nilai pada posisi [" << baris << "][" << kolom << "]..." << endl;
        cout << "Nilai awal: Matriks A = " << arrayA[baris][kolom] << ", Matriks B = " << arrayB[baris][kolom] << endl;

        tukarArray(arrayA, arrayB, baris, kolom);
        cout << "\nArray A Setelah Ditukar:" << endl;
        tampilkanArray(arrayA);
        cout << "Array B Setelah Ditukar:" << endl;
        tampilkanArray(arrayB);
    } else {
        cout << "Posisi yang dimasukkan tidak valid." << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan3_Modul3/LAPRAK/Output-Unguided3.png)

Program ini memperlihatkan proses pertukaran elemen antara dua matriks 2D berukuran 3x3. Pengguna diminta memasukkan posisi berupa baris dan kolom, kemudian program menukar nilai pada posisi tersebut di kedua matriks dan menampilkan hasil akhirnya.

## Kesimpulan
Dari praktikum ini, saya memahami cara mengelola data menggunakan struct, fungsi, array, dan pointer dalam bahasa C++. Penerapan konsep Abstract Data Type (ADT) membantu membuat program lebih terstruktur dan mudah dipahami. Selain itu, penggunaan fungsi terpisah dan array dua dimensi menunjukkan pentingnya modularitas dan efisiensi dalam pengolahan data.

## Referensi
1. Malik, D. S. (2018). C++ Programming: From Problem Analysis to Program Design (8th Edition). Cengage Learning.
2. Rahman, M. A. (2021). “Analisis Konsep Abstract Data Type (ADT) dalam Pemrograman Berorientasi Objek.” Jurnal Teknologi Informasi dan Ilmu Komputer (JTIIK), 8(3). https://jtiik.ub.ac.id/
3. Siregar, R. (2022). “Penerapan Modularitas dalam Pemrograman C++.” Jurnal Ilmiah Teknologi dan Rekayasa, 5(2). https://ejournal.itn.ac.id/