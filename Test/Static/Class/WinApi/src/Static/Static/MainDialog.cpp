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
	m_pEdit = NULL;	// m_pEdit��NULL�ŏ�����.
	m_pStatic = NULL;	// m_pStatic��NULL�ŏ�����.
}

// �����o�֐�OnCLose
BOOL CMainDialog::OnClose() {

	// �{�^���n���h���̍폜.
	DeleteCommandHandler(IDC_BUTTON1, BN_CLICKED);	// DeleteCommandHandler��(IDC_BUTTON1, BN_CLICKED)�̃n���h�����폜.

	// �����o�̏I������.
	if (m_pButton != NULL) {	// m_pButton��NULL�łȂ���.
		delete m_pButton;	// delete��m_pButton��j��.
		m_pButton = NULL;	// m_pButton��NULL���Z�b�g.
	}
	if (m_pEdit != NULL) {	// m_pEdit��NULL�łȂ���.
		delete m_pEdit;		// delete m_pEdit��j��.
		m_pEdit = NULL;		// m_pEdit��NULL���Z�b�g.
	}
	if (m_pStatic != NULL) {	// m_pStatic��NULL�łȂ��Ƃ�.
		delete m_pStatic;	// delete m_pStatic��j��.
		m_pStatic = NULL;		// m_pStatic��NULL���Z�b�g.
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

	// �X�^�e�B�b�N�e�L�X�g�R���g���[���̃��[�h.
	m_pStatic = new CStatic(m_hWnd, IDC_STATIC1);	// �X�^�e�B�b�N�e�L�X�g�R���g���[���̐���.

	// �{�^���n���h����ǉ�.
	AddCommandHandler(IDC_BUTTON1, BN_CLICKED, (int(CWindow::*)(WPARAM, LPARAM))&CMainDialog::OnClickedButton1);	// AddCommandHandler��OnClickedButton1��ǉ�.

	// �����ł����̂�TRUE.
	return TRUE;

}

// �����o�֐�OnClickedButton1
int CMainDialog::OnClickedButton1(WPARAM wParam, LPARAM lParam) {

	// �X�^�e�B�b�N�e�L�X�g�R���g���[���ɃG�f�B�b�g�R���g���[���̃e�L�X�g���Z�b�g����.
	m_pEdit->GetText();	// m_pEdit->GetText�ŃG�f�B�b�g�R���g���[������e�L�X�g���擾.(m_pEdit->m_tstrText�Ɋi�[����Ă���.)
	m_pStatic->SetText(m_pEdit->m_tstrText);	// m_pStatic->SetText��m_pEdit->m_tstrText���X�^�e�B�b�N�e�L�X�g�R���g���[���ɃZ�b�g����.

	// ���������̂�0��Ԃ�.
	return 0;	// 0��Ԃ�.

}
