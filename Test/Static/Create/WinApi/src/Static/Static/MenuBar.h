// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// ���j���[�o�[�N���XCMenuBar
class CMenuBar {

	// public�����o
	public:

		// public�����o�ϐ�
		HMENU m_hMenu;	// ���j���[�n���h��m_hMenu
		HWND m_hWnd;	// �E�B���h�E�n���h��m_hWnd

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMenuBar();	// �R���X�g���N�^CMenuBar()
		virtual ~CMenuBar();	// �f�X�g���N�^~CMenuBar()

		// �����o�֐�
		virtual BOOL LoadMenu(HINSTANCE hInstance, UINT nID);	// ���j���[���[�h�֐�LoadMenu.
		virtual BOOL SetMenu(HWND hwnd);	// ���j���[�Z�b�g�֐�SetMenu.

};