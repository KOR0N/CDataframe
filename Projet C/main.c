#include <stdio.h>
#include "functions.c"
#include "CDataframe.c"

int main() {
    df CDataframe;
    CDataframe.title = "Feuille 1";
    printf("Veuillez entrer un nombre de colonnes à ajouter :\n");
    scanf(" %d",&CDataframe.nb_col);
    CDataframe.col = malloc(CDataframe.nb_col * sizeof(int));
    remplir_CDataframe(&CDataframe);
    print_DF(&CDataframe);

    //COLUMN *mycol = create_column("My column");
    //printf("%s\n",mycol->title);
    //int n = 0, val = 0;

    //printf("Veuillez choisir un nombre de valeurs à entrer : ");
    //scanf(" %d",&n);

    //for (int i = 0; i<n ; i++)
    //{
      //  printf("\nVeuillez choisir une valeur : ");
        //scanf(" %d",&val);
        //if (insert_value(mycol, val)) {
          //  printf("Value added successfully to my column\n");
        //}
        //else {
          //  printf("Error adding value to my column\n");
        //}
    //}

    //print_col(mycol);

    return 0;
}
