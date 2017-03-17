#include "mass.h"
#include "GameData.h"

mass::mass(string _fileName, ID3D11Device* _pd3dDevice, IEffectFactory* _EF) : CMOGO(_fileName, _pd3dDevice, _EF)
{


}


mass::~mass()
{
}

void mass::Tick(GameData * _GD)
{
	CMOGO::Tick(_GD);
}


