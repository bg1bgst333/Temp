// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// �E�B���h�E�N���X
class CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		HWND m_hWnd;	// �E�B���h�E�n���h��m_hWnd
		// static�����o�ϐ�
		static TCHAR m_tszClassName[256];	// �E�B���h�E�N���X��m_tszClassName

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName = _T("CWindow"));	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�f�t�H���g������"CWindow")(static�֐�)

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual BOOL ShowWindow(int nCmdShow);	// �E�B���h�E�\���֐�ShowWindow

};

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��WindowProc