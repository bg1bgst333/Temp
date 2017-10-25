// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MenuWindow.h"	// CMenuWindow

// �R���X�g���N�^CMenuWindow
CMenuWindow::CMenuWindow() : CWindow() {

	// �����o�̏�����
	m_pMenuBar = NULL;	// m_pMenuBar��NULL�ŏ�����.

}

// �f�X�g���N�^~CMainWindow
CMenuWindow::~CMenuWindow() {

	// �����o�̏I������.
	if (m_pMenuBar != NULL) {	// m_pMenuBar��NULL�łȂ����.
		delete m_pMenuBar;	// delete��m_pMenuBar�����.
		m_pMenuBar = NULL;	// m_pMenuBar��NULL�Ŗ��߂�.
	}

}

// �����o�֐�RegisterClass(���j���[�����o�[�W����.)
BOOL CMenuWindow::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E�N���X��"CMenuWindow"��o�^.
	return CWindow::RegisterClass(hInstance, _T("CMenuWindow"));	// // CWindow::RegisterClass��"CMenuWindow"��o�^��, �߂�l�����̂܂ܕԂ�.

}

// �����o�֐�RegisterClass(���j���[ID�w��̃o�[�W����.)
BOOL CMenuWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// �E�B���h�E�N���X��"CMenuWindow"��o�^.
	return CWindow::RegisterClass(hInstance, _T("CMenuWindow"), nID);	// CWindow::RegisterClass��"CMenuWindow"��nID��o�^��, �߂�l�����̂܂ܕԂ�.

}

// �����o�֐�RegisterClass(�E�B���h�E�N���X���w��̃o�[�W����.)
BOOL CMenuWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName) {

	// �w��̃E�B���h�E�N���X��lpctszClassName��o�^.
	return CWindow::RegisterClass(hInstance, lpctszClassName);	// CWindow::RegisterClass��lpctszClassName��o�^��, �߂�l�����̂܂ܕԂ�.

}

// �����o�֐�RegisterClass(���j���[ID, �E�B���h�E�N���X���w��̃o�[�W����.)
BOOL CMenuWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID) {

	// �w��̃E�B���h�E�N���X��lpctszClassName��o�^.
	return CWindow::RegisterClass(hInstance, lpctszClassName, nID);	// CWindow::RegisterClass��lpctszClassName��nID��o�^��, �߂�l�����̂܂ܕԂ�.

}

// �����o�֐�Create
BOOL CMenuWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X��"CMenuWindow"�̃E�B���h�E���쐬.
	return CWindow::Create(_T("CMenuWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�̃E�B���h�E�N���X����"CMenuWindow"���w��.

}

// �����o�֐�Create
BOOL CMenuWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �w��̃E�B���h�E�N���X��lpctszClassName�̃E�B���h�E���쐬.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�̃E�B���h�E�N���X����"lpctszClassName"���w��.

}