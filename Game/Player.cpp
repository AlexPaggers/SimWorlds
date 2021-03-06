#include "Player.h"
#include <dinput.h>
#include "GameData.h"
#include "mass.h"
#include "VBGO.h"

Player::Player(string _fileName, ID3D11Device* _pd3dDevice, IEffectFactory* _EF) : CMOGO(_fileName, _pd3dDevice, _EF)
{
	//any special set up for Player goes here
	m_fudge = Matrix::CreateRotationY(XM_PI);

	m_pos.y = 10.0f;

	VBGO::

}

Player::~Player()
{
	//tidy up anything I've created
}



mass* Player::getClosestMass(std::vector<mass *> _masses)
{
	mass* _currentMass = nullptr;

	for (int it = 0; it < _masses.size(); it++)
	{
		if (it == 0)
		{
			_currentMass = _masses[0];
		}
		else
		{
			if ((this->m_pos - _masses[it]->GetPos()).Length() < (this->m_pos - _currentMass->GetPos()).Length())
			{
				_currentMass = _masses[it];
			}
		}
	}
	return _currentMass;
}


Vector3 Player::findGravity(mass* _currentClosestMass)
{
	Vector3 _graviDirection = -Vector3(m_pos - _currentClosestMass->GetPos()) * _currentClosestMass->getMass();
	_graviDirection.Normalize();
	return _graviDirection;
}

void Player::setListOfMasses(std::vector<mass*> _masses)
{
	for (int it = 0; it < _masses.size(); it++)
	{
		m_masses.push_back(_masses[it]);
	}
}



void Player::Tick(GameData* _GD)
{	
	if (!m_grounded)
	{
		m_clostestMass = getClosestMass(m_masses);

		m_acc = findGravity(m_clostestMass) * _GD->m_dt * _GD->m_gravitational_constant
			//	/(pow(this->GetPos().Length() - m_clostestMass->GetPos().Length(), 2))
			//	/ (this->GetPos().Length() - m_clostestMass->GetPos().Length())
			;
	}
	else
	{
		Vector3 _D = (m_pos - m_clostestMass->GetPos());
		_D.Normalize();
		m_pos = m_clostestMass->GetPos() + (_D * m_clostestMass->getRadius());

		m_vel = Vector3::Zero;

	}
	

	if (_GD->m_keyboardState[DIK_SPACE] & 0x80 &&
		m_grounded)
	{
		setVelocity(-findGravity(m_clostestMass) * _GD->m_player_jump_height);
		m_grounded = false;
	}

	if (_GD->m_keyboardState[DIK_A] & 0x80)
	{
		Vector3 _D = Vector3(-(m_pos - m_clostestMass->GetPos()).y, (m_pos - m_clostestMass->GetPos()).x, 0);
		_D.Normalize();
		m_pos += (_D * _GD->m_player_walk_speed * _GD->m_dt * 100);
	}
	if (_GD->m_keyboardState[DIK_D] & 0x80)
	{
		Vector3 _D = Vector3((m_pos - m_clostestMass->GetPos()).y, -(m_pos - m_clostestMass->GetPos()).x, 0);
		_D.Normalize();
		m_pos += (_D * _GD->m_player_walk_speed * _GD->m_dt * 100);
	}

	m_pos.z = 0;


	m_vel += m_acc;
	m_pos += m_vel;


	m_acc = Vector3::Zero;

	if ((m_pos - m_clostestMass->GetPos()).Length() <= m_clostestMass->getRadius())
	{
		m_grounded = true;
	}
	else
	{
		m_grounded = false;
	}

	CMOGO::Tick(_GD);
}