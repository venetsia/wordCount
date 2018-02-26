# pragma once
// This file needs to know what printf is
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//count how many words for read file
int countForFile(FILE *fp)
{
	int ch;
	int linecount, charcount, wordcount;
	
	
	 // Initialize counter variables
	 linecount = 0;
	 wordcount = 0;
	 charcount = 0;
	
	
   // If file opened successfully, then write the string to file
   if ( fp )
   {
	   //Repeat until End Of File character is reached.	
	   while ((ch=getc(fp)) != EOF) {
	   	  // Increment character count if NOT new line or space
		    if (ch != ' ' && ch != '\n') { ++charcount; }
		  
		  // Increment word count if new line or space character
		   if (ch == ' ' || ch == '\n') { ++wordcount; }
		   
		  // Increment line count if new line character
		   if (ch == '\n') { ++linecount; }
		  
	    }
    }
   else
    {
        printf("Failed to open the file\n");
	}
	getchar();
	return wordcount;
}

/*
	Hello, Bye, Hello;

	int index = 2;
	String[] words = [Hello, Bye, null];
	int [] count = [2, 1, 0,];
*/
int count(char *input, int wordcount)
{	
	//wordcount = 0;
	/*while(scanf("%s",input) != EOF)
				{
					if(input[0] == 'q' && strlen(input) == 1)
						break;
					wordcount++;
					
				}// end of while loop
				
				printf("WordCount is: %d\n", wordcount);
	getchar();*/
	int i =0;
	wordcount = 0;
	for(i = 0;input[i] != '\0'; i++)
	{
		if(input[i] == ' ' && input[i+1] != ' ')
		wordcount++;
						
	}// end of while loop
	return wordcount;
}	