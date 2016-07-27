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



class Entity
{
public:
	Entity(vector<Node*>* a_nodes, vector<ship*>* a_ship, vector<int*>* a_idle);

	void updateEntity(vector <int*>* IdleShips);
	
	float rMetal;
	float rFuel;
	float FuelUse;

	float CalculateFuelUse();

	enum PriorityQ
	{
		Metal, Fuel
	};

private:
	vector<Node*>* m_nodes;
	vector<ship*>* m_ship;

	float m_x;
	float m_y;

	float turn;

	int MetalThreshold;
	int FuelThreshold;


	float FuelEconomy;

	bool Alive;
	int m_Home;

	int m_cost;
};