#ifndef OBJECT_H_
#define OBJECT_H_

#include <d3d9.h>
#include <d3dx9.h>
#include "../Engine/Graphics.h"
#include "../Utility/Collision.h"
#include "../Data/GameData.h"
#include "../State/State.h"

class Object
{
public:
	Object();
	~Object(){}

private:
	struct ObjectInfo
	{
		D3DXVECTOR2 posA;
		D3DXVECTOR2 enemey_pos;

		D3DXVECTOR2 vec;
		TEXTURE_DATA tex;

		int state_conter;

		D3DXVECTOR2 nor_dir;
		float move_speed;
		
		// ’Ç‰Á
		OldState state;
	}m_obj_info;

public:
	void Load();
	void Draw();
	void Update();
	void Release();

	void MoveA();
	void MoveB();

	void Stay();
	void Move();
	void Chase();

	void StateChange();
	void StateUpdate();
private:
	Collision* m_collision;
	State* m_state;
};
#endif