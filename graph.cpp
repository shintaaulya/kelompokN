#include "graph.h"

void inisialisasiGraf(Graf &G) {
    G.jumlahNode = 0;
    for (int i = 0; i < 100; i++) {
        G.first[i] = nullptr;
    }
}

void tambahHubungan(Graf &G, int pengguna1, int pengguna2) {
    Node *baru1 = new Node{pengguna2, G.first[pengguna1};
    G.first[pengguna1] = baru1;

    Node *baru2 = new Node{pengguna1, G.first[pengguna2]};
    G.first[pengguna2] = baru2;
    G.jumlahNode = max(G.jumlahNode, max(pengguna1, pengguna2));
}
