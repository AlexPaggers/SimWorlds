#pragma once
#include "gameobject.h"

class mass : public GameObject
{
public:
	mass();
	~mass();
	
	void Tick(GameData* _GD);


private:
	float			m_mass;	
	const float		m_gravitational_constant = 1.0f;

	Vector3			m_gravity;
	Vector3			m_velocity;
	Vector3			m_acceleration;

	bool			m_stationary;
};

