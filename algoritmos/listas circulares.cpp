#include <stdio.h>


#include <stdlib.h>
#include <math.h>

struct node{
       int key;
       struct node *next;
};

struct node *insertincircularlist ( struct node *tail,  int element)
{
       struct node *p;
       p = (struct node *) malloc (sizeof(struct node));
       p -> key = element;
       if (tail == NULL )
       {
                p -> next = p;
                tail = p;
       } 
       else
       {
           p -> next = tail -> next;
           tail -> next = p;
           tail = p;
       }
       return tail;
}

void printcircularlist (struct node *tail)
{
     struct node *actual ,*previo;
     if(tail==NULL)
     {
               printf("the list its empty.\n");
     }
     else
     {
         previo= NULL;
         actual=tail->next;
         while(previo != tail)
         {
                      printf("%d->",actual -> key);
                      previo=actual;
                      actual=previo->next;
         } 
         printf(". . .\n");
     }
}


struct node *DeleteCircularList(struct node *tail)
{
      struct node *actual;
      
      if (tail == NULL)
      {
         printf("Imposible delete of list. The list is empty.\n");
      }
      else
      {
          if (tail -> next == tail)
          {
             free(tail);
             tail = NULL;
          }
          else
          {
               actual = tail -> next;
               tail -> next = actual -> next;
               free(actual);
          }
      }
      return tail;
}

/*struct node *DeleteElementCircularList(struct node *tail,int element)
{
      struct node *actual, *prev;
      
      if (tail == NULL)
      {
         printf("Imposible delete of list. The list is empty.\n");
      }
      else
      {
      if(tail->next==tail)
      {
              if(tail->key == element)
              {
                   free(tail);
                   tail= NULL;
              }
              else
                  printf("element %d is not in list.\n",element);
       }
       else
       {
          prev = NULL;
          actual = tail -> next;
          while ((prev != tail) && (actual -> key != element))
          {
               prev = actual;
               actual = actual -> next;
          }
          if (actual -> key == element)
          {
            if (prev == NULL)
               prev = tail;
            if (actual == tail)
               tail = prev;
            prev -> next = actual -> next;
            free(actual);
          }
          else
          {
              printf("Element %d is not in the list", element);
          }
      }
      }
      return tail;             
}   
*/

int main()
{
    struct node *tail;
    int element,operation;
    tail = NULL;
    while(scanf("%d", &operation) != EOF)
    {
                      if (operation == 1)
                      {
                                    scanf("%d",&element);
                                    tail= insertincircularlist(tail,element);
                                    printcircularlist(tail);
                      }
                      else
                      {
                          if(operation == 2)
                          {
                                       //
                                       scanf("%d",&element);
                                       tail=DeleteCircularList(tail);
                                       printcircularlist(tail);
                          }
                      }
    }
    return 0;
}
