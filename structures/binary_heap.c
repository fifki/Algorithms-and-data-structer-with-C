#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define left(i)  (2*(i)+1)
#define right(i)  (2*(i)+2)
#define parent(i)  (((i)-1)/2)

typedef struct {
  int allocated; /* current allcoation of array */
  int filled;    /* number of items present in the binheap */
  int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);

void Print(BinaryHeap * h ){
    int i;
    for(i=0;i<h->filled; i++){
        printf("| %d", h->array[i]);
    }
    printf("\r\n");
}

int main(void) 
{
  char lecture[100];
  int val;
  BinaryHeap * heap;
  heap = Init(10);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"insert")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(heap,val);
    } else if (strcmp(lecture,"extract")==0) {
      if(ExtractMax(heap,&val))
      {
        printf("%d\r\n",val);
      }
    }
    Print(heap);
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(heap);
  return 0;
}

BinaryHeap * Init(int size)
{
  BinaryHeap * heap;
  heap = malloc(sizeof(BinaryHeap));
  heap->allocated = size;
  heap->filled = 0;
  heap->array = malloc(sizeof(int)*size);
  return heap;
}

#define swap(i,j) tmp (i):(i)=(j):(j)=tmp

void InsertValue(BinaryHeap * heap, int value)
{
     if (heap->filled == heap->allocated) 
        {
                heap->allocated += 10;
                heap->array = (int*) realloc(heap->array, sizeof(int) * heap->allocated);
        }

        
        heap->array[heap->filled] = value;
        int current = heap->filled;
        while (heap->array[current] > heap->array[parent(current)] )
        {
                int temp = heap->array[parent(current)];
                heap->array[parent(current)] = heap->array[current];
                heap->array[current] = temp;
                current = parent(current);
        }
        heap->filled++;




}

int ExtractMax(BinaryHeap * heap, int *res)
{
  if (heap->filled == 0)
		{
				return 0;
		}
		
    *res = heap->array[0];
    heap->array[0] = heap->array[heap->filled-1];
    heap->array[heap->filled-1] = 0;
    heap->filled--;
    		int index = 0;
		//Tant qu'il existe un noeud fils qui a une valeur plus grande
		while ((left(index) < heap->filled && heap->array[index] < heap->array[left(index)])
			|| (right(index) < heap->filled && heap->array[index] < heap->array[right(index)]))
		{
				//Quel est le noeud qui existe et qui a la valeur maximale ?
				int next_index;
				if(left(index) < heap->filled && right(index) < heap->filled)
				{
					next_index = (heap->array[left(index)] > heap->array[right(index)]) ? left(index) : right(index);
				}
				else if(left(index) >= heap->filled)
				{
					next_index = right(index);
				}
				else if(right(index) >= heap->filled)
				{
					next_index = left(index);
				}
				
				//Echanger les valeurs avec ce noeud fils
				int tmp = heap->array[index];
				heap->array[index] = heap->array[next_index];
				heap->array[next_index] = tmp;
				
				index = next_index;
		}
		return 1;
}


void Destroy(BinaryHeap * heap)
{
	if (heap) {
		free(heap->array);
		free(heap);
	}
}