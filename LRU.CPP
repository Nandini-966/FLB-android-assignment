#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;


class LRUCache {
    int capacity;  
    list<pair<int, int>> cacheList;  
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;  

public:
    
    LRUCache(int cap) {
        capacity = cap;
    }

    
    int get(int key) {
       
        if (cacheMap.find(key) == cacheMap.end())
            return -1;

        
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);

        return cacheMap[key]->second;
    }

    
    void put(int key, int value) {
        
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        } else {
            
            if (cacheList.size() == capacity) {
                auto lru = cacheList.back(); 
                cacheMap.erase(lru.first);   
                cacheList.pop_back();        
            }

            
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        }
    }
};

int main() {
    LRUCache lru(2);  
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;  
    lru.put(3, 3);               
    cout << lru.get(2) << endl;  
    lru.put(4, 4);               
    cout << lru.get(1) << endl;  
    cout << lru.get(3) << endl;  
    cout << lru.get(4) << endl; 
    return 0;
}

