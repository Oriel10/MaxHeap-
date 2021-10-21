# MaxHeap-
A maxheap implementation ic C++.  
Each node in the heap is a contains a pair of an integer key and a templated data T.  
The heap is implemented using and expandable array since each complete binary tree can be represented using an array.  
# Assumptions:  
-each key has to be unique  
-the generic data has to have a copy constructor

# The maxheap supports:  
-insert - insertion of key and data pairs  
-contains - returns True if a certain key is already in the heap  
-getMax - return the pair with the largest key  
-popMax - pop the pair with the largest key, and returns True if popping succeeded  
