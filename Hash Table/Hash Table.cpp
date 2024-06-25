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

    // Linear probing
    while (table[hashIndex] != -1) {
        hashIndex = (hashIndex + 1) % Tsize;
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
    int keys[] = {32, 53, 22, 92, 17, 34, 24, 37, 56};
    int n = sizeof(keys) / sizeof(keys[0]);

    HashTable ht(10); // Ukuran tabel hash adalah 10

    for (int i = 0; i < n; i++) {
        ht.insert(keys[i]);
    }

    ht.displayHash();

    return 0;
}
