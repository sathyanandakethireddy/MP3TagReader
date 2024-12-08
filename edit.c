#include "main.h"
#include "edit.h"
STATUS edit_tag(char *filename,char *tag,char *value)
{
   FILE *fptr1=fopen(filename,"r+");
   if(fptr1==NULL)
   {
      perror("Error in opening file:");
      exit(1);
   } 
   char id[4];
    fread(id, sizeof(char), 3, fptr1);  
    id[3] = '\0';

    if (strcmp(id, "ID3") == 0) 
    {
      unsigned char version[2];
      fread(version, sizeof(char), 2, fptr1);
      if (version[0] == 0x03 && version[1] == 0x00) 
      {
         if(find_editable_tag(fptr1,tag,value)==SUCCESS)
         {
            return SUCCESS;
         }
      }
    }
    return FAILURE;
   
}
STATUS find_editable_tag(FILE *fptr1,char *tag,char *value)
{
   fseek(fptr1,10,SEEK_SET);
   if(strcmp(tag,"TIT2")==0)
   {
      if(edit_title(fptr1,value)==SUCCESS)
      {
        printf("Title Edited Successfully:\n");
      }
      else
      {
         printf("Title Not Edited Successfully:\n");
         return FAILURE;
      }
   }
   skip_the_pointer(fptr1);
   if(strcmp(tag,"TPE1")==0)
   {
      if(Artist_name(fptr1,value)==SUCCESS)
      {
        printf("Artist_name Edited Successfully:\n");
      }
      else
      {
         printf("Artist_name Not Edited Successfully:\n");
         return FAILURE;
      }
   }
   skip_the_pointer(fptr1);
   if(strcmp(tag,"TALB")==0)
   {
      if(Album_name(fptr1,value)==SUCCESS)
      {
        printf("Album name Edited Successfully:\n");
      }
      else
      {
         printf("Album name Not Edited Successfully:\n");
         return FAILURE;
      }
   }
   skip_the_pointer(fptr1);
   if(strcmp(tag,"TYER")==0)
   {
      if(year(fptr1,value)==SUCCESS)
      {
        printf("Year Edited Successfully:\n");
      }
      else
      {
         printf("Year Not Edited Successfully:\n");
         return FAILURE;
      }
   }
   skip_the_pointer(fptr1);
   if(strcmp(tag,"TCON")==0)
   {
      if(content(fptr1,value)==SUCCESS)
      {
        printf("Content Edited Successfully:\n");
      }
      else
      {
         printf("Content Not Edited Successfully:\n");
         return FAILURE;
      }
   }
   skip_the_pointer(fptr1);
   if(strcmp(tag,"COMM")==0)
   {
      if(composer(fptr1,value)==SUCCESS)
      {
        printf("Composer Edited Successfully:\n");
      }
      else
      {
         printf("Composer Not Edited Successfully:\n");
         return FAILURE;
      }
   }

   
   return SUCCESS;
   

}
STATUS edit_title(FILE *fptr1,char *value)
{
   fseek(fptr1,4,SEEK_CUR);
   int size;
   fread(&size,sizeof(int),1,fptr1);
   little_to_end(&size);
   fseek(fptr1,2,SEEK_CUR);
   char buff[size];
   strcpy(buff,value);
   int i=0;
   while(buff[i]!='\0')
   {
      i++;
   }
   for(int j=i;j<size;j++)
   {
      buff[j]='\0';
   }
   fwrite(buff,1,size,fptr1);
   return SUCCESS;
}
STATUS Artist_name(FILE *fptr1,char *value)
{
   fseek(fptr1,4,SEEK_CUR);
   int size;
   fread(&size,sizeof(int),1,fptr1);
   little_to_end(&size);
   fseek(fptr1,2,SEEK_CUR);
   char buff[size];
   strcpy(buff,value);
   int i=0;
   while(buff[i]!='\0')
   {
      i++;
   }
   for(int j=i;j<size;j++)
   {
      buff[j]='\0';
   }
   fwrite(buff,1,size,fptr1);
   return SUCCESS;
}
STATUS Album_name(FILE *fptr1,char *value)
{
   fseek(fptr1,4,SEEK_CUR);
   int size;
   fread(&size,sizeof(int),1,fptr1);
   little_to_end(&size);
   fseek(fptr1,2,SEEK_CUR);
   char buff[size];
   strcpy(buff,value);
   int i=0;
   while(buff[i]!='\0')
   {
      i++;
   }
   for(int j=i;j<size;j++)
   {
      buff[j]='\0';
   }
   fwrite(buff,1,size,fptr1);
   return SUCCESS;
}
STATUS year(FILE *fptr1,char *value)
{
   fseek(fptr1,4,SEEK_CUR);
   int size;
   fread(&size,sizeof(int),1,fptr1);
   little_to_end(&size);
   fseek(fptr1,2,SEEK_CUR);
   char buff[size];
   strcpy(buff,value);
   int i=0;
   while(buff[i]!='\0')
   {
      i++;
   }
   for(int j=i;j<size;j++)
   {
      buff[j]='\0';
   }
   fwrite(buff,1,size,fptr1);
   return SUCCESS;
}
STATUS content(FILE *fptr1,char *value)
{
   fseek(fptr1,4,SEEK_CUR);
   int size;
   fread(&size,sizeof(int),1,fptr1);
   little_to_end(&size);
   fseek(fptr1,2,SEEK_CUR);
   char buff[size];
   strcpy(buff,value);
   int i=0;
   while(buff[i]!='\0')
   {
      i++;
   }
   for(int j=i;j<size;j++)
   {
      buff[j]='\0';
   }
   fwrite(buff,1,size,fptr1);
   return SUCCESS;
}
STATUS composer(FILE *fptr1,char *value)
{
   fseek(fptr1,4,SEEK_CUR);
   int size;
   fread(&size,sizeof(int),1,fptr1);
   little_to_end(&size);
   fseek(fptr1,2,SEEK_CUR);
   char buff[size];
   strcpy(buff,value);
   int i=0;
   while(buff[i]!='\0')
   {
      i++;
   }
   for(int j=i;j<size;j++)
   {
      buff[j]='\0';
   }
   fwrite(buff,1,size,fptr1);
   return SUCCESS;
}
void skip_the_pointer(FILE *fptr1)
{
   fseek(fptr1,4,SEEK_CUR);
   int size;
   fread(&size,sizeof(int),1,fptr1);
   little_to_end(&size);
   fseek(fptr1,2,SEEK_CUR);
   fseek(fptr1,size,SEEK_CUR);
}
