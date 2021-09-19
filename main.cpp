#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000


 FILE * fPtr;
 FILE * fTemp;

   char *oldWord=NULL ,*newWord=NULL;

   char buff[BUFFER_SIZE];


 int replica(char *oldWord,char *newWord);
void replaceAll(char *str, char *oldWord, char *newWord);

int main()
{





   char *str[1000];
    char *str1[1000];
  int i=0;

   int j=0;







    FILE *fp = fopen("french_dictionary.csv","r");

   fPtr  = fopen("t8.shakespeare.txt", "r");
    fTemp = fopen("replace.txt", "w");

   if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
       printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }




    if(!fp){
        printf("error occured");
        return 0;
    }
    else{
           char buffer[1024];


        int row = 0;
        int column = 0;


        while (fgets(buffer,1024, fp)) {
            column = 0;
            row++;
            int i=0,j=0;
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(buffer, ", ");






            while (value)
                // Column 1+-*
{


                if (column == 0) {
                    str[i]=value;

                   oldWord=str[i];

                    i++;






                }

                // Column 2
                if (column == 1) {

                    str1[j]=value;
                    newWord=str1[j];
                    j++;





                }





                value = strtok(NULL, ", ");
                column++;





            }





              replica(oldWord,newWord);
              printf("\n");


            }









}
}






    int replica(char *oldWord,char *newWord)
    {


    while ((fgets(buff, BUFFER_SIZE, fPtr)) != NULL)
    {
        // Replace all occurrence of word from current line
        printf("%s %s",oldWord,newWord);
        replaceAll(buff, oldWord, newWord);

        // After replacing write it to temp file.
            fputs(buff, fTemp);

    }








    /* Delete original source file */


    /* Rename temp file as original file */
    rename("replace.txt", "t8.shakespeare.txt");

    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.", oldWord, newWord);

    return 0;

    }











    void replaceAll(char *str,  char *oldWord, char *newWord)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);

    // Fix: If oldWord and newWord are same it goes to infinite loop
    if (!strcmp(oldWord, newWord)) {
        return;
    }


    /*
     * Repeat till all occurrences are replaced.
     */
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        // Backup current line
        strcpy(temp, str);


        // Index of current found word
        index = pos - str;

        // Terminate str after word found index
        str[index] = '\0';

        // Concatenate str with new word
        strcat(str, newWord);

        // Concatenate str with remaining words after
        // oldword found index.
        strcat(str, temp + index + owlen);


    }
}

        // Close the file
