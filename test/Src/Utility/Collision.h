#ifndef COLLISION_
#define COOLISION_H_

#include <d3dx9.h>
class Collision
{
public:
	bool CircleHit(D3DXVECTOR2 posA_, D3DXVECTOR2 posB_, float radiusA, float radiusB);

	bool OugiHit(D3DXVECTOR2 posA_, D3DXVECTOR2 posB_, float ougi_radius, float radian, float cosradian);

};
#endif