#include "stdafx.h"
#include "Pathfinders.h"

Entity::Entity(EntityType entitytype, std::string name, int x, int y)
	: m_entitytype(entitytype), m_name(name), m_x(x), m_y(y)
{
	if (MoveNotBlocked(x, y) == true) { m_active = true; }
	else { m_active = false; }

	m_ID = m_newID++;

	m_gamespace.AddMe(*this);

}
bool Entity::MovePossible(int x, int y)
{
	if ( abs(m_x - x) > 1 || abs(m_y - y) > 1 ) { return false; }
	else { return true; }
	// If the x OR y displacement is greater than 1 (i.e. anything other than a King's move in chess), it's not a valid move
	// Abs() is the modulus function
}
bool Entity::MoveNotBlocked(int x, int y)
{
	// Look in the gamespace for an object 
	for (Entity &element : m_gamespace.GetEntities())
	{
		if (element.m_x == x && element.m_y == y) { return false; }
	}
	// If there is no object with the same x and y co-ordinates, then return true
	return true;

}
void Entity::Move(int x, int y)
{

	bool EntityFound{ false };

	// Store the gamespace entity vector in gsref -- for concision's sake
	std::vector<std::reference_wrapper<Entity>> gsref = m_gamespace.GetEntities();

	// Access each element in gsref
	for ( std::reference_wrapper<Entity> element : gsref )
		{
			Entity &unwrapped = element.get();
			if (unwrapped.m_ID == this->m_ID)
			{
				// Set bool 
				EntityFound = true;

				if (	MovePossible(x, y)		== true &&
						MoveNotBlocked(x, y)	== true	)
				{
					unwrapped.m_x = x;
					unwrapped.m_y = y;
					std::cout << "The movement was successful!\n";
					return;
				}
			}
		}

	// The following if statements are ordered hierarchically, according to which is most hindering:
	if (EntityFound == 0)
	{
		std::cout << "Entity not found.\n";
		return;
	}
	if (MovePossible(x, y) == false)
	{
		std::cout << "That destination is too far away.\n";
		return;
	}
	if (MoveNotBlocked(x, y) == false)
	{
		std::cout << "That movement is blocked.\n";
		return;
	}
}

std::string Entity::GetName()		{ return m_name; }
int Entity::GetID()					{ return m_ID; }
int Entity::GetX()					{ return m_x; }
int Entity::GetY()					{ return m_y; }