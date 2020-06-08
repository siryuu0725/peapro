#include "Collision.h"

bool Collision::CircleHit(D3DXVECTOR2 posA_, D3DXVECTOR2 posB_, float radiusA, float radiusB)
{
	float a = posA_.x - posB_.x;
	float b = posA_.y - posB_.y;

	float c = sqrt(a * a + b + b);

	if (c <= radiusA + radiusB)
	{
		return true;
	}
	else
		return false;
}

bool Collision::OugiHit(D3DXVECTOR2 posA_, D3DXVECTOR2 posB_, float ougi_radius, float radian, float cosradian)
{
	posB_.x = posB_.x + 25.0f;
	posB_.y = posB_.y + 25.0f;
	D3DXVECTOR2 vec = posA_ - posB_;

	float lenght = sqrtf((vec.x * vec.x) + (vec.y * vec.y));

	D3DXVECTOR2 nor_vec;

	nor_vec.x = vec.x / lenght;
	nor_vec.y = vec.y / lenght;

	D3DXVECTOR2 ougivec1 = D3DXVECTOR2(1.0f, 0.0f);

	D3DXVECTOR2 ougivec2;

	ougivec2.x = ougivec1.x * cosf(D3DXToRadian(radian)) - ougivec1.y * sinf(D3DXToRadian(radian));
	ougivec2.y = ougivec1.x * sinf(D3DXToRadian(radian)) + ougivec1.y * cosf(D3DXToRadian(radian));

	float dot = (ougivec2.x * nor_vec.x) + (ougivec2.y * nor_vec.y);

	float ougi_cos = cosf(D3DXToRadian(cosradian) / 2);
	if (lenght <= ougi_radius)
	{
		if (ougi_cos > dot)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
