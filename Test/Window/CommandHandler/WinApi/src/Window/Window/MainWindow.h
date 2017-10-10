// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow
#include "MenuBar.h"	// CMenuBar

// ���C���E�B���h�E�N���X
class CMainWindow : public CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		CMenuBar *m_pMenuBar;	// CMenuBar�I�u�W�F�N�g�|�C���^m_pMenuBar.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMainWindow();	// �R���X�g���N�^CMainWindow()
		virtual ~CMainWindow();	// �f�X�g���N�^~CMainWindow()
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�����o�[�W����.)(static�֐�)
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[ID�w��̃o�[�W����.)(static�֐�)
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(CWindow�̃I�[�o�[���C�h�����o�֐�.)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.(CWindow�̃I�[�o�[���C�h�����o�֐�.)
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.(CWindow�̃I�[�o�[���C�h�����o�֐�.)
		virtual int handler2(LPVOID p);	// �n���h���֐�handler

};