// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Dialog.h"	// CDialog
#include "Button.h"	// CButton
#include "Edit.h"	// CEdit

// ���C���_�C�A���O�N���XCMainDialog
class CMainDialog : public CDialog {

	// public�����o
	public:

		// public�����o�ϐ�
		CButton *m_pButton;	// �{�^���I�u�W�F�N�g�|�C���^m_pButton
		CEdit *m_pEdit;		// �G�f�B�b�g�R���g���[���I�u�W�F�N�g�|�C���^m_pEdit

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMainDialog(UINT nIDTemplate, CWindow *pParent);	// �R���X�g���N�^CMainDialog
		// �����o�֐�
		virtual BOOL OnClose();			// ����ꂽ���̃n���h��OnClose.
		virtual BOOL OnInitDialog(HWND hwndDlg);	// �_�C�A���O���������̃n���h��OnInitDialog.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h�������̃n���h��OnCommand.

};