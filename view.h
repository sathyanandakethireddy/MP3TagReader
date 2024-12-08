#ifndef VIEW_H
#define VIEW_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tag_information
{
   char Title[200];
   char artistname[50];
   char Album[50];
   char Year[10];
   char contenttype[50];
   char composer[50];

}TagData;



STATUS checkversion(FILE *fptr);
STATUS view_tag(FILE *fptr,char *name);
void view_tags(const char *filename);


#endif
