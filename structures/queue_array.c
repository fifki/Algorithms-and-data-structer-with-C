#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// On ajoute un 1 car il faut toujours au moins un espace vide dans la file.
#define TAILLE 101
#define next(x) ((x+1) % TAILLE)

typedef struct {
    int D;
    int F;
    int tab[TAILLE];
  
} File;

/* Init allocates the structure File and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
File * Init();

/* InsertValue insert value into the binary file
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void Empiler(File * file, int value);

/* ExtractMAx returns 0 if the binary file is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary file
 * filled is decremented by 1  and the max value is removed
 * from the binary file */
int Depiler(File * file, int * valDepilee);

int Vide(File * file);

int Pleine(File * file);

/* Destroy frees the structure and the array */
void Deconstruire(File * file);


int main(void) 
{
  char lecture[100];
  int val;
  File * file;
  file = Init();

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"queue")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      Empiler(file,val);
    } else if (strcmp(lecture,"dequeue")==0) {
      if(Depiler(file,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Deconstruire(file);
  return 0;
}

int Vide(File * file)
{
    return file->F == file->D;
}

int Pleine(File * file)
{
    return next(file->F) == file->D;
}

File * Init()
{
  File * file;
  file = malloc(sizeof(File));
  file->F = 0;
  file->D = 0;
  return file;
}

void Empiler(File * file, int value)
{
    if(!Pleine(file))
    {
        file->tab[file->F]=value;
        file->F=next(file->F);
    }
}


int Depiler(File * file, int *res)
{
  if(Vide(file))
  {
    return 0;
  }

  *res = file->tab[file->D];
  file->D = next(file->D);

  return 1;
  
}

void Deconstruire(File * file)
{
	if (file)
    {
		free(file);
	}
}
