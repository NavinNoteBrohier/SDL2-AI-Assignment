#pragma once
#include "Node.h"
#include "Entity.h"

Entity::Entity(vector<Node*>* a_nodes, vector<ship*>* a_ship, vector<int*>* a_idle)
{
	m_nodes = a_nodes;
	m_ship = a_ship;

	rMetal = 100;
	rFuel = 100;
	Alive = true;

	bool HomeSet = false;
	bool ShipSet = false;

	int i = 0;
	turn = 100;

	while (HomeSet == false)
	{
		if ((*m_nodes)[i]->rType == Home) { m_Home = i; HomeSet = true; };
	}

	for (int j = 0; j < m_ship->size(); j++)
	{
		(*m_ship)[j]->m_Home = m_Home;
		MetalThreshold += 10;
	}

}

void Entity::updateEntity(vector <int*>* IdleShips)
{
	if (rFuel <= 0) { Alive = false; };
	if (Alive == false) { delete[] m_nodes->at(m_Home); m_nodes->erase(m_nodes->begin() + m_Home);}

	turn -= 1;
	if (turn == 0) 
	{
		CalculateFuelUse();



		turn = 100; rFuel-= FuelUse;
	}

	


}

float Entity::CalculateFuelUse()
{
	return 0;
}
