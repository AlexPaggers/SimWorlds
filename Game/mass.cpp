#include "mass.h"



mass::mass(string _fileName, ID3D11Device* _pd3dDevice, IEffectFactory* _EF) : CMOGO(_fileName, _pd3dDevice, _EF)
{
}


mass::~mass()
{
}

void mass::Tick(GameData * _GD)
{
}

mass* mass::findClosestMass(std::vector<mass> masses)
{
	mass* current_selected_mass;
	for (auto it = masses.begin(); it != masses.end(); ++it)
	{
		if ()
		{

		}
		current_selected_mass = it;
	}

	return current_selected_mass;
}
