#pragma once
#include <iostream>
#include "string.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "Game Setup\sdlWindow.h"
#include "Game Setup\sdlResources.h"
#include "Game Setup\Helper.h"
#include "Screens\SpriteGame\ship.h"
#include <vector>


class Entity
{
public:
	Entity(vector<Node*>* a_waypoint,int a_current,int a_rows, int a_cols);
	void calculatecost();
	void updateEntity();


private:
	vector<Node*>* m_nodes;
	float m_x;
	float m_y;
	int m_cost;
	int m_currentNode;
	int m_rows;
	int m_cols;

};