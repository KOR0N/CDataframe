/************************************************************/
/********************** Projet C ***************************/
/**********************************************************/

///Codé et rédigé par Jules Zivkovic et Alexandre Dauvel

// Le fichier "main.c" permet d'exécuter le programme principal et permet d'intérragir avec notre Dataframe par le biais de propositions de fonctionnalitées.
// Ce fichier à besoin de fonctions comprises dans le fichier "CDataframe.c"

#include <stdio.h>
#include "columns.c"
#include "CDataframe.c"

int main() {
    int val,l,r,rep,rep2;
    df CDataframe;
    CDataframe.title = "Feuille 1";
    printf("Bonjour et bienvenue dans notre système de Dataframe.\nPour commencer, veuillez remplir votre Dataframe.\n");
    remplir_CDataframe(&CDataframe);
    do {
        print_DF(&CDataframe);
        printf("\n Que voulez-vous faire :\n\n-----Affichage-----\n  1.Afficher des lignes.\n  2.Afficher des colonnes.\n\n-----Opérations-----\n  3.Ajouter une ligne de valeurs"
               "\n  4.Supprimer une ligne\n  5.Ajouter une colonne.\n  6.Supprimer une colonne.\n  7.Renommer le titre d’une colonne.\n  8.Vérifier l’existence d’une valeur.\n"
               "  9.Accéder/remplacer la valeur se trouvant dans une cellule.\n  10.Afficher les noms des colonnes.\n\n-----Analyse et Statistique-----\n  11.Afficher le nombre de lignes.\n"
               "  12.Afficher le nombre de colonnes.\n  13.Afficher le nombre de cellules contenant une valeur égale à x.\n  14.Afficher le nombre de cellules contenant une valeur supérieure à x."
               "\n  15.Afficher le nombre de cellules contenant une valeur inférieure à x.\n\n Autres. Quitter.\n\nVeuillez entrer votre choix:");
        scanf(" %d", &rep);
        switch (rep) {
            case 1:
                printf("\nVoulez vous:\n  1.Afficher toutes les lignes.\n  2.Afficher une partie des lignes. \n\nVeuillez entrer votre réponse :");
                scanf(" %d", &rep2);

                switch (rep2) {

                    case 1:
                        print_limied_row(&CDataframe, 1, CDataframe.nb_col);
                        break;

                    case 2:
                        printf("Veuillez entrer une limite des lignes à afficher (x:y) : ");
                        scanf(" %d:%d", &l, &r);
                        print_limied_row(&CDataframe, l, r);
                        break;

                    default:
                        printf("ERREUR. Choix invalide !");
                        break;
                }
                break;

            case 2:
                printf("\nVoulez vous:\n  1Afficher toutes les colonnes.\n  2.Afficher une partie des colonnes. \n\nVeuillez entrer votre réponse :");
                scanf(" %d", &rep2);
                switch (rep2) {
                    case 1:
                        print_limied_col(&CDataframe, 1, CDataframe.nb_col);
                        break;
                    case 2:
                        printf("Veuillez entrer une limite des lignes à afficher (x:y) : ");
                        scanf(" %d:%d", &l, &r);
                        print_limied_col(&CDataframe, 1, CDataframe.nb_col);
                        break;
                    default:
                        printf("ERREUR. Choix invalide !\n");
                        break;
                }
                break;

            case 3:
                add_row(&CDataframe);
                break;

            case 4:
                printf("\nQuelle ligne voulez-vous supprimer : ");
                scanf(" %d", &l);
                del_row(&CDataframe, l);
                break;

            case 5:
                add_col(&CDataframe);
                break;

            case 6:
                printf("\nQuelle colonne voulez-vous supprimer : ");
                scanf(" %d", &l);
                del_col(&CDataframe, l);
                break;

            case 7:
                printf("\nQuelle colonne voulez-vous renommer : ");
                scanf(" %d", &l);
                rename_col(&CDataframe, l);
                break;

            case 8:
                printf("\nQuelle valeur voulez-vous chercher : ");
                scanf(" %d", &val);
                if(find_val(&CDataframe, val)){
                    printf("\nLa valeur %d est présente dans le Dataframe !\n", val);
                }
                else{
                    printf("\nValeur non présente !\n");
                }
                break;

            case 9:
                printf("\nQuelle ligne de quelle colonne voulez-vous remplacer la valeur (colonne/ligne) : ");
                scanf(" %d/%d", &r, &l);
                change_val(&CDataframe, r-1, l-1);
                break;

            case 10:
                print_all_col_title(&CDataframe);
                break;

            case 11:
                print_nb_row(&CDataframe);
                break;

            case 12:
                print_nb_col(&CDataframe);
                break;

            case 13:
                printf("\nVeuillez entre une valeur pour vérifier le nombre de cellules égales à celle-ci : ");
                scanf(" %d", &val);
                printf("\nIl y a %d cellules égales à %d.\n",nb_egal_x(&CDataframe, val),val);
                break;

            case 14:
                printf("\nVeuillez entre une valeur pour vérifier le nombre de cellules supérieures à celle-ci : ");
                scanf(" %d", &val);
                printf("\nIl y a %d cellules supérieures à %d.\n",nb_sup_x(&CDataframe, val),val);
                break;

            case 15:
                printf("\nVeuillez entre une valeur pour vérifier le nombre de cellules inférieure à celle-ci : ");
                scanf(" %d", &val);
                printf("\nIl y a %d cellules inférieures à %d.\n",nb_inf_x(&CDataframe, val),val);
                break;

            default:
                return 0;
        }
    }while(rep>0 && rep<16);

    return 0;
}
