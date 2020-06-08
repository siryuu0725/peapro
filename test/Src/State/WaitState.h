#pragma once
#include "State.h"
class WaitState :
	public State
{
public:
	WaitState();
	~WaitState();

	void Init() override;
	void Update() override;
};

