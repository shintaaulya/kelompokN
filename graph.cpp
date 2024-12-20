#include "graph.h"

void buatPengguna(Pengguna*& nextVertex, string nama, string Ttl, int umur) {
    nextVertex = new Pengguna;
    nextVertex->info.nama = nama;
    nextVertex->info.Ttl = Ttl;
    nextVertex->info.umur = umur;
    nextVertex->nextEdge = nullptr;
    nextVertex->nextVertex = nullptr;
}

void inisialisasiGraf(Graf &G) {
   G.first = nullptr;
}

Pengguna searchPengguna(Graf G, string nama){
    Pengguna temp = G.first;
    if (temp == nullptr) {
        return nullptr
    }else{
        while (temp!= nullptr){
            if (temp -> info.nama == nama){
                return temp;
            }
            temp = temp -> nextPengguna;
        }
        return nullptr;
    }
}


void tambahHubungan(Graf& G, string pengguna1, string pengguna2) {
    Pengguna* p1 = searchPengguna(G, pengguna1);
    Pengguna* p2 = searchPengguna(G, pengguna2);

    if (p1 != nullptr && p2 != nullptr) {
        Teman* temanBaru = new Teman;
        temanBaru->nama = pengguna2;
        temanBaru->nextEdge = p1->nextEdge;
        p1->nextEdge = temanBaru;
    } else {
        cout << "Salah satu atau kedua pengguna tidak ditemukan.\n";
    }
}

void tampilkanGraf(Graf G) {
    Pengguna* temp = G.first;
    while (temp != nullptr) {
        cout << "Nama: " << temp->info.nama << ", Ttl: " << temp->info.Ttl << ", Umur: " << temp->info.umur << endl;
        Teman* edge = temp->nextEdge;
        cout << "Teman: ";
        while (edge != nullptr) {
            cout << edge->nama << " ";
            edge = edge->nextEdge;
        }
        cout << endl;
        temp = temp->nextVertex;
    }
}

void cariTerpopuler(Graf G) {
    Pengguna* temp = G.first;
    string terpopuler;
    int maxHubungan = 0;

    while (temp != nullptr) {
        int count = 0;
        Teman* edge = temp->nextEdge;
        while (edge != nullptr) {
            count++;
            edge = edge->nextEdge;
        }
        if (count > maxHubungan) {
            maxHubungan = count;
            terpopuler = temp->info.nama;
        }
        temp = temp->nextVertex;
    }

    cout << "Pengguna terpopuler: " << terpopuler << " dengan " << maxHubungan << " hubungan." << endl;
}

void cariTidakTerpopuler(Graf G) {
    Pengguna* temp = G.first;
    string tidakTerpopuler;
    int minHubungan = INT_MAX;

    while (temp != nullptr) {
        int count = 0;
        Teman* edge = temp->nextEdge;
        while (edge != nullptr) {
            count++;
            edge = edge->nextEdge;
        }
        if (count < minHubungan) {
            minHubungan = count;
            tidakTerpopuler = temp->info.nama;
        }
        temp = temp->nextVertex;
    }

    cout << "Pengguna tidak terpopuler: " << tidakTerpopuler << " dengan " << minHubungan << " hubungan." << endl;
}

