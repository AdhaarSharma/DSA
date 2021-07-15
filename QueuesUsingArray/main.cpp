#include <bits/stdc++.h>
 
using namespace std;

#define CAPACITY 100

class Queue{
    public:
        int a[CAPACITY];
        int front = 0;
        int rear = 0;
        void push();
        void pop();
        int peek();
        void display();
};

void Queue::push(){
    if(rear==CAPACITY-1){
        cout<<"Queue Overflow"<<endl;
        exit(1);
    }
    else{
        int val;
        cout<<"Insert element in Queue: "<<endl;
        cin>>val;
        a[rear]=val;
        rear++;
    }
}

void Queue::pop(){
    if(front==rear){
        cout<<"Queue Underflow"<<endl;
        exit(1);
    }
    else{
        cout<<"Element delete: "<<a[front]<<endl;
        for(int i=front; i<rear-1; i++){
            a[i]=a[i+1];
        }
        rear--;
    }
}

void Queue::display(){
    if(front==rear){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue elements are: ";
        for(int i=front; i<rear; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
}