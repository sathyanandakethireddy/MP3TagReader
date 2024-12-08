#include "main.h"
#include "view.h"
STATUS checkversion(FILE *fptr) 
{
    char id[4];
    fread(id, sizeof(char), 3, fptr);  
    id[3] = '\0';

    if (strcmp(id, "ID3") == 0) {
        unsigned char version[2];
        fread(version, sizeof(char), 2, fptr);
        if (version[0] == 0x03 && version[1] == 0x00) {
            return SUCCESS;
        }
    }
    return FAILURE;
}
void view_tags(const char *filename) 
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) 
    {
        perror("Error in opening file");
        exit(1);
    }
    if(checkversion(fptr)==SUCCESS)
    {
        rewind(fptr); 
        fseek(fptr, 10, SEEK_SET); 
        printf("Title: ");
        if(view_tag(fptr,"TIT2")==SUCCESS)
        {
            printf("Artist Name : ");
            if(view_tag(fptr,"TPE1")==SUCCESS)
            {
                printf("Album : ");
                if(view_tag(fptr,"TALB")==SUCCESS)
                {
                    printf("Year : ");
                    if(view_tag(fptr,"TYER")==SUCCESS)
                    {
                        printf("Content: ");
                        if(view_tag(fptr,"TCON")==SUCCESS)
                        {
                           printf("Comment: ");
                           if(view_tag(fptr,"COMM")==SUCCESS)
                           {
                               printf("All Tags Are Extracted Successfully\n");
                           }
                           else
                           {
                               printf("Comment Tag not Extracted");
                           }
                        }
                        else
                        {
                            printf("Content Tag not Extracted");
                        }
                    }
                    else
                    {
                        printf("Year Tag not Extracted");
                    }
                }
                else
                {
                    printf("Album Tag not Extracted");
                }
            }
            else
            {
                printf("artist Tag not Extracted");
            }
        }
        else
        {
            printf("Title Tag not Extracted");
        }
    }
}

STATUS view_tag(FILE *fptr,char *name)
{
    char Tag[5];
    fread(Tag, sizeof(char), 4, fptr);
    Tag[4] = '\0'; 
    if (strcmp(Tag, name) == 0) 
    {
        int size;
        fread(&size, sizeof(int), 1, fptr);
        little_to_end(&size); 
        fseek(fptr,2, SEEK_CUR);
        char ch;
        for(int i=0;i<size;i++)
        {
            fread(&ch,1,1,fptr);
            printf("%c",ch);
        }
        printf("\n");
    }
    else
    {
        return FAILURE;
    }
    return SUCCESS;
}
