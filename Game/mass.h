#pragma once
#include "CMOGO.h"
#include <vector>

class mass : public CMOGO
{
public:
	mass(string _fileName, ID3D11Device* _pd3dDevice, IEffectFactory* _EF);
	~mass();
	
	void Tick(GameData* _GD);

	void setMass(float _mass) { m_mass = _mass; }


private:
	float	m_mass = 1;	


};

