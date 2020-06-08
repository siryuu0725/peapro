#pragma once
#include "State.h"

class MoveState :
	public State
{
public:
	MoveState() {};
	~MoveState() {};

	void Init(Object* obj) override;
	void Update(Object* obj) override;


};

