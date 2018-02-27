/* * * * * * * * * ** * * * * * * * * * * */
/*  Author: Venetsia Krasteva 40313507    */
/*                                        */
/* Date of last modification : 27.02.2018 */
/*                                        */
/* Purpose of the program:                */
/*   C Program to Find the Frequency      */
/*   of  Every Word in a given String     */
/*                                        */
/* * * * * * * * * * * * * * * * * * * *  */

#include <stdio.h>
#include <string.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* The first wordOccurrences method is for when we take from stdin  *  				       *
*  							                                       *
*	Variables:                                                     *
*    - char input (stdin)                                          *
*	 - FILE *output (output file)                                  *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ** */
 
wordOccurences(char *input, FILE *output)
{
	//Initializing and Declaring
    int count = 0, c = 0, i, j = 0, k, space = 0;
    char str[100], p[50][100], str1[20], ptr1[50][100];
    char *ptr;
 
	// loops through the input 
    for (i = 0;i<strlen(input);i++)
    {
		// if there is a space a ',', a '.' or a newline
        if ((input[i] == ' ')||(input[i] == ', ')||(input[i] == '.') || (input[i] == '\n'))
        {
            space++; // the space increase
        }//end of if
		
    }// end of for
	
    for (i = 0, j = 0, k = 0;j < strlen(input);j++)
    {
        if ((input[j] == ' ')||(input[j] == 44)||(input[j] == 46))  
        {    
            p[i][k] = '\0';
            i++;
            k = 0;
        }//end of if  
		
        else
            p[i][k++] = input[j];
    }//end of for
	
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
            }// end of if
            else
            {
                if (strcmp(ptr1[j], p[i]) != 0)
                    continue;
                else
                    break;
            }//end of else
        }//end of for
    }//end of for
	
    for (i = 0;i < count;i++) 
    {
        for (j = 0;j <= space;j++)
        {
            if (strcmp(ptr1[i], p[j]) == 0)
                c++;
        }//end of for
		
		fprintf(output,"%s : %d times\n", ptr1[i], c);
        c = 0;
    }//end of for
}//end of method

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* The second wordOccurrences method is for when we input a file *  				       *
*  							                                    *
*	Variables:                                                  *
*    - FILE *fp (input file)                                    *
*    - cFlag (ignorePunctuation and convert to lowerCase)       *
*	 - FILE *output (output file)                               *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

wordOccurencesForFile(FILE *fp, int cFlag, FILE *output)
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
	
	// if open
	if ( fp )
	{	
		//go through string
		for (i = 0;i<strlen(str);i++)
		{
			if(str[i] == '\n') 
			{
				str[i] = '\0 ';
			}//end of if
			
			//if -c is found
			if (cFlag == 1)
			{
				//ignoring punctuation 	
				if(str[i] == ',' || str[i] == '.' || str[i] == '!' 
				|| str[i] == '?' || str[i] == '"' || str[i] == ':' 
				|| str[i] ==';' || str[i] == '-')
				{
					str[i] = ' ';
				}//end of if
			}//end of if
			
			if ((str[i] == ' ')||(str[i] == ',')||(str[i] == '.'))
			{
				space++;
			}//end of if
			
			
		}//end of for
		
		for (i = 0, j = 0, k = 0;j < strlen(str);j++)
		{	
			if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))
			{
				p[i][k] = '\0';
				i++;
				k = 0;
			}//end of if
			else
			{	
				//if -c is found	
				if (cFlag == 1)
				{
					//find upperCase letters 
					if(str[j] >= 'A' && str[j] <= 'Z')
					{
						//overwrite to lowerCase
						str[j] = tolower(str[j]);
						
					}//end of if statement
				}//end of if
				
				p[i][k++] = str[j];
				
			}//end of else
				
		}//end of for
	
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
				}// end of if
				else
				{
					if (strcmp(ptr1[j], p[i]) != 0)
						continue;
					else
						break;
				}//end of else
			}//end of for
		}//end of for
		
		for (i = 0;i < count;i++)
		{
			for (j = 0;j <= space;j++)
			{
				
				if (strcmp(ptr1[i], p[j]) == 0)
				c++;
			
			}//end of for
			
			fprintf(output,"%s: %d \n", ptr1[i], c);
			c = 0;
			
		}// end of for
	}//end of if
	else
    {
        printf("Failed to open the file\n");
	}//end of else
	
	free(str); //clean
}