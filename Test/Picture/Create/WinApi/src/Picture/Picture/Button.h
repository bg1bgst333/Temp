// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// �{�^���N���X
class CButton : public CCustomControl {

	// public�����o
	public:

		// public�����o�ϐ�
		int m_nID;	// ���\�[�XID

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CButton();	// �R���X�g���N�^CButton
		CButton(HWND hParent, UINT nID);	// �R���X�g���N�^CButton(HWND hParent, UINT nID)
		HWND Load(HWND hParent, UINT nID);	// ���\�[�X�̃��[�h�֐�Load
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(�E�B���h�E�N���X���w��o�[�W����.)

};