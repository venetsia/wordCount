#include "sort.h"
#include <stdio.h>

void bubbleSort(int size, int *data)
{
	//Iterate through each value
	for(int i = 0; i < size; ++i)
	{
		//Loop through values above index i
		for (int j = 0; j < size - (i + 1); ++j)
		{
			//Test if data[j] > data[j + 1])
			if (data[j]  > data[j + 1]
			{
				//Swap values
				int temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
		
	}
}