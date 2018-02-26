#include "count.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Check for UpperCase and turn into LowerCase for a read file
toLowerCase(FILE *fp,int *ch)
{
	//Initialize variables
	int single_character;
	int i =0;
	
	//if file is read
	if ( fp )
	{
	   //Repeat until End Of File character is reached.	
	   while ((single_character=getc(fp)) != EOF)
		{
			//check every single character if it's a upperCase
			if(single_character >= 'A' && single_character <= 'Z')
			{
				//if it is overwrite it to lowerCase
				single_character = tolower(single_character); //overwrite
			}	
			ch[i] = single_character;
			i++;
		} //end while	
	} //end if
   
   //if file not opened 
   else
	{
	 printf("Error: File not opened\n");  
	} //end else	
		
	getchar();
	
	//printf("toLowerCase Working\n");
	
} // end toLowerCase

ignorePunctuation(FILE *fp, int *ch)
{
	//Initialize variables
	int single_character;
	int i = 0;
	
	if ( fp )
	{
	   //Repeat until End Of File character is reached.	
	   while ((single_character=getc(fp)) != EOF)
		{
			if(single_character == ',' || single_character == '.' || single_character == '!' || single_character == '?' || single_character == '"' || single_character == ':' || single_character ==';' || single_character == '-')
			{
				single_character = ' ';
				printf("Converted without punctuation\n");
			}
			ch[i] = single_character;
			i++;
		}
	}
	else
	{
		printf("Error: File not opened\n");  
	} //end else	
}