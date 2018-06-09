// Pathfinders.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pathfinders.h"

// Initialise this static member variable for Entity at 0.
int Entity::m_newID = 0;
Gamespace CURRENT_GAMESPACE(25, 25);
Gamespace &Entity::m_gamespace = CURRENT_GAMESPACE;

int _tmain(int argc, _TCHAR* argv[])
{


	Entity x1(BETA, "Key", 3, 2);
	Entity x2(BETA, "Pot", 1, 6);
	Entity x3(GAMMA, "Hagstone", 3, 7);
	Entity x4(BETA, "Shoelace", 4, 4);
	Entity x5(BETA, "Candle", 2, 3);
	Entity x6(BETA, "Comb", 6, 3);

	
	int mode;
	std::string input;


	do
	{

		std::cout << "What would you like to do? ";

		input = GetInput();
		mode = GetActionFromInput( input );

		// 1-move, 2-list
		if (mode == 1)
		{
			std::cout << "\nOn which entity? ";
			PerformActionOnEntity(mode, GetInput());
			CURRENT_GAMESPACE.TestRender();
		}
		if (mode == 2)
		{
			PerformActionOnEntity(mode, "null");
		}

		std::cout << "\n";

	} 
	while ( input != "quit" );

	return 0;
}

