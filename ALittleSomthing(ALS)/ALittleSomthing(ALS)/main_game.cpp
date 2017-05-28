#include "main_game.h"



main_game::main_game()
{	
	loopRuns = true;
	b2Vec2 grav(0, 10);
	world=new b2World(grav);
	render = new renderer(&loopRuns);
	render->startStuff();
}


void main_game::gameloop() {
	while (loopRuns) {
		
		world->Step(1/60.f,2,2);
		
		render->render();

	}

}

main_game::~main_game()
{
}
