
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

template<class T>
class MaxHeap{
    static const int INIT_SIZE = 10;
    int curr_size;
    int max_size;
    void expand();
    static const int EXPAND_RATE = 2;
    void siftUp(int pos);
    void siftDown(int pos);
    bool isLeaf(int pos) const;
    void swap_pairs(int pos1, int pos2);
    int parent(int pos) const;
    int leftChild(int pos) const;
    int rightChild(int pos) const;
public:
    vector<pair<int,T>> heap;
    MaxHeap(int heap_size = INIT_SIZE) : heap(vector<pair<int,T>>(heap_size)), curr_size(0), max_size(heap_size){}
    void insert(int key, T data);
    bool contains(int key) const;
    pair<int,T> getMax() const;
    bool popMax();
};

template<class T>
int MaxHeap<T>::parent(int pos) const{
    return (pos-1)/2;
}

template<class T>
int MaxHeap<T>::leftChild(int pos) const{
    return pos*2 + 1;
}

template<class T>
int MaxHeap<T>::rightChild(int pos) const{
    return pos*2 + 2;
}

template<class T>
bool MaxHeap<T>::isLeaf(int pos) const{
    if((pos >= curr_size/2) && (pos < curr_size)){
        return true;
    }
    return false;
}

template<class T>
void MaxHeap<T>::insert(int key, T data){
    if(contains(key)){
        return;
    }
    
    if(curr_size >= max_size){
        expand();
    }
    heap[curr_size] = pair<int,T>(key, data);
    
    // int curr = curr_size;
    siftUp(curr_size);
    curr_size++;
}

template<class T>
void MaxHeap<T>::expand(){
    int new_size = max_size*EXPAND_RATE; 
    vector<pair<int,T>> tmp(new_size);
    for(int i = 0; i < max_size; i++){
        tmp[i] = heap[i];
    }
    heap = tmp;
    max_size = new_size;
}

template<class T>
void MaxHeap<T>::siftUp(int pos){
    int curr = pos;
    while(heap[curr].first > heap[parent(curr)].first){
        swap_pairs(curr,parent(curr));
        curr = parent(curr);
    }
}

template<class T>
void MaxHeap<T>::swap_pairs(int pos1, int pos2){
    pair<int,T> tmp = heap[pos1];
    heap[pos1] = heap[pos2];
    heap[pos2] = tmp;
}

template<class T>
void MaxHeap<T>::siftDown(int pos){
    if(isLeaf(pos)){
        return;
    }
    int curr = pos;
    int rc = rightChild(curr);
    int lc = leftChild(curr);
    bool sifting_done = true;
    if(rc >= curr_size || heap[lc].first > heap[rc].first){
        if(heap[lc].first > heap[curr].first){
            swap_pairs(curr,lc);
            curr = lc;
            sifting_done = false;
        }
    }
    else if(heap[lc].first < heap[rc].first){
        if(heap[rc].first > heap[curr].first){
            swap_pairs(curr,rc);
            curr = rc;
            sifting_done = false;
        }
    }
    if(sifting_done){
        return;
    }
    siftDown(curr);
}

template<class T>
bool MaxHeap<T>::contains(int key) const{
    for(const auto& elem : heap){
        if(elem.first == key){
            return true;
        }
    }
    return false;
}

template<class T>
pair<int,T> MaxHeap<T>::getMax() const{
    pair<int,T> empty(-1,"heap is empty");
    return curr_size!=0 ? heap[0] : empty;
}

template<class T>
bool MaxHeap<T>::popMax(){
    if(curr_size == 0){
        return false;
    }
    heap[0] = heap[curr_size-1];
    curr_size--;
    siftDown(0);
    return true;
}

