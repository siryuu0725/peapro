#include"ObjectManager.h"
//#include"Object.h"

ObjectManager* ObjectManager::p_instance = 0;

ObjectManager* ObjectManager::Instance()
{
	if (p_instance == 0)
	{
		p_instance = new ObjectManager;
	}

	return p_instance;
}

ObjectManager::ObjectManager()
{

}

void ObjectManager::AllDeleteObject()
{
	delete m_object;
}


void ObjectManager::CreateObject()
{
	m_object = new Object;
}

void ObjectManager::Load()
{
	m_object->Load();
}

void ObjectManager::Update()
{
	m_object->Update();

	
}

void ObjectManager::Draw()
{
	m_object->Draw();
}

void ObjectManager::Release()
{
	m_object->Release();
}
