#pragma once
#include "CMOGO.h"
#include <vector>

class mass : public CMOGO
{
public:
	mass(string _fileName, ID3D11Device* _pd3dDevice, IEffectFactory* _EF);
	~mass();
	
	void Tick(GameData* _GD);
	mass* findClosestMass( std::vector<mass> masses );


private:
	float			m_mass;	
	const float		m_gravitational_constant = 1.0f;

	Vector3			m_gravity;
	Vector3			m_velocity;
	Vector3			m_acceleration;

	bool			m_stationary;
};

