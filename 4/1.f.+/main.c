#include <stdio.h>
#include <stdlib.h>
int s=1;
 typedef struct one
        {
            int a;
            struct one *next ;
        }
        node ;
void tabe(int x , int y , node* head , node* current )
{
   // node **head ;
    node *th ;
    th =malloc(sizeof(node));
    th->a=x;
    current=head;
    while(current->next!=NULL)
    {
        if (current->next->a==y || current->a==y)
        {
            s=-1;
            break ;
        }
        else ;
        current=current->next;
    }
    if (s==1)
    {
        current->next=th;
        th->next=NULL;
    }
    else ;
    if (s==-1)
    {
        if (current->a==y)
        {
            th->next=head;                                               // new_node->next = *plist;
            //head=th;                                                //*plist= new_node;
        }
        else
        {
        current=head;
        while(current->next->a != y)
        {
            current=current->next;
        }
        th->next=current->next;
        current->next=th;
        }



    }
    else ;

}
void prnt(node *head)
{
    node *pr ;
    pr=head;
    while(pr!= NULL)
    {
        printf("%d\n",pr->a);
        pr=pr->next;
    }
}
int main (void)
{
    node *currnet ;
    node * head = NULL;
    head = malloc(sizeof(node));
    head->a = 10;
    head->next =NULL ;



    tabe(20,100,head,currnet);
    prnt(head);
    printf("\n");

    tabe(30,100,head,currnet);
    prnt(head);
    printf("\n");

    tabe(40,30,head,currnet);
    prnt(head);
    printf("\n");

    tabe(50,20,head,currnet);
    prnt(head);
    printf("\n");

    tabe(60,10,head,currnet);
    prnt(head);
    printf("\n");



    return 0 ;
}

