// �Ǝ��̃w�b�_
#include "Edit.h"	// CEdit

// �R���X�g���N�^CEdit
CEdit::CEdit() : CCustomControl() {

}

// �R���X�g���N�^CEdit(HWND hParent, UINT nID)
CEdit::CEdit(HWND hParent, UINT nID) {

	// �{�^���̃��[�h.
	Load(hParent, nID);	// Load��nID�̃G�f�B�b�g�R���g���[�������[�h.

}

// �����o�֐�Load
HWND CEdit::Load(HWND hParent, UINT nID) {

	// ���\�[�XID�̃G�f�B�b�g�R���g���[���̃E�B���h�E�n���h�����擾.
	m_nID = nID;	// �����o�ɃZ�b�g.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItem��m_nID�̃G�f�B�b�g�R���g���[���E�B���h�E�n���h�����擾��, m_hWnd�Ɋi�[.
	return m_hWnd;	// m_hWnd��Ԃ�.

}

// �����o�֐�Create
BOOL CEdit::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �����o�ɃZ�b�g.
	m_nID = (int)hMenu;	// hMenu��m_nID�ɑ��.
	return CCustomControl::Create(_T("Edit"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, (HMENU)m_nID, hInstance);	// CCustomControl::Create�ŃG�f�B�b�g�R���g���[�����쐬.

}

// �����o�֐�SetText
void CEdit::SetText(tstring tstrText) {

	// �e�L�X�g�̃Z�b�g.
	m_tstrText = tstrText;	// m_tstrText��tstrText���i�[.
	SetWindowText(m_hWnd, tstrText.c_str());	// SetWindowText��tstrText���Z�b�g.

}

// �����o�֐�GetText
void CEdit::GetText() {

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