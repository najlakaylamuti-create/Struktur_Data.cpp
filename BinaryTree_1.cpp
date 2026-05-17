#include <iostream>
using namespace std;

// Struktur untuk merepresentasikan setiap node dalam pohon biner
struct Node {
    int val;      // Nilai yang disimpan di node
    Node* left;   // Pointer ke anak kiri
    Node* right;  // Pointer ke anak kanan
};

// Fungsi untuk membuat node baru
Node* createNode(int val) {
    Node* newNode  = new Node(); // Alokasikan memori untuk node baru
    newNode->val   = val;        // Simpan nilai ke dalam node
    newNode->left  = nullptr;    // Anak kiri belum ada, isi dengan null
    newNode->right = nullptr;    // Anak kanan belum ada, isi dengan null
    return newNode;              // Kembalikan node yang sudah dibuat
}

// Fungsi rekursif untuk menghitung kedalaman maksimum pohon
int countDepth(Node* node) {
    // Jika node kosong, kedalaman = 0 (sudah mencapai ujung pohon)
    if (node == nullptr) {
        return 0;
    }

    // Hitung kedalaman dari sisi kiri secara rekursif
    int leftSide = countDepth(node->left);

    // Hitung kedalaman dari sisi kanan secara rekursif
    int rightSide = countDepth(node->right);

    // Bandingkan keduanya, ambil yang lebih dalam, lalu tambah 1 untuk node sekarang
    if (leftSide > rightSide) {
        return leftSide + 1;
    } else {
        return rightSide + 1;
    }
}

int main() {
    cout << "=== Maximum Depth of Binary Tree ===" << endl;

    // Membuat node-node pohon sesuai soal: [3, 9, 20, null, null, 15, 7]
    Node* root         = createNode(3);  // Root utama bernilai 3
    root->left         = createNode(9);  // Anak kiri root bernilai 9
    root->right        = createNode(20); // Anak kanan root bernilai 20
    root->right->left  = createNode(15); // Anak kiri dari node 20 bernilai 15
    root->right->right = createNode(7);  // Anak kanan dari node 20 bernilai 7

    // Panggil fungsi untuk menghitung kedalaman dan simpan hasilnya
    int result = countDepth(root);

    // Tampilkan hasil kedalaman maksimum
    cout << "maxDepth = " << result << endl;

    return 0;
}