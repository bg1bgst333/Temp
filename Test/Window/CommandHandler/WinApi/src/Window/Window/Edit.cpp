// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Edit.h"	// CEdit

// �R���X�g���N�^CEdit
CEdit::CEdit(HWND hParent, UINT nID) {

	// �{�^���̃��[�h.
	Load(hParent, nID);	// Load��nID�̃{�^�������[�h.

}

// �����o�֐�Load
HWND CEdit::Load(HWND hParent, UINT nID) {

	// ���\�[�XID�̃{�^���̃E�B���h�E�n���h�����擾.
	m_nID = nID;	// �����o�ɃZ�b�g.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItem��m_nID�̃{�^���E�B���h�E�n���h�����擾��, m_hWnd�Ɋi�[.
	return m_hWnd;	// m_hWnd��Ԃ�.

}

// �����o�֐�SetText
void CEdit::SetText(tstring tstr) {

}

// ���C���֐�GetText
tstring CEdit::GetText() {

	// tstring�I�u�W�F�N�g�̐錾.
	tstring tstrText;	// �e�L�X�gtstrText

	// �e�L�X�g�̒������擾.
	int iLen = GetWindowTextLength(m_hWnd);	// GetWindowTextLength�Œ������擾.

	// �e�L�X�g���I�z��̍쐬.
	TCHAR *ptszText = new TCHAR[iLen + 1];	// ptszText�̍쐬.

	// �e�L�X�g�̎擾.
	GetWindowText(m_hWnd, ptszText, iLen + 1);	// GetWindowText�Ńe�L�X�g���擾.

	// tstrText�Ɋi�[.
	tstrText = ptszText;	// tstrText��ptszText���Z�b�g.

	// �z��̔j��.
	delete[] ptszText;	// ptszText�̔j��.

	// tstrText��Ԃ�.
	return tstrText;

}