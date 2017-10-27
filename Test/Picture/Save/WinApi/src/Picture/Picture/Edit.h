// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string
#include <tchar.h>	// TCHAR�^
// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �G�f�B�b�g�R���g���[���N���X
class CEdit : public CCustomControl {

	// public�����o
	public:

		// public�����o�ϐ�
		int m_nID;	// ���\�[�XID
		tstring m_tstrText;	// �e�L�X�g

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CEdit();	// �R���X�g���N�^CEdit
		CEdit(HWND hParent, UINT nID);	// �R���X�g���N�^CEdit(HWND hParent, UINT nID)
		HWND Load(HWND hParent, UINT nID);	// ���\�[�X�̃��[�h�֐�Load
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(�E�B���h�E�N���X���w��o�[�W����.)
		void SetText(tstring tstrText);	// �e�L�X�g�̐ݒ�֐�SetText
		void GetText();	// �e�L�X�g�̎擾�֐�GetText

};