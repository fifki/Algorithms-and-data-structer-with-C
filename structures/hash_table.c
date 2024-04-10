#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* mettez ici vos déclarations de fonctions et types */

#define VIDE 0
#define REMPLI 1
#define SUPPR 2

typedef char * Key, * Value;

typedef struct {
        int status;
        Key key;
        Value val;
} Cell;

typedef struct {
        Cell *tuples;
        int size;
} HashTable;

HashTable * Init(unsigned int size);

void Insert(HashTable* hTable, Key k, Value v);

void Delete(HashTable *h, Key k);

int Query(HashTable *hTable, Key k, Value *v);

void Stats(HashTable *hTable, int *empty, int *deleted, int *used);

void Destroy(HashTable* hTable);

void error(void);

int main(void)
{
	int size = 0, empty = 0, deleted = 0, used = 0;
	char lecture[100];
	char * key = NULL;
	char * val = NULL;

	HashTable *hashTable = NULL;

	if (fscanf(stdin, "%99s", lecture) != 1)
			error();
	while (strcmp(lecture, "bye") != 0)
	{
		if (strcmp(lecture, "init") == 0)
		{
			if (fscanf(stdin, "%99s", lecture) != 1)
					error();
			size = atoi(lecture);
			/* mettre le code d'initialisation ici */
			hashTable = Init(size);
		}
		else if (strcmp(lecture, "insert") == 0)
		{
			if (fscanf(stdin, "%99s", lecture) != 1)
					error();
			key = strdup(lecture);
			if (fscanf(stdin, "%99s", lecture) != 1)
					error();
			val = strdup(lecture);
			/* mettre ici le code d'insertion */
			Insert(hashTable, key, val);
		}
		else if (strcmp(lecture, "delete") == 0)
		{
			if (fscanf(stdin, "%99s", lecture) != 1)
					error();
			key = strdup(lecture);
			/* mettre ici le code de suppression */
			Delete(hashTable, key);
		}
		else if (strcmp(lecture, "query") == 0)
		{
			if (fscanf(stdin, "%99s", lecture) != 1)
					error();
			key = strdup(lecture);
			/* mettre ici le code de recherche et traitement/affichage du résultat */
			if(Query(hashTable, key, &val))
			{
				printf("%s\r\n", val);
			}
			else
			{
				printf("Not found\r\n");
			}
		}
		else if (strcmp(lecture, "destroy") == 0)
		{
			/* mettre ici le code de destruction */
			Destroy(hashTable);
		}
		else if (strcmp(lecture, "stats") == 0)
		{
			/* mettre ici le code de statistiques */
			Stats(hashTable, &empty, &deleted, &used);
			printf("size    : %d\r\n", size);
			printf("empty   : %d\r\n", empty);
			printf("deleted : %d\r\n", deleted);
			printf("used    : %d\r\n", used);
		}

		if (fscanf(stdin, "%99s", lecture) != 1)
			error();
	}
	return 0;
}

/* fonction de décalage de bit circulaire */
unsigned int shift_rotate(unsigned int val, unsigned int n)
{
	n = n % (sizeof(unsigned int) * 8);
	return (val << n) | (val >> (sizeof(unsigned int) * 8 - n));
}

/* fonction d'encodage d'une chaîne de caractères */
unsigned int Encode(Key key)
{
	unsigned int i;
	unsigned int val = 0;
	unsigned int power = 0;
	for (i = 0; i<strlen(key); i++)
	{
			val += shift_rotate(key[i], power * 7);
			power++;
	}
	return val;
}

/* fonction de hachage simple qui prend le modulo */
unsigned int hash(unsigned int val, unsigned int size)
{
	return val%size;
}

/* fonction de hachage complète à utiliser */
unsigned int HashFunction(Key key, unsigned int size)
{
	return hash(Encode(key), size);
}

/* placer ici vos définitions (implémentations) de fonctions ou procédures */

void error(void)
{
	printf("input error\r\n");
	exit(0);
}

HashTable * Init(unsigned int size)
{
	HashTable *hTable = (HashTable*) malloc(sizeof(HashTable));
	hTable->size = size;
	hTable->tuples = (Cell*) malloc(size * sizeof(Cell));
	int i=0;
	for (i=0; i<size; i++)
	{
		hTable->tuples[i].status = VIDE;
		hTable->tuples[i].key = "";
		hTable->tuples[i].val = "";
	}
	return hTable;
}

void Insert(HashTable* hTable, Key k, Value v)
{
	//Est-ce que la cle existe deja dans la table ?
	int indice = HashFunction(k, hTable->size);
	int indiceInit = indice;
	//La cle existe-t-elle a l'indice cible par la fonction de hachage ?
	if (strcmp(hTable->tuples[indice].key, k) == 0)
	{
		hTable->tuples[indice].val = v;
		hTable->tuples[indice].status = REMPLI;
		return;
	}
	//La cle existe-t-elle dans la suite de la table ?
	indice++;
	indice %= hTable->size;
	while(hTable->tuples[indice].status != VIDE && indice != indiceInit)
	{        
		if (strcmp(hTable->tuples[indice].key, k) == 0)
		{
			hTable->tuples[indice].val = v;
			hTable->tuples[indice].status = REMPLI;
			return;
		}
		indice++;
		indice %= hTable->size;
	}
	
	//La cle n'existe pas dans la table, il faut la rajouter au premier indice libre
	indice = indiceInit;
	if (hTable->tuples[indice].status != REMPLI)
	{
		hTable->tuples[indice].key = k;
		hTable->tuples[indice].val = v;
		hTable->tuples[indice].status = REMPLI;
		return;
	}
	indice++;
	indice %= hTable->size;
	while (hTable->tuples[indice].status == REMPLI && indice != indiceInit)
	{
		indice++;
		indice %= hTable->size;
	}
	if (indice != indiceInit)
	{
		hTable->tuples[indice].key = k;
		hTable->tuples[indice].val = v;
		hTable->tuples[indice].status = REMPLI;
		return;
	}
}

void Delete (HashTable *hTable, Key k)
{
	int indice = HashFunction(k, hTable->size);
	if (strcmp(hTable->tuples[indice].key, k) == 0)
	{
		hTable->tuples[indice].val = "";
		hTable->tuples[indice].key = "";
		hTable->tuples[indice].status = SUPPR;
		return;
	}
	int indiceInit = indice++;
	indice %= hTable->size;
	while (hTable->tuples[indice].status != VIDE && indice != indiceInit)
	{
		if (strcmp(hTable->tuples[indice].key, k) == 0)
		{
			hTable->tuples[indice].val = "";
			hTable->tuples[indice].key = "";
			hTable->tuples[indice].status = SUPPR;
			return;
		}
		indice++;
		indice %= hTable->size;
	}
	//la cle n'existe pas dans la table
}

int Query(HashTable *hTable, Key k, Value *v)
{
	int indice = HashFunction(k, hTable->size);
	if (strcmp(hTable->tuples[indice].key, k) == 0)
	{
		*v = hTable->tuples[indice].val;
		return 1;
	}
	int indiceInit = indice++;
	indice %= hTable->size;
	while (hTable->tuples[indice].status != VIDE && indice != indiceInit)
	{
		if (strcmp(hTable->tuples[indice].key, k) == 0)
		{
			*v = hTable->tuples[indice].val;
			return 1;
		}
		indice++;
		indice %= hTable->size;
	}
	return 0;
}

void Stats(HashTable *hTable, int *empty, int *deleted, int *used)
{
	*empty = 0;
	*deleted = 0;
	*used = 0;
	Cell *it = hTable->tuples;
	for(it = hTable->tuples; it < hTable->tuples + hTable->size; ++it)
	{
		if(it->status == VIDE)
			(*empty)++;
		else if(it->status == REMPLI)
			(*used)++;
		else if(it->status == SUPPR)
			(*deleted)++;
	}
}

void Destroy(HashTable *hTable)
{
	if(hTable != NULL)
	{
		if(hTable->tuples != NULL)
		{
			free(hTable->tuples);
		}
		free(hTable);
	}
}