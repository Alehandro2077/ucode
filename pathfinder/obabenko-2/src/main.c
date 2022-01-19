#include "../inc/pathfinder.h"

void mx_islands_value(t_valid *s, char *str) {
    int i = 0;
    
    while (str[i] != '\n')
        i++;
    s->value = mx_strnew(i - 1);
    for (i = 0; str[i] != '\n'; i++) {
        s->value[i] = str[i];
    }
    s->h = mx_atoi(s->value);
}


void mx_first_matrix(t_valid *s, t_matrix *m) {
    m->matrix_first = (long int **)malloc(sizeof(long int *) * s->h);

    for(int i = 0; i < s->h; i++) {
        m->matrix_first[i] = (long int *)malloc(sizeof(long int) * s->h);
    }

    for(int c = 0; c < s->h; c++) {
        for(int r = 0; r < s->h; r++) {
            m->matrix_first[c][r] = INT_MAX;
            if(c == r) {
                m->matrix_first[c][r] = 0;
            }
        }
    }
}

int mx_short_path(t_matrix *m, int k) {
    int i = m->way[m->waypt];
    int j = m->way[0];

    if(i != k) {
        if(m->matrix_first[i][k] == m->matrix_adj[j][i] - m->matrix_adj[j][k]) {
            return 1;
        }
    }

    return 0;
}

void mx_print_boundary() {
    mx_printstr("========================================\n");
}

void mx_print(t_valid *s, t_matrix *m) {
    if(m->way[m->waypt] == m->way[0]) {
        mx_print_boundary();

        mx_printstr("Path: ");
        mx_printstr(m->islands_save[m->way[1]]);
        mx_printstr(" -> ");
        mx_printstr(m->islands_save[m->way[m->waypt]]);
        mx_printstr("\n");

        mx_printstr("Route: ");
        for (int i = 1; i <= m->waypt; i++)
        {
            mx_printstr(m->islands_save[m->way[i]]);
            if (i < m->waypt)
                mx_printstr(" -> ");
            else
                mx_printstr("\n");
        }


        int distance = 0;

        mx_printstr("Distance: ");
        for (int i = 1; i < m->waypt; i++)
        {
            mx_printint((int)m->matrix_first[m->way[i]][m->way[i + 1]]);
            distance += (int)m->matrix_first[m->way[i]][m->way[i + 1]];
            if (i < m->waypt - 1)
                mx_printstr(" + ");
            else if (i != 1)
            {
                mx_printstr(" = ");
                mx_printint(distance);
            }
        }
        mx_printstr("\n");

        mx_print_boundary();
    }
    else {
        for (int k = 0; k < s->h; k++) {
            if (mx_short_path(m, k))
            {
                if (m->waypt < s->h)
                {
                    m->waypt++;
                    m->way[m->waypt] = k;
                }
                mx_print(s, m);
                if (m->waypt > 1)
                    m->waypt--;
            }
        }
    } 
}


int main(int argc, char *argv[]) {
    mx_errors(argc, argv);

    char *str = mx_file_to_str(argv[1]);
    char **str_split = mx_strsplit(str, '\n');

    t_valid s;
    t_matrix m;

    mx_islands_value(&s, str);
    mx_parse(&s, &m, str_split);

    for(s.i = 1; str_split[s.i]; s.i++);
    m.count_bridge = s.i - 1;

    long int d = 0;
    int f = 0;
    int j = 0;

    m.value = (int*)malloc(sizeof(int) * m.count_bridge);

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ',' || str[i] == '\n') {
            str[i] = '-';
        }
    }

    m.bridge = mx_strsplit(str, '-');

    for(int i = 0; m.bridge[i]; i++) {
        f++;
    }

    for(int i = 3; i < f; i += 3) {
        d += mx_atoi_long(m.bridge[i]);
        m.value[j] = mx_atoi_long(m.bridge[i]);
        j++;
    }

    mx_first_matrix(&s, &m);
    mx_filling_matrix(&m, &s, str_split);
    mx_adj_matrix(&s, &m);


    for(int k = 0; k < s.h; k++) {
        for(int i = 0; i < s.h; i++) {
            for(int j = i + 1; j < s.h; j++) {
                if(m.matrix_adj[i][k] != INT_MAX
                && m.matrix_adj[k][j] != INT_MAX
                && m.matrix_adj[i][j] > m.matrix_adj[i][k] + m.matrix_adj[k][j]) {
                    m.matrix_adj[i][j] = m.matrix_adj[i][k] + m.matrix_adj[k][j];
                    m.matrix_adj[j][i] = m.matrix_adj[i][j];
                }
            }
        }
    }

    m.way = (int*)malloc(sizeof(int) * s.h);

    for(int i = 0; i < s.h; i++) {
        for(int j = i + 1; j < s.h; j++) {
            int way_b = i;
            int way_e = j;

            for(int k = 0; k < s.h; k++) {
                m.way[k] = 0;
            }

            m.waypt = 1;
            m.way[0] = way_e;
            m.way[1] = way_b;

            mx_print(&s, &m);
        }
    }

    for (int f = 0; str_split[f]; f++) {
        free(str_split[f]);
    }

    free(str_split);
    free(str);

    return 0;
}

