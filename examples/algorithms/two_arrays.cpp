#include <iostream>
#include <random>
#include <time.h>
#include <cstring>

int getRandomInteger(int low, int high)
{
	//generate random LENGTH betwee 1 - 100
	int rando = (rand() % high) + low;

	return rando;
}

int main()
{
	//define buffer length
	const int LENGTH=10;
	
	//instantiate buffer
	int values[LENGTH];
	
	//clear all entries
	memset(values,0,LENGTH);
	
	//provide a random seed
	srand(time(NULL));
	
	
	for(int i=0;i<20;i++)
	{
		//place value in circular buffer that will never overflow
		values[i%LENGTH]=getRandomInteger(1,100);
		
		//print out each integer
		float sum=0;
		for(int j=0;j<LENGTH-1;j++)
		{
			float diff = values[j%LENGTH] - values[(j-1)%LENGTH];
			
			sum+=diff;
		}
		
		float average = sum/LENGTH;
	}
	
	
	return 0;
	
}
