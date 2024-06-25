#include <iostream>
using namespace std;

class Node{
    public:
        Node *left;
        Node *right;
        int key;
        
        Node(){
            left = right = NULL;
        }
};

class BST{
    public:
        Node *root;
        
        BST(){
            root = NULL;
        }
        
        Node *insertRecursive(int inputKey, Node *currentRoot){
        
            if (currentRoot == NULL){
                Node *newNode = new Node();
                newNode->key = inputKey;
                return newNode;
            } 
            
            if (inputKey < currentRoot -> key){
                currentRoot->left = insertRecursive(inputKey, currentRoot->left);
            } else if (inputKey > currentRoot -> key){
                currentRoot->right = insertRecursive(inputKey, currentRoot->right);
            }
            
            return currentRoot;
        }
        
        void insert(int inputKey){
            root = insertRecursive(inputKey, root);
        }
        
        void preOrderTransversal(Node *currentNode){
            if(currentNode != NULL){
                cout << currentNode->key << " ";
                preOrderTransversal(currentNode->left);
                preOrderTransversal(currentNode->right);
            }
        }
        
        void preOrder(){
            cout << "Pre Order Trasversal : ";
            preOrderTransversal(root);
            cout << endl;
        }
        
        void inOrderTransversal(Node *currentNode){
            if(currentNode != NULL){
                inOrderTransversal(currentNode->left);
                cout << currentNode->key << " ";
                inOrderTransversal(currentNode->right);
            }
        }
        
        void inOrder(){
            cout << "In Order Trasversal : ";
            inOrderTransversal(root);
            cout << endl;
        }
        
        void postOrderTransversal(Node *currentNode){
            if(currentNode != NULL){
                postOrderTransversal(currentNode->left);
                postOrderTransversal(currentNode->right);
                cout << currentNode->key << " ";
            }
        }
        
        void postOrder(){
            cout << "Post Order Trasversal : ";
            postOrderTransversal(root);
            cout << endl;
        }

        // Fungsi untuk mencari nilai minimum
        void findMin(Node* currentNode, int& minVal) {
            if (currentNode == NULL)
                minVal = -1; // Nilai yang dihasilkan jika tree kosong
            else {
                while (currentNode->left != NULL)
                    currentNode = currentNode->left;
                minVal = currentNode->key;
            }
        }

        // Fungsi untuk mencari nilai maksimum
        void findMax(Node* currentNode, int& maxVal) {
            if (currentNode == NULL)
                maxVal = -1; // Nilai yang dihasilkan jika tree kosong
            else {
                while (currentNode->right != NULL)
                    currentNode = currentNode->right;
                maxVal = currentNode->key;
            }
        }

        // Fungsi untuk melakukan pencarian
        void search(int key, Node* currentNode, bool& found) {
            if (currentNode == NULL)
                found = false;
            else {
                if (key == currentNode->key)
                    found = true;
                else if (key < currentNode->key)
                    search(key, currentNode->left, found);
                else
                    search(key, currentNode->right, found);
            }
        }

        // Fungsi untuk menghapus node
        void deleteNode(Node*& currentNode, int key) {
            if (currentNode == NULL)
                return;
            if (key < currentNode->key)
                deleteNode(currentNode->left, key);
            else if (key > currentNode->key)
                deleteNode(currentNode->right, key);
            else {
                // Node dengan satu anak atau tanpa anak
                if (currentNode->left == NULL) {
                    Node* temp = currentNode->right;
                    delete currentNode;
                    currentNode = temp;
                } else if (currentNode->right == NULL) {
                    Node* temp = currentNode->left;
                    delete currentNode;
                    currentNode = temp;
                }
                // Node dengan dua anak: Dapatkan nilai penerus (nilai terkecil dari subtree kanan)
                else {
                    Node* temp = currentNode->right;
                    while (temp->left != NULL)
                        temp = temp->left;
                    // Salin nilai penerus ke node saat ini
                    currentNode->key = temp->key;
                    // Hapus nilai penerus dari subtree kanan
                    deleteNode(currentNode->right, temp->key);
                }
            }
        }

        void deleteKey(int key) {
            deleteNode(root, key);
        }
};

int main(int argc, char** argv){
    
    BST *bin1 = new BST();
    
    bin1 -> insert(6);
    bin1 -> insert(7);
    bin1 -> insert(4);
    bin1 -> insert(8);
    bin1 -> insert(5);
    bin1 -> insert(3);
    
    bin1 -> preOrder();
    bin1 -> inOrder();
    bin1 -> postOrder();
    
    int minVal, maxVal;
    bin1->findMin(bin1->root, minVal);
    bin1->findMax(bin1->root, maxVal);
    cout << "Nilai minimum: " << minVal << endl;
    cout << "Nilai maksimum: " << maxVal << endl;

    int searchKey = 5;
    bool found = false;
    bin1->search(searchKey, bin1->root, found);
    if (found)
        cout << "Nilai " << searchKey << " ditemukan dalam binary tree.\n";
    else
        cout << "Nilai " << searchKey << " tidak ditemukan dalam binary tree.\n";

    int deleteKey = 4;
    bin1->deleteKey(deleteKey);
    cout << "Setelah menghapus nilai " << deleteKey << ":\n";
    bin1->inOrder();

    return 0;
}