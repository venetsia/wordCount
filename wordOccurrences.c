/* 
 * C Program to Find the Frequency of  Every Word in a 
 * given String
 */
#include <stdio.h>
#include <string.h>
#include "functions.h"
 
wordOccurences(char *input, FILE *output)
{
    int count = 0, c = 0, i, j = 0, k, space = 0;
    char str[100], p[50][100], str1[20], ptr1[50][100];
    char *ptr;
 
   // printf("Enter the string\n");
    //scanf(" %[^\n]s", input);
    printf("string length is %d\n", strlen(input));
    for (i = 0;i<strlen(input);i++)
    {
        if ((input[i] == ' ')||(input[i] == ', ')||(input[i] == '.'))
        {
            space++;
        }
    }
    for (i = 0, j = 0, k = 0;j < strlen(input);j++)
    {
        if ((input[j] == ' ')||(input[j] == 44)||(input[j] == 46))  
        {    
            p[i][k] = '\0';
            i++;
            k = 0;
        }        
        else
             p[i][k++] = input[j];
    }
    k = 0;
    for (i = 0;i <= space;i++)
    {
        for (j = 0;j <= space;j++)
        {
            if (i == j)
            {
                strcpy(ptr1[k], p[i]);
                k++;
                count++;
                break;
            }
            else
            {
                if (strcmp(ptr1[j], p[i]) != 0)
                    continue;
                else
                    break;
            }
        }
    }
    for (i = 0;i < count;i++) 
    {
        for (j = 0;j <= space;j++)
        {
            if (strcmp(ptr1[i], p[j]) == 0)
                c++;
        }
		
		fprintf(output,"%s -> %d times\n", ptr1[i], c);
        c = 0;
    }
}

wordOccurencesForFile(FILE *fp, int cFLag, FILE *output)
{
	fseek(fp, 0, SEEK_END);
	long fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *str = (char*)malloc(fsize + 1);
   fread(str, fsize, 1, fp);
   fclose(fp);

   str[fsize] = 0;
   int count = 0, c = 0, i, j = 0, k, space = 0;
   char p[1000][512], str1[512], ptr1[1000][512];
   char *ptr;
	
	if ( fp )
	{	
		for (i = 0;i<strlen(str);i++)
		{
			if (cFLag == 1)
			{
				//ignoring punctuation 	
				if(str[i] == ',' || str[i] == '.' || str[i] == '!' 
				|| str[i] == '?' || str[i] == '"' || str[i] == ':' 
				|| str[i] ==';' || str[i] == '-')
				{
					str[i] = ' ';
				}
			}
			
			if ((str[i] == ' ')||(str[i] == ',')||(str[i] == '.'))
			{
				space++;
			}
		}
		
		for (i = 0, j = 0, k = 0;j < strlen(str);j++)
		{
			if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))
			{
				p[i][k] = '\0';
				i++;
				k = 0;
			}
			else
			{	
				if (cFlag == 1)
				{
					//find upperCase letters
					if(str[j] >= 'A' && str[j] <= 'Z')
					{
						//overwrite to lowerCase
						str[j] = tolower(str[j]);
						
					}//end of if statement
				}
				
				p[i][k++] = str[j];
			}
		}
	
	   k = 0;
		for (i = 0;i <= space;i++)
		{
			for (j = 0;j <= space;j++)
			{
				if (i == j)
				{
					strcpy(ptr1[k], p[i]);
					k++;
					count++;
					break;
				}
				else
				{
					if (strcmp(ptr1[j], p[i]) != 0)
					continue;
					else
					break;
				}
			}
		}
		
		for (i = 0;i < count;i++)
		{
			for (j = 0;j <= space;j++)
			{
				if (strcmp(ptr1[i], p[j]) == 0)
				c++;
			}
			fprintf(output,"%s %d \n", ptr1[i], c);
			c = 0;
		}
	}
	 else
    {
        printf("Failed to open the file\n");
	}
}
