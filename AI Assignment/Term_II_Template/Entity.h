#pragma once
#include <iostream>
#include "string.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "Game Setup\main.h"
#include "Game Setup\sdlWindow.h"
#include "Game Setup\sdlResources.h"
#include "Game Setup\Helper.h"
#include "Screens\SpriteGame\ship.h"
#include <vector>

//enum ResourceType
//{
//	Empty, Home, Metal, Fuel, Depleted
//};

class Entity
{
public:
	Entity(vector<Node*>* a_waypoint, vector<ship*>* a_ship);
	void updateEntity(vector <int*>* IdleShips);
	int rMetal;
	int rFuel;

private:
	vector<Node*>* m_nodes;
	vector<ship*>* m_ship;

	float m_x;
	float m_y;

	float turn;

	bool Alive;
	int m_Home;

	int m_cost;
};