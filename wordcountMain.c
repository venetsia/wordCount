#include "count.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//#include "wordOccurances.h"
#include "wordOccurrences.c"

int main(int argc, char **argv)
{	
		//Initialize variables
		FILE *fp; //file		
		char buffer[1000];
		
		char *input; //for manually entering string with -c
		input = (char*)malloc(100 * sizeof(char));
		char *name = "invalid";
		
		int wordcount; // the number of words
	
		char *ch; //a single character
		ch = (char*)malloc(100000 * sizeof(char));
		
		char consoleInput[60];
		
		int  c = 0, i;
        char ptr1[50][100];
        char *ptr;
		
		
	
	if(argc >=2)
	{		
		if(argc == 6) //if argc = 5 --> wordcount -i .txt -o .txt -c
		{		
			//for (int i=0; i<=argc; i++)
			//{	
				// if line has -i
				if (strcmp("-i", argv[1]) == 0)
				{
					//open file on directory after -i
					fp = fopen(argv[2],"r");
					
					//do wordcount method
					wordcount = countForFile(fp, wordcount);
					
					//close file
					fclose(fp);
				}// end of first if
				else
					printf("-i not in position\n");
				
				// if line has -o
				if(strcmp("-o", argv[3]) == 0)
				{
					name = argv[4];
					printf("%s",name);
					//open file on directory after -o
					fp = fopen(name, "w");
					
					//put wordcount in file
					fprintf(fp,"%d", wordcount);
					printf("Putting output to file\n");
					
					//close file
					fclose(fp);
				} // end of second if
				else
					printf("-o not in position\n");
				
				//if line has -c
				if(strcmp("-c", argv[5]) == 0)
				{

					//open file on location 2
					fp = fopen(argv[2],"r");				
					
					//count occurances
					wordOccurencesForFile(fp, 1, 1,name); // doesn't take converted string
					
					//close file
					fclose(fp);
					
				} //end of third if
				else
					printf("-c not in position\n");
			
			//}
		}
		if (argc == 5) // if argc = 4 --> wordcount -i .txt -o .txt 
		{
			//for (int i=0; i<=argc; i++)
			//{	
				// if line has -i
				if (strcmp("-i", argv[1]) == 0)
				{
					//open file on directory after -i
					fp = fopen(argv[2],"r");
					
					//do wordcount method
					wordcount = countForFile(fp, wordcount);
					wordOccurencesForFile(fp, 0, 0,name);
					
					//close file
					fclose(fp);
				}// end of first if
				else
					printf("-i not in position\n");
				
				// if line has -o
				if(strcmp("-o", argv[3]) == 0)
				{
					name = argv[4];
					//open file on directory after -o
					fp = fopen(name, "w");
					
					//put wordcount in file
					fprintf(fp,"%d", wordcount);
					printf("Putting output to file\n");
					
					//close file
					fclose(fp);
					
				} // end of second if
				else
					printf("-o not in position\n");
			//}
		}
		else if(argc == 4) // if argc = 3 -> wordcount -i txt -c; wordcount -o txt -c
		{
			//for (int i=0; i<=argc; i++)
			//{
				if(strcmp("-i",argv[1]) == 0) //wordcount -i .txt -c
				{ 
					if(strcmp("-i",argv[1]) == 0)
					{
						//open file on directory after -i
						fp = fopen(argv[2],"r");
						
						//do wordcount method
						wordcount = countForFile(fp, wordcount);
		
						//close file
						fclose(fp);
					}
					else
					printf("-i not in position\n");
				
					//if line has -c
					if(strcmp("-c", argv[3]) == 0)
					{
						////open file on location 2
						fp = fopen(argv[2],"r");
						
						// do toLowerCase method
						//toLowerCase(fp,ch);
						
						//open file on location 2
						//fp = fopen(argv[2],"r");
						
						//ignore Punctuation
						//ignorePunctuation(fp, ch);
						
						//count occurances
						wordOccurencesForFile(fp, 1, 1,name);
						
						//close file
						fclose(fp);
						
					} //end of third if
					else
					printf("-c not in position\n");
				}
				else if(strcmp("-o",argv[1]) == 0) //wordcount -o .txt -c
				{
						if(strcmp("-o", argv[1]) == 0)
					{
						name = argv[2];
						//open file on directory after -o
						fp = fopen(name, "w");
						
						//put wordcount in file
						fprintf(fp,"%d \n", wordcount);
						printf("Putting output to file\n");
						
						//close file
						fclose(fp);
					} // end of second if
					else
					printf("-o not in position\n");
					
					if(strcmp("-c", argv[3]) == 0)
					{
					printf("Enter q to exit\n");
					printf("Enter text: ");
					scanf(" %[^\n]s", input);
						
						//Loop through input
						int i = 0;
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
					
						printf("%s\n",input);
						printf("WordCount is: %d\n", wordcount);
						
						//count occurrences
						wordOccurences(input, name);
						
						
					} //end of third if
					else
					printf("-c not in position\n");
					
				
					
					
				}
			//}
		}	
		
		if(argc == 3) // if argc = 2 -> wordcount -i txt; wordcount -o txt
		{
			//for (int i=0; i<=argc; i++)
			//{
				if(strcmp("-i",argv[1]) == 0)
				{
					//open file on directory after -i
					fp = fopen(argv[2],"r");
							
					//do wordcount method
					wordcount = countForFile(fp, wordcount);
					
					wordOccurencesForFile(fp, 0, 0,name);
			
					//close file
					fclose(fp);

				}	
				
				else if(strcmp("-o", argv[1]) == 0)
				{
					printf("Enter q to exit\n");
					printf("Enter text: ");
					scanf(" %[^\n]s", input);
					
					wordcount = 0;
					for(i = 0;input[i] != '\0'; i++)
					{
						if(input[i] == ' ' && input[i+1] != ' ')
						wordcount++;
						
					}// end of while loop
				
					printf("%s\n",input);
					printf("WordCount is: %d\n", wordcount + 1);
					
					wordOccurences(input, name);
					
					name = argv[2];
					//open file on directory after -o
					fp = fopen(name, "w");
								
					//put wordcount in file
					fprintf(fp,"%d", wordcount);
					/*fprintf(fp,"%s -> %d times\n", ptr1[i], c);*/
					printf("Putting output to file\n");
								
					//close file
					fclose(fp);
				} // end of second if
				else
					printf("-i or -o not in position\n");
			//}
		}
		if(argc == 2) //wordcountMain -c
		{
			//for (int i=0; i<argc; i++)
			//{
				//converting from UpperCase to LowerCase
				if(strcmp("-c", argv[1]) == 0)
				{	
					//Get input
					printf("Enter text: ");
					scanf(" %[^\n]s", input);
					
					int i = 0;
					//Loop through input
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
				
					printf("%s\n",input);
					printf("WordCount is: %d\n", wordcount);
					wordOccurences(input,name);
				}
				else
					printf("-c not in position\n");
			//}
		}
	}
	else
	{
		//Get input
		printf("Enter text: ");
		scanf(" %[^\n]s", input);
		
		wordcount = 0;
		for(i = 0;input[i] != '\0'; i++)
		{
			if(input[i] == ' ' && input[i+1] != ' ')
			wordcount++;
			
		}// end of while loop
		
		printf("WordCount is: %d\n", wordcount + 1);
			
		wordOccurences(input, name);
	}
	return 0;
}