#include "Object.h"
#include "Input.h"
#include <math.h>

Object::Object()
{
	Object_info.posA = D3DXVECTOR2(0.0f, 0.0f);
	Object_info.posB = D3DXVECTOR2(10.0f, 0.0f);

}

void Object::Load()
{
	LoadTexture("Enemy.png", &Object_info.tex);

}

void Object::Draw()
{
	DrawTexture(&Object_info.tex, Object_info.posA);
	DrawTexture(&Object_info.tex, Object_info.posB);

}

void Object::Update()
{
	
	MoveA();
	
	MoveB();
}

void Object::Release()
{
	ReleaseTexture(&Object_info.tex);
}

void Object::MoveA()
{
	if (GetKey(W_KEY))
	{
		Object_info.posA.y -= 2.0f;
	}
	if (GetKey(S_KEY))
	{
		Object_info.posA.y += 2.0f;
	}
	if (GetKey(D_KEY))
	{
		Object_info.posA.x += 2.0f;
	}
	if (GetKey(A_KEY))
	{
		Object_info.posA.x -= 2.0f;
	}
}

void Object::MoveB()
{
	/*if (m_collision->CircleHit(Object_info.posA, Object_info.posB, 50.0f, 10.0f) == true
		|| m_collision->OugiHit(Object_info.posA, Object_info.posB, 100.0f, 90.0f))
	{
		Object_info.vec.x = Object_info.posA.x - Object_info.posB.x;
		Object_info.vec.y = Object_info.posA.y - Object_info.posB.y;

		Object_info.vec.x /= sqrtf(Object_info.vec.x * Object_info.vec.x + Object_info.vec.y * Object_info.vec.y);
		Object_info.vec.y /= sqrtf(Object_info.vec.x * Object_info.vec.x + Object_info.vec.y * Object_info.vec.y);

		Object_info.posB.x += Object_info.vec.x * 1.1f;
		Object_info.posB.y += Object_info.vec.y * 1.1f;
	}*/

	if (m_collision->OugiHit(Object_info.posA, Object_info.posB, 100.0f, 0.0f, 90.0f))
	{
		Object_info.vec.x = Object_info.posA.x - Object_info.posB.x;
		Object_info.vec.y = Object_info.posA.y - Object_info.posB.y;

		Object_info.vec.x /= sqrtf(Object_info.vec.x * Object_info.vec.x + Object_info.vec.y * Object_info.vec.y);
		Object_info.vec.y /= sqrtf(Object_info.vec.x * Object_info.vec.x + Object_info.vec.y * Object_info.vec.y);

		Object_info.posB.x += Object_info.vec.x * 1.1f;
		Object_info.posB.y += Object_info.vec.y * 1.1f;
	}
}
