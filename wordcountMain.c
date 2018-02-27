#include "count.h"
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
		char buffer[1000];
		
		char *input; //for manually entering string with -c
		input = (char*)malloc(100 * sizeof(char));
		char *name = "invalid";
		
		int wordcount; // the number of words
	
		char *ch; //a single character
		ch = (char*)malloc(100000 * sizeof(char));
		int  c = 0, i, iFlag = 0, oFlag = 0, cFlag = 0;
        char ptr1[50][100];
        char *ptr;
		if(argc == 1)
		{
			printf("Default settings\n");
		}
		else
		{
			for(i=1; i<argc;i++)
			{
				if(strcmp(argv[i], "-i")==0)
				{
					printf("input\n");
					iFlag = 1;
					fi = fopen(argv[++i],"r");
				}
				if(strcmp(argv[i], "-o")==0)
				{
					printf("output\n");
					oFlag = 1;
					fo = fopen(argv[++i],"w");
				}
				if(strcmp(argv[i], "-c")==0)
				{
					cFlag = 1;
				}
			}
		}
		if(iFlag ==1)
		{
			wordcount = countForFile(fi, wordcount);
			fprintf(fo,"Word count is: %d \n", wordcount);
			wordOccurencesForFile(fi, cFlag,fo);	
		}
		else
		{
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
									
						//input[i] = input[i] +32;
									
					}//end of if statement 	
									
					//ignoring punctuation 	
					if(input[i] == ',' || input[i] == '.' || input[i] == '!' || input[i] == '?' || input[i] == '"' || input[i] == ':' || input[i] ==';' || input[i] == '-')
					{
						input[i] = ' ';
					}
				} //end of for loop
				wordcount = 0;
				for(i = 0;input[i] != '\0'; i++)
				{
					if(input[i] == ' ' && input[i+1] != ' ')
					wordcount++;
								
				}// end of while loop
				fprintf(fo,"WordCount is: %d\n", wordcount);
							
				//count occurrences
				wordOccurences(input, fo);
				
			}
			else
			{
				wordcount = 0;
				for(i = 0;input[i] != '\0'; i++)
				{
					if(input[i] == ' ' && input[i+1] != ' ')
					wordcount++;
								
				}// end of while loop
				fprintf(fo,"WordCount is: %d\n", wordcount + 1);
							
				//count occurrences
				wordOccurences(input, fo);
			}
		}
		
		if(oFlag == 1)
		{fclose(fo);}
		
}