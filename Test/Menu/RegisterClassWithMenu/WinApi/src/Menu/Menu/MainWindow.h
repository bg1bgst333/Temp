// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow
#include "resource.h"			// ���\�[�X�t�@�C��

// ���C���E�B���h�E�N���X
class CMainWindow : public CWindow {

	// public�����o
	public:

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[ID�w��̃o�[�W����.)(static�֐�)
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(CWindow�̃I�[�o�[���C�h�����o�֐�.)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.(CWindow�̃I�[�o�[���C�h�����o�֐�.)
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h�������̃n���h��OnCommand.(CWindow�̃I�[�o�[���C�h�����o�֐�.)
		void OnItem1_1();	// Item1-1���I�����ꂽ���̃n���h��.
		void OnItem1_2();	// Item1-2���I�����ꂽ���̃n���h��.
		void OnItem1_3();	// Item1-3���I�����ꂽ���̃n���h��.
		void OnItem2_1();	// Item2-1���I�����ꂽ���̃n���h��.
		void OnItem2_2();	// Item2-2���I�����ꂽ���̃n���h��.
		void OnItem2_3();	// Item2-3���I�����ꂽ���̃n���h��.
		void OnItem3_1();	// Item3-1���I�����ꂽ���̃n���h��.
		void OnItem3_2();	// Item3-2���I�����ꂽ���̃n���h��.
		void OnItem3_3();	// Item3-3���I�����ꂽ���̃n���h��.

};