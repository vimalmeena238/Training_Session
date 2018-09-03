#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache: public Cache{
    public:
    LRUCache(int cap)
    {
        cp = cap;
        head = NULL;
        tail = NULL;
        
    }
    void set(int key, int value)
    {
        Node* t = new Node(key,value);
        if(head==NULL)
        {  
            head = t;
            tail = t;
            mp.insert(pair<int,Node*>(key,t));
            return;
        }
        int size = static_cast<int>(mp.size());
        if(size < cp)
        {
            if(mp.find(key)==mp.end())
            {
 
               t->next = head;
               head->prev = t;
               head = t;
               mp.insert(pair<int,Node*>(key,t));
            }
            else
            {
                Node* temp = mp.find(key)->second;
                if(temp==head)
                    head = head->next;
                if(temp->next != NULL)
                temp->next->prev = temp->prev;
                if(temp->prev != NULL)
                temp->prev->next = temp->next;  
                mp.erase(key);
                delete temp;
                if(head!=NULL)
                {
                    t->next = head;
                    head->prev = t;
                    head = t;     
                }
                else{
                    head = t;
                    tail = t;
                }
                mp.insert(pair<int,Node*>(key,t));
            }
             
            
        }
        else if(size==cp){
            mp.erase(tail->key);
            tail = tail->prev;
            if(tail==NULL)
            {
                head==NULL;
            }
            else{
                tail->next = NULL;
            }
            if(mp.find(key)==mp.end())
            {
                t->next = head;
                head->prev = t;
                head = t;
                mp.insert(pair<int,Node*>(key,t));
            }
            else
            {
                Node* temp = mp.find(key)->second;
                if(temp==head)
                    head = head->next;
                if(temp->next != NULL)
                temp->next->prev = temp->prev;
                if(temp->prev != NULL)
                temp->prev->next = temp->next;  
                mp.erase(key);
                delete temp;
                if(head!=NULL)
                {
                    head->prev = NULL;
                    t->next = head;
                    head->prev = NULL;
                    head->prev = t;
                    head = t;     
                }
                else{
                    head = t;
                    tail = t;
                }
                mp.insert(pair<int,Node*>(key,t));
            }     
        }
        
        
        return;
    }
    int get(int k)
    {
        if(mp.find(k) == mp.end())
        {
            return -1;
        }
 
       return mp.find(k)->second->value;
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
