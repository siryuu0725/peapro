#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H_

#include "Object.h"

#include<vector>

//class Object;

class ObjectManager
{
public:
	static ObjectManager* Instance();

	//�}�l�[�W���[�̏��������R���X�g���N�^���̂�
	void Load();
	//�I�u�W�F�N�g����
	void CreateObject();//�}�b�v�A�v���C���[(2�܂�)�A�A�C�e���B�u���b�N�͕ʔz��

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