#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
   int data;
   struct node *next;
} NodeT;

NodeT *makeNode(int v)
{
   NodeT *new = malloc(sizeof(NodeT));
   assert(new != NULL);
   new->data = v;    // initialise data
   new->next = NULL; // initialise link to next node
   return new;       // return pointer to new node
}

int inLL(NodeT *list, int d)
{
   NodeT *p;
   for (p = list; p != NULL; p = p->next)
      if (p->data == d) // element found
         return true;
   return false; // element not in list
}

void showLL(NodeT *list)
{
   NodeT *p;
   for (p = list; p != NULL; p = p->next)
      if (p->next == NULL)
         printf("%d", p->data);
      else
         printf("%d-->", p->data);
}

NodeT *insertLL(NodeT *list, int d)
{
   NodeT *new = makeNode(d); // create new list element
   new->next = list;         // link to beginning of list
   return new;               // new element is new head
}

NodeT *appendLL(NodeT *list, int d)
{
   NodeT *new = makeNode(d); // create new list element
   new->next = NULL;
   NodeT *p = list;
   
   // if list is empty, just return the new node as the head 
   if (list == NULL) {
      return new;
   }

   while (p->next != NULL)
   {
      p = p->next;
   }
   p->next = new;
   return list;
}

NodeT *deleteHead(NodeT *list)
{
   assert(list != NULL); // ensure list is not empty
   NodeT *head = list;   // remember address of first element
   list = list->next;    // move to second element
   free(head);
   return list; // return pointer to second element
}

void freeLL(NodeT *list)
{
   NodeT *p, *temp;

   p = list;
   while (p != NULL)
   {
      temp = p->next;
      free(p);
      p = temp;
   }
}

int main(void)
{
   int *n = malloc(sizeof(int));
   assert(n != NULL);

   NodeT *list = NULL; // list must be instantiated as NULL --> new nodes will point to null, otherwise the linked list will point at an uninitiated value

   printf("Enter an integer: ");
   while (scanf("%d", n) == 1)
   {
      //   list = insertLL(list, *n);
      list = appendLL(list, *n);
      printf("Enter an integer: ");
   }


   if (list == NULL) {
      printf("Done.");
   } else {
      printf("Done. List is ");
      showLL(list);
   }
   
   printf("\n");
   freeLL(list);

   return 0;
}

// scp llcreate.c z5114919@login.cse.unsw.edu.au:~/9024/pracs/prac_4
