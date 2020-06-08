#include "MoveState.h"

void MoveState::Init(Object* obj)
{
}

void MoveState::Update(Object* obj)
{
	obj->Move();
	state_counter++;
	if (state_counter % 300 == 0)
	{
		//obj->MoveState(true)
		obj->ActiveChase();
	}
}
