#ifndef INPUT_H_
#define INPUT_H_

#include <Windows.h>
#include <dinput.h>
#include "Vec.h"

/** @brief �}�E�X�{�^���̎�� */
enum MouseButton
{
	Left,		//!< ��
	Right,		//!< �E
	Center,		//!< �^��
};

// @brife �L�[�̎��
enum KEY_INFO
{
	ESC_KEY,
	SPACE_KEY,
	UP_KEY,
	DOWN_KEY,
	RIGHT_KEY,
	LEFT_KEY,
	A_KEY,
	W_KEY,
	S_KEY,
	D_KEY,
	F_KEY,
	E_KEY,
	Q_KEY,
	T_KEY,
	Y_KEY,
	RETURN_KEY,
	L_CONTROL,
	L_SHIFT,
	MAX_KEY_INFO,
};

/**
* @brief Input�@�\�̏������֐�@n
* �f�o�C�X�̓��͎擾�ɕK�v�ȏ��������s���܂�
* InitEngine�Ŏ��s�����̂ŊJ���������s����K�v�͂���܂���
* @return ���������ʁA�����̏ꍇ��true
* @param[in] hInstance �C���X�^���X�n���h��
* @param[in] hWindow �E�B���h�E�n���h��
*/
bool InitInput();

/**
* @brief Input�@�\�̏I���֐�@n
* Input�@�\���I�������܂�@n
* EndEngine�Ŏ��s�����̂ŊJ���������s����K�v�͂���܂���
*/
void EndInput();

bool CreateInputInterface();

bool CreateMouseDevice();

bool CreateKeyboardDevice();
/**
* @brief �L�[�{�[�h�̓��͏��̍X�V@n
* �f�o�C�X�̓��͏��̍X�V���s���܂�@n
* ���t���[����1�x�K�����s����K�v������܂�
*/
void KeyStateUpdate();

/**
* @brief �L�[��������Ă����Ԃ̔���֐�@n
* �w�肵���L�[��������Ă��邩�𔻒肵�܂�
* @return ���茋�ʁA������Ă���Ȃ�true
* @param[in] key ���肵�����L�[
*/
bool GetKey(KEY_INFO key);

/**
* @brief ���͏��̍X�V@n
* �f�o�C�X�̓��͏��̍X�V���s��@n
* ���t���[���ɂP�x�K�����s����K�v������
*/
void UpdateInput();

/**
* @brief �L�[�������ꂽ�u�Ԃ̔���֐�@n
* �w�肵���L�[�������ꂽ�u�ԉ��𔻒肵�܂�
* @return ���茋�ʁA�����ꂽ�u�ԂȂ�true
* @param[in] key ���肵�����L�[
*/
bool GetKeyDown(KEY_INFO key);

/**
* @brief �L�[�������ꂽ�u�Ԃ̔���֐�@n
* �w�肵���L�[�������ꂽ�u�ԉ��𔻒肵�܂�
* @return ���茋�ʁA�����ꂽ�Ȃ�true
* @param[in] key ���肵�����L�[
*/
bool GetKeyUp(KEY_INFO key);

/**
* @brief �N���b�N�����u�Ԕ���֐�@n
* �w�肵���}�E�X�̃{�^�����N���b�N���ꂽ�u�Ԃ��ǂ����𔻒肷��
* @return ���茋��(�����ꂽ�u�ԂȂ�true)
* @param[in] button_type ���肵�����{�^���̎��
*/
bool OnMouseDown(MouseButton button_type);

/**
* @brief �N���b�N������֐�@n
* �w�肵���}�E�X�̃{�^�����N���b�N�����ǂ����𔻒肷��
* @return ���茋��(�N���b�N���u�ԂȂ�true)
* @param[in] button_type ���肵�����{�^���̎��
*/
bool OnMousePush(MouseButton button_type);

/**
* @brief �N���b�N�I������֐�@n
* �w�肵���}�E�X�̃{�^�����N���b�N���I�������u�Ԃ��ǂ����𔻒肷��
* @return ���茋��(�N���b�N����߂��u�ԂȂ�true)
* @param[in] button_type ���肵�����{�^���̎��
*/
bool OnMouseUp(MouseButton button_type);

/** @brief �}�E�X�̍��W�擾�֐� */
Vec2 GetMousePos();


#endif