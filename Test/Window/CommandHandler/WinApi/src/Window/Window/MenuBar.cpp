// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MenuBar.h"	// CMenuBar�N���X
#include "MainDialog.h"		// CMainDialog�N���X
#include "resource.h"	// ���\�[�X�t�@�C��

// �R���X�g���N�^CMenuBar()
CMenuBar::CMenuBar() {

	// �����o�̏�����.
	m_hMenu = NULL;	// m_hMenu��NULL�ŏ�����.

}

// �f�X�g���N�^~CMenuBar()
CMenuBar::~CMenuBar() {

	// �����o�̏I������.
	// �Ƃ肠�����Ȃ��ł���.

}

// ���j���[���[�h�֐�LoadMenu.
BOOL CMenuBar::LoadMenu(HINSTANCE hInstance, UINT nID) {

	// ���j���[nID�����[�h.
	m_hMenu = ::LoadMenu(hInstance, MAKEINTRESOURCE(nID));	// LoadMenu��nID�����[�h.
	if (m_hMenu == NULL) {	// m_hMenu��NULL�Ȃ�.

		// ���s�Ȃ̂�FALSE��Ԃ�.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �����Ȃ̂�TRUE��Ԃ�.
	return 0;	// TRUE��Ԃ�.

}

// ���j���[�Z�b�g�֐�SetMenu.
BOOL CMenuBar::SetMenu(HWND hwnd) {

	// �����o�Ɉ������Z�b�g.
	m_hWnd = hwnd;	// m_hWnd��hwnd���Z�b�g.

	// ���j���[�̃Z�b�g.
	return ::SetMenu(m_hWnd, m_hMenu);	// SetMenu��m_hMenu���Z�b�g��, �߂�l�����̂܂ܕԂ�.

}