// �Ǝ��̃w�b�_
#include "Button.h"	// CButton

// �R���X�g���N�^CButton
CButton::CButton() : CCustomControl() {

}

// �R���X�g���N�^CButton(HWND hParent, UINT nID)
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

// �����o�֐�Create
BOOL CButton::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �����o�ɃZ�b�g.
	m_nID = (int)hMenu;	// hMenu��m_nID�ɑ��.
	return CCustomControl::Create(_T("Button"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, (HMENU)m_nID, hInstance);	// CCustomControl::Create�Ń{�^�����쐬.

}