#include "graph.h"

int main() {
    graph G;
    initGraph(G);
    int choice;
    string name, birthDate, name2;
    int age;

    do {
        showMenu();
        cout << "Masukan pilihan: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, name);
                cout << "Masukkan TTL (dd/mm/yyyy): ";
                getline(cin, birthDate);
                cout << "Masukkan umur: ";
                cin >> age;
                addPengguna(G, name, birthDate, age);
                break;

            case 2:
                cout << "Masukkan nama pengguna pertama: ";
                getline(cin, name);
                cout << "Masukkan nama pengguna kedua: ";
                getline(cin, name2);
                if (isPenggunaExist(G, name) && isPenggunaExist(G, name2)) {
                    addTeman(G, name, name2);
                    cout << "Hubungan berhasil ditambahkan." << endl;
                } else {
                    cout << "Salah satu atau kedua pengguna tidak ditemukan." << endl;
                }
                break;

            case 3:
                showAllUsers(G);
                break;

            case 4:
                showMostPopular(G);
                break;
        }
    } while (choice != 5);

    return 0;
}
