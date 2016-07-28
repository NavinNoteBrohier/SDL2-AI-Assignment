#pragma once
#include "Node.h"
#include "Entity.h"

Entity::Entity()
{
	m_nodes = 0;
	m_ship = 0;

	rMetal = 100;
	rFuel = 100;
	Alive = true;
	BuildCost = 110;

	bool HomeSet = false;
	bool ShipSet = false;

	int i = 0;
	turn = 100;
}

void Entity::Construct(vector<Node*>* a_nodes, vector<ship*>* a_ship, vector<int*>* a_idle)
{
	m_nodes = a_nodes;
	m_ship = a_ship;

	rMetal = 100;
	rFuel = 100;
	Alive = true;
	BuildCost = 110;

	bool HomeSet = false;
	bool ShipSet = false;

	int i = 0;
	turn = 100;

	while (HomeSet == false)
	{
		if ((*m_nodes)[i]->rType == Home) { m_Home = i; HomeSet = true; }
		else { HomeSet = false; };
		i++;
	}

	for (int j = 0; j < m_ship->size(); j++)
	{
		(*m_ship)[j]->SetHome(m_Home);
		(*m_ship)[j]->SetDeposits(rMetal, rFuel);
		MetalThreshold += 10;
	}
}

void Entity::updateEntity(vector <int*>* IdleShips)
{
	if (rFuel <= 0) { Alive = false; };
	if (Alive == false)
	{
		//delete[] m_nodes->at(m_Home);
		Alive = true;
	}

	turn -= 1;
	if (turn == 0)
	{
	

		CollectIdleShips(IdleShips, m_ship);

		for (int i = 0; i < IdleShips->size(); i++)
		{
			int seven = *(*IdleShips)[2] ;
			while (	(*m_ship)[ *(*IdleShips)[i] ]->Hull != 100) 
			{
				(*m_ship)[ *(*IdleShips)[i] ]->Hull++;
				rMetal--;
			}
		}

		FindRec();
		CalculatePriotity(IdleShips);



		CalculateFuelUse(IdleShips);
		turn = 100;
		rFuel -= FuelUse;

		
		
		cout << "Fuel  " << rFuel << endl;
		cout << "Fuel Use " << FuelUse << endl;
		cout << "Metal " << rMetal << endl;
		cout << "Metal Threshold " << MetalThreshold  << endl << endl;
	}

	//cout << turn << endl;


}

float Entity::CalculateFuelUse(vector <int*>* IdleShips)
{
	float j = IdleShips->size() * 0.05f;		
	FuelUse = j;
	return j;
}

void Entity::CalculatePriotity(vector <int*>* IdleShips)
{
	int p_Metal = 100;
	int p_Fuel  = 101;
	int BuildQ  = 90;

	if (rMetal > MetalThreshold + BuildCost) { BuildQ += 1; };

	if (rMetal > MetalThreshold) { p_Metal -= 1; BuildQ += 1; }
	else { p_Metal += 1; }

	if (rFuel > FuelThreshold) { p_Fuel -= 1; }
	else { p_Fuel += 1; }

	if (IdleShips->size() > 0 )
	{
		for (int i = 0; i <= IdleShips->size(); i++)
		{
			for (int j = 0; j <= m_ship->size(); j++)
			{
				if ((*m_ship)[j]->m_rtype == Fuel) 
				{ p_Fuel -= 1; };
				if ((*m_ship)[j]->m_rtype == Metal) 
				{ p_Metal -= 1; BuildQ += 1; };
			}
			if (p_Fuel > p_Metal)
			{ (*m_ship)[*(*IdleShips)[0]]->SetDestination(C_Fuel); }
			else if (p_Metal > p_Fuel)
			{ (*m_ship)[*(*IdleShips)[0]]->SetDestination(C_Metal); }
			else { p_Metal += 1; p_Fuel += 2; }
			CollectIdleShips(IdleShips, m_ship);
		}
		cout << "Ships Sorted " << endl;
	}


}

void Entity::CollectIdleShips(vector<int*>* IdleShips, vector <ship*>* Ships)
{
	for (int i = 0; i < IdleShips->size(); i++)
	{
		delete (*IdleShips)[i];
		IdleShips->erase(IdleShips->begin() + i);
	}

	for (int i = 0; i < Ships->size(); i++)
	{
		if ((*Ships)[i]->Idle == true) { IdleShips->push_back(new int(i)); };
	}
}

void Entity::FindRec()
{
	(*m_nodes)[m_Home]->m_x;
	(*m_nodes)[m_Home]->m_y;

	float TX = 5000;
	float TY = 5000;

	float TXa = 5000;
	float TYa = 5000;
	int FuelAddress = 0;


	for (int i = 0; i < m_nodes->size(); i++)
	{
		if ((*m_nodes)[i]->rType == Fuel)
		{
			if (((*m_nodes)[i]->m_x - (*m_nodes)[m_Home]->m_x) < TX && ((*m_nodes)[i]->m_y - (*m_nodes)[m_Home]->m_y) < TY)
			{
				TX = ((*m_nodes)[i]->m_x - (*m_nodes)[m_Home]->m_x);
				TY = ((*m_nodes)[i]->m_y - (*m_nodes)[m_Home]->m_y);
				C_Fuel = i;
			}
		} 
		else if ((*m_nodes)[i]->rType == Metal)
		{
			if (((*m_nodes)[i]->m_x - (*m_nodes)[m_Home]->m_x) < TXa && ((*m_nodes)[i]->m_y - (*m_nodes)[m_Home]->m_y) < TYa)
			{
				TXa = ((*m_nodes)[i]->m_x - (*m_nodes)[m_Home]->m_x);
				TYa = ((*m_nodes)[i]->m_y - (*m_nodes)[m_Home]->m_y);
				C_Metal = i;
			}
		}
	}

}


