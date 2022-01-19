#include "../inc/pathfinder.h"

void mx_adj_matrix(t_valid *s, t_matrix *m) {
    int c = 0;
    int r = 0;

    m->matrix_adj = (long int**)malloc(sizeof(long int*) * s->h);

    for(int i = 0; i < s->h; i++) {
        m->matrix_adj[i] = (long int*)malloc(sizeof(long int) * s->h);
    }

    for(c = 0; c < s->h; c++, r++) {
        for(r = 0; r < s->h; r++) {
            m->matrix_adj[c][r] = m->matrix_first[c][r];
        }
    }
}

