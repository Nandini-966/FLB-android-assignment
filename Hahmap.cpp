#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* next;

    Node(int k = -1, int v = -1, Node* n = nullptr) : key(k), val(v), next(n) {}
};

class MyHashMap {
private:
    vector<Node*> map;

public:
    MyHashMap() {
        map.resize(1000);
        for (int i = 0; i < 1000; ++i) {
            map[i] = new Node();
        }
    }

    int hash(int key) {
        return key % 1000;
    }

    void put(int key, int value) {
        int hash_key = hash(key);
        Node* cur = map[hash_key];

        while (cur->next) {
            if (cur->next->key == key) {
                cur->next->val = value;
                return;
            }
            cur = cur->next;
        }

        cur->next = new Node(key, value);
    }

    int get(int key) {
        int hash_key = hash(key);
        Node* cur = map[hash_key];

        while (cur->next) {
            if (cur->next->key == key) {
                return cur->next->val;
            }
            cur = cur->next;
        }

        return -1;
    }

    void remove(int key) {
        int hash_key = hash(key);
        Node* cur = map[hash_key];

        while (cur->next) {
            if (cur->next->key == key) {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                return;
            }
            cur = cur->next;
        }
    }
};


int main() {
    MyHashMap obj;
    obj.put(1, 10);
    obj.put(2, 20);
    cout << obj.get(1) << endl; 
    cout << obj.get(3) << endl; 
    obj.put(2, 30);            
    cout << obj.get(2) << endl; 
    obj.remove(2);
    cout << obj.get(2) << endl; 
    return 0;
}
