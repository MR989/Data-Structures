#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * link;
};
struct Node * root=NULL;



void printlist(){
    struct Node* n;
    n=root;
    while(n!=NULL){
        printf("%d",n->data);
        n=n->link;
    }


}

void append(){

    struct Node * temp;
    temp=(struct Node*)malloc(sizeof(struct Node));

    printf("Enter the data into node");
    scanf("%d",&temp->data);

    temp->link=NULL;

    if(root==NULL){
        root=temp;
    }
    else{

        struct Node * p;
        p = root;

        while(p->link!=NULL){
            p=p->link;

        }
            
        p->link=temp;     
        
    }
    

}
void main(){
    int n =3 ;
    while(n!=0){
        append();
        n--;
    }



    printlist();

    
}

