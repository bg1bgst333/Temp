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
	m_pPicture = NULL;	// m_pPicture��NULL�ŏ�����.

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
	if (m_pPicture != NULL) {	// m_pPicture��NULL�łȂ��Ƃ�.
		delete m_pPicture;	// delete m_pPicture��j��.
		m_pPicture = NULL;		// m_pPicture��NULL���Z�b�g.
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

	// �s�N�`���[�R���g���[���̃��[�h.
	m_pPicture = new CPicture(m_hWnd, IDC_PICTURE1);	// �s�N�`���[�R���g���[���̐���.

	// �{�^���n���h����ǉ�.
	AddCommandHandler(IDC_BUTTON1, BN_CLICKED, (int(CWindow::*)(WPARAM, LPARAM))&CMainDialog::OnClickedButton1);	// AddCommandHandler��OnClickedButton1��ǉ�.

	// �����ł����̂�TRUE.
	return TRUE;

}

// �����o�֐�OnClickedButton1
int CMainDialog::OnClickedButton1(WPARAM wParam, LPARAM lParam) {

	// �ϐ��̐錾.
	HINSTANCE hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h��hInstance.
	HBITMAP hBitmap;	// �r�b�g�}�b�v�n���h��hBitmap.

	// �C���X�^���X�n���h���̎擾.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWLP_HINSTANCE);	// GetWindowLong�ŃC���X�^���X�n���h�����擾.

	// �G�f�B�b�g�R���g���[���̃e�L�X�g�ɏ����ꂽ�p�X�̉摜�����[�h����.
	m_pEdit->GetText();	// m_pEdit->GetText�ŃG�f�B�b�g�R���g���[������e�L�X�g���擾.(m_pEdit->m_tstrText�Ɋi�[����Ă���.)
	
	// �摜�̃��[�h.
	hBitmap = (HBITMAP)LoadImage(hInstance, m_pEdit->m_tstrText.c_str(), IMAGE_BITMAP, 320, 240, LR_LOADFROMFILE);	// LoadImage�ŉ摜�����[�h.
	if (hBitmap != NULL) {	// hBitmap��NULL�łȂ����.

		// �摜�̕\��.
		SendMessage(m_pPicture->m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);	// SendMessage��STM_SETIMAGE�𑗐M���邱�Ƃŉ摜��\��.

		// �r�b�g�}�b�v�̔j��.
		DeleteObject(hBitmap);	// DeleteObject�Ńr�b�g�}�b�v��j��.

	}

	// ���������̂�0��Ԃ�.
	return 0;	// 0��Ԃ�.

}