// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "Picture.h"	// CPicture

// �R���X�g���N�^CPicture(HWND hParent, UINT nID)
CPicture::CPicture(HWND hParent, UINT nID) {

	// �s�N�`���[�R���g���[���̃��[�h.
	Load(hParent, nID);	// Load��nID�̃s�N�`���[�R���g���[�������[�h.

}

// �����o�֐�Load
HWND CPicture::Load(HWND hParent, UINT nID) {

	// ���\�[�XID�̃s�N�`���[�R���g���[���̃E�B���h�E�n���h�����擾.
	m_nID = nID;	// �����o�ɃZ�b�g.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItem��m_nID�̃s�N�`���[�R���g���[���E�B���h�E�n���h�����擾��, m_hWnd�Ɋi�[.
	return m_hWnd;	// m_hWnd��Ԃ�.

}
