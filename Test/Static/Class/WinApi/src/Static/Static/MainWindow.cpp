// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow
#include "MainDialog.h"	// CMainDialog
#include "resource.h"	// ���\�[�X�t�@�C��

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow() : CMenuWindow() {

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow() {

}

// �����o�֐�RegisterClass(���j���[�����o�[�W����.)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E�N���X��"CMainWindow"��o�^.
	return CMenuWindow::RegisterClass(hInstance, _T("CMainWindow"));	// CMenuWindow::RegisterClass��"CMainWindow"��o�^��, �߂�l�����̂܂ܕԂ�.

}

// �����o�֐�RegisterClass(���j���[ID�w��̃o�[�W����.)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// �E�B���h�E�N���X��"CMainWindow"��o�^.
	return CMenuWindow::RegisterClass(hInstance, _T("CMainWindow"), nID);	// CMenuWindow::RegisterClass��"CMainWindow"��nID��o�^��, �߂�l�����̂܂ܕԂ�.

}

// �����o�֐�Create
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// CMenuWindow::Create�̃E�B���h�E�N���X���w��o�[�W�������g��.
	return CMenuWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CMenuWindow::Create�̃E�B���h�E�N���X����"CMainWindow"���w��.

}

// �����o�֐�OnCreate
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���j���[�o�[�̍쐬.(���I�ɍ쐬����ꍇ.)
	m_pMenuBar = new CMenuBar();	// CMenuBar�I�u�W�F�N�g���쐬��, �|�C���^��m_pMenuBar�Ɋi�[.

	// ���j���[�̃��[�h.
	m_pMenuBar->LoadMenu(lpCreateStruct->hInstance, IDR_MAINMENU);	// LoadMenu��ID_MAINMENU�����[�h.

	// ���j���[�̃Z�b�g.
	m_pMenuBar->SetMenu(hwnd);	// SetMenu��hwnd�Ƀ��j���[���Z�b�g.

	// ���j���[�n���h����ǉ�.
	AddCommandHandler(ID_MENU_DIALOG, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnMenuDialog);	// AddCommandHandler��OnMenuDialog��ǉ�.

	// ��ɃE�B���h�E�쐬�����Ƃ���.
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �����o�֐�OnDestroy
void CMainWindow::OnDestroy() {

	// ���j���[�n���h���̍폜.
	DeleteCommandHandler(ID_MENU_DIALOG, 0);	// DeleteCommandHandler��(ID_MENU_DIALOG, 0)�̃n���h�����폜.

	// �����̃E�B���h�E�n���h�����c���Ă�����}�b�v����폜.
	if (CWindow::m_mapWindowMap.find(m_hWnd) != CWindow::m_mapWindowMap.end()) {	// find�Ō���������.
		CWindow::m_mapWindowMap.erase(m_hWnd);	// CWindow::m_mapWindowMap.erase�ō폜.
	}

	// ���b�Z�[�W���[�v�I��.
	PostQuitMessage(0);	// PostQuitMessage�Ń��b�Z�[�W���[�v�𔲂�������.

}

// �����o�֐�OnSize
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

}

// �����o�֐�OnMenuDialog
int CMainWindow::OnMenuDialog(WPARAM wParam, LPARAM lParam) {

	// �I�u�W�F�N�g�̐���.
	CMainDialog dlg(IDD_DIALOG, CWindow::m_mapWindowMap[m_hWnd]);	// �R���X�g���N�^�Ƀ��\�[�XID�ƃ��j���[�o�[�̃I�[�i�[�E�B���h�E�I�u�W�F�N�g�|�C���^(�E�B���h�E�}�b�v�ŒT��.)���w��.

	// �_�C�A���O�̕\��.
	dlg.DoModal();	// dlg.DoModal�Ń_�C�A���O��\��.

	// ���������̂�0��Ԃ�.
	return 0;	// 0��Ԃ�.

}
