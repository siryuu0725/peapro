#pragma once
#include "State.h"
#include "../Object/Object.h"

class MoveState :
	public State
{
public:
	MoveState();
	~MoveState();

	void Init(Object* obj) override;
	void Update(Object* obj) override;


};

