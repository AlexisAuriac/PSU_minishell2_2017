/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Contains the prototypes of all the functions exposed by libmy.a.
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdbool.h>

#define ALLOW "abcdefghijklmnopqrstuvwxyz"
#define ALUP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUM "0123456789"
#define ALPHA_NUM ALLOW ALUP NUM "_"

#define READ_SIZE 1

//write
void my_putchar(char c);
__attribute__((nonnull))
void my_putstr(char const *str);
void my_put_nbr(int nb);
__attribute__((format (printf, 1, 2), nonnull (1)))
void my_printf(const char *str, ...);

//conversion
__attribute__((nonnull))
int my_getnbr(char const *str);

//files
__attribute__((warn_unused_result))
char *get_next_line(int fd);
__attribute__((nonnull (2)))
void my_fputs(int fd, const char *str);
void my_fputc(int fd, const char c);
void my_fput_nbr(int fd, int n);
__attribute__((format (printf, 2, 3), nonnull (2)))
void my_fprintf(int fd, const char *str, ...);

//alloc
__attribute__((warn_unused_result))
void *my_realloc(void *ptr, int const size);
__attribute__((nonnull (1)))
void *my_memset(void *s, char c, size_t n);
__attribute__((nonnull))
void my_free_array(void **arr);

//my_str -> infos
__attribute__((nonnull, warn_unused_result))
int my_strlen(char const *str);
__attribute__((nonnull, warn_unused_result))
int my_strcmp(char const *s1, char const *s2);
__attribute__((nonnull (1, 2), warn_unused_result))
int my_strncmp(char const *s1, char const *s2, int n);
__attribute__((nonnull (2), warn_unused_result))
bool in_str(char const c, char const *str);
__attribute__((nonnull (2), warn_unused_result))
int my_rindex(const char c, const char *str);
__attribute__((nonnull, warn_unused_result))
bool my_str_is(const char *str, const char *allowed);
__attribute__((nonnull, warn_unused_result))
bool my_str_is_signednum(char *str);
__attribute__((nonnull, warn_unused_result))
int my_strstr(const char *haystack, const char *needle);

//my_str -> word array
__attribute__((nonnull, warn_unused_result))
char **my_str_split(const char *str, const char *seps);
__attribute__((nonnull, warn_unused_result))
int my_strlen_tab(void * const *arr);

//my_str -> write
__attribute__((nonnull))
int my_strcpy(char *dest, char const *src);
__attribute__((nonnull (1, 2)))
char *my_strncpy(char *dest, char const *src, int n);
__attribute__((nonnull))
char *my_strcat(char *dest, char const *src);
__attribute__((nonnull))
char *my_revstr(char *str);
__attribute__((nonnull, warn_unused_result))
char *my_strdup(char const *str);
char *my_append(char *str, char const *cat);
__attribute__((nonnull (1, 2), format (printf, 2, 3)))
void my_sprintf(char *str, const char *format, ...);

#endif