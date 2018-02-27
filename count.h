/* * * * * * * * * ** * * * * * * * * * * */
/*  Author: Venetsia Krasteva 40313507    */
/*                                        */
/* Date of last modification : 27.02.2018 */
/*                                        */
/* Purpose of the program:                */
/*   Finding the word count               */
/*                                        */
/* * * * * * * * * * * * * * * * * * * *  */

# pragma once
// This file needs to know what printf is
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//count how many words for read file
int countForFile(FILE *fp)
{
	//Declaration of counter variables
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
		  
	    }//end of while
    }//end of if
   else
    {
        printf("Failed to open the file\n");
	}//end of if

	return wordcount;//return integer
}