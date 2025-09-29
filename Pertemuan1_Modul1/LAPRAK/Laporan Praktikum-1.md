# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
Bahasa pemrograman C++ merupakan pengembangan dari bahasa C yang dilengkapi dengan konsep pemrograman berorientasi objek serta fitur tambahan seperti operator overloading dan manajemen memori dinamis, sehingga sering digunakan dalam pengembangan aplikasi sistem maupun umum [1]. Pada pembelajaran dasar C++, salah satu materi utama adalah operasi aritmatika (penjumlahan, pengurangan, perkalian, pembagian) serta operator modulus untuk menghitung sisa bagi, yang menjadi fondasi bagi perhitungan logika program [2]. Selain itu, struktur kontrol seperti percabangan if-else maupun switch-case berfungsi untuk menentukan alur eksekusi program berdasarkan kondisi tertentu [3]. Pemahaman kontrol alur ini kemudian dilengkapi dengan perulangan (for, while, do-while) yang memungkinkan instruksi dijalankan berulang kali untuk membangun pola maupun melakukan perhitungan berulang [4]. Berbagai penelitian juga menunjukkan bahwa penggunaan media pembelajaran berbasis modul dalam pengajaran C++ efektif meningkatkan pemahaman mahasiswa terhadap struktur program, operasi dasar, percabangan, dan perulangan melalui pendekatan yang lebih sistematis dan interaktif [5].

## Guided 

### 1. I/O dasar

```C++
s#include <iostream>
using namespace std;

int main(){
 int angka ;
 cout << "masukan angka : " << endl;
 cin >> angka ;
 cout << "angka yang dimasukan : " << angka << endl;
 return 0;
}
```
program ini merupakan program yang meminta pengguna untuk memasukkan sebuah angka kemudian program ini akan mencetak angka masukkan tersebut ke layar.

### 2. Kalkulator sederhana

```C++
#include <iostream>
using namespace std;
int main() {
    int angka1, angka2;
    cout << "masukkan angka1 :";
    cin >> angka1;
    cout << "masukkan angka2:";
    cin >> angka2;

    cout << "penjumlahan :" << angka1 + angka2 << endl;
    cout << "pengurangan :" << angka1 - angka2 << endl;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian :" << angka1 / angka2 << endl;
    cout << "sisa bagi :" << angka1 % angka2 << endl;
    return 0;
}
```
program ini merupakan program yang mengoperasikan kalkulator sederhana.

### 3. Percabangan if/else

```C++
#include<iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    if (angka1 > angka2 ) {
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << " angka berbeda " << endl;
    }

     int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "masukan pilihan: ";
    cin >> pilihan;

    switch (pilihan){
        case 1:
        cout << "Penjumlahan :" << angka1 + angka2 << endl;
        cout << endl;
        break; 
        case 2:
        cout << "Pengurangan :" << angka1 - angka2 << endl;
        cout << endl;
        break;
        default:
        cout << "Pilihan Salah" << endl;

    }
    return 0;
}
```
Program ini merupakan program untuk perbandingan dua angka dan operasi aritmatika (penjumlahan/pengurangan) berdasarkan menu.

### 4. Perulangan

```C++
#include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
    
 }
```
program ini merupakan program yang dapat mendemonstrasikan tiga jenis perulangan.

### 5. Rapor siswa

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX = 5;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << endl;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
    }

    int j = 0;
    while(j < MAX){
        cout << "nama siswa : " << siswa[j].nama << ", nilai : " << siswa[j].nilai << endl;
    }
    return 0;
}
```
program ini merupakan program yang dibuat untuk menyimpan dan menampilkan nama serta nilai siswa.

## Unguided 

### 1. Kalkulator sederhana

```C++
#include <iostream>
using namespace std;
int main() {
    int angka1, angka2;
    cout << "masukkan angka1 :";
    cin >> angka1;
    cout << "masukkan angka2:";
    cin >> angka2;

    cout << "penjumlahan :" << angka1 + angka2 << endl;
    cout << "pengurangan :" << angka1 - angka2 << endl;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian :" << angka1 / angka2 << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan1_Modul1/LAPRAK/Output-Unguided1.png)

program ini merupakan program kalkulator sederhana yang bisa melakukan (penjumlahan, pengurangan, perkalian, pembagian) berdasarkan angka yang dimasukkan oleh pengguna.

### 2. Konversi angka 0-100 menjadi teks

```C++
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka (0 s.d 100): ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "luar jangkauan!" << endl;
        return 0;
    }

    string hasil;
    string satuan[]  = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", 
                        "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", 
                        "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    switch (n) {
        case 0:
            hasil = "nol";
            break;
        case 100:
            hasil = "seratus";
            break;

        case 10 ... 19:   
            hasil = belasan[n - 10];
            break;

        default:
            if (n < 10) { 
                hasil = satuan[n];
            } else { 
                int p = n / 10;
                int s = n % 10;
                hasil = puluhan[p];
                if (s != 0) {
                    hasil += " " + satuan[s];
                }
            }
    }

    cout << hasil << endl;
    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan1_Modul1/LAPRAK/Output-Unguided2.png)

program ini merupakan program yang mencetak nilai angka ke dalam bentuk tulisan berdasarkan angka yang dimasukkan oleh pengguna

### 3. Pola iterasi

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;

    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < n - i; s++) {
            cout << "  "; 
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "*";

        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }
        cout << endl;
    }

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan1_Modul1/LAPRAK/Output-Unguided3.png)

Program ini merupakan program yang digunakan untuk mencetak segitiga terbalik sesuai angka yang dimasukkan oleh pengguna.

## Kesimpulan
Setelah mempelajari dan menyelesaikan tugas dari modul ini saya dapat sedikit lebih memahami terkait pemograman bahasa C++

## Referensi
[1] Bahasa Pemrograman C++. (2023). Jurnal Majemuk, Vol. 23(2), hlm. 55–62.
Link: https://jurnalilmiah.org/journal/index.php/majemuk/article/download/664/483/1442
<br>[2] Indahyati, U., & Yunianita, R. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press.
DOI: https://doi.org/10.21070/2020/978-623-6833-67-4
<br>[3] Gede Indrawan, I., & Suryawan, A. (2014). Media Pembelajaran Bahasa Pemrograman C++ untuk Siswa SMK. Jurnal Pendidikan Teknik dan Kejuruan, Universitas Pendidikan Ganesha.
Link: https://ejournal.undiksha.ac.id/index.php/JPTK/article/download/31/25/94
<br>[4] Jurusan Teknik Elektro UM. (2016). Modul Praktikum Dasar Pemrograman: Pengenalan Pemrograman C++. Universitas Negeri Malang.
Link: https://elektro.um.ac.id/wp-content/uploads/2016/04/Dasar-Pemrograman-Modul-1-Pengenalan-Pemrograman.pdf
<br>[5] Suryanto, A., & Lestari, D. (2021). Pengembangan Media Pembelajaran Interaktif untuk Algoritma dan Pemrograman C++. Jurnal Algo, Vol. 18(1), hlm. 45–52.
Link: https://id.scribd.com/document/659718513/Jurnal-Algo-Media-Pembelajaran-Bahasa-c-1