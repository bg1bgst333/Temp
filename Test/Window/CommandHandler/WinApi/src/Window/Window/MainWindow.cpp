// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow
#include "MainDialog.h"	// CMainDialog
#include "resource.h"			// ���\�[�X�t�@�C��

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow() : CWindow() {

	// �����o�̏�����
	m_pMenuBar = NULL;	// m_pMenuBar��NULL�ŏ�����.

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow() {

	// �����o�̏I������.
	if (m_pMenuBar != NULL) {	// m_pMenuBar��NULL�łȂ����.
		delete m_pMenuBar;	// delete��m_pMenuBar�����.
		m_pMenuBar = NULL;	// m_pMenuBar��NULL�Ŗ��߂�.
	}

}

// �����o�֐�RegisterClass(���j���[�����o�[�W����.)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E�N���X��"CMainWindow"��o�^.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"));	// // CWindow::RegisterClass��"CMainWindow"��o�^��, �߂�l�����̂܂ܕԂ�.

}

// �����o�֐�RegisterClass(���j���[ID�w��̃o�[�W����.)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// �E�B���h�E�N���X��"CMainWindow"��o�^.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), nID);	// CWindow::RegisterClass��"CMainWindow"��nID��o�^��, �߂�l�����̂܂ܕԂ�.

}

// �����o�֐�Create
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// CWindow::Create�̃E�B���h�E�N���X���w��o�[�W�������g��.
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�̃E�B���h�E�N���X����"CMainWindow"���w��.

}

// �����o�֐�OnCreate
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���j���[�o�[�̍쐬.(���I�ɍ쐬����ꍇ.)
	m_pMenuBar = new CMenuBar();	// CMenuBar�I�u�W�F�N�g���쐬��, �|�C���^��m_pMenuBar�Ɋi�[.

	// ���j���[�̃��[�h.
	m_pMenuBar->LoadMenu(lpCreateStruct->hInstance, IDR_MAINMENU);	// LoadMenu��ID_MAINMENU�����[�h.

	// ���j���[�̃Z�b�g.
	m_pMenuBar->SetMenu(hwnd);	// SetMenu��hwnd�Ƀ��j���[���Z�b�g.

	// �n���h���̒ǉ�.
	//int(CWindow::*fp)(LPVOID) = (int(CWindow::*)(LPVOID))&CMainWindow::handler2;
	AddCommandHandler(ID_MENU_DIALOG, 0, (int(CWindow::*)(LPVOID))&CMainWindow::handler2/*OnMenuDialog*/);	// ���j���[�n���h���̒ǉ�.

	// ��ɃE�B���h�E�쐬�����Ƃ���.
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �����o�֐�OnDestroy
void CMainWindow::OnDestroy() {

	// �����̃E�B���h�E�n���h�����c���Ă�����}�b�v����폜.
	if (CWindow::m_mapWindowMap.find(m_hWnd) != CWindow::m_mapWindowMap.end()) {	// find�Ō���������.
		CWindow::m_mapWindowMap.erase(m_hWnd);	// CWindow::m_mapWindowMap.erase�ō폜.
	}

	// ���b�Z�[�W���[�v�I��.
	PostQuitMessage(0);	// PostQuitMessage�Ń��b�Z�[�W���[�v�𔲂�������.

}

// �����o�֐�handler
int CMainWindow::handler2(LPVOID p) {

	// ���b�Z�[�W�{�b�N�X�̕\��.
	MessageBox(m_hWnd, _T("handler!"), _T("Window"), MB_OK | MB_ICONASTERISK);	// "handler!"�ƕ\��.

	// ���������̂�0
	return 0;

}