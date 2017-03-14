#pragma once
#include "ImageGO2D.h"
#include <vector>

class mass;

class Player2D : public ImageGO2D
{
public:
	Player2D				(string _fileName, ID3D11Device* _GD);
	~Player2D				();
	
	void Tick				(GameData * _GD);
	
	mass* getClosestMass	(std::vector<mass> _masses);
	Vector2 findGravity		(mass _currentClosestMass);

	//Getters

	Vector2 getVelocity		()				{ return m_vel; }
	Vector2 getAcceleration	()				{ return m_acc; }

	//Setterinoes

	void setVelocity		(Vector2 _vel)	{ m_vel = _vel; }
	void setAcceleration	(Vector2 _acc)	{ m_acc = _acc; }

private:
	Vector2 m_vel;
	Vector2 m_acc;
	
	mass* m_clostestMass = nullptr;
	std::vector<mass> m_masses;


protected:

	ID3D11ShaderResourceView* m_pTextureRV;
};

