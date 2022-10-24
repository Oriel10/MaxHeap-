#include <iostream>
#include "MaxHeap.h"

int* testHeap(int arr[], int size, int k);
//{4,3,2,1,6,5,10,7,9,8}, k = 3
int main(){
    int k = 4;
    int arr[10] = {4, 3, 2, 1, 6, 5, 10, 7, 9, 8};
    int* res = testHeap(arr, 10,  k);
    
    for(int i = 0; i < 10; i++){
        cout<<res[i]<< " ";
    }
    cout<<"finished";
    return 0;
    MaxHeap<string> names;
    names.insert(25,"Oriel");
    names.insert(29,"Shiran");
    names.insert(21,"Rinat");
    names.insert(58,"Roni");
    names.insert(55,"Adina");
    names.insert(24,"Tal");
    names.insert(1,"Adam");
    names.insert(1,"Narkis");
    names.insert(59,"Sonia");
    names.insert(8,"Izik");
    names.insert(6,"Dani");
    names.insert(11,"Haim");
    names.insert(12,"Israel");
    cout<<names.heap.size()<<endl;
    cout<<(names.contains(1) ? "True" : "false")<<endl;
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.delMax();
    cout<<(names.delMax() ? "heap is not empty" : "heap is empty as expected")<<endl;
    
    
}


int* testHeap(int arr[], int size,  int k){
    int i = size - k;
    MaxHeap<int> numbers(k);
    // int num_elems = sizeof(arr)/sizeof(int);
    int* res = new int[size];
    int counter = 0;
    while(i > 0){
        if(i == size - k){
            for(int j = 0; j < k; j++){
                numbers.insert(arr[size - j - 1], 0);
            }
        }
        cout<<"Top: "<<numbers.getMax().first<<endl;
        // return res; 
        pair<int,int> curr_max = numbers.getMax();
        res[counter++] = curr_max.first;
        numbers.delMax();
        numbers.insert(arr[--i], 0);
    }

    while(!numbers.isEmpty()){
        cout<<"numbers.getSize(): " << numbers.getSize()<<endl;
        pair<int,int> curr_max = numbers.getMax();
        res[counter++] = curr_max.first;
        numbers.delMax();
    }

    return res;
}
