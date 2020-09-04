#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{

    int data;
    struct Node* link;
};

struct Node* root;
int len;
void Append(void);
int length(void);
void display(void);
void Delete(void);
void AddBegin(void);
void AddAfter();
void main()
{
    int ch;
    printf("\n\t............MENUE.............\n");
    printf("\n1.Append\n2.length\n3.delete\n4.Display\n5.Exit\n6.AddBegin\n7.AddAfter");

    do
    {
        printf("\nEnter your choice\n");
        scanf("\n%d",&ch);

        switch(ch)
        {
            case 1:
                Append();
                break;

            case 2:
                len = length();
                printf("\nlength is %d",len);
                break;

            case 3:
                Delete();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExit");
                break;
            case 6:
                AddBegin();
                break;
            case 7:
                AddAfter();
                break;

            default:
                printf("\nInvalid input");


        }
    }while(ch!=5);
  getch();
}

void Append()
{
    struct Node* temp;
    temp=(struct Node*)malloc(sizeof(struct Node));

    printf("\nEnter node data\n");
    scanf("%d",&temp->data);

    temp->link=0;

    if(root==0)
    {
        root=temp;
    }
    else
    {
        struct Node* p;
        p=root;

        while(p->link!=0)
        {
            p=p->link;
        }
        p->link=temp;

    }
}

int length()
{
    int count=0;
    struct Node* temp;
    temp=root;

    while(temp!=0)
    {
        count++;
        temp=temp->link;
    }
    return count;
}

void display()
{
    struct Node*temp;
    temp=root;
    if(temp==0)
    {
        printf("\nList is empty");
    }
    else
    {
        while(temp!=0)
        {

            printf("||%d|| ",temp->data);
            temp=temp->link;
        }

    }
}

void Delete()
{
    struct Node* temp;
    int loc;

    printf("\nEnter location\n");
    scanf("%d",&loc);

    if(loc>length())
    {
        printf("Invalid input");
    }
    else if(loc==1)
    {
        temp=root;
        root=temp->link;
        temp->link=0;

       // temp=loc;

        printf("\nDeleted item is %d",temp->data);

        free(temp);
    }
    else
    {
        struct Node* p;
        struct Node* q;
        p=root;
        int i=1;

        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=0;
       // temp=loc;
        printf("\nDeleted item is %d",q->data);
        free(q);
    }

}
void AddBegin()
{
     struct Node* temp;
    temp=(struct Node*)malloc(sizeof(struct Node));

    printf("\nEnter node data\n");
    scanf("%d",&temp->data);

    temp->link=0;

    if(root==0)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
}

void AddAfter()
{
    struct Node* temp;
    int i=1;
    int loc,len;
    struct Node* p;

    printf("\nEnter location\n");
    scanf("%d",&loc);
    len=length();
    if(loc>=len)
    {
        printf("\nInvalid Input");
        printf("\nCurrent list is having %d nodes",len);
    }
    else if(loc==1)
    {

        AddBegin();
    }


    else
{
         p=root;
        while(i<loc)
        {
            p=p->link;
            i++;
        }
        temp=(struct Node*)malloc(sizeof(struct Node));

        printf("\nEnter data to be inserted at node %d\n",loc);
        scanf("\n%d",&temp->data);
        temp->link=0;

        temp->link=p->link;
        p->link=temp;
}
}