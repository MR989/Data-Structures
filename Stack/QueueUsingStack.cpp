#include<bits/stdc++.h>

using namespace std;
class MyQueue{
    public:
    stack <int > s1,s2;
void enqueue(int x){
    cout<<"test"<<endl;
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }

}
// void printqueue(){
//     for(auto it =s1.begin();it!=s1.end();it++)
// }

int  dequeue(){
    if (s1.empty()){
        cout<<"queue is empty";
        
        exit(0);
    }
    int x = s1.top();
    s1.pop();
    return x; 

}
};


int main(){

    MyQueue q1;
    q1.enqueue(1);
    
    q1.enqueue(2);
    
    q1.enqueue(3);
    
    q1.enqueue(4);

    cout<<q1.dequeue()<<"\n";
    cout<<q1.dequeue();


}   