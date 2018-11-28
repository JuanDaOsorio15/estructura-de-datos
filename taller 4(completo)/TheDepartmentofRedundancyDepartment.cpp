#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct nodeTree
{
  int key;
  int times;
  int pos;
  struct nodeTree *Left;
  struct nodeTree *Right;
  struct nodeTree *p;
};

void InorderTreeWalk(struct nodeTree *x)
{
  if(x != NULL)
  {
    InorderTreeWalk(x->Left);
    printf("%d %d\n", x->key, x->times);
    InorderTreeWalk(x->Right);
  }
}

struct nodeTree *TreeSearch(struct nodeTree *x, int k)
{
    if ((x == NULL) || (k == x->key))
        return x;  
    if(k < x->key)
        return TreeSearch(x->Left,k);
    else
        return TreeSearch(x->Right,k);
}

struct nodeTree *TreeMinimum(struct nodeTree *x)
{
    while (x->Left != NULL)
    {
        x = x->Left;
    }
  return x;
}

struct nodeTree *TreeMaximun(struct nodeTree *x)
{
    while (x->Right != NULL)
    {
        x = x->Right;
    }
  return x;
}

struct nodeTree *TreeSuccessor(struct nodeTree *x)
{
    if (x->Right != NULL)
        return TreeMinimum(x->Right);

    struct nodeTree *y;
    y = x->p;
    while ((y != NULL) && (x == y->Right))
    {
        x = y;
        y = y->p;
    }
    return y;
}

struct nodeTree *TreePredeccessor(struct nodeTree *x)
{
    if (x->Left != NULL)
        return TreeMinimum(x->Left);
    struct nodeTree *y;
    y = x->p;
    while ((y != NULL) && (x == y->Left))
    {
        x = y;
        y = y->p;
    }
    return y;
}

struct nodeTree *TreeInsert(struct nodeTree *T, int k, int val)
{
    struct nodeTree *x, *y, *z;
    z = (struct nodeTree *) malloc(sizeof(struct nodeTree));
    z->pos = k;
    z->key = val;
    z->times = 1;
    z->Left = NULL;
    z->Right = NULL;
    y = NULL;
    x = T;

    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->Left;
        else
            x = x->Right;
    }
    z->p = y;

    if (y == NULL) 
        T = z;
    else 
    {
        if (z->key < y->key)
            y->Left = z;
        else
            y->Right = z;
    }
  return T;
}

struct nodeTree *TreeDelete(struct nodeTree *T, struct nodeTree *z)
{
    struct nodeTree *x, *y;
    if ((z->Left == NULL) || (z->Right == NULL))
        y = z;
    else
        y = TreeSuccessor(z);

    if (y->Left != NULL)
        x = y->Left;
    else
        x = y->Right;

    if (x != NULL)
        x->p = y->p;

    if (y->p == NULL)
        T = x;
    else
    {
        if (y == y->p->Left)
            y->p->Left = x;
        else
            y->p->Right = x;
    }
    if (y != z)
    {
        z->key = y->key;
        z->pos = y->pos;
        z->times = y->times;
        //Campos de informacion.
    }
    free(y);
    return T;
}

int main()
{
    struct nodeTree *T, *z;
    int val, order = 0,arrayOriginalOrder[100005], idArray=0, totalDifferentElements;

    T = NULL;

    while(scanf("%d", &val) != EOF)
    {
        if(TreeSearch(T, val) != NULL)
            TreeSearch(T, val)->times++;
        else
        {
            order++;
            arrayOriginalOrder[order] = val;
            T = TreeInsert(T, order, val);
        }
    }
    totalDifferentElements = order;

    for(idArray=1; idArray<=totalDifferentElements; idArray++)
    {
        z = TreeSearch(T, arrayOriginalOrder[idArray]);
        printf("%d %d\n", z->key, z->times);
    }
  return 0;
}