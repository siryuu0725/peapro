#include <Windows.h>
#include "Window.h"
#include "Graphics.h"
#include <thread>
#include "Engine.h"
#include "ObjectManager.h"
#include "Input.h"

int WINAPI WinMain(HINSTANCE hinstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmpLine,
	INT nCmdShow)
{
	// �G���W���̏�����
	if (InitEngine(512, 512, "�A�Q�A�Q�o�[�h") == false)
	{
		return 0;
	}

	ObjectManager::Instance()->CreateObject();

	ObjectManager::Instance()->Load();

	while (true)
	{
		bool message_ret = false;
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else if (msg.message == WM_CLOSE)
			{
				break;
			}
			else {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			UpdateInput();

			KeyStateUpdate();

			ObjectManager::Instance()->Update();

			DrawStart();

			SetRenderMode(ERenderMode::Normal, true);

			GetD3DDevice()->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
			ObjectManager::Instance()->Draw();

			DrawEnd();
		}
	}
	ObjectManager::Instance()->Release();

	ObjectManager::Instance()->AllDeleteObject();
	// �G���W���I��
	EndEngine();
}