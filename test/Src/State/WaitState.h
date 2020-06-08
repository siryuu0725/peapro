#pragma once
#include "State.h"

class WaitState :
	public State
{
public:
	WaitState();
	~WaitState();

	void Init(Object* obj) override;
	void Update(Object* obj) override;


};

