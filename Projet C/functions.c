#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colonnes.h"

COLUMN *create_column(char* title){
    COLUMN *mycol = NULL;
    mycol = (COLUMN*)malloc(sizeof(COLUMN));
    mycol->title = malloc(sizeof(char)*(strlen(title)+1));
    strcpy(mycol->title,title);
    mycol->tab = NULL;
    mycol->TP = 0;
    mycol->TL = 0;
    return mycol;
}

int insert_value(COLUMN* col, int value){
    if(col == NULL){
        printf("Erreur d'allocation !\n");
        return 1;
    }
    if(col->TP == col->TL) {
        col->TL += REALOCSIZE;
        col->tab = realloc(col->tab, col->TL * sizeof(int));
    }
    (col->tab)[col->TP] = value;
    col->TP += 1;
    return 1;

}

void delete_column(COLUMN **col)
{
    free((*col)->tab);
    free((*col)->title);
    free(*col);
    *col = NULL;
}

void print_col(COLUMN* col)
{
    for(int i = 0; i < (col->TP); i++)
    {
        //IL faut recommencer et changer la version (C99 ou C11)
        printf("[%d] %d\n",i,(col->tab)[i]);
    }
}

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

int position_val(COLUMN* col, int x)
{
    if(x > col->TP)
    {
        return 0;
    }
    else
    {
        return (col->tab)[x];
    }
}

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

/// CDataframe Functions ///
void remplir_CDataframe(df * DF){
    int val = 0, nb_val = 0;
    char col_title[20];
    for(int i=0; i<DF->nb_col; i++){
        val = 0;
        printf("Veuillez entrer un nom pour la colonne %d :\n",i+1);
        scanf("%s", col_title);
       // gets(col_title);
        COLUMN *col = create_column(col_title);
        printf("%s",col->title);
        (DF->col)[i] = col;
        printf("Veuillez entrer un nombre de valeurs à ajouter :\n");
        scanf(" %d",&nb_val);
        while(nb_val>0) {
            printf("Veuillez entrez une valeur :\n");
            scanf(" %d", &val);
            insert_value((DF->col)[i], val);
            nb_val--;
        }
    }
}

void print_DF(df* DF){
    int max_Tp = 0, decalage;
    printf("\n");
    for(int i = 0; i<DF->nb_col; i++) {
        printf("%s\t",DF->col[i]->title);
        if(DF->col[i]->TP > max_Tp){
            max_Tp = DF->col[i]->TP;
        }
    }
    printf("\n");
    for(int i = 0; i<max_Tp; i++){
        for(int j = 0; j<DF->nb_col; j++){
            decalage = strlen(DF->col[j]->title);
            for(int k = 0; k <decalage/2; k++){
                printf(" ");
            }
            if(DF->col[j]->TP > i){
                printf("%d\t",DF->col[j]->tab[i]);
            }
            else{
                printf(" \t");
            }
        }
        printf("\n");
    }
}