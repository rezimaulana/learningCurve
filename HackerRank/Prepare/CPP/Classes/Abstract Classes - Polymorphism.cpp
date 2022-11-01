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
class LRUCache : Cache
{
    private:
        // Member variable to distinguish between first 
        // element added and remaining elements
        bool m_first_node_added = false;
        // Iterator for map
        std::map<int, Node*>::iterator it;
        
        // Add new Node
        void AddNode(int key, int value);
        // Discard last item of list and add new Node
        void UpdateNewNode(int key, int value);
        // Update Cache order after a get command
        void UpdateLastHit(Node * node);
    
    public:
        // Public constructor with capacity
        LRUCache(int capacity)
        {
            cp = capacity;
        }
        
        // set new item
        void set(int key, int value);
        
        // get value from list
        int get(int key);
};

int LRUCache::get(int key)
{
    int ret_value = 0;
    try
    {
        it = mp.find(key);
        if (it != mp.end())
        {
            Node* tmp = it->second;
            ret_value = tmp->value;
            
            // Update
            UpdateLastHit(tmp);
            
            /*std::cout << "Print" << std::endl;
            // Print from tail to head
            Node* x = tail;
            for (int i = 0; i < mp.size(); i++)
            {
                std::cout <<" i - " << i << " - " <<  x->key << " - " << x->value << std::endl;
                if (x->next != nullptr)
                {
                    x = x->next; 
                }
                else 
                {
                    break;
                } 
            }*/
            
            // Print from head to tail
            /*x = head;
            for (int i = 0; i < mp.size(); i++)
            {
                std::cout <<" i - " << i << " - " <<  x->key << " - " << x->value << std::endl;
                
                if (x->prev != nullptr)
                {
                    x = x->prev; 
                }
                else 
                {
                    break;
                }  
            }*/
        }
        else 
        {
            ret_value = -1;
        }
    }
    catch (const std::out_of_range& oor) 
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }

    return ret_value;
}

void LRUCache::UpdateLastHit(Node* node)
{
    // If node requested is already head
    // no update needed
    if (node->value != head->value &&
        node->key   != head->key)
    {        
        // If node is tail
        // linked list update shall be different
        if (node == tail)
        {      
            Node* next_node = node->next;
            tail = next_node;
            next_node->prev = nullptr;
        }
        else 
        {
            // Get previous and next node
            Node* prev_node = node->prev;
            Node* next_node = node->next;
            
            // Link previous and next node
            prev_node->next = next_node;
            next_node->prev = prev_node;
        }
        
        //Update head
        node->prev = head;
        node->next = nullptr;
        
        head->next = node;
        
        head = node;
    }
}

void LRUCache::set(int key, int value)
{
    if (mp.size() < cp)
    {
        //std::cout << "AddNode" << std::endl;
        AddNode(key, value);
    }
    else 
    {
        //std::cout << "Update of list is needed" << std::endl;
        UpdateNewNode(key, value); 
    }
}

void LRUCache::AddNode(int key, int value)
{
    // Create Node ptr
    Node* entry = new Node(key, value);
            
    if (!m_first_node_added)
    {
        // Since it is first Node there is no prev or next
        entry->prev = nullptr;
    }
    else 
    {
        // If is not the first Node, set prev as the current head
        entry->prev = head;
    }
    // Next will always be null since the new node is added to the head
    entry->next = nullptr;
    
    // If it is not the first node, current Head will point to new node
    // Update the next entry for the previous head
    if (m_first_node_added)
    {
        head->next = entry;
    }
    
    // Add/Update entry to map
    mp[key] = entry;
    
    // Entry is always the new head
    head = entry;
    
    // First Node added then is at same time tail and head
    if (!m_first_node_added)
    {
        tail = entry;
    }
    
    // If first node is added
    // initialize variable
    if (!m_first_node_added)
    {
        m_first_node_added = true;
    }
}

void LRUCache::UpdateNewNode(int key, int value)
{
    // Update tail first and remove current tail
    int tail_key = tail->key;
    tail = tail->next;
    tail->prev = nullptr;
    
    // remove old tail
    mp.erase(tail_key);
    
    // Add new entry as header
    // Create Node ptr
    Node* entry = new Node(key, value);
    
    // Copy next reference from current tail
    entry->prev = head;
    entry->next = nullptr;
    
    // Assign next entry to old head
    head->next = entry;
    
    // Add entry to map
    mp[key] = entry;
    
    // Set new head
    head = entry;
}
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
