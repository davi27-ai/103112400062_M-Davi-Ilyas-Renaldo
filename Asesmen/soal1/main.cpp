#include "sll.h"
#include <limits>
#include <sstream>

using namespace std;

void display_menu() {
    cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
    cout << "Masukkan: ";
}

int main() {
    SinglyLinkedList list;
    
    cout << "=== Program C++ (Singly Linked List) ===" << endl;
    cout << "Soal Nomor 1 (Single Linked List)" << endl;
    cout << "Masukkan nama berikut: insert \"Agung\", insert \"Rizal\", insert \"Rio\", delete \"Rio\", hitung genap." << endl;
    
    int choice;
    string input_line, name;

    cout << "\nMenu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
    cout << "Masukkan: 1" << endl;
    cout << "Masukkan nama: Agung" << endl;
    list.insert_tail("Agung");

    cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
    cout << "Masukkan: 1" << endl;
    cout << "Masukkan nama: Rizal" << endl;
    list.insert_tail("Rizal");

    cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
    cout << "Masukkan: 1" << endl;
    cout << "Masukkan nama: Rio" << endl;
    list.insert_tail("Rio");

    cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
    cout << "Masukkan: 3" << endl;
    list.display_list();

    cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
    cout << "Masukkan: 2" << endl;
    cout << "Masukkan nama untuk delete: Rio" << endl;
    list.delete_first_occurrence("Rio");
    
    cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
    cout << "Masukkan: 3" << endl;
    list.display_list();

    cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
    cout << "Masukkan: 4" << endl;
    int count = list.count_even_length_names();
    cout << "Jumlah nama dengan huruf genap: " << count << endl;

    cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
    cout << "Masukkan: 0" << endl;
    

    return 0;
}