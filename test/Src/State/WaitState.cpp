#include "WaitState.h"
#include "../Object/Object.h"
#include "MoveState.h"


WaitState::WaitState()
{
}


WaitState::~WaitState()
{
}

void WaitState::Init(Object* obj)
{
	obj->SetMoveSpeed(0.0f);
	
}

void WaitState::Update(Object* obj)
{
	state_counter++;
	if (state_counter % 300 == 0)
	{
		//obj->MoveState(true)
		obj->ActiveMove();
	}
}
