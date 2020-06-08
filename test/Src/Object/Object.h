#ifndef OBJECT_H_
#define OBJECT_H_

#include <d3d9.h>
#include <d3dx9.h>
#include "Graphics.h"
#include "Collision.h"

class Object
{
public:
	Object();
	~Object(){}

private:
	struct ObjectInfo
	{
		D3DXVECTOR2 posA;
		D3DXVECTOR2 posB;

		D3DXVECTOR2 vec;
		TEXTURE_DATA tex;

		int wait_conter;

	}Object_info;

public:
	void Load();
	void Draw();
	void Update();
	void Release();

	void MoveA();
	void MoveB();
private:
	Collision* m_collision;
};
#endif