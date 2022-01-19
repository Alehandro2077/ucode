#include "../inc/pathfinder.h"

void mx_get_index_island(t_matrix *m, t_valid *s, char *tmp_island, int *index) {
    for(int i = 0; i < s->h; i++) {
        if(!mx_strcmp(tmp_island, m->islands_save[i])) {
            (*index) = i;
            return;
        }
    }
}


void mx_filling_matrix(t_matrix *m, t_valid *s, char **str_split) {
    int c = 0;
    int r = 0;

    char **tmp_islands = NULL;
    char **tmp_bridges = NULL;

    for(int i = 0; i <m->count_bridge; i++) {
        tmp_bridges = mx_strsplit(str_split[i+1], ',');
        tmp_islands = mx_strsplit(tmp_bridges[0], '-');

        mx_get_index_island(m, s, tmp_islands[0], &c);
        mx_get_index_island(m, s, tmp_islands[1], &r);

        m->matrix_first[c][r] = m->value[i];
        m->matrix_first[r][c] = m->value[i];

        if(tmp_islands) {
            mx_del_strarr(&tmp_islands);
        }
        if(tmp_bridges) {
            mx_del_strarr(&tmp_bridges);
        }

    }
}

