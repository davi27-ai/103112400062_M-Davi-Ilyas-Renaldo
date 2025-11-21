# <h1 align="center">Laporan Praktikum Modul 7 - Stack </h1>
<p align="center">M-Davi-Ilyas-Renaldo - 103112400062</p>

## Dasar Teori
Stack didefinisikan sebagai struktur data linear abstrak (Abstract Data Type/ADT) yang menerapkan mekanisme akses dan manipulasi data yang sangat ketat, yaitu hanya melalui satu titik yang disebut Top, serta tunduk pada prinsip LIFO (Last In, First Out), yang berarti elemen data yang terakhir kali dimasukkan adalah yang akan pertama kali dikeluarkan. Operasi esensial yang harus dimiliki sebuah stack adalah push untuk penambahan elemen ke puncak, pop untuk penghapusan dan pengambilan elemen teratas, serta peek atau top untuk inspeksi elemen puncak tanpa menghapusnya. Dalam implementasinya pada bahasa C++, stack dapat direalisasikan secara statis menggunakan Array dengan batasan ukuran, atau secara dinamis menggunakan Linked List yang lebih fleksibel. Penerapan konsep stack sangat krusial dalam dunia komputasi, antara lain untuk mengatur urutan eksekusi fungsi (call stack), mengkonversi dan mengevaluasi ekspresi aritmatika, serta dalam proses backtracking.

## Guided 
### 1. stack dan linked list
#### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL    

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif 
```
#### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program C++ ini mengelola struktur stack menggunakan linked list, di mana stack bekerja dengan prinsip LIFO (Last In, First Out) sehingga data yang dimasukkan terakhir akan diambil terlebih dahulu. Setiap elemen stack disimpan dalam sebuah node yang berisi nilai dan pointer ke node berikutnya. Program ini menyediakan fungsi-fungsi utama seperti createStack() untuk membuat stack baru, alokasi() untuk membuat node, push() untuk menambah data, pop() untuk menghapus data teratas, update() untuk mengubah nilai pada posisi tertentu, view() untuk menampilkan seluruh data, dan searchData() untuk mencari nilai tertentu di dalam stack, sehingga pengelolaan data menjadi lebih terstruktur dan mudah dilakukan.

### 2.stack dengan array
#### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct stack {
    infotype info[MaxEl];//Array unutk menyimpan elemen stack
    int top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype X); //Menambahkan elemen ke dalam stack
infotype pop(stack &S); //Mengambil elemn teratas dari stack
void printinfo(stack S); //Menampilkan isi stack
void balikStack(stack &S); //Membalik urutan elemen dalam stack
#endif
```
#### stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void createStack(stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printinfo(stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        stack temp1, temp2;  // Deklarasi dua stack temporary
        createStack(temp1); createStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printinfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printinfo(S);

    return 0;
}
```
Program C++ ini dirancang untuk mengimplementasikan struktur data Stack (Tumpukan) melalui Linked List (Daftar Berantai). Stack beroperasi dengan prinsip LIFO (Last In, First Out), yang berarti elemen data yang terakhir kali dimasukkan adalah yang akan pertama kali dikeluarkan. Implementasi ini menggunakan pointer untuk menghubungkan setiap node (simpul), di mana setiap node terdiri dari sebuah nilai data dan sebuah pointer yang menunjuk ke node berikutnya dalam tumpukan.

## Unguided 
### 1. main stack
#### stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack\n";
    balikStack(S);
    printInfo(S);

    return 0;
}
```

#### stack.h
```C++
#ifndef STACK1_H
#define STACK1_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif
```

#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack\n";
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 1:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan7_Modul7/LAPRAK/Output-Unguided1.png)
Program C++ ini mengimplementasikan struktur data Stack (Tumpukan) menggunakan Array statis, menyediakan fungsi-fungsi esensial seperti menambah data (push), menghapus data (pop), menampilkan seluruh isi stack, dan fitur khusus untuk membalik urutan elemen di dalamnya; alur program dimulai dengan menginisialisasi stack menjadi kosong, diikuti dengan memasukkan serangkaian nilai data, kemudian mengeluarkan sebagian data, lalu menampilkan sisa isi stack, dan diakhiri dengan menunjukkan perubahan posisi data setelah pembalikan urutan elemen yang dilakukan dengan bantuan stack temporer.

### 2. main stack dengan push ascending
#### stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) { S.top = -1; }
bool isEmpty(const Stack &S) { return S.top == -1; }
bool isFull(const Stack &S) { return S.top == MaxEl - 1; }

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh\n";
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) cout << S.info[i] << " ";
    cout << endl;
}

void balikStack(Stack &S) {
    Stack T;
    createStack(T);
    while (!isEmpty(S)) push(T, pop(S));
    S = T;
}

void pushAscending(Stack &S, infotype x) {
    Stack Temp;
    createStack(Temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(Temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(Temp)) {
        push(S, pop(Temp));
    }
}
```

#### stack.h
```C++
#ifndef STACK2_H
#define STACK2_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif
```

#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack\n";
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 2:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan7_Modul7/LAPRAK/Output-Unguided2.png)

Program C++ ini dirancang untuk mengelola struktur data Stack dengan menambahkan fungsionalitas penyisipan terurut melalui fungsi pushAscending. Inti dari fungsi ini adalah memastikan bahwa setiap nilai baru yang dimasukkan akan ditempatkan pada posisi yang benar sehingga seluruh elemen di dalam stack selalu tersusun dalam urutan menaik (ascending), tanpa perlu menjalankan algoritma pengurutan terpisah.

### 3. main stack dengan input stream
#### stack.cpp
```C++
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

void createStack(Stack &S) { S.top = -1; }
bool isEmpty(const Stack &S) { return S.top == -1; }
bool isFull(const Stack &S) { return S.top == MaxEl - 1; }

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh\n";
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) cout << S.info[i] << " ";
    cout << endl;
}

void balikStack(Stack &S) {
    Stack T;
    createStack(T);
    while (!isEmpty(S)) push(T, pop(S));
    S = T;
}

void getInputStream(Stack &S) {
    string line;
    cout << "";

    getline(cin, line);
    if (line.size() == 0) getline(cin, line);

    for (char c : line) {
        if (c >= '0' && c <= '9') push(S, c - '0');
    }
}
```

#### stack.h
```C++
#ifndef STACK3_H
#define STACK3_H

#define MaxEl 20
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif
```

#### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    getInputStream(S);

    printInfo(S);

    cout << "balik stack\n";
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output Unguided 3:
##### Output
![Screenshot Output Unguided](https://github.com/davi27-ai/103112400062_M-Davi-Ilyas-Renaldo/blob/main/Pertemuan7_Modul7/LAPRAK/Output-Unguided3.png)

Program C++ ini dirancang untuk membaca satu baris masukan dari pengguna, di mana setiap karakter digit yang terbaca akan dikonversi menjadi nilai bilangan dan langsung dimasukkan ke dalam struktur data Stack mengikuti urutan inputnya; setelah input selesai, program akan menampilkan isi stack yang telah terbentuk dan kemudian mendemonstrasikan manipulasi data dengan membalik urutan elemen menggunakan fungsi balikStack, sehingga secara keseluruhan program ini memperlihatkan bagaimana data dari masukan pengguna dapat secara efektif disimpan, diolah, dan disusun ulang berdasarkan prinsip kerja LIFO dari stack.

## Kesimpulan
Program C++ ini bertujuan untuk menangani masukan sebaris dari pengguna; di dalamnya, setiap digit karakter yang diterima akan segera dikonversi menjadi nilai numerik yang kemudian disimpan secara berurutan ke dalam struktur Stack (Tumpukan); setelah selesai memproses masukan tersebut, program akan menayangkan isi akhir dari stack dan melanjutkan dengan mendemonstrasikan penyusunan ulang data melalui fungsi balikStack untuk membalikkan urutan elemen-elemennya. Secara keseluruhan, program ini menyajikan ilustrasi bagaimana data yang berasal dari interaksi pengguna dapat secara efisien diakumulasi, dimanipulasi, dan diubah urutannya dengan memanfaatkan karakteristik LIFO (Last In, First Out) dari stack.

## Referensi
1. Munir, Rinaldi. (2016). Algoritma dan Pemrograman. Bandung: Informatika Bandung.
2. Rosa, A.S., & Salahuddin, M. (2013). Modul Pembelajaran Rekayasa Perangkat Lunak (Terstruktur dan Berorientasi Objek). Bandung: Modula.
3. Wahyudin, A. (2014). Struktur Data. Yogyakarta: Andi Offset.
4. Sismoro, Edy. (2005). Pengantar Basis Data. Yogyakarta: Andi Offset.