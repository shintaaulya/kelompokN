#include <iostream>

using namespace std;

   int main() {
    Graf G;
    inisialisasiGraf(G);

    tambahPengguna(G, "Alice", "01/01/2000", 23);
    tambahPengguna(G, "Bob", "02/02/1999", 24);
    tambahPengguna(G, "Charlie", "03/03/1998", 25);

    tambahHubungan(G, "Alice", "Bob");
    tambahHubungan(G, "Alice", "Charlie");
    tambahHubungan(G, "Bob", "Charlie");

    cout << "Graf pengguna:\n";
    tampilkanGraf(G);

    cariTerpopuler(G);
    cariTidakTerpopuler(G);

    return 0;
}


