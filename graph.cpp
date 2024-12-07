#include "graph.h"

void buatPengguna(adr*& nextVertex, string nama, string Ttl, int umur) {
    adr = new Pengguna;
    adr -> info.nama = nama;
    adr -> info.Ttl = Ttl;
    adr -> info.umur = umur;
    adr -> nextTeman = nullptr;
    adr -> nextPengguna = nullptr;
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


void tambahHubungan(Graf &G, string pengguna1, string pengguna2) {
    Pengguna searchPengguna(Graf G, string nama)
    buatPengguna(pengguna1, pengguna2, penggunaBaru);

    if(G.firstPengguna == nullptr) {
        G.firstPengguna = penggunaBaru;
    }else{
        Pengguna* temp = G.firstPengguna;
        while (temp->nextVertex != nullptr) {
            temp = temp->nextVertex;
        }
        temp->nextVertex = penggunaBaru;
    }
}

