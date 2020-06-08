#include "Object.h"
#include "../Engine/Input.h"
#include <math.h>

Object::Object()
{
	m_obj_info.posA = D3DXVECTOR2(0.0f, 0.0f);
	m_obj_info.enemey_pos = D3DXVECTOR2(10.0f, 0.0f);

	m_obj_info.nor_dir = D3DXVECTOR2(1.0f, 1.0f);
	m_obj_info.move_speed = 1.5f;

	m_obj_info.state_conter = 0;

	m_obj_info.state = State::WAIT;
}

void Object::Load()
{
	LoadTexture("Enemy.png", &m_obj_info.tex);

}

void Object::Draw()
{
	DrawTexture(&m_obj_info.tex, m_obj_info.posA);
	DrawTexture(&m_obj_info.tex, m_obj_info.enemey_pos);

}

void Object::Update()
{

	StateChange();

	StateUpdate();


	MoveA();
	
	//MoveB();
}

void Object::Release()
{
	ReleaseTexture(&m_obj_info.tex);
}

void Object::MoveA()
{
	if (GetKey(W_KEY))
	{
		m_obj_info.posA.y -= 2.0f;
	}
	if (GetKey(S_KEY))
	{
		m_obj_info.posA.y += 2.0f;
	}
	if (GetKey(D_KEY))
	{
		m_obj_info.posA.x += 2.0f;
	}
	if (GetKey(A_KEY))
	{
		m_obj_info.posA.x -= 2.0f;
	}
}

void Object::MoveB()
{
	/*if (m_collision->CircleHit(m_obj_info.posA, m_obj_info.posB, 50.0f, 10.0f) == true
		|| m_collision->OugiHit(m_obj_info.posA, m_obj_info.posB, 100.0f, 90.0f))
	{
		m_obj_info.vec.x = m_obj_info.posA.x - m_obj_info.posB.x;
		m_obj_info.vec.y = m_obj_info.posA.y - m_obj_info.posB.y;

		m_obj_info.vec.x /= sqrtf(m_obj_info.vec.x * m_obj_info.vec.x + m_obj_info.vec.y * m_obj_info.vec.y);
		m_obj_info.vec.y /= sqrtf(m_obj_info.vec.x * m_obj_info.vec.x + m_obj_info.vec.y * m_obj_info.vec.y);

		m_obj_info.posB.x += m_obj_info.vec.x * 1.1f;
		m_obj_info.posB.y += m_obj_info.vec.y * 1.1f;
	}*/

	if (m_collision->OugiHit(m_obj_info.posA, m_obj_info.enemey_pos, 100.0f, 0.0f, 90.0f))
	{
		m_obj_info.vec.x = m_obj_info.posA.x - m_obj_info.enemey_pos.x;
		m_obj_info.vec.y = m_obj_info.posA.y - m_obj_info.enemey_pos.y;

		m_obj_info.vec.x /= sqrtf(m_obj_info.vec.x * m_obj_info.vec.x + m_obj_info.vec.y * m_obj_info.vec.y);
		m_obj_info.vec.y /= sqrtf(m_obj_info.vec.x * m_obj_info.vec.x + m_obj_info.vec.y * m_obj_info.vec.y);

		m_obj_info.enemey_pos.x += m_obj_info.vec.x * 1.1f;
		m_obj_info.enemey_pos.y += m_obj_info.vec.y * 1.1f;
	}
}

void Object::Stay()
{
	m_obj_info.move_speed = 0.0f;
}

void Object::Move()
{
	m_obj_info.move_speed = 1.5f;

	m_obj_info.enemey_pos.x += m_obj_info.nor_dir.x * m_obj_info.move_speed;
	m_obj_info.enemey_pos.y += m_obj_info.nor_dir.y * m_obj_info.move_speed;
}

void Object::Chase()
{
	m_obj_info.vec.x = m_obj_info.posA.x - m_obj_info.enemey_pos.x;
	m_obj_info.vec.y = m_obj_info.posA.y - m_obj_info.enemey_pos.y;

	m_obj_info.vec.x /= sqrtf(m_obj_info.vec.x * m_obj_info.vec.x + m_obj_info.vec.y * m_obj_info.vec.y);
	m_obj_info.vec.y /= sqrtf(m_obj_info.vec.x * m_obj_info.vec.x + m_obj_info.vec.y * m_obj_info.vec.y);

	m_obj_info.enemey_pos.x += m_obj_info.vec.x * m_obj_info.move_speed;
	m_obj_info.enemey_pos.y += m_obj_info.vec.y * m_obj_info.move_speed;

}

void Object::StateChange()
{
	m_obj_info.state_conter++;

	if (m_obj_info.state_conter % 300 == 0)
	{
		switch (m_obj_info.state)
		{
		case State::WAIT:
			m_obj_info.state = State::MOVE;
			break;
		case State::MOVE:
			m_obj_info.state = State::CHASE;
			break;
		case State::CHASE:
			m_obj_info.state = State::WAIT;
			break;
		default:
			break;
		}
	}
}

void Object::StateUpdate()
{
	switch (m_obj_info.state)
	{
	case State::WAIT:
		Stay();
		break;
	case State::MOVE:
		Move();
		break;
	case State::CHASE:
		Chase();
		break;
	default:
		break;
	}
}
