#include <iostream>
#include <random>
#include <time.h>
#include <cstring>

int getRandomInteger(int low, int high)
{
	//generate random length betwee 1 - 100
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
	
	
	for(int i=0;i<1000;i++)
	{
		//place value in circular buffer that will never overflow
		values[i%LENGTH]=getRandomInteger(1,100);
		
		//print out each integer
		std::cout << values[i%LENGTH] << std::endl;
	}
	
	
	return 0;
	
}
