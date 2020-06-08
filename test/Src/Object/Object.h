#ifndef OBJECT_H_
#define OBJECT_H_

#include <d3d9.h>
#include <d3dx9.h>
#include "../Engine/Graphics.h"
#include "../Utility/Collision.h"
#include "../Data/GameData.h"

class State;

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

		bool waitflg;
		bool moveflg;
		bool chaseflg;

		
		// ’Ç‰Á
		OldState state;
	}m_obj_info;

public:
	void Load();
	void Draw();
	void Update();
	void Release();

	void SetMoveSpeed(float move_speed) { m_obj_info.move_speed = move_speed; }

	void MoveA();
	void MoveB();

	void Stay();
	void Move();
	void Chase();

	void StateChange();
	void StateUpdate();

	void ActiveWait();
	void ActiveMove();
	void ActiveChase();

	//void ChangeState(State* state) { m_state = state; }
private:
	Collision* m_collision;
	State* m_state;
};
#endif