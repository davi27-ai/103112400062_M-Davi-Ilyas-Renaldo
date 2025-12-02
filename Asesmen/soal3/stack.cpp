#include "stack.h"

float hitungNilaiAkhir(float tugas, float uts, float uas) {
    return (0.20f * tugas) + (0.40f * uts) + (0.40f * uas);
}

bool isEmpty(const StackMahasiswa& S) {
    return S.top == -1;
}

bool isFull(const StackMahasiswa& S) {
    return S.top == MAX - 1;
}

void createStack(StackMahasiswa& S) {
    S.top = -1;
}

void Push(StackMahasiswa& S, const Mahasiswa& inputData) {
    if (isFull(S)) {
        return;
    }
    
    Mahasiswa dataToPush = inputData;
    dataToPush.NilaiAkhir = hitungNilaiAkhir(dataToPush.NilaiTugas, dataToPush.NilaiUTS, dataToPush.NilaiUAS);

    S.top++;
    S.dataMahasiswa[S.top] = dataToPush;
}

bool Pop(StackMahasiswa& S, Mahasiswa& outputData) {
    if (isEmpty(S)) {
        return false;
    }
    outputData = S.dataMahasiswa[S.top];
    S.top--;
    return true;
}

void Update(StackMahasiswa& S, int posisi, const Mahasiswa& newData) {
    int index = posisi - 1; 

    if (index < 0 || index > S.top) {
        return;
    }

    Mahasiswa dataToUpdate = newData;
    dataToUpdate.NilaiAkhir = hitungNilaiAkhir(dataToUpdate.NilaiTugas, dataToUpdate.NilaiUTS, dataToUpdate.NilaiUAS);

    S.dataMahasiswa[index] = dataToUpdate;
}

void View(const StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }

    cout << setprecision(2) << fixed;
    cout << "--- Isi Stack (Pos | Nama | Nilai Akhir) ---" << endl;
    
    for (int i = 0; i <= S.top; i++) {
        const Mahasiswa& m = S.dataMahasiswa[i];
        cout << setw(3) << i + 1 
             << " | " << setw(10) << left << m.Nama 
             << " | " << setw(7) << m.NilaiAkhir 
             << (i == S.top ? " <--- TOP" : "") << endl;
    }
    cout << "----------------------------------" << endl;
}

void SearchNilaiAkhir(const StackMahasiswa& S, float NilaiAkhirMin, float NilaiAkhirMax) {
    cout << "\n--- Hasil Pencarian Nilai Akhir [" << NilaiAkhirMin << ", " << NilaiAkhirMax << "] ---" << endl;
    
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }

    bool found = false;
    
    for (int i = 0; i <= S.top; i++) {
        const Mahasiswa& m = S.dataMahasiswa[i];
        
        if (m.NilaiAkhir >= NilaiAkhirMin && m.NilaiAkhir <= NilaiAkhirMax) {
            cout << "Ditemukan: " << m.Nama 
                 << ", Posisi: " << i + 1 
                 << ", Nilai Akhir: " << m.NilaiAkhir << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Tidak ditemukan data dalam rentang tersebut." << endl;
    }
    cout << "--------------------------------------------------------" << endl;
}

void MaxNilaiAkhir(const StackMahasiswa& S) {
    cout << "\n--- Nilai Akhir Terbesar ---" << endl;
    
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }

    float max_nilai = -1.0f;
    int max_posisi = -1;

    for (int i = 0; i <= S.top; i++) {
        if (S.dataMahasiswa[i].NilaiAkhir > max_nilai) {
            max_nilai = S.dataMahasiswa[i].NilaiAkhir;
            max_posisi = i;
        }
    }
    
    if (max_posisi != -1) {
        const Mahasiswa& m = S.dataMahasiswa[max_posisi];
        cout << "Nama: " << m.Nama 
             << ", Posisi: " << max_posisi + 1 
             << ", Nilai Akhir: " << m.NilaiAkhir << endl;
    }
}