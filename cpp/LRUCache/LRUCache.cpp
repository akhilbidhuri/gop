// LRUCache.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This is a simple implementation of an inmemnory LRU cache.
// Author: Akhil Bidhuri
//

#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
#include <stdexcept>

using namespace std;

template <typename T>
class LRUCache {
    int capacity;
    list<pair<string, T>> cacheOrder;
    unordered_map<string, typename list<pair<string, T>>::iterator> cache;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    void put(string key, T value);
    T get(string key);
    void remove(string key);
};

template <typename T>
void LRUCache<T>::put(string key, T value) {
    // if the given key is already present in the cache
    if (cache.find(key) != cache.end()) {
        cout << "Key already present in cache, updating the value!" << endl;
        auto cacheIt = cache[key];
        cacheOrder.erase(cacheIt);
        cache.erase(key);
    }

    // evict the least recently used item if size of cache is at capacity
    else if (cache.size() == capacity) {
        string evictionKey = cacheOrder.back().first;
        cout << "Cache reached capacity evicting least recently used key: " << evictionKey << endl;
        cacheOrder.pop_back();
        cache.erase(evictionKey);
    }

    // insert the given key, value
    cacheOrder.push_front({ key, value });
    cache[key] = cacheOrder.begin();
}

template <typename T>
T LRUCache<T>::get(string key) {
    auto cacheIt = cache.find(key);
    if (cacheIt == cache.end()) {
        throw runtime_error("Key not found");
    }
    // Move the accessed item to the front
    cacheOrder.splice(cacheOrder.begin(), cacheOrder, cacheIt->second);
    return cacheIt->second->second;
}

template <typename T>
void LRUCache<T>::remove(string key) {
    auto cacheIt = cache.find(key);
    if (cacheIt != cache.end()) {
        auto cacheNode = cacheIt->second;
        cache.erase(key);
        cacheOrder.erase(cacheNode);
        cout << "Deleted: " << key << endl;
    }
    else {
        cout << "key not present in cache!" << endl;
    }
}

int main() {
    cout << "This is a dummy LRU Cache system!" << endl;
    LRUCache<string> cache(5);
    while (true) {
        cout << "choose your operation=> 1: PUT, 2: GET, 3: Delete, 4: Exit." << endl;
        int input;
        string key, value;
        cin >> input;
        switch (input) {
        case 1:
            cout << "Enter key and value:";
            cin >> key >> value;
            cout << endl;
            cache.put(key, value);
            break;
        case 2:
            cout << "Enter Key:";
            cin >> key;
            cout << endl;
            try {
                value = cache.get(key);
                cout << "Value: " << value << endl;
            }
            catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        case 3:
            cout << "Enter Key:";
            cin >> key;
            cout << endl;
            cache.remove(key);
            break;
        case 4:
            cout << "Exiting Bye!" << endl;
            return 0;
        default:
            cout << "Wrong choice, Golli beta masti nahi!, Try Again." << endl;
        }
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

