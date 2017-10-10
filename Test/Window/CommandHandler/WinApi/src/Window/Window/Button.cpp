// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Button.h"	// CButton
#include "MainDialog.h"	// CMainDialog

// �R���X�g���N�^CButton
CButton::CButton(HWND hParent, UINT nID) {

	// �{�^���̃��[�h.
	Load(hParent, nID);	// Load��nID�̃{�^�������[�h.

}

// �����o�֐�Load
HWND CButton::Load(HWND hParent, UINT nID) {

	// ���\�[�XID�̃{�^���̃E�B���h�E�n���h�����擾.
	m_nID = nID;	// �����o�ɃZ�b�g.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItem��m_nID�̃{�^���E�B���h�E�n���h�����擾��, m_hWnd�Ɋi�[.
	return m_hWnd;	// m_hWnd��Ԃ�.

}

// �����o�֐�OnCommandButton
BOOL CButton::OnCommandButton(CWindow *pWindow, WPARAM wParam, LPARAM lParam) {

	// ���̃{�^�����ǂ������`�F�b�N.
	if (LOWORD(wParam) == m_nID) {	// m_nID�Ɠ������`�F�b�N.

		// �ʒm�R�[�h�̃`�F�b�N
		switch (HIWORD(wParam)) {

			// �N���b�N��.
			case BN_CLICKED:

				// BN_CLICKED�u���b�N
				{	
			
					// OnClick�ɔC����.
					OnClick(pWindow);	// OnClick���Ă�.

					// TRUE��Ԃ�.
					return TRUE;	// �����ł����̂�TRUE.

				}

				// ������.
				break;	// break�Ŕ�����.

			// ����ȊO.
			default:

				// ������.
				break;	// break�Ŕ�����.

		}

	}
	
	// �R�}���h���������Ă��Ȃ��̂�FALSE.
	return FALSE;	// FALSE��Ԃ�.

}

// �����o�֐�OnClick
void CButton::OnClick(CWindow *pWindow){

	// �_�E���L���X�g
	CMainDialog *pMainDialog = dynamic_cast<CMainDialog *>(pWindow);	// CMainDialog�Ƀ_�E���L���X�g.

	// �e�L�X�g�̓��e��\��..
	MessageBox(pMainDialog->m_hWnd, pMainDialog->m_pEdit->GetText().c_str(), _T("Edit"), MB_OK | MB_ICONASTERISK);	// pMainDialog->m_pEdit->GetText�Ńe�L�X�g���擾����, MessageBox�ŕ\��.

}