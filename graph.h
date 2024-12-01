#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Graf {
    Node *first[100];
    int jumlahNode;
};

void inisialisasiGraf(Graf &G);
void tambahHubungan(Graf &G, int pengguna1, int pengguna2);
void tampilkanGraf(Graf G, int pengguna = -1);
void cariKomunitas(Graf &G, bool *dikunjungi);
void eksplorasiKomunitas(Graf &G, int pengguna, bool *dikunjungi, string &komunitas);

#endif // GRAPH_H
