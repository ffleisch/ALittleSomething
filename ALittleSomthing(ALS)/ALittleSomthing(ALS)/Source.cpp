
#ifndef MAINGAME_INC
#define MAINGAME_INC
#include "main_game.h"
#endif

#ifndef ERROR_INC
#define ERROR_INC
#include "error.h"
#endif // !ERROR_INC


int main() {
	main_game thaGame =main_game();
	thaGame.gameloop();
	return(420);
}