1. Direct-address tables (when universe U is small)
2. Hash tables (when U is large, we use hash function for each key)
3. Load factor: alpha, n / k
        n is the number of entries occupied in the hash table.  
        k is the number of buckets.
    - As the load factor grows larger, the hash table becomes slower.
    - As the load factor approaches 0, the proportion of unused areas in the hash table increases.
4. Collision resolution: 
    - Chaining (closed hashing)
    - Open addressing: linear, quadratic probing, double hashing ( h(k, i) = (h1(k) + i * h2(k)) mod m )

- The downside of chained hashing is having to follow pointers in order to search linked lists. 
- The upside is that chained hash tables only get linearly slower as the load factor (the ratio of elements in the hash table to the length of the bucket array) increases, even if it rises above 1.

Open-addressing is usually faster than chained hashing when the load factor is low because you don't have to follow pointers between list nodes. It gets very, very slow if the load factor approaches 1, because you end up usually having to search through many of the slots in the bucket array before you find either the key that you were looking for or an empty slot. Also, you can never have more elements in the hash table than there are entries in the bucket array.
