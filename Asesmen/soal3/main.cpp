#include "stack.h"

Mahasiswa createMahasiswa(string nama, string nim, float tugas, float uts, float uas) {
    Mahasiswa m;
    m.Nama = nama;
    m.NIM = nim;
    m.NilaiTugas = tugas;
    m.NilaiUTS = uts;
    m.NilaiUAS = uas;
    return m;
}

int main() {
    StackMahasiswa S;
    Mahasiswa tempMahasiswa;

    cout << "=== Program ADT Stack (Array) Ringkas ===" << endl;
    
    cout << "\n[1] Create Stack:" << endl;
    createStack(S);

    Mahasiswa dataMhs[6] = {
        createMahasiswa("Venti", "11111", 75.7f, 82.1f, 65.5f),    
        createMahasiswa("Xiao", "22222", 87.4f, 88.9f, 81.9f),      
        createMahasiswa("Kazuha", "33333", 92.3f, 88.8f, 82.4f),    
        createMahasiswa("Wanderer", "44444", 95.5f, 85.5f, 90.5f),  
        createMahasiswa("Lynette", "55555", 77.7f, 65.4f, 79.9f),   
        createMahasiswa("Chasca", "66666", 99.9f, 93.6f, 87.3f)     
    };

    cout << "\n[2] Push 6 Data..." << endl;
    for (int i = 0; i < 6; ++i) {
        Push(S, dataMhs[i]);
    }
    
    cout << "\n[3] Stack Setelah 6x Push:" << endl;
    View(S);

    cout << "\n[4] Pop 1x..." << endl;
    Pop(S, tempMahasiswa);

    cout << "\n[5] Stack Setelah 1x Pop:" << endl;
    View(S);

    Mahasiswa dataUpdate = createMahasiswa("Heizou", "77777", 99.9f, 88.8f, 77.7f); 

    cout << "\n[6] Update Posisi ke 3 (menjadi Heizou)..." << endl;
    Update(S, 3, dataUpdate);

    cout << "\n[7] Stack Setelah Update:" << endl;
    View(S);
    
    cout << "\n[8] Search Nilai Akhir [85.5, 95.5]:" << endl;
    SearchNilaiAkhir(S, 85.5f, 95.5f);
    
    cout << "\n[B] Max Nilai Akhir:" << endl;
    MaxNilaiAkhir(S);

    cout << "\nProgram Selesai." << endl;

    return 0;
}