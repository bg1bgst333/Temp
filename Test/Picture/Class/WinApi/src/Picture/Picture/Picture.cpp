// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "Picture.h"	// CPicture

// �R���X�g���N�^CPicture(HWND hParent, UINT nID)
CPicture::CPicture(HWND hParent, UINT nID) {

	// �����o�̏�����.
	m_hBitmap = NULL;	// m_hBitmap��NULL���Z�b�g.
	m_tstrImageName = _T("");	// m_tstrImageName��""���Z�b�g.

	// �s�N�`���[�R���g���[���̃��[�h.
	Load(hParent, nID);	// Load��nID�̃s�N�`���[�R���g���[�������[�h.

}

// �f�X�g���N�^~CPicture()
CPicture::~CPicture() {

	// �r�b�g�}�b�v�̔j��.
	if (m_hBitmap != NULL) {	// NULL�łȂ����.
		DeleteObject(m_hBitmap);	// DeleteObject��m_hBitmap��j��.
		m_hBitmap = NULL;	// m_hBitmap��NULL���Z�b�g.
	}

}

// �����o�֐�Load
HWND CPicture::Load(HWND hParent, UINT nID) {

	// ���\�[�XID�̃s�N�`���[�R���g���[���̃E�B���h�E�n���h�����擾.
	m_nID = nID;	// �����o�ɃZ�b�g.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItem��m_nID�̃s�N�`���[�R���g���[���E�B���h�E�n���h�����擾��, m_hWnd�Ɋi�[.
	return m_hWnd;	// m_hWnd��Ԃ�.

}

// �����o�֐�LoadImage
BOOL CPicture::LoadImage(HINSTANCE hInstance, LPCTSTR lpctszImageName) {

	// �����o�ɃZ�b�g.
	m_tstrImageName = lpctszImageName;	// m_tstrImageName��lpctszImageName���Z�b�g.

	// �摜�̃��[�h.
	m_hBitmap = (HBITMAP)::LoadImage(hInstance, m_tstrImageName.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImage��m_tstrImageName�����[�h.(�Ƃ肠�����摜�t�@�C���Ƃ��ă��[�h.)
	if (m_hBitmap == NULL) {	// NULL�Ȃ玸�s.

		// �G���[����.
		m_tstrImageName = _T("");	// ���s�����̂�""���Z�b�g.

		// ���s�Ȃ̂�FALSE��Ԃ�.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �����Ȃ̂�TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}

// �����o�֐�SetImage
void CPicture::SetImage() {

	// �摜�̕\��.
	SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_hBitmap);	// SendMessage��STM_SETIMAGE�𑗐M���邱�Ƃŉ摜��\��.

}