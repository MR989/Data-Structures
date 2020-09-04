#include<bits/stdc++.h>

using namespace std;
class MyStack{

    public:
    queue <int> q1,q2;
    void push(int x){
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);

    }

    void pop(){
        if(q1.empty()){
            cout<<"queue is empty";
            exit(0);
        }

        q1.pop();

    }

    int top(){
        if(q1.empty()){
            cout<<"queue is empty";
            return -1;
        }
        return q1.front();
    }
};

int main(){

    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<s.top()<<endl;
    s.pop();

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    

}