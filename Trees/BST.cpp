#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* root=NULL;

void insert(int d);
void insert(int d){
    Node *p,*t;
    t=new Node();

    t->data=d;
    cout<<t->data;
    t->left=NULL;
    t->right=NULL;
    p=root;

    if(root==NULL)
        root=t;
    else{
        Node *curr;
        curr=root;  
        while(curr){
            p=curr;
            if(t->data > curr->data)
                curr=curr->right;
            else
            {
                curr=curr->left;
            }
        }
        if(t->data>p->data)
            p->right=t;
        else
            p->left=t;
        
    }
    return;

}

void deleteNode(int data){
    Node *curr,*p;
    string relation="";
    curr=root;
    while(curr->data!=data){
        p=curr;
        if(data > curr->data){
            curr=curr->right;
            relation="right";
        }
        else{ 
            curr=curr->left;
            relation="left";
        }
    }

    //case 1
    if(curr->right==NULL && curr->left==NULL){
        if(p->right==curr)
            p->right=NULL;
        else 
            p->left=NULL;
        delete curr;
    }

    //case 2
    else if(curr->right==NULL || curr->left==NULL){
        if(curr->left!=NULL){
            if(relation=="left")p->left=curr->left;
            else p->right=curr->left;
            
        }
        else{
            if(relation=="left")p->left=curr->right;
            else p->right=curr->right;
        
            
        }
        delete curr;
    }
    else{   
        Node *rep_node=curr->left;
        p=curr; 
        //finding largest in left sub-tree
        while(rep_node->right!=NULL){
            p=rep_node;
            rep_node=rep_node->right;


        }
        curr->data=rep_node->data;
        //now delete the replacing node
        if(rep_node->left==NULL){
            //apply case 1
            if(p->left==curr)p->left=NULL;
            else p->right=NULL;

        }
        else{
            //apply case 2
            p->left=rep_node->left;
        }



    }

}


bool Search(Node *root ,int data){
    if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(data >= root->data) return Search(root->right,data);
    else return Search(root->left,data);
}

int height(Node *node){
    if (node==NULL)
        return 0;
    int lheight=height(node->left);
    int rheight=height(node->right);

    if(lheight>rheight) return lheight+1;
    else return rheight+1;

}

void LevelOrderTraversal(Node *root){
    if(root==NULL)return;
    queue<Node *> Q;
    Q.push(root);
    while(!Q.empty()){
        Node * current=Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL)Q.push(current->left);
        if(current->right!=NULL)Q.push(current->right);
        Q.pop();

    }
}

bool IsBStUtil(Node * root , int min ,int max){
    if (root==NULL)return true;

    if(root->data>min && root->data<max
        && IsBStUtil(root->left,min,root->data)
        &&IsBStUtil(root->right,root->data,max))
        return true;
    else return false;
}
bool IsBST(Node *root){
    return(IsBStUtil(root,INT_MIN,INT_MAX));

}

int main(){
    
    int number;
    insert(10);
    insert(6);
    insert(15);
    insert(17);
    insert(18);
    cout<<"\nenter no";
    cin>>number;

    if(Search(root,number)==true)cout<<"\nfound";
    else cout<<"\nnot found";

    LevelOrderTraversal(root);

    int he=height(root);
    cout<<"\n height "<<he;
    if(IsBST)cout<<"\nTrue";
    else cout<<"\nFalse";
    return 0;
    
    
 
}