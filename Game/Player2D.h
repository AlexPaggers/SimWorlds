#pragma once
#include "ImageGO2D.h"
class Player2D : public ImageGO2D
{
public:
	Player2D(string _fileName, ID3D11Device* _GD);
	~Player2D();
	void Tick(GameData * _GD);

private:


protected:

	ID3D11ShaderResourceView* m_pTextureRV;
};

