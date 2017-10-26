// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow
#include "MenuBar.h"	// CMenuBar

// ���j���[�E�B���h�E�N���X
class CMenuWindow : public CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		CMenuBar *m_pMenuBar;	// CMenuBar�I�u�W�F�N�g�|�C���^m_pMenuBar.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMenuWindow();	// �R���X�g���N�^CMenuWindow
		virtual ~CMenuWindow();	// �f�X�g���N�^~CMenuWindow
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�����o�[�W����.)(static�֐�)
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[ID�w��̃o�[�W����.)(static�֐�)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// �E�B���h�E�N���X���o�^�֐�RegisterClass(�E�B���h�E�N���X���̎w��̃o�[�W����.)(static�֐�)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�E�B���h�E�N���X��, ���j���[ID�w��̃o�[�W����.)(static�֐�)
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(�E�B���h�E�N���X���w��o�[�W����.)

};