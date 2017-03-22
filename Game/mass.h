#pragma once
#include "CMOGO.h"
#include <vector>

class mass : public CMOGO
{
public:
	mass(string _fileName, ID3D11Device* _pd3dDevice, IEffectFactory* _EF);
	~mass();
	
	void Tick(GameData* _GD);

	void setMass(float _mass);

	float getMass()				{ return m_mass; }
	float getRadius()			{ return m_radius; }

private:
	float	m_mass = 1;	
	float	m_radius = 1;

};

