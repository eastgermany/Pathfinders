#include "stdafx.h"
#include "Pathfinders.h"

Gamespace::Gamespace(int x = 50, int y = 50)
{

	m_x = x;
	m_y = y;

	if ( x > 80 )
	{
		m_x = 80;
	}
	if ( y > 80 )
	{
		m_y = 80;
	}
	// If user specifies a gamespace larger than 80 (max console width) in either direction, then 

	for (int i(0); i < m_x; i++)
	{
		// Should probably make a macro, e.g. CHAR_EMPTY
		m_xteststring.push_back('.');
	}
}

// TESTRENDER IS CURRENTLY BROKEN
void Gamespace::TestRender()
{

	//std::vector<char> initialstring = m_xteststring;

	// Hold the current string (should be empty) in initialstring, string is reset.
	// Even if not empty, this will ensure the string remains unchanged after being modified by TestRender

	std::vector<std::reference_wrapper<Entity>> gsref = this->GetEntities();

	for (int i(0); i < m_x; i++)
	{
		float abs_i_by_five = abs(i / 5);
		float i_by_five = i / 5;

		if (i_by_five == abs_i_by_five)
		{
			m_xteststring[0] = i;
		}
		else
		{
			m_xteststring[0] = ' ';
		}
	}

	for (auto element : m_xteststring)
	{
		std::cout << element;
	}
	std::cout << "\n";

	for (int i(0); i < m_y; i++)
	{

		float abs_i_by_five = abs(i / 5);
		float i_by_five = i / 5;

		if (i_by_five == abs_i_by_five)
		{
			m_xteststring[0] = static_cast<char>(i);
		}
		else
		{
			m_xteststring[0] = ' ';
		}

		// Go through the entity vector and look for all the Entities with m_x value equal to i
		for ( std::reference_wrapper<Entity> &element : gsref )
		{

			Entity& unwrapped = element.get();

			// element.GetN() +/- 1????
			if ( unwrapped.GetY() + 1  == i )
			{
				m_xteststring[unwrapped.GetX() + 1] = 'X';
			}
			else
			{
				m_xteststring[unwrapped.GetX() + 1] = '_';
			}
		}

		for (auto element : m_xteststring)
		{
			std::cout << element;
		}
		std::cout << "\n";
	}

}
// SHOULD PROBABLY REMOVE IT

void Gamespace::ReturnSize()
{
	std::cout << "The gamespace's x value is: " << m_x << "\n";
	std::cout << "The gamespace's y value is: " << m_y << "\n";
}

// Called by the constructor of an Entity, which supplies a reference to itself as an argument to AddMe, which adds that reference to m_entityvector
void Gamespace::AddMe(Entity &entity)
{
	m_entityvector.push_back(entity);
}

// Couts the elements in m_entityvector
void Gamespace::DisplayEntities()
{
	std::cout << "\nThe gamespace contains the following objects:\n";
	for (Entity &element : m_entityvector)
	{
		std::cout << element.GetID() << " " << element.GetName() << ": " << element.GetX() << ", " << element.GetY() << "\n";
	}
}


//Get functions
std::vector<std::reference_wrapper<Entity>> Gamespace::GetEntities()	{ return m_entityvector; }
int											Gamespace::GetX()			{ return m_x; }