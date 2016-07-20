#pragma once
#include "Node.h"
#include "Entity.h"

Entity::Entity(vector<Node*>* a_nodes, int a_current, int a_rows, int a_cols)
{
	m_nodes = a_nodes;
	m_currentNode = a_current;
	m_cols = a_cols;
	m_rows = a_rows;
}

void Entity::calculatecost()
{
	int VecSize = m_nodes->size();

	int p_tileA = (*m_nodes)[m_currentNode + 1]->m_cost;
	int p_tileB = (*m_nodes)[m_currentNode + m_rows]->m_cost;

	int p_tileC = (*m_nodes)[m_currentNode - 1]->m_cost;
	int p_tileD = (*m_nodes)[m_currentNode - m_rows]->m_cost;

	if (p_tileA < p_tileB)
	{
		m_currentNode = m_currentNode + 1;
	}
	else if (p_tileB < p_tileA)
	{
		m_currentNode + m_rows;
	}
	else if (p_tileB < p_tileC)
	{
		m_currentNode + m_rows;
	}

}

void Entity::updateEntity()
{
}
