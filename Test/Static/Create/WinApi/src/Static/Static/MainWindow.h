// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MenuWindow.h"	// CMenuWindow
#include "Button.h"	// CButton
#include "Edit.h"	// CEdit
#include "Static.h"	// CStatic

// ���C���E�B���h�E�N���X
class CMainWindow : public CMenuWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		CButton *m_pButton;	// CButton�I�u�W�F�N�g�|�C���^m_pButton.
		CEdit *m_pEdit;	// CEdit�I�u�W�F�N�g�|�C���^m_pEdit.
		CStatic *m_pStatic;	// CStatic�I�u�W�F�N�g�|�C���^m_pStatic.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMainWindow();	// �R���X�g���N�^CMainWindow()
		virtual ~CMainWindow();	// �f�X�g���N�^~CMainWindow()
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�����o�[�W����.)(static�֐�)
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[ID�w��̃o�[�W����.)(static�֐�)
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual int OnClickedButton(WPARAM wParam, LPARAM lParam);	// Button�������ꂽ���̓Ǝ��n���h��OnClickedButton

};