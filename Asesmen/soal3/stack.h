#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> 

using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
    float NilaiAkhir; 
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int top;
};

bool isEmpty(const StackMahasiswa& S);
bool isFull(const StackMahasiswa& S);

void createStack(StackMahasiswa& S);
void Push(StackMahasiswa& S, const Mahasiswa& inputData);
bool Pop(StackMahasiswa& S, Mahasiswa& outputData);
void Update(StackMahasiswa& S, int posisi, const Mahasiswa& newData);
void View(const StackMahasiswa& S);

void SearchNilaiAkhir(const StackMahasiswa& S, float NilaiAkhirMin, float NilaiAkhirMax);

void MaxNilaiAkhir(const StackMahasiswa& S);

#endif