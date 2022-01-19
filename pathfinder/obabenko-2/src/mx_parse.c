#include "../inc/pathfinder.h"

void mx_island_save(t_matrix *m) {
    int i = 0;
    for(; m->islands_save[i] != NULL; i++) {
        if(!mx_strcmp(m->islands_save[i], m->temp)) {
            return;
        }
    }
    m->islands_save[i] = mx_strdup(m->temp);
}


void mx_parse(t_valid *s, t_matrix *m, char **str_split) {
    char **tmp_br = NULL;
    char **tmp_islands = NULL;

    m->islands_save = NULL;
    m->islands_save = (char **)malloc(sizeof(char*) * s->h + 1);

    for(int i = 0; i <= s->h; i++) {
        m->islands_save[i] = NULL;
    }

    for(int i = 1; str_split[i]; i++) {
        tmp_br = mx_strsplit(str_split[i], ',');
        tmp_islands = mx_strsplit(tmp_br[0], '-');
        m->temp = mx_strdup(tmp_islands[0]);
        mx_island_save(m);

        free(m->temp);

        m->temp = mx_strdup(tmp_islands[1]);
        mx_island_save(m);
        free(m->temp);

        mx_del_strarr(&tmp_br);
        mx_del_strarr(&tmp_islands);
    }
}

