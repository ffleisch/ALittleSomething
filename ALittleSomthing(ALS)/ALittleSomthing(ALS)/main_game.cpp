#include "main_game.h"



main_game::main_game()
{	
	*loopRuns = true;
	b2Vec2 grav(0, 10);
	world=new b2World(grav);
}


void main_game::gameloop() {
	while (*loopRuns) {
		
		world->Step(1/60.f,2,2);

	}

}

main_game::~main_game()
{
}
