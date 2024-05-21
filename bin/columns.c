/************************************************************/
/********************** Projet C ***************************/
/**********************************************************/

///Codé et rédigé par Jules Zivkovic et Alexandre Dauvel

// Le fichier "columns.c" contient des fonctions qui permettent d'intérragir sur des colonnes via des pointeurs.
// Il sera utilisé par le fichier "CDataframe.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "columns.h"

/// Création d'une structure de type COLUMN
COLUMN *create_column(char* title){
    COLUMN *mycol = NULL;
    // Allocation de la mémoire nécessaire
    mycol = (COLUMN*)malloc(sizeof(COLUMN));
    mycol->title = malloc(sizeof(char)*(strlen(title)+1));
    strcpy(mycol->title,title);
    mycol->tab = NULL;
    mycol->TP = 0;
    mycol->TL = 0;
    return mycol;
}

/// Insert une valeur dans le colonne
int insert_value(COLUMN* col, int value){

    // Vérification de l'existence de la colonne
    if(col == NULL){
        printf("Erreur d'allocation !\n");
        return 1;
    }
    // Reallocation de la mémoire si la tableau n'a plus de place (Taille physique = Taille logique)
    if(col->TP == col->TL) {
        col->TL += REALOCSIZE;
        col->tab = realloc(col->tab, col->TL * sizeof(int));
    }

    // Insertion de la valeur
    (col->tab)[col->TP] = value;
    col->TP += 1;
    return 0;

}

/// Suppression d'une colonne
void delete_column(COLUMN **col)
{
    // Libération de la mémoire
    free((*col)->tab);
    free((*col)->title);
    free(*col);
    *col = NULL;
}

/// Affichage d'une colonne
void print_col(COLUMN* col)
{
    printf("\n*-------*\n|%s\t|\n*-------*\n",col->title);
    for(int i = 0; i < (col->TP); i++)
    {
        printf("|%d\t|\n",(col->tab)[i]);
    }
}

/// Retourne l'occurence d'une valeur donné dans la colonne
int val_occurence(COLUMN* col, int x)
{
    int occ = 0;
    for(int i = 0; i < col->TP; i++)
    {
        if((col->tab)[i] == x)
        {
            occ +=1;
        }
    }
    return occ;
}

/// Retourne la valeur d'une position cherché dans le colonne
int position_val(COLUMN* col, int x)
{
    // Retourne O si la position est supérieure à la taille de la colonne
    if(x > col->TP)
    {
        return 0;
    }
    else
    // Retourne sinon la valeur
    {
        return (col->tab)[x];
    }
}

//// Retourne le nombre de cellules ayant une valeur égale à celle donné
int val_sup(COLUMN* col, int x)
{
    int occ = 0;
    for(int i = 0; i < col->TP; i++)
    {
        if ((col->tab)[i] > x)
        {
            occ += 1;
        }
    }
    return occ;
}

/// Retourne le nombre de cellules ayant une valeur supérieure à celle donné
int val_inf(COLUMN* col, int x)
{
    int occ = 0;
    for(int i = 0; i < col->TP; i++)
    {
        if ((col->tab)[i] < x)
        {
            occ += 1;
        }
    }
    return occ;
}

/// Retourne le nombre de cellules ayant une valeur inférieure à celle donné
int val_eg(COLUMN* col, int x)
{
    int occ = 0;
    for(int i = 0; i < col->TP; i++)
    {
        if ((col->tab)[i] == x)
        {
            occ += 1;
        }
    }
    return occ;
}
