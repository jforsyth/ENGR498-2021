#include <iostream>
#include <cstring>

typedef enum State {
	Init, ReadData, CalcAvg} State;


int main()
{
	State currentState = State::Init;
	State nextState = State::Init;
	
	int buffer[5];
	int counter=0;
	
	while(true)
	{
		
		std::cout << "Current State is " << currentState << std::endl;
		
		switch(currentState){
		
			case Init:
				//do the stuff for the initial state
				counter=0;
				
				//clear the buffer
				memset(buffer,0,5);
				
				//update state variable
				nextState = State::ReadData;
				
				//must always have this break here
				break;
		
		
			case ReadData:
			
				//do stuff for the ReadData state
				counter++;
				
				//update state variables
				if(counter<5)
				{
					nextState = State::ReadData;
				}
				else
				{
					nextState = State::CalcAvg;
				}
				
				break;
				
			case CalcAvg:
			
				//do stuff for CalcAvg state
				
				//update state variables
				nextState = State::Init;
				
				break;
				
			default:
				//DANGER! SHOULD NEVER REACH HERE!!!
				while(1){std::cout << "Help me! Bad State!" << std::endl;}
				
		}
		
		
		std::cout << "Next State is " << nextState << std::endl;
		
		//update state variable before end of loop
		currentState=nextState;
	}

	return 0;
}