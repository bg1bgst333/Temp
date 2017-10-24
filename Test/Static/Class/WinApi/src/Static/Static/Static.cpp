// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "Static.h"	// CStatic

// �R���X�g���N�^CStatic(HWND hParent, UINT nID)
CStatic::CStatic(HWND hParent, UINT nID) {

	// �{�^���̃��[�h.
	Load(hParent, nID);	// Load��nID�̃X�^�e�B�b�N�e�L�X�g�R���g���[�������[�h.

}

// �����o�֐�Load
HWND CStatic::Load(HWND hParent, UINT nID) {

	// ���\�[�XID�̃X�^�e�B�b�N�e�L�X�g�R���g���[���̃E�B���h�E�n���h�����擾.
	m_nID = nID;	// �����o�ɃZ�b�g.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItem��m_nID�̃X�^�e�B�b�N�e�L�X�g�R���g���[���E�B���h�E�n���h�����擾��, m_hWnd�Ɋi�[.
	return m_hWnd;	// m_hWnd��Ԃ�.

}

// �����o�֐�SetText
void CStatic::SetText(tstring tstrText) {

	// �e�L�X�g�̃Z�b�g.
	m_tstrText = tstrText;	// m_tstrText��tstrText���i�[.
	SetWindowText(m_hWnd, tstrText.c_str());	// SetWindowText��tstrText���Z�b�g.

}

// �����o�֐�GetText
void CStatic::GetText() {

	// �e�L�X�g�̒������擾.
	int iLen = GetWindowTextLength(m_hWnd);	// GetWindowTextLength�Œ������擾.

	// �e�L�X�g���I�z��̍쐬.
	TCHAR *ptszText = new TCHAR[iLen + 1];	// ptszText�̍쐬.

	// �e�L�X�g�̎擾.
	GetWindowText(m_hWnd, ptszText, iLen + 1);	// GetWindowText�Ńe�L�X�g���擾.

	// m_tstrText�Ɋi�[.
	m_tstrText = ptszText;	// m_tstrText��ptszText���Z�b�g.

	// �z��̔j��.
	delete[] ptszText;	// ptszText�̔j��.

}