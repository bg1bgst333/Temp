// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainDialog.h"	// CMainDialog
#include "resource.h"	// ���\�[�X�t�@�C��

// �R���X�g���N�^CMainDialog
CMainDialog::CMainDialog(UINT nIDTemplate, CWindow * pParent) : CDialog(nIDTemplate, pParent) {

	// �����o�̏�����.
	m_pButton = NULL;	// m_pButton��NULL�ŏ�����.

}

// �����o�֐�OnCLose
BOOL CMainDialog::OnClose() {

	// �����o�̏I������.
	if (m_pButton != NULL) {	// m_pButton��NULL�łȂ���.
		delete m_pButton;	// delete��m_pButton��j��.
		m_pButton = NULL;	// m_pButton��NULL���Z�b�g.
	}
	if (m_pEdit != NULL) {	// m_pEdit��NULL�łȂ���.
		delete m_pEdit;		// delete m_pEdit��j��.
		m_pEdit = NULL;		// m_pEdit��NULL���Z�b�g.
	}

	// �e�N���X��OnClose�ɔC����.
	return CDialog::OnClose();	// CDialog::OnClose�̒l��Ԃ�.

}

// �����o�֐�OnInitDialog
BOOL CMainDialog::OnInitDialog(HWND hwndDlg) {

	// �����o�ɃE�B���h�E�n���h�����Z�b�g.
	m_hWnd = hwndDlg;	// m_hWnd��hwndDlg���Z�b�g.

	// �{�^���̃��[�h.
	m_pButton = new CButton(m_hWnd, IDC_BUTTON1);	// �{�^���̐���.

	// �G�f�B�b�g�R���g���[���̃��[�h.
	m_pEdit = new CEdit(m_hWnd, IDC_EDIT1);			// �G�f�B�b�g�R���g���[���̐���.

	// �����ł����̂�TRUE.
	return TRUE;

}

// �����o�֐�OnCommand
BOOL CMainDialog::OnCommand(WPARAM wParam, LPARAM lParam) {
	
	// �ϐ��̐錾.
	BOOL bRet;	// �������ꂽ���ǂ�����Ԃ�.

	// �{�^���I�u�W�F�N�g�����邩�`�F�b�N.
	if (m_pButton != NULL){// m_pMenuBar��NULL�łȂ��ꍇ.

		// m_pButton->OnCommandButton�ɏ�����C����.
		bRet = m_pButton->OnCommandButton(this, wParam, lParam);	// OnCommandButton��this, wParam, lParam��n���Ă��Ƃ͔C��, �߂�l�����̂܂ܕԂ�.
		if (bRet) {	// �������ꂽ��.
			return bRet;	// �������ꂽ��bRet��Ԃ�.
		}

	}

	// �R�}���h���������Ă��Ȃ��̂�FALSE.
	return FALSE;	// FALSE��Ԃ�.

}
