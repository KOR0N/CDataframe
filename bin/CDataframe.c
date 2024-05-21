/************************************************************/
/********************** Projet C ***************************/
/**********************************************************/

///Codé et rédigé par Jules Zivkovic et Alexandre Dauvel

// Le fichier "CDataframe.c" contient des fonctions permettant d'intérragir avec le Dataframe, comme par exemple pour modifier ou récupérer des données.
// Certaines fonctions ont notamment besoin d'autre fonctions comprises dans le fichier "columns.c"
// Il sera utilisé par le fichier "main.c"

#include <stdio.h>
#include <stdlib.h>
#include "columns.h"
#include "CDataframe.h"

/// Créer un Dataframe selon des paramètres et de le remplir
void remplir_CDataframe(df * DF){
    int val = 0, nb_val = 0;
    char col_title[20];
    printf("Veuillez entrer un nombre de colonnes à ajouter :\n");
    scanf(" %d",&DF->nb_col);

    // Alloue l'espace nécessaire pour n colonnes
    DF->col = malloc(DF->nb_col * sizeof(int));

    // Création de chaque colonnes
    for(int i=0; i<DF->nb_col; i++){
        val = 0;
        do{
            printf("Veuillez entrer un nom pour la colonne %d (max 6) :\n",i+1);
            scanf("%s", col_title);
        }while(strlen(col_title)>6);

        // Création de la colonne avec le titre
        COLUMN *col = create_column(col_title);
        (DF->col)[i] = col;
        printf("Veuillez entrer un nombre de valeurs à ajouter :\n");
        scanf(" %d",&nb_val);

        // Remplissage de la colonne pour n valeurs renseignées
        while(nb_val>0) {
            printf("Veuillez entrez une valeur :\n");
            scanf(" %d", &val);
            insert_value((DF->col)[i], val);
            nb_val--;
        }
    }
}

/// Afficher le Dataframe
void print_DF(df* DF) {
    int max_Tp = 0;
    printf("\nAffichage du Dataframe :\n");
    for (int i = 0; i < DF->nb_col; i++) {
        printf("*-------");
    }

    printf("*\n");

    // Affichage des titres de chaque colonnes
    for (int i = 0; i < DF->nb_col; i++) {
        printf("|%s\t", DF->col[i]->title);
        // Obtention de la taille physique de la plus grande colonne pour stopper l'affichage des lignes
        if (DF->col[i]->TP > max_Tp) {
            max_Tp = DF->col[i]->TP;
        }
    }

    printf("|\n");

    for (int i = 0; i < DF->nb_col; i++) {
        printf("*-------");
    }

    printf("*\n");

    for (int i = 0; i < max_Tp; i++) {
        for (int j = 0; j < DF->nb_col; j++) {

            // Affichage des valeurs des lignes de chaque colonnes si la taille du tableau est supérieure à l'indice
            if (DF->col[j]->TP > i) {
                printf("|%d\t", DF->col[j]->tab[i]);
            }
            // Sinon afficher une cellule vide
            else {
                printf("|\t");
            }
        }

        printf("|\n");
    }
}

/// Afficher une partie des colonnes du Dataframe (l et r un intervalle [l:r] soit l-> le début et r-> la fin)
void print_limied_row(df* DF,int l, int r){
    int max_Tp = 0;

    // Message d'erreur si la première l est inférieur à 1 ou supérieur à la deuxième ou
    if(l>r || l<1){
        printf("Erreur. Valeurs invalides ! ");
    }

    else{
        printf("\n");
        for (int i = 0; i < DF->nb_col; i++) {
            printf("*-------");
        }

        printf("*\n");

        // Affichage des titres de chaque colonnes
        for (int i = 0; i < DF->nb_col; i++) {
            printf("|%s\t", DF->col[i]->title);

            // Obtention de la taille physique de la plus grande colonne pour stopper l'affichage des lignes
            if (DF->col[i]->TP > max_Tp) {
                max_Tp = DF->col[i]->TP;
            }
        }

        printf("|\n");

        for (int i = 0; i < DF->nb_col; i++) {
            printf("*-------");
        }

        printf("*\n");

        // Affichage des lignes de chaque colonnes comprises dans l'intervalle [l:r]
        for(int i = l-1; i < r; i++)
        {
            for(int j=0; j<DF->nb_col; j++){
                // Affichage des valeurs des colonnes si la taille du tableau est supérieure à l'indice
                if(DF->col[j]->TP >= i+1) {
                    printf("|%d\t", DF->col[j]->tab[i]);
                }
                // Sinon afficher une cellule vide
                else {printf("|\t");}
            }
            printf("|\n");
        }
        printf("\n");
    }
}

/// Afficher une partie des lignes du Dataframe (l et r un intervalle [l:r] soit l-> le début et r-> la fin)
void print_limied_col(df*DF,int l, int r){
    int max_Tp = 0;

    // Verifie s'il n'y a pas d'erreurs avec les valeurs renseignées
    if(l>r || l<1 || r>DF->nb_col){
        printf("Erreur. Valeurs invalides ! ");
    }
    else {
        printf("\n");

        for (int i = 0; i < r - l + 1; i++) {
            printf("*-------");
        }
        printf("*\n");

        // Affichage des titres des colonnes comprises dans l'intervalle [l:r]
        for (int i = 0; i < r - l + 1; i++) {
            printf("|%s\t", DF->col[i + l - 1]->title);
            if (DF->col[i + l - 1]->TP > max_Tp) {
                max_Tp = DF->col[i + l - 1]->TP;
            }
        }
        printf("|\n");

        for (int i = 0; i < r - l + 1; i++) {
            printf("*-------");
        }
        printf("*\n");

        // Affichage des lignes de chaque colonnes
        for (int i = 0; i < max_Tp; ++i) {
            for (int j = 0; j < r - l + 1; ++j) {
                // Affichage des valeurs des colonnes si la taille du tableau est supérieure à l'indice
                if (i < DF->col[j + l - 1]->TP) {
                    printf("|%d\t", DF->col[j + l - 1]->tab[i]);
                }
                // Sinon afficher une cellule vide
                else { printf("|\t"); }
            }
            printf("|\n");
        }
        printf("\n");
    }
}

/// Ajouter une ligne au Dataframe
void add_row(df* DF){
    int val = 0;
    for (int i = 0; i < DF->nb_col; ++i) {
        printf("Veuillez entrer une valeur à ajouter pour la colonne '%s':\n",DF->col[i]->title);
        scanf(" %d",&val);

        // Ajout de la valeur à la fin de chaque colonnes
        insert_value(DF->col[i], val);
    }
}

/// Supprimer une ligne donné en paramètre du Dataframe
void del_row(df* DF, int row_index) {
    if (DF == NULL || row_index < 0) {
        printf("Ligne invalide.\n");
        return;
    }

    for (int i = 0; i < DF->nb_col; i++) {
        COLUMN *col = DF->col[i];

        // Ne prête pas attention si la taille physique de la colonne est supérieure à l'index donné
        if (row_index >= col->TP) {
            continue;
        }

        // Déplacer les lignes suivantes pour combler le vide
        for (int j = row_index; j < col->TP - 1; j++) {
            col->tab[j] = col->tab[j + 1];
        }

        // Réduire le nombre de lignes pour chaque colonne
        col->TP--;
    }
}

/// Ajouter une colonne au Dataframe
void add_col(df* DF){
    char title[20];
    printf("Veuillez saisir un nom à votre nouvelle colonne :\n");
    scanf(" %s",title);

    // Création de la nouvelle colonne avec son titre
    COLUMN* col = create_column(title);
    (DF->col)[DF->nb_col] = col;

    // Augmenter le nombre de colonnes
    DF->nb_col++;
}

/// Supprimer une colonne donné en paramètre du Dataframe
void del_col(df* DF, int col_index) {
    if (DF == NULL || col_index < 0 || col_index >= DF->nb_col) {
        printf("Colonne invalide.\n");
        return;
    }

    // Libérer la mémoire de la colonne à supprimer
    delete_column(&(DF->col[col_index]));

    // Déplacer les colonnes suivantes pour combler le vide
    for (int i = col_index; i < DF->nb_col - 1; i++) {
        DF->col[i] = DF->col[i + 1];
    }

    // Réduire le nombre de colonnes
    DF->nb_col--;

    // Réallouer la mémoire du tableau de colonnes pour économiser de l'espace
    DF->col = (COLUMN**)realloc(DF->col, DF->nb_col * sizeof(COLUMN*));
}

/// Renommer une colonne donné en paramètre
void rename_col(df* DF, int col_index){
    char title[20];
    printf("\nQuel nom voulez-vous donner à votre colonne :\n");
    scanf(" %s", title);

    // Attribution du nouveau nom à la colonne
    DF->col[col_index]->title = title;
}

/// Trouver une valeur dans le Dataframe
int find_val(df* DF, int val){
    for (int i = 0; i < DF->nb_col; ++i){

        // Si son occurence est supérieure à 0, la valeur a été trouvé
        if (val_occurence(DF->col[i], val)) {
            return 1;
        }
    }
    return 0;
}

/// Changer la valeur d'une colonne et d'une ligne donné
void change_val(df* DF, int r, int l){
    int val;
    printf("\nVeuillez entrer une valeur :\n");
    scanf(" %d",&val);

    // Changement de la valeur
    DF->col[r]->tab[l] = val;
}

/// Affichage des titres de toutes les colonnes
void print_all_col_title(df* DF){
    printf("\n");
    for (int i = 0; i < DF->nb_col; ++i) {
        printf("| %s ", DF->col[i]->title);
    }
    printf("|\n");
}

/// Afficher le nombre de lignes dans le Dataframe
void print_nb_row(df* DF){
    int max_tp = 0;
    for (int i = 0; i < DF->nb_col; ++i) {

        // Récupère la taille physique la plus grande dans toues les colonnes
        if(max_tp<DF->col[i]->TP){
            max_tp = DF->col[i]->TP;
        }
    }
    printf("Il y a %d lignes dans votre Dataframe",max_tp);
}

/// Afficher le nombre de colonnes dans le Dataframe
void print_nb_col(df* DF){
    printf("Il y a %d colonnes dans votre Dataframe",DF->nb_col);
}

/// Retourne le nombre de cellules ayant la même valeur que celle donné
int nb_egal_x(df* DF, int val){
    int occ = 0;
    for (int i = 0; i < DF->nb_col; ++i) {
        // Ajout de l'occurence de la valeur cherchée pour chaque colonnes
        occ += val_eg(DF->col[i], val);
    }
    return occ;
}

/// Retourne le nombre de cellules ayant une valeur supérieure à celle donné
int nb_sup_x(df* DF, int val){
    int occ = 0;
    for (int i = 0; i < DF->nb_col; ++i) {
        // Ajout de l'occurence des valeurs cherchées pour chaque colonnes
        occ += val_sup(DF->col[i], val);
    }
    return occ;
}

/// Retourne le nombre de cellules ayant une valeur inférieure à celle donné
int nb_inf_x(df* DF, int val){
    int occ = 0;
    for (int i = 0; i < DF->nb_col; ++i) {
        // Ajout de l'occurence des valeurs cherchées pour chaque colonnes
        occ += val_inf(DF->col[i], val);
    }
    return occ;
}