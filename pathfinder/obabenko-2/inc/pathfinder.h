#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"
#define INT_MAX 2147483647

typedef struct s_valid {
    char *value;
    int i, j;
    int h;
    int n;
    int c;

}   t_valid;

typedef struct s_matrix {
    char **islands_save;
    int count_bridge;
    char **bridge;
    int *value;
    long int **matrix_first;
    char *temp;
    long int **matrix_adj;
    int *way;
    int waypt;

}   t_matrix;



void mx_file_errors(const char *file);
void mx_errors(int argc, char **argv);
void mx_parse(t_valid *s, t_matrix *m, char **str_split);
void mx_filling_matrix(t_matrix *m, t_valid *s, char **str_split);
void mx_adj_matrix(t_valid *s, t_matrix *m);



#endif

