# FLB-android-assignment
# LRU Cache (Least Recently Used) – C++ Implementation

This project implements a Least Recently Used (LRU) Cache in C++ with `O(1)` time complexity for both `get` and `put` operations using `unordered_map` and `doubly linked list`.

##  Features

- `get(key)` – Returns the value of the key if it exists in the cache, else `-1`.
- `put(key, value)` – Inserts or updates the key-value pair. Evicts the least recently used item if the cache exceeds its capacity.
- Time complexity: **O(1)** for both operations.

##  Constraints

- 1 ≤ capacity ≤ 3000
- 0 ≤ key, value ≤ 10⁴
- Up to 10⁵ operations supported efficiently

##  Code Structure

- `LRUCache.cpp` – Contains the main LRU cache class and example usage.

##  Implementation Logic

- Uses a `list<pair<int, int>>` to store keys and values in the order of usage.
- Uses `unordered_map` to map keys to their positions in the list.
- On `get`, the element is moved to the front of the list (most recently used).
- On `put`, if the key exists, update and move it to front; if not, insert it, and evict the least recently used key if needed.








