// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �_�C�A���O�N���XCDialog
class CDialog : public CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		UINT m_nIDTemplate;		// �_�C�A���O�̃��\�[�XID, m_nIDTemplate
		CWindow *m_pParent;		// �e�E�B���h�Em_pParent

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CDialog(UINT nIDTemplate, CWindow *pParent);	// �R���X�g���N�^CDialog
		// �����o�֐�
		virtual INT_PTR DoModal();	// ���[�_���_�C�A���O�\���֐�DoModal
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// StaticWindowProc����e�E�B���h�E�I�u�W�F�N�g���ƂɌĂяo�����T�u�E�B���h�E�v���V�[�W��DynamicWindowProc.
		virtual BOOL OnClose();			// ����ꂽ���̃n���h��OnClose.
		virtual BOOL OnInitDialog(HWND hwndDlg);	// �_�C�A���O���������̃n���h��OnInitDialog.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h�������̃n���h��OnCommand.

};