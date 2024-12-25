#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

typedef struct Pengguna *adrPengguna;
typedef struct Teman *adrTeman;

struct Pengguna {
    string name;
    string birthDate;
    int age;
    adrPengguna nextPengguna;
    adrTeman firstTeman;
};

struct Teman {
    adrPengguna destPengguna;
    adrTeman nextTeman;
};

struct graph {
    adrPengguna firstPengguna;
};

void createPengguna(string name, string birthDate, int age, adrPengguna &v);
void initGraph(graph &G);
void addPengguna(graph &G, string name, string birthDate, int age);
void createTeman(adrPengguna &v1, adrPengguna &v2);
void addTeman(graph &G, string name1, string name2);
adrPengguna findPengguna(graph G, string name);
bool isPenggunaExist(graph G, string name);
void showMenu();
void showAllUsers(graph G);
void showUserConnections(graph G, string name);
void showMostPopular(graph G);


#endif // GRAPH_H_INCLUDED
