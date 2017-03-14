#include "ImageGO2D.h"
#include "DDSTextureLoader.h"
#include "Player2D.h"
#include "DrawData2D.h"
#include "GameData.h"
#include "helper.h"


Player2D::Player2D(string _fileName, ID3D11Device* _GD) : ImageGO2D(_fileName, _GD)
{
	string fullfilename =
#if DEBUG
		"../Debug/"
#else
		"../Release/"
#endif
		+ _fileName + ".dds";
	HRESULT hr = CreateDDSTextureFromFile(_GD, Helper::charToWChar(fullfilename.c_str()), nullptr, &m_pTextureRV);

	//this nasty thing is required to find out the size of this image!
	ID3D11Resource *pResource;
	D3D11_TEXTURE2D_DESC Desc;
	m_pTextureRV->GetResource(&pResource);
	((ID3D11Texture2D *)pResource)->GetDesc(&Desc);

	m_origin = 0.5f*Vector2((float)Desc.Width, (float)Desc.Height);//around which rotation and scaing is done
}


Player2D::~Player2D()
{
}

void Player2D::Tick(GameData * _GD)
{
}
