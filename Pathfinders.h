#ifndef ENUM_ENTITYTYPE
#define ENUM_ENTITYTYPE

enum EntityType
{
	ALPHA,
	BETA,
	GAMMA,
	MAX_ENTITY_TYPES
};

#endif

#ifndef CLASS_GAMESPACE
#define CLASS_GAMESPACE

class Entity;

class Gamespace
{


private:

	int m_x;
	int m_y;
	// The maximum dimensions of the game world

	std::vector<char> m_xteststring;

	// Forward declaration of the Entity class so we can build a vector with it
	std::vector<std::reference_wrapper<Entity>> m_entityvector;
	// A vector of the active entities in the gameworld

public:

	Gamespace(int, int);

	// Make this function a friend so it can get entityvector
	friend int GetEntityIDFromGamespace(std::string, Gamespace&);
	friend Entity& GetEntityFromGamespace(std::string, Gamespace&);

	void TestRender();
	void ReturnSize();
	void AddMe(Entity&);
	void DisplayEntities();

	// Get functions
	std::vector<std::reference_wrapper<Entity>> GetEntities();
	int GetX();

};

#endif

#ifndef CLASS_ENTITY
#define CLASS_ENTITY

class Entity
{
private:

	static Gamespace &m_gamespace;
	EntityType m_entitytype;

	// Spatial co-ordinates
	int m_x;
	int m_y;

	int m_ID;
	static int m_newID;
	
	std::string m_name;
	bool m_active;

	//Functions:

	bool MovePossible(int , int);

	bool MoveNotBlocked(int , int);

public:

	// Allow these functions to retrieve m_gamespace
	friend int GetEntityIDFromGamespace(std::string);
	friend Entity& GetEntityFromGamespace(std::string);

	// PerformActionOnEntity needs to access m_gamespace to call DisplayEntities
	friend void PerformActionOnEntity(int, std::string);

	//Constructor
	Entity(EntityType, std::string, int, int);

	void Move(int , int );

	std::string GetName();
	int GetID();
	int GetX();
	int GetY();
};

#endif

#ifndef FILLER_CHAR
#define FILLER_CHAR '.'
#endif

#ifndef MARGIN_CHAR
#define MARGIN_CHAR '-'
#endif

#ifndef CLASS_GSRENDER
#define CLASS_GSRENDER

class GSRender
{
private:

	int m_marking;
	std::vector<std::vector<char>> m_2dspace;

public:
	GSRender(int x, int y, int marking = 5) : m_marking(marking)
	{
		std::vector<char> tempx;

		for (int i(0); i < x; i++)
		{
			tempx.push_back(MARGIN_CHAR);
		}
		m_2dspace[0] = tempx;

		for (int i(1); i < x; i++)
		{

		}
	}

	void ChangePosition(int x, int y, char newchar)
	{

	}


};
#endif

#ifndef INPUT
#define INPUT

std::string GetInput();
int GetActionFromInput(std::string);
void PerformActionOnEntity(int, std::string);
int GetEntityIDFromGamespace(std::string);
Entity& GetEntityFromGamespace(std::string);
int GetNewInt();

#endif

#ifndef CURRENT_GAMESPACE
#define CURRENT_GAMESPACE my_gs

#endif

