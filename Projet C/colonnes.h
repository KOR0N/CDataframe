
#ifndef PROGRAMMATION_EN_C_FUNCTIONS_H
#define PROGRAMMATION_EN_C_FUNCTIONS_H

#define REALOCSIZE 256

typedef struct {
    char* title;
    int *tab;
    int TP;
    int TL;
} COLUMN;

typedef struct{
    char* title;
    int nb_col;
    COLUMN** col;
}df;



void remplir_Dataframe(COLUMN ** CDataframe,int n);

/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN *create_column(char* title);


/**
* @brief : Add a new value to a column
* @param1 : Pointer to a column
* @param2 : The value to be added
* @return : 1 if the value is added 0 otherwise
*/
int insert_value(COLUMN* col, int value);


/**
* @brief : Free allocated memory
* @param1 : Pointer to a column
*/
void delete_column(COLUMN **col);


/**
* @brief: Print a column content
* @param: Pointer to a column
*/
void print_col(COLUMN* col);

/**
* @brief: Count the occurence of value in a column
* @param1: Pointer to a column
* @param2: The occurence of value to search
*/
int val_occurence(COLUMN* col, int x);

/**
* @brief: Return the value at gived position
* @param1: Pointer to a column
* @param2: The position in the column
*/
int position_val(COLUMN* col, int x);

int val_sup(COLUMN* col, int x);

int val_inf(COLUMN* col, int x);

int val_eg(COLUMN* col, int x);

#endif //PROGRAMMATION_EN_C_FUNCTIONS_H
