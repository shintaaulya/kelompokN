#include "graph.h"

void createPengguna(string name, string birthDate, int age, adrPengguna &v) {
    v = new Pengguna;
    v->name = name;
    v->birthDate = birthDate;
    v->age = age;
    v->firstTeman = NULL;
    v->nextPengguna = NULL;
}

void initGraph(graph &G) {
    G.firstPengguna= NULL;
}

void addPengguna(graph &G, string name, string birthDate, int age) {
    adrPengguna v;
    createPengguna(name, birthDate, age, v);
    if (G.firstPengguna == NULL) {
        G.firstPengguna = v;
    } else {
        adrPengguna lastV = G.firstPengguna;
        while (lastV->nextPengguna != NULL) {
            lastV = lastV->nextPengguna;
        }
        lastV->nextPengguna = v;
    }
}

void createTeman(adrPengguna &v1, adrPengguna &v2) {
    adrTeman newTeman = new Teman;
    newTeman -> destPengguna = v2;
    newTeman -> nextTeman = NULL;

    if (v1->firstTeman == NULL) {
        v1->firstTeman = newTeman;
    } else {
        adrTeman lastTeman = v1->firstTeman;
        while (lastTeman->nextTeman != NULL) {
            lastTeman = lastTeman->nextTeman;
        }
        lastTeman->nextTeman = newTeman;
    }
}

void addTeman(graph &G, string name1, string name2) {
    adrPengguna v1 = findPengguna(G, name1);
    adrPengguna v2 = findPengguna(G, name2);

    if (v1 != NULL && v2 != NULL) {
        createTeman(v1, v2);
        createTeman(v2, v1);
    }
}

adrPengguna findPengguna(graph G, string name) {
    adrPengguna curr = G.firstPengguna;
    while (curr != NULL) {
        if (curr->name == name) {
            return curr;
        }
        curr = curr->nextPengguna;
    }
    return NULL;
}

bool isPenggunaExist(graph G, string name) {
    return findPengguna(G, name) != NULL;
}

void showMenu() {
    cout << "=====================================\n";
    cout << "              Menu Utama             \n";
    cout << "=====================================\n";
    cout << "1. Tambah Pengguna\n";
    cout << "2. Tambah Hubungan\n";
    cout << "3. Tampilkan Graf\n";
    cout << "4. cari Pengguna Terpopuler\n";
    cout << "5 Keluar\n";
    cout << "=====================================\n";
}

void showAllUsers(graph G) {
    adrPengguna curr = G.firstPengguna;
    while (curr != NULL) {
        cout << "Pengguna: " << curr->name << " (" << curr->age << " tahun, TTL: " << curr->birthDate << ")" << endl;
        cout << "Teman:" << endl;

        adrTeman Teman = curr->firstTeman;
        while (Teman != NULL) {
            cout << "- " << Teman->destPengguna->name << endl;
            Teman = Teman->nextTeman;
        }
        cout << endl;
        curr = curr->nextPengguna;
    }
}

void showMostPopular(graph G) {
    adrPengguna curr = G.firstPengguna;
    adrPengguna mostPopular = NULL;
    int maxFriends = -1;

    while (curr != NULL) {
        int friendCount = 0;
        adrTeman Teman = curr->firstTeman;
        while (Teman != NULL) {
            friendCount++;
             Teman = Teman->nextTeman;
        }

        if (friendCount > maxFriends) {
            maxFriends = friendCount;
            mostPopular = curr;
        }
        curr = curr->nextPengguna;
    }

    if (mostPopular != NULL) {
        cout << "Pengguna terpopuler adalah: " << mostPopular->name
             << " dengan " << maxFriends << " teman." << endl;
    }
}
