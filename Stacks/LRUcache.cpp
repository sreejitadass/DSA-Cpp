#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public: 
    Node* next,*prev;
    int data[2];

    Node(int key, int val){
        data[0] = key;
        data[1] = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    unordered_map<int, Node*> mpp;
    int capacity;
    Node* head, *tail;
public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);  // Dummy head
        tail = new Node(-1, -1);  // Dummy tail

        head->next = tail;
        tail->prev = head;
        mpp.clear();
    }

    // Utility function to insert a node at the front (right after head)
    void insertAtHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Utility function to delete a node from the linked list
    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Display the current state of the LRU cache
    void displayLRU() {
        Node* curr = head->next;
        while (curr != tail) {
            cout << "[" << curr->data[0] << ", " << curr->data[1] << "] ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node* reqdNode = mpp[key];
            deleteNode(reqdNode);
            insertAtHead(reqdNode);
            return reqdNode->data[1];
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {  
        // If the key already exists, update the value and move it to the front
        if (mpp.find(key) != mpp.end()) {
            Node* existingNode = mpp[key];
            existingNode->data[1] = value;
            deleteNode(existingNode);
            insertAtHead(existingNode);
        } 
        else {
            // If the cache is full, remove the least recently used node
            if (mpp.size() == capacity) {
                Node* lru = tail->prev;
                mpp.erase(lru->data[0]);
                deleteNode(lru);
                delete lru;
            }
            // Insert the new node at the front and add it to the map
            Node* newNode = new Node(key, value);
            insertAtHead(newNode);
            mpp[key] = newNode;
        }
    }
};

int main() {
    LRUCache lru(4);
    lru.put(2, 6);
    lru.put(4, 7);
    lru.put(8, 11);
    lru.put(7, 10);
    cout << lru.get(2) << endl; // Should return 6
    cout << lru.get(8) << endl; // Should return 11
    lru.put(5, 6);              // This should evict key 4
    cout << lru.get(7) << endl; // Should return 10
    lru.put(5, 7);              // This should update key 5 to value 7
    lru.displayLRU();           // Display current LRU cache

    return 0;
}
