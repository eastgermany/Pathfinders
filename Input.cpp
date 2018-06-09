#include "stdafx.h"
#include "Pathfinders.h"


std::string GetInput()
{
	std::string input;
	std::cin >> input;
	return input;
}
int GetActionFromInput(std::string input)
{
	// Return value reports on action specified. 0 is an invalid action.
	if (input == "move")	{ return 1; }
	if (input == "list")	{ return 2; }
	else					{ return 0; }
}
void PerformActionOnEntity(int mode, std::string entitystring)
{

	int x;
	int y;

	Entity& entity = GetEntityFromGamespace(entitystring);

	switch (mode)
	{
	case (1) :

		std::cout << "\nNew x value?: ";
		x = GetNewInt();

		std::cout << "\nNew y value?: ";
		y = GetNewInt();

		entity.Move(x, y);
		return;

	case (2) :

		Entity::m_gamespace.DisplayEntities();
		return;
	}
}
int GetEntityIDFromGamespace(std::string input)
{
	for (std::reference_wrapper<Entity> element : Entity::m_gamespace.GetEntities() )
	{
		Entity &unwrapped = element.get();
		if (unwrapped.GetName() == input)
		{
			return unwrapped.GetID();
		}
	}
	return 0;
}
Entity& GetEntityFromGamespace(std::string input)
{
	for (std::reference_wrapper<Entity> element : Entity::m_gamespace.GetEntities() )
	{
		Entity &unwrapped = element.get();
		if (unwrapped.GetName() == input)
		{
			return unwrapped;
		}
	}
}
int GetNewInt()
{
	int input;
	std::cin >> input;
	return input;
}