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
