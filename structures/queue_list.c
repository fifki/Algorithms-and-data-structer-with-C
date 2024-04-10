#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// On ajoute un 1 car il faut toujours au moins un espace vide dans la Queue.
#define TAILLE 101
#define next(x) ((x+1) % TAILLE)

typedef struct Cell{
    int val;
    struct Cell * next ;
  
} Cell;

typedef struct {
    Cell * first ;
    Cell * last;
} Queue;

/* Init allocates the structure Queue and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
Queue * Init(int size);

/* InsertValue insert value into the binary Queue
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void EnQueue(Queue * queue, int value);

/* ExtractMAx returns 0 if the binary Queue is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary Queue
 * filled is decremented by 1  and the max value is removed
 * from the binary Queue */
int DeQueue(Queue * queue, int * val);

//int Vide(Queue * queue);

//int Pleine(Queue * queue);

/* Destroy frees the structure and the array */
void Destroy(Queue * queue);


int main(void) 
{
  char lecture[100];
  int val;
  Queue * queue;
  queue = Init(10);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"queue")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      EnQueue(queue,val);
    } else if (strcmp(lecture,"dequeue")==0) {
      if(DeQueue(queue,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(queue);
  return 0;
}
/*/
int Vide(Queue * Queue)
{
    return Queue->F == Queue->D;
}

int Pleine(Queue * Queue)
{
    return next(Queue->F) == Queue->D;
}*/

Queue * Init(int size)
{
  Queue * queue;
  queue = ( Queue*)malloc(sizeof(Queue));
  queue->first= NULL;
  queue->last=NULL;
  return queue;
}

void EnQueue(Queue * queue, int value)
{
    Cell * c =(Cell*) malloc(sizeof(Cell));
    c->val=value;
    c->next=NULL;
    if(!queue->last){
        queue->first=c;
    }
    else{
        queue->last->next=c;
    }
    queue->last=c;
}


int DeQueue(Queue * queue, int *res)
{
  if(!queue->first)// if first is NULL
  {
    return 0;
  }
  Cell * toFree=queue->first;
  *res = queue->first->val;
  queue->first=queue->first->next;
  if(!queue->first){
    queue->last=NULL;
  }
  free(toFree);
  return 1;
 /**
  *res = queue->tab[queue->D];
  queue->D = next(queue->D);

  return 1;
  */
}

void Destroy(Queue * queue)
{
	free(queue);
}
