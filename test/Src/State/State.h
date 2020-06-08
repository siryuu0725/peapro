#pragma once
#include "../Object/Object.h"
class State
{
public:
	State()
	{
		state_counter = 0;
	}
	~State() {};
	
	virtual void Init(Object* obj) = 0;
	virtual void Update(Object* obj) = 0;
protected:
	static int state_counter;
};

