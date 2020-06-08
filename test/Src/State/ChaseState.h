#pragma once
#include "State.h"

class ChaseState :
	public State
{
public:
	ChaseState() {};
	~ChaseState() {};

	void Init(Object* obj) override;
	void Update(Object* obj) override;


};

