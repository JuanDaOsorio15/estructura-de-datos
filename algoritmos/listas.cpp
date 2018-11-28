#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
int main()
{
    char *p;
    int n = 10;
    p = (char *)malloc(n);
    strcpy(p,"sencillo");
    printf("%s\n",p);
}
*/
/*
typedef struct R
{
        int a;
        float b;
        double c;
        char *p;
}structure;

int main()
{
    int n = 10;
    structure *q;
    q=(structure *)malloc(sizeof(structure));
    q -> a = 8;
    q -> b = 10.31;
    q -> c = 10.32;
    q -> p =(char *)malloc(n);
    
    strcpy(q -> p, "cadena");
    printf("%d %2f %2lf %s\n",q -> a,q -> b,q -> c, q -> p);
    return 0;
}
*/

/*
int main()
{
    char *p,*q;
    int n=50;
    p=(char *)malloc(n);
    strcpy(p,"pascal");
    q=(char *)malloc(n);
    strcpy(q,"lenguaje c");
    printf("%s %s\n", p,q);
    free(q);
    q = p;
    printf("%s %s\n",p,q);
    system("pause");
    return 0;
}
*/

 
/*
int main()
{
    struct node *head,*q;
    head = (struct node *)malloc(sizeof(struct node));
    head -> key = 1;
    q = (struct node *)malloc(sizeof(struct node)); 
    q -> key = 2;
    head -> next = q;
    q -> next = (struct node *) malloc(sizeof(struct node));
    q -> next -> key=3;
    q -> next -> next = NULL;
    printf("%d %d %d\n", head -> key, head -> next -> key,head -> next -> next -> key);
    system("pause");
    return 0; 
}
*/

/*int main()
{
    struct node *head,*q;
    
    int n = 1000;
    head=NULL;
    while(n>0)
    {
              q = (struct node *)malloc(sizeof(struct node)); 
              q->key=n;
              q->next=head;
              head=q;
              n--;
    }
    q=head;
    while(q != NULL)
    {
            printf("%d", q -> key);
            q= q-> next;
    }
    q=head;
    while(q != NULL)
    {
            head = q;
            q= q->next;
            free(head);
    }
    return 0;
}*/

/*
struct node *build_list(int n)
{
    struct node *head, *q;
    head=NULL;
    while(n>0)
    {
              q = (struct node *)malloc(sizeof(struct node)); 
              q->key=n;
              q->next=head;
              head=q;
              n--;
    }
    return head;
}

void print_list(struct node *head)
{
     struct node *q; 
     q=head;
     while(q != NULL)
     {
            printf("%d", q -> key);
            q= q-> next;
     }
}

void eraselist(struct node *head)
{
     struct node *q;
     q=head;
     while(q != NULL)
      {
            head = q;
            q= q->next;
            free(head);
      }
}

int main()
{
    struct node *head;
    head = build_list(1000);
    print_list(head);
    eraselist(head);
    return 0;
}
*/
/*
struct node
{
       int key;
       struct node *next;
};
 
 
struct node *InsertInAscendentList(struct node *head, int element)
{
      struct node *newnode, *actual, *prev;
      newnode =(struct node *)malloc(sizeof(struct node));
      newnode->key=element;
      if (head == NULL)
      {
               newnode -> next = head;
               head = newnode;

      }
      else
      {   
          if (element <= head -> key)
          {
            newnode -> next = head;
            head = newnode;
          }
          else
          {
              prev = NULL;
              actual = head;
              while ((actual != NULL) && (element > actual -> key))
              {
                    prev = actual;
                    actual = actual -> next;
              }
              
              prev -> next = newnode;
              newnode -> next = actual;
          }
      }
      return head;
}

void print_list(struct node *head)
{
     struct node *q; 
     q=head;
     while(q != NULL)
     {
            printf("%d ->", q->key);
            q=q->next;
     }
     printf("NULL\n");
}

int main()
{
    struct node *head;
    int element;
    head = NULL;
    while(scanf("%d",&element)!= EOF)
    {
                                 head = InsertInAscendentList(head, element);
                                 print_list(head);
    }
}
*/
struct node
{
       int key;
       struct node *next;
};
 
 struct node *InsertInAscendentList(struct node *head, int element)
{
      struct node *newnode, *actual, *prev;
      newnode =(struct node *)malloc(sizeof(struct node));
      newnode->key=element;
      if (head == NULL)
      {
               newnode -> next = head;
               head = newnode;

      }
      else
      {   
          if (element <= head -> key)
          {
            newnode -> next = head;
            head = newnode;
          }
          else
          {
              prev = NULL;
              actual = head;
              while ((actual != NULL) && (element > actual -> key))
              {
                    prev = actual;
                    actual = actual -> next;
              }
              
              prev -> next = newnode;
              newnode -> next = actual;
          }
      }
      return head;
}

struct node *deleteInAscendentList(struct node *head, int element)
{
    struct node *p, *q;
      
    if (head == NULL)
        printf("empty list. imposible delete element.\n");
    else
    {   
        if (element == head -> key)
        {
           q=head;
           head=head->next;
           free(q);
        }
        else
        {
            if(element<head->key)
                printf("element is not in list");
            p = NULL;
            q = head;
            while ((q != NULL) && (element > q -> key))
            {
                p = q;
                q = q -> next;
            }

            if((q != NULL) && (q->key == element))
            {
                p->next= q->next;
                free(q); 
            }else
              {
                   printf("element %d is not in list.\n",element);
              }
          }
      }
      return head;
}

void print_list(struct node *head)
{
     struct node *q; 
     q=head;
     while(q != NULL)
     {
            printf("%d ->", q->key);
            q=q->next;
     }
     printf("NULL\n");
}

int main()
{
    struct node *head;
    int element,operation;
    head = NULL;
    while(scanf("%d",&operation)!= EOF)
    {
                                 if(operation==1)
                                 {
                                                 scanf("%d",&element);
                                        head = InsertInAscendentList(head, element);
                                        print_list(head);          
                                 }else
                                 {
                                      if(operation==2)
                                      {
                                                      scanf("%d", &element);
                                                      head=deleteInAscendentList(head,element);
                                                      print_list(head);
                                      }else
                                      printf("invalid operation.\n");
                                 }
                                
    }
    return 0;
}
