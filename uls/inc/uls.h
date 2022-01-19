#ifndef ULS_H
#define ULS_H

#include "libmx.h"


#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>

bool mx_cmp(void *a, void *b);
bool mx_cmp2(void *a, void *b);
int mx_check_files(t_list *dirs, int flag_l);
char *mx_handle_flag(char *name, int *ct_block);
bool mx_dir_handle(char *name, int flag_l);
char *mx_get_path(char *path);

void mx_col_print_l(t_list *list);
void mx_print_list(t_list *list);




#endif
