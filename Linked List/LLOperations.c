#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node * link;
};

struct Node* root=NULL;
void append(void);
void delete(void);
int length(void);
void display(void);
void deleteNode(int loc);
void addBegin(void);
void addAfter(int loc);
void reverseList(void);


void append(){
    struct Node * temp;
    temp=(struct Node*)malloc(sizeof(struct Node));

    printf("\nEnter your data ");
    scanf("%d",&temp->data);

    temp->link=NULL;

    if(root==NULL){
        root=temp;
    
    }
    else{
        struct Node * p;
        p=root;
        while(p->link!=NULL){
            p=p->link;
        }
        p->link=temp;
    }

}
int length(){
    int count=0;
    struct Node* temp;
    temp=root;

    while(temp!=NULL){
        count++;
        temp=temp->link;
    }
    return count;

}

void deleteNode(int loc){

    struct Node * temp;
    
    

    if(loc>length()){
        printf("\nno such location");
    }
    else if(loc==1){
        temp=root;
        root=temp->link;
        temp->link=0;
        printf("Deleted %d",temp->data);
        free(temp);
    }
    else{
        int i=1;
        struct Node *p;
        struct Node *q;
        p=root;
        while(i<loc-1){
            
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=0;
        printf("Deleted %d",q->data);
        free(q);
    }
}



void display(){

    struct Node* temp;
    temp=root;

    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->link;
    } 
}

void addBegin(){

    struct Node * temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    printf("enter node data");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root == NULL){
        temp=root;     
    }
    else{
        temp->link=root;
        root=temp;      

    }

}

void addAfter(int loc){
    struct Node* temp;
    int i=1,len;

    len=length();

    if(loc>=len){
        printf("Invalid Input\nthis list contains %d nodes",len);
    }
    else if(loc==1)
    addBegin();
    else{
        struct Node * p;
        p=root;
        while(i<loc){
            p=p->link;
            i++;

        }
        temp=(struct Node*)malloc(sizeof(struct Node*));
        printf("\nenter the data ");
        scanf("%d",&temp->data);
        temp->link=p->link;
        p->link=temp;
    }
     
}

void reverseList(){
    struct Node *prev,*current,*next;
    prev=NULL;
    current=root;
    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;

    }
    root = prev;
    printf("\nreversed list\n ");
    display();

}


void sortlist(){
struct Node* current ,*index=NULL;
current=root;
int temp;
if(root==NULL)return;

else{
    while(current!=NULL){
        index=current->link;
        while(index!=NULL){
            if(current->data > index->data){
                temp=current->data;
                current->data=index->data;
                index->data=temp;
            }
            index=index->link;
        }

        current=current->link;
        
    }
}
    
}

void InsertInBetweenRange(){
    int a;
    printf("enter the data ");
    scanf("%d",&a);
    int pos=0;
    struct Node* p=root;
    while(p->data<a){
        p=p->link;
        pos++;
    }
    addAfter(pos);

}

void dublicateCount(){
    struct Node* current=root ,*index=NULL;
    int count =0;
    while(current!=NULL){
        index=current->link;
        while(index!=NULL){
            if(current->data==index->data)
                count++;
            index=index->link;
        }
        current=current->link;

    }
    printf("dub count %d",count);
}

void Removedublicate(){
    struct Node* current=root ,*index=NULL;
    int pos =1,pos2=0;
    while(current!=NULL){
        index=current->link;
        pos2=pos+1;
        while(index!=NULL){
            
            if(current->data==index->data){
                printf("%d",pos);
                deleteNode(pos2);
                break;
            }
            pos2++;
            index=index->link;
        }
        current=current->link;
        pos++;
    }
   
}

int main(){
    int ch,len;
    printf("\t\t---MENU---\n\t1.append\n\t2.display\n\t3.length\n\t4.Delete\n\t5.addBegin\n\t6.addAfter\n\t7.Reverse List\n\t8.Exit");

    do {

        printf("\nEnter Your Choice! ");
        scanf("%d",&ch);
        int loc;
        switch(ch)
        {
            case 1:
            append();
            break;

            case 2:
            display();
            break;

            case 3:
            len=length();
            printf("\nlength is -> %d",len);
            break;

            case 4:
            printf("\nenter location ");
            scanf("%d",&loc);
            deleteNode(loc);
            break;

            case 5:
            addBegin();
            break;
            
            case 6:
            
            printf("\nenter location\n");
            scanf("%d",&loc);
            addAfter(loc);
            break;

            case 7:
             reverseList();
            break;

            case 8:
            printf("Coming Out");
            break;

            case 9:
            Removedublicate();
            break;
        }


    }
    while(ch!=8);
    

    return 0;

}
