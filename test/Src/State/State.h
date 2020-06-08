#pragma once
class State
{
public:
	State() {};
	~State() {};
	
	virtual void Init() = 0;
	virtual void Update() = 0;
};

