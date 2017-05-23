#pragma once


#ifndef B2D_INC
#define B2D_INC
#include "BoX2D/Box2D.h"
#endif // !B2D_INC



class main_game
{
public:
	b2World* world;
	bool* loopRuns;
	void gameloop() {
	
	}

	main_game();
	~main_game();
};
