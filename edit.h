#ifndef EDIT_H
#define EDIT_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
STATUS edit_tag(char *filename, char *tag, char *value);
STATUS find_editable_tag(FILE *fptr1,char *tag,char *value);

STATUS edit_title(FILE *fptr1,char *value);
STATUS Artist_name(FILE *fptr1,char *value);
STATUS Album_name(FILE *fptr1,char *value);
STATUS year(FILE *fptr1,char *value);
STATUS content(FILE *fptr1,char *value);
STATUS composer(FILE *fptr1,char *value);
void skip_the_pointer(FILE *fptr1);
#endif
