#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    array<int , 6> arr = {1,2,3,4,5,6};
    vector<int> v = {1,2,3};
    deque<int> d = {1,4,5,7,8};
    list<int> l = {1,3,6,7};
    stack<int> st;
    queue<int> q;
    //priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq;
    set<int> s;
    map<string,int> phone_book;

    int i;
    //array implementation 
    cout<<"printing array elemnets"<<endl;

    for(i = 0;i<arr.size();i++)
        cout<<arr[i]<<endl;

    //vector implementation
    cout<<"printing vector elements"<<endl;
    for(auto iter : v)
        cout<<iter<<endl;

    cout<<"Adding more elements"<<endl;
    v.push_back(4);
    v.push_back(8);
    v.push_back(6);

    sort(v.begin(),v.end());
    cout<<"printing vector elements after element add and sorting"<<endl;
    for(auto iter : v)
        cout<<iter<<endl;
    cout<<"vector size : "<< v.size()<<endl;
    //dequeue implementation 
    
    cout<<"printing dqueue elements of size:"<<d.size()<<endl;
    for(auto iter: d)
        cout<<iter<<endl;

    cout<<"Adding some more elements"<<endl;
    d.push_back(8);
    d.push_back(10);
    d.push_back(12);

    cout<<"re-printing dqueue elements of size:"<<d.size()<<endl;
    for(auto iter: d)
        cout<<iter<<endl;

    cout<<"poping two elements from front"<<endl;
    d.pop_front();
    d.pop_front();
    cout<<"Size of the queue post popping: "<<d.size()<<endl;
    cout<<"front element of queue : "<<d[0]<<endl;

    //list implementation
    cout<<"Printing list elements of size: "<<l.size()<<endl;

    for(auto iter: l)
        cout<<iter<<endl;

    l.push_back(8);
    l.push_front(10);
    
    cout<<"Printing list elements after adding ,final size : "<<l.size()<<endl;
    for( auto iter: l )
       cout<< iter<<endl;

    cout<<"Reversing the list and printing them:"<<endl;
    l.reverse();
    for( auto iter: l )
       cout<< iter<<endl;

    cout<<"inserting in middle"<<endl;
    int mid = l.size() / 2;
    auto iter = l.begin();
    advance(iter,mid);
    l.insert(iter,100); 
    
    cout<<"Printing list elements after adding ,final size : "<<l.size()<<endl;
    for( auto iter: l )
       cout<< iter<<endl;

    iter = find(l.begin(),l.end(),80);
    if(iter != l.end())
       cout<<"Element is found"<<endl;
    else
       cout<<"Element not found"<<endl;

    cout<<"Stack operations "<<endl;
    //stack operations 
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<<"Top of stack : "<<st.top()<<endl;
    cout<<"No of elements : "<<st.size()<<endl;
    cout<<"printing stack elements"<<endl;

    while( !st.empty() )
    {
        cout<<st.top()<<endl;
	st.pop();
    }
    cout<<"Queue operations "<<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<"No of elements : "<<q.size()<<endl;
    cout<<"printing queue elements"<<endl;
    
    while( !q.empty() )
    {
        cout<<q.front()<<endl;
	q.pop();
    }

    //priority queue
    //
    cout<< "priority queue operations"<<endl;
    pq.push(10);
    pq.push(8);
    pq.push(80);
    pq.push(100);
    
    auto tempq = pq;

    cout<<"top priority ele: "<<pq.top()<<endl;
    cout<<"printing elements "<<endl;

    while(!tempq.empty())
    {
         cout<<tempq.top()<<endl;
	 tempq.pop();
    } 
    //Set operations 

    s.insert(2);
    s.insert(1);
    s.insert(-1);
    s.insert(5);
    //s.erase(-1);
    cout <<"Size of the set:  "<<s.size()<<endl;
    cout <<"Printing elements  "<<endl;

    for(auto iter : s)
    {
       cout<<iter<<endl;
    }
    
    cout<< "Find element 5"<<endl;
    auto it = s.find(5);

    if( it!= s.end() )
        cout<<"Element found"<<endl;
    else
	cout<<"Element not found"<<endl;
    it = max_element(s.begin(),s.end());

    cout<<"Max element :"<<*it<<endl;
    
    cout<<"Map operations "<<endl;
    phone_book.insert({"Anand",988654532});
    phone_book.insert({"Vijay",809543242});
    phone_book.insert({"Sahana",888480265});
    
    cout<<"No of entries : "<<phone_book.size()<<endl;
    for(auto iter : phone_book)
    { 
        cout<<"Name: "<<iter.first<<", Number: "<<iter.second<<endl;
    }
    return 0;
}
