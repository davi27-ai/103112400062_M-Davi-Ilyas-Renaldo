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