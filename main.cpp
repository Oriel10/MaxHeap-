#include <iostream>
#include "MaxHeap.h"

int main(){
    MaxHeap<string> names;
    names.insert(25,"Oriel");
    names.insert(29,"Shiran");
    names.insert(21,"Rinat");
    names.insert(58,"Roni");
    names.insert(55,"Adina");
    names.insert(24,"Tal");
    names.insert(1,"Fury");
    names.insert(1,"Oscar");
    names.insert(59,"Sonia");
    names.insert(8,"Izik");
    names.insert(6,"Dani");
    names.insert(11,"Haim");
    names.insert(12,"Israel");
    cout<<names.heap.size()<<endl;
    cout<<(names.contains(1) ? "True" : "false")<<endl;
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    cout<<names.getMax().second<<", age: "<<names.getMax().first<<endl;
    names.popMax();
    
}