// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �{�^���N���XCButton
class CButton : public CWindow{
	
	// public�����o
	public:

		// public�����o�ϐ�
		int m_nID;	// ���\�[�XID

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CButton(HWND hParent, UINT nID);	// �R���X�g���N�^CButton
		// �����o�֐�
		HWND Load(HWND hParent, UINT nID);	// ���\�[�X�̃��[�h�֐�Load
		virtual BOOL OnCommandButton(WPARAM wParam, LPARAM lParam);	// �ǂ̃{�^���������ꂽ����U�蕪����n���h��OnCommandButton.
		virtual void OnClick();	// �N���b�N���ꂽ���̃n���h��OnClick

};