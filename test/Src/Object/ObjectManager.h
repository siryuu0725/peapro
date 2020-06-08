#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H_

#include "Object.h"

#include<vector>

//class Object;

class ObjectManager
{
public:
	static ObjectManager* Instance();

	//マネージャーの初期化※コンストラクタ時のみ
	void Load();
	//オブジェクト生成
	void CreateObject();//マップ、プレイヤー(2まで)、アイテム。ブロックは別配列

	void Update();
	void Draw();
	void Release();
	void AllDeleteObject();

	Object* GetObjInfo() { return m_object; }

protected:
	ObjectManager();
	~ObjectManager() {};

private:
	static ObjectManager* p_instance;
	
	Object* m_object;

};

#endif