#ifndef __UTILS_H
#define __UTILS_H

char *retain_alnum(const char *str);
char *get_workdir_path(const char *dirname);
bool dir_exists(const char *dirpath);
char *get_file_path(char *parent_dir, char *name, char *suffix);

#endif
