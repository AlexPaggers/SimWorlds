#pragma once
#include "ImageGO2D.h"
#include <vector>

class mass : public ImageGO2D
{
public:
	mass(string _fileName, ID3D11Device* _GD);
	~mass();
	
	void Tick(GameData* _GD);



private:
	float	m_mass;	

protected:

	ID3D11ShaderResourceView* m_pTextureRV;
};

