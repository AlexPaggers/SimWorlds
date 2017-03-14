#ifndef _GAME_DATA_H_
#define _GAME_DATA_H_

//=================================================================
//Data to be passed by game to all Game Objects via Tick
//=================================================================

#include <dinput.h>
#include "GameState.h"
#include <AntTweakBar.h>

using namespace DirectX;

struct GameData
{
	float m_dt;  //time step since last frame
	GameState m_GS; //global GameState
	float m_gravitational_constant = 1;

	

	//player input
	unsigned char* m_keyboardState; //current state of the Keyboard
	unsigned char* m_prevKeyboardState; //previous frame's state of the keyboard
	DIMOUSESTATE* m_mouseState; //current state of the mouse
};
#endif
