#include <iostream>
#include <vector>

using namespace std;

class HashTable {
    int Tsize;
    vector<int> table;

public:
    HashTable(int size);
    void insert(int key);
    void displayHash();
};

HashTable::HashTable(int size) {
    Tsize = size;
    table.resize(Tsize, -1); // Inisialisasi tabel hash dengan -1 (menandakan kosong)
}

void HashTable::insert(int key) {
    int hashIndex = key % Tsize;
    int i = 1;

    // Quadratic probing
    while (table[hashIndex] != -1) {
        hashIndex = (hashIndex + i * i) % Tsize;
        i++;
    }
    table[hashIndex] = key;
}

void HashTable::displayHash() {
    for (int i = 0; i < Tsize; i++) {
        if (table[i] != -1)
            cout << i << " --> " << table[i] << endl;
        else
            cout << i << endl;
    }
}

int main() {
    int keys[] = {0, 15, 16, 20, 30, 25, 26, 36};
    int n = sizeof(keys) / sizeof(keys[0]);

    HashTable ht(10); // Ukuran tabel hash adalah 10

    for (int i = 0; i < n; i++) {
        ht.insert(keys[i]);
    }

    ht.displayHash();

    return 0;
}
