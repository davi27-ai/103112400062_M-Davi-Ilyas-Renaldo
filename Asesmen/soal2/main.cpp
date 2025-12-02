#include "dll.h"
#include <limits>
#include <sstream>

using namespace std;

void print_menu_line() {
    cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
}

int main() {
    DoublyLinkedList list;
    
    print_menu_line();
    cout << "Masukkan: 1" << endl;
    cout << "Masukkan nilai: 5" << endl;
    list.insert_tail(5);
    
    print_menu_line();
    cout << "Masukkan: 0" << endl;
    
    print_menu_line();
    cout << "Masukkan: 1" << endl;
    cout << "Masukkan nilai: 5" << endl;
    list.insert_tail(5);
    
    print_menu_line();
    cout << "Masukkan: 1" << endl;
    cout << "Masukkan nilai: 10" << endl;
    list.insert_tail(10);
    
    print_menu_line();
    cout << "Masukkan: 1" << endl;
    cout << "Masukkan nilai: 15" << endl;
    list.insert_tail(15);
    
    print_menu_line();
    cout << "Masukkan: 1" << endl;
    cout << "Masukkan nilai: 20" << endl;
    list.insert_tail(20);
    
    print_menu_line();
    cout << "Masukkan: 3" << endl;
    cout << "List: "; 
    list.display_forward();

    print_menu_line();
    cout << "Masukkan: 2" << endl;
    cout << "List setelah di-delete (last):" << endl;
    list.delete_tail(); 

    print_menu_line();
    cout << "Masukkan: 3" << endl;
    cout << "List: ";
    list.display_forward(); 

    print_menu_line();
    cout << "Masukkan: 4" << endl;
    list.reverse_list();
    cout << "List setelah di-reverse: ";
    list.display_forward();

    print_menu_line();
    cout << "Masukkan: 0" << endl;

    return 0;
}