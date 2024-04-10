#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 101
#define next(x) ((x+1) % TAILLE)

typedef struct {
    int sommet;
    int tab[TAILLE];
} Pile;

Pile * Init();
void Empiler(Pile * pile, int valeur);
int Depiler(Pile * pile, int * valDepilee);
int Vide(Pile * pile);
int Pleine(Pile * pile);
void Deconstruire(Pile * pile);
void AfficherPile(Pile * pile);

int main(void) 
{
    char lecture[100];
    int val;
    Pile * pile = Init();

    fscanf(stdin, "%99s", lecture);
    while (strcmp(lecture, "bye") != 0) {
        if (strcmp(lecture, "push") == 0) {
            fscanf(stdin, "%99s", lecture);
            val = strtol(lecture, NULL, 10);
            Empiler(pile, val);
        } else if (strcmp(lecture, "pop") == 0) {
            int poppedValue;
            if (Depiler(pile, &poppedValue)) {
                printf("Popped value: %d\n", poppedValue);
            } else {
                printf("Stack is empty.\n");
            }
        } else if (strcmp(lecture, "print") == 0) {
            AfficherPile(pile);
        }
        fscanf(stdin, "%99s", lecture);
    }
    Deconstruire(pile);
    return 0;
}

Pile * Init()
{
    Pile * pile = malloc(sizeof(Pile));
    pile->sommet = 0;
    return pile;
}

void Empiler(Pile * pile, int valeur)
{
    if (!Pleine(pile)) {
        pile->tab[pile->sommet] = valeur;
        pile->sommet = next(pile->sommet);
    }
}

int Depiler(Pile * pile, int *res)
{
    if (Vide(pile)) {
        return 0;
    }
    pile->sommet = (pile->sommet - 1 + TAILLE) % TAILLE;
    *res = pile->tab[pile->sommet];
    return 1;
}

int Vide(Pile * pile)
{
    return pile->sommet == 0;
}

int Pleine(Pile * pile)
{
    return pile->sommet == TAILLE - 1;
}

void Deconstruire(Pile * pile)
{
    if (pile) {
        free(pile);
    }
}

void AfficherPile(Pile * pile)
{
    printf("Stack content: ");
    if (Vide(pile)) {
        printf("Stack is empty.\n");
        return;
    }
    int i = (pile->sommet - 1 + TAILLE) % TAILLE;
    while (i != pile->sommet) {
        printf("%d ", pile->tab[i]);
        i = (i - 1 + TAILLE) % TAILLE;
    }
    printf("\n");
}
