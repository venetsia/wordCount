/* * * * * * * * * ** * * * * * * * * * * */
/*  Author: Venetsia Krasteva 40313507    */
/*                                        */
/* Date of last modification : 27.02.2018 */
/*                                        */
/* Purpose of the program:                */
/*   Main method for wordCount            */
/*                                        */
/* * * * * * * * * * * * * * * * * * * *  */

#include "count.h" //include method for count 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "wordOccurrences.c" // include the method word Occurrences

int main(int argc, char **argv)
{	
	//Initialize variables
	FILE *fi; // input file		
	FILE *fo =stdout; //output file
	
	char *input; //for manually entering string with -c
	input = (char*)malloc(100 * sizeof(char));
	char *name = "invalid";
	
	int wordcount; // the number of words
	
	char *ch; //a single character
	ch = (char*)malloc(100000 * sizeof(char));
	
	int  c = 0, i, iFlag = 0, oFlag = 0, cFlag = 0;
    char ptr1[50][100];
    char *ptr;
	
	//if argc is 1
	if(argc == 1)
	{
		printf("Default settings\n");
	}// end if
	else
	{
		//go through argc
		for(i=1; i<argc;i++)
		{
			//if -i is found
			if(strcmp(argv[i], "-i")==0)
			{
				printf("input\n");
				iFlag = 1;
				fi = fopen(argv[++i],"r");
			}
			//if -o is found
			if(strcmp(argv[i], "-o")==0)
			{
				printf("output\n");
				oFlag = 1;
				fo = fopen(argv[++i],"w");
			}
			//if -c is found
			if(strcmp(argv[i], "-c")==0)
			{
				cFlag = 1;
			}
		}//end of for
	}// end of else
	
	//if -i is found 
	if(iFlag ==1)
	{
		wordcount = countForFile(fi);
		fprintf(fo,"Total word count: %d \n \n", wordcount);
		wordOccurencesForFile(fi, cFlag,fo);	
	}// end of if
	else
	{
		//Promp user for input
		printf("Enter text: ");
		scanf(" %[^\n]s", input);
		
		//Loop through input
		int i = 0;
		if(cFlag == 1)
		{
			int i =0;
			for( i = 0;input[i]!='\0'; i++) 
			{
				//find upperCase letters
				if(input[i] >= 'A' && input[i] <= 'Z')
				{
					//overwrite to lowerCase
					input[i] = tolower(input[i]);			
					
				}//end of if statement 	
									
				//ignoring punctuation 	
				if(input[i] == ',' || input[i] == '.' || input[i] == '!' || input[i] == '?' || input[i] == '"' || input[i] == ':' || input[i] ==';' || input[i] == '-')
				{
					input[i] = ' ';
				}//end of is statement 
			} //end of for loop
			
			//find word count
			wordcount = 0;
			for(i = 0;input[i] != '\0'; i++)
			{
				if(input[i] == ' ' && input[i+1] != ' ')
				wordcount++;
				
			}// end of while loop
			
			fprintf(fo,"Total word count: %d\n \n", wordcount);
			
			//count occurrences
			wordOccurences(input, fo);
			
		}//end of if
		else
		{
			// find word count
			wordcount = 0;
			for(i = 0;input[i] != '\0'; i++)
			{
				if(input[i] == ' ' && input[i+1] != ' ')
				wordcount++;
				
			}// end of while loop
			
			fprintf(fo,"Total word count:: %d\n \n", wordcount + 1);
			
			//count occurrences
			wordOccurences(input, fo);
		} //end of else
	
	}//end of main else
	
	//if -o is found 
	if(oFlag == 1)
	{fclose(fo);} //close file afterwards
	
	free(input);
	free(ch);
}