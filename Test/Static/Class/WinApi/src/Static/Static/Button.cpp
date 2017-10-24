// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Button.h"	// CButton

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
BOOL CButton::OnCommandButton(WPARAM wParam, LPARAM lParam) {

	// ���̃{�^�����ǂ������`�F�b�N.
	if (LOWORD(wParam) == m_nID) {	// m_nID�Ɠ������`�F�b�N.

		// �ʒm�R�[�h�̃`�F�b�N
		switch (HIWORD(wParam)) {

			// �N���b�N��.
			case BN_CLICKED:

				// BN_CLICKED�u���b�N
				{	
			
					// OnClick�ɔC����.
					OnClick();	// OnClick���Ă�.

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
void CButton::OnClick(){

	// "Button1 Clicked!"�ƕ\��.
	MessageBox(m_hWnd, _T("Button1 Clicked!"), _T("Button"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Button1 Clicked!"�ƕ\��.

}