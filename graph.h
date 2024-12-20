#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

struct data {
    string nama;
    string Ttl;
    int umur;
};

struct Teman {
    string nama;
    Teman* nextEdge;
};

struct Pengguna {
     data info;
    Pengguna* nextVertex;
    Teman* nextEdge;
};

struct Graf {
    Pengguna* first;
};

void buatPengguna(Pengguna*& nextVertex, string nama, string Ttl, int umur);
void inisialisasiGraf(Graf& G);
void tambahPengguna(Graf &G, string nama, string Ttl, int umur);
void tambahHubungan(Graf &G, string pengguna1, string pengguna2);
Pengguna searchPengguna(Graf G, string nama);
void tampilkanGraf(Graf G);
void cariTerpopuler(Graf G);
void cariTidakTerpopuler(Graf G);

#endif // GRAPH_H
