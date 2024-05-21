#ifndef PROJET_C_CDATAFRAME_H
#define PROJET_C_CDATAFRAME_H

#include "columns.h"

typedef struct{
    char* title;
    int nb_col;
    COLUMN** col;
}df;

/**
* @brief : Remplit un DataFrame avec des colonnes et des valeurs saisies par l'utilisateur.
* @param1 : Pointeur vers le DataFrame à remplir.
* @return : Aucun retour.
*/
void remplir_CDataframe(df * DF);

/**
* @brief : Affiche l'intégralité du DataFrame.
* @param1 : Pointeur vers le DataFrame à afficher.
* @return : Aucun retour.
*/
void print_DF(df* DF);

/**
* @brief : Affiche une partie des lignes du DataFrame spécifiées par un intervalle.
* @param1 : Pointeur vers le DataFrame.
* @param2 : Indice de début de l'intervalle.
* @param3 : Indice de fin de l'intervalle.
* @return : Aucun retour.
*/
void print_limied_row(df* DF,int l, int r);

/**
* @brief : Affiche une partie des colonnes du DataFrame spécifiées par un intervalle.
* @param1 : Pointeur vers le DataFrame.
* @param2 : Indice de début de l'intervalle.
* @param3 : Indice de fin de l'intervalle.
* @return : Aucun retour.
*/
void print_limied_col(df*DF,int l, int r);

/**
* @brief : Ajoute une ligne au DataFrame.
* @param1 : Pointeur vers le DataFrame.
* @return : Aucun retour.
*/
void add_row(df* DF);

/**
* @brief : Supprime une ligne spécifiée dans le DataFrame.
* @param1 : Pointeur vers le DataFrame.
* @param2 : Indice de la ligne à supprimer.
* @return : Aucun retour.
*/
void del_row(df* DF, int row_index);

/**
* @brief : Ajoute une colonne au DataFrame.
* @param1 : Pointeur vers le DataFrame.
* @return : Aucun retour.
*/
void add_col(df* DF);

/**
* @brief : Supprime une colonne spécifiée dans le DataFrame.
* @param1 : Pointeur vers le DataFrame.
* @param2 : Indice de la colonne à supprimer.
* @return : Aucun retour.
*/
void del_col(df* DF, int col_index) ;

/**
* @brief : Renomme une colonne spécifiée dans le DataFrame.
* @param1 : Pointeur vers le DataFrame.
* @param2 : Indice de la colonne à renommer.
* @return : Aucun retour.
*/
void rename_col(df* DF, int col_index);

/**
* @brief : Recherche une valeur dans le DataFrame.
* @param1 : Pointeur vers le DataFrame.
* @param2 : Valeur à rechercher.
* @return : 1 si la valeur est trouvée, 0 sinon.
*/
int find_val(df* DF, int val);

/**
* @brief : Change la valeur d'une cellule spécifiée dans le DataFrame.
* @param1 : Pointeur vers le DataFrame.
* @param2 : Indice de la colonne.
* @param3 : Indice de la ligne.
* @return : Aucun retour.
*/
void change_val(df* DF, int r, int l);

/**
* @brief : Affiche les titres de toutes les colonnes du DataFrame.
* @param1 : Pointeur vers le DataFrame.
* @return : Aucun retour.
*/
void print_all_col_title(df* DF);

/**
* @brief : Affiche le nombre de lignes dans le DataFrame.
* @param1 : Pointeur vers le DataFrame.
* @return : Aucun retour.
*/
void print_nb_row(df* DF);

/**
* @brief : Affiche le nombre de colonnes dans le DataFrame.
* @param1 : Pointeur vers le DataFrame.
* @return : Aucun retour.
*/
void print_nb_col(df* DF);

/**
* @brief : Retourne le nombre de cellules ayant une valeur égale à celle donnée.
* @param1 : Pointeur vers le DataFrame.
* @param2 : Valeur à comparer.
* @return : Le nombre de cellules ayant la valeur spécifiée.
*/
int nb_egal_x(df* DF, int val);

/**
* @brief : Retourne le nombre de cellules ayant une valeur supérieure à celle donnée.
* @param1 : Pointeur vers le DataFrame.
* @param2 : Valeur à comparer.
* @return : Le nombre de cellules ayant une valeur supérieure à celle spécifiée.
*/
int nb_sup_x(df* DF, int val);

/**
* @brief : Retourne le nombre de cellules ayant une valeur inférieure à celle donnée.
* @param1 : Pointeur vers le DataFrame.
* @param2 : Valeur à comparer.
* @return : Le nombre de cellules ayant une valeur inférieure à celle spécifiée.
*/
int nb_inf_x(df* DF, int val);

#endif //PROJET_C_CDATAFRAME_H

