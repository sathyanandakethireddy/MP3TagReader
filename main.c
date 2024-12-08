#include "main.h"
#include "view.h"
#include "edit.h"
void display_help() 
{
   printf("-----------------------HELP MENU-----------------------\n");
   printf("1. -v -> to view mp3 file contents\n");
   printf("2. -e -> to edit mp3 file contents\n");
   printf("         2.1. -t -> to edit song title\n");
   printf("         2.2. -a -> to edit artist name\n");
   printf("         2.3. -A -> to edit album name\n");
   printf("         2.4. -y -> to edit year\n");
   printf("         2.5. -m -> to edit content\n");
   printf("         2.6. -c -> to edit comment\n");
   printf("----------------------------------------------------------\n");
   

}
int main(int argc, char *argv[]) 
{
    if (argc < 2)
    {
        printf("------------------------------------------------------\n");
	    printf("ERROR : ./a.out : INVALID ARGUMENTS\n");
	    printf("USAGE: \nTo view please pass like : ./a.out -v mp3filename\n");
	    printf("To edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
	    printf("To get help pass like : ./a.out --help\n");
	    printf("------------------------------------------------------\n");
        return 1;
    }
    if(strcmp(argv[1],"--help")==0)
    {
        printf("Selected For Display Help Menu:");
        display_help();
    }
    else if (strcmp(argv[1], "-v") == 0 && argc == 3) 
    {
        printf("Selected the view Tags Option\n");
        view_tags(argv[2]);
    }
   else if (strcmp(argv[1], "-e") == 0 && argc == 5) 
    {
        char *tag = argv[2];
        char *value = argv[3];
        char *filename = argv[4];
        if (edit_tag(filename, tag, value)==FAILURE)
        {
            printf("Failed to edit tag.");
            return 1;
        }
        printf("Tag edited successfully.\n");
    } 
    else 
    {
        printf("Error:In Entering The arguments,see The Help Menu,And try The Correct Input Format");
        display_help();
        return 1;
    }

    return 0;
}
void little_to_end(int *size)
{
    char *ch=(char *)(size);
    char temp1=*(ch+0);
    *(ch+0)=*(ch+3);
    *(ch+3)=temp1;

    char temp2=*(ch+1);
    *(ch+1)=*(ch+2);
    *(ch+2)=temp2;


}

