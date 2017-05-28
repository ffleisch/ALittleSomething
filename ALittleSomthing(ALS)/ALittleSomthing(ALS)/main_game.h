#pragma once


#ifndef B2D_INC
#define B2D_INC
#include "BoX2D/Box2D.h"
#endif // !B2D_INC

#ifndef RENDER_INC
#define RENDER_INC
#include "renderer.h"
#endif // !RENDER_INC

#ifndef GLEW_INC
#define GLEW_INC
#include "opengl_stuff\headers\GL\glew.h"
#endif

#ifndef GLFW_INC
#define GLFW_INC
#include "opengl_stuff\headers\GLFW\glfw3.h"
#endif 

class main_game
{
public:
	b2World* world;
	renderer* render;
	bool loopRuns;
	void gameloop();

	main_game();
	~main_game();
};
