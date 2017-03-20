#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "CMOGO.h"

//=================================================================
//Base Player Class (i.e. a GO the player controls)
//=================================================================

class mass;

class Player : public CMOGO
{

public:
	Player(string _fileName, ID3D11Device* _pd3dDevice, IEffectFactory* _EF);
	~Player();

	virtual void Tick(GameData* _GD) override;

	mass* getClosestMass(std::vector<mass *> _masses);
	Vector3 findGravity(mass* _currentClosestMass);

	//Getters

	Vector3 getVelocity() { return m_vel; }
	Vector3 getAcceleration() { return m_acc; }

	//Setterinoes

	void setVelocity(Vector3 _vel) { m_vel = _vel; }
	void setAcceleration(Vector3 _acc) { m_acc = _acc; }

	void setListOfMasses(std::vector<mass *> _masses);

private:

	mass* m_clostestMass = nullptr;
	std::vector<mass *> m_masses;

};

#endif