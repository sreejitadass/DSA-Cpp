#include<iostream>
#include<unordered_map>
#include<utility>
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

class LFUCache {
    unordered_map<int, Node*> mpp;  //(key,address)
    unordered_map<int,int> freq;    //(key,frequency)
    int capacity;
    Node* head, *tail;
public:
    LFUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);  // Dummy head
        tail = new Node(-1, -1);  // Dummy tail

        head->next = tail;
        tail->prev = head;
        mpp.clear();
        freq.clear();
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

    // Display the current state of the LFU cache
    void displayLFU() {
        Node* curr = head->next;
        while (curr != tail) {
            cout << "[" << curr->data[0] << ", " << curr->data[1] << "] ";
            curr = curr->next;
        }
        cout << endl;
    }

    bool isTie(int minFreq) {
        int count = 0;
        for (auto& it : freq) {
            if (it.second == minFreq) {
                count++;
                if (count > 1) {
                    return true;
                }
            }
        }
        return false;
    }

    pair<int,int> findMinFreq(){
        int minFreq = INT_MAX, minFreqKey;
        for(auto &it: freq){
            if(it.second < minFreq){
                minFreq = it.second;
                minFreqKey = it.first;
            }
        }
        return {minFreq,minFreqKey};
    }

    int get(int key) {
        //if key found
        if (mpp.find(key) != mpp.end()) {
            Node* reqdNode = mpp[key];
            deleteNode(reqdNode);
            insertAtHead(reqdNode);
            freq[key]++;
            return reqdNode->data[1];
        //not found
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
                pair<int,int>result = findMinFreq();
                int minFreq = result.first;

                //if there is a tie b/w min frequency elts, delete lru node
                if(isTie(minFreq))
                {
                    Node* lru = tail->prev;
                    mpp.erase(lru->data[0]);
                    freq.erase(lru->data[0]);
                    deleteNode(lru);
                    delete lru;
                }
                //otherwise, delete lfu node
                else
                {
                    int minFreqKey = result.second;
                    Node* lfu = mpp[minFreqKey];
                       mpp.erase(lfu->data[0]);
                        freq.erase(lfu->data[0]);
                        deleteNode(lfu);
                        delete lfu;
                }
            }
            // Insert the new node at the front and add it to the maps
            Node* newNode = new Node(key, value);
            insertAtHead(newNode);
            mpp[key] = newNode;
            freq[key]=1;
        }
    }
};

int main()
{
    LFUCache lfu(2);
    lfu.put(1,10);
    lfu.put(2,20);
    cout<<lfu.get(1)<<endl;
    lfu.put(3,30);
    cout<<lfu.get(2)<<endl;
    cout<<lfu.get(3)<<endl;
    lfu.put(4,40);
    cout<<lfu.get(1)<<endl;
    cout<<lfu.get(3)<<endl;
    cout<<lfu.get(4)<<endl;
    lfu.displayLFU();

    return 0;
}