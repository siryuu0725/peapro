#include "ChaseState.h"

void ChaseState::Init(Object* obj)
{

}

void ChaseState::Update(Object* obj)
{
	obj->Chase();
	state_counter++;
	if (state_counter % 300 == 0)
	{
		//obj->MoveState(true)
		obj->ActiveWait();
	}
}
