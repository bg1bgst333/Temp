// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string
#include <tchar.h>	// TCHAR�^
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �G�f�B�b�g�R���g���[���N���XCEdit
class CEdit : public CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		int m_nID;	// ���\�[�XID
		tstring tstrText;	// �e�L�X�g

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CEdit(HWND hParent, UINT nID);	// �R���X�g���N�^CEdit
		// �����o�֐�
		HWND Load(HWND hParent, UINT nID);	// ���\�[�X�̃��[�h�֐�Load
		void SetText(tstring tstr);	// �e�L�X�g�̐ݒ�.
		tstring GetText();	// �e�L�X�g�̎擾.

};