#include "Player.h"
#include <dinput.h>
#include "GameData.h"
#include "mass.h"

Player::Player(string _fileName, ID3D11Device* _pd3dDevice, IEffectFactory* _EF) : CMOGO(_fileName, _pd3dDevice, _EF)
{
	//any special set up for Player goes here
	m_fudge = Matrix::CreateRotationY(XM_PI);

	m_pos.y = 10.0f;

	SetDrag(0.7);
	SetPhysicsOn(true);
}

Player::~Player()
{
	//tidy up anything I've created
}



mass* Player::getClosestMass(std::vector<mass> _masses)
{
	mass* _currentMass = nullptr;

	for (int it = 0; it < _masses.size(); it++)
	{
		if (it == 0)
		{
			_currentMass = &_masses[0];
		}
		else
		{
			if ((this->m_pos - _masses[it].GetPos()).Length() < (this->m_pos - _currentMass->GetPos()).Length())
			{
				_currentMass = &_masses[it];
			}
		}
	}
	return _currentMass;
}


Vector3 Player::findGravity(mass* _currentClosestMass)
{
	Vector3 _graviDirection = Vector3(m_pos - _currentClosestMass->GetPos());
	_graviDirection.Normalize();
	return _graviDirection;
}



void Player::Tick(GameData* _GD)
{

	//change orinetation of player
	float rotSpeed = 2.0f * _GD->m_dt;
	if (_GD->m_keyboardState[DIK_A] & 0x80)
	{
		m_yaw += rotSpeed;
	}
	if (_GD->m_keyboardState[DIK_D] & 0x80)
	{
		m_yaw -= rotSpeed;
	}

	m_acc = findGravity(m_clostestMass) * _GD->m_dt;

	m_vel += m_acc;
	m_pos += m_vel;

	m_acc = Vector3::Zero;

	//apply my base behaviour
	CMOGO::Tick(_GD);
}