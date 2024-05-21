
#ifndef PROGRAMMATION_EN_C_FUNCTIONS_H
#define PROGRAMMATION_EN_C_FUNCTIONS_H

#define REALOCSIZE 256

typedef struct {
    char* title;
    int *tab;
    int TP;
    int TL;
} COLUMN;

/**
* @brief : Crée une nouvelle colonne avec un titre donné.
* @param1 : Titre de la colonne à créer.
* @return : Pointeur vers la nouvelle colonne créée.
*/
COLUMN *create_column(char* title);


/**
* @brief : Insère une valeur dans une colonne.
* @param1 : Pointeur vers la colonne.
* @param2 : Valeur à insérer.
* @return : 0 si la valeur est insérée avec succès, 1 en cas d'erreur.
*/
int insert_value(COLUMN* col, int value);


/**
* @brief : Supprime une colonne et libère la mémoire associée.
* @param1 : Double pointeur vers la colonne à supprimer.
* @return : Aucun retour.
*/
void delete_column(COLUMN **col);


/**
* @brief : Affiche le contenu d'une colonne.
* @param1 : Pointeur vers la colonne à afficher.
* @return : Aucun retour.
*/
void print_col(COLUMN* col);

/**
* @brief : Retourne le nombre d'occurrences d'une valeur donnée dans une colonne.
* @param1 : Pointeur vers la colonne.
* @param2 : Valeur à rechercher.
* @return : Nombre d'occurrences de la valeur dans la colonne.
*/
int val_occurence(COLUMN* col, int x);

/**
* @brief : Retourne la valeur à une position donnée dans une colonne.
* @param1 : Pointeur vers la colonne.
* @param2 : Position de la valeur à retourner.
* @return : Valeur à la position donnée, ou 0 si la position est invalide.
*/
int position_val(COLUMN* col, int x);

/**
* @brief : Retourne le nombre de cellules ayant une valeur supérieure à celle donnée.
* @param1 : Pointeur vers la colonne.
* @param2 : Valeur à comparer.
* @return : Nombre de cellules ayant une valeur supérieure à celle spécifiée.
*/
int val_sup(COLUMN* col, int x);

/**
* @brief : Retourne le nombre de cellules ayant une valeur inférieure à celle donnée.
* @param1 : Pointeur vers la colonne.
* @param2 : Valeur à comparer.
* @return : Nombre de cellules ayant une valeur inférieure à celle spécifiée.
*/
int val_inf(COLUMN* col, int x);

/**
* @brief : Retourne le nombre de cellules ayant une valeur égale à celle donnée.
* @param1 : Pointeur vers la colonne.
* @param2 : Valeur à comparer.
* @return : Nombre de cellules ayant une valeur égale à celle spécifiée.
*/
int val_eg(COLUMN* col, int x);

#endif //PROGRAMMATION_EN_C_FUNCTIONS_H
