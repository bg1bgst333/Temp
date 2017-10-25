// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow() : CMenuWindow() {

	// �����o�̏�����
	m_pButton = NULL;	// m_pButton��NULL�ŏ�����.
	m_pEdit = NULL;	// m_pEdit��NULL�ŏ�����.
	m_pStatic = NULL;	// m_pStatic��NULL�ŏ�����.

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow() {

	// �����o�̏I������.
	if (m_pStatic != NULL) {
		delete m_pStatic;	// delete��m_pStatic�����.
		m_pStatic = NULL;	// m_pStatic��NULL���Z�b�g.
	}
	if (m_pEdit != NULL) {
		delete m_pEdit;	// delete��m_pEdit�����.
		m_pEdit = NULL;	// m_pEdit��NULL���Z�b�g.
	}
	if (m_pButton != NULL) {
		delete m_pButton;	// delete��m_pButton�����.
		m_pButton = NULL;	// m_pButton��NULL���Z�b�g.
	}

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

	// �{�^���I�u�W�F�N�g�̐���.
	m_pButton = new CButton();	// CButton�I�u�W�F�N�g���쐬��, �|�C���^��m_pButton�Ɋi�[.

	// �{�^���̍쐬.
	m_pButton->Create(_T("Button"), 0, 25, 330, 200, 50, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// m_pButton->Create�Ń{�^�����쐬.

	// �n���h���̒ǉ�.
	AddCommandHandler((WM_APP + 1), BN_CLICKED, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnClickedButton);	// �{�^���n���h��OnClickedButton�̒ǉ�.

	// �G�f�B�b�g�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pEdit = new CEdit();	// CEdit�I�u�W�F�N�g���쐬��, �|�C���^��m_pEdit�Ɋi�[.

	// �G�f�B�b�g�R���g���[���̍쐬.
	m_pEdit->Create(_T(""), WS_BORDER | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, 25, 25, 400, 300, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// m_pEdit->Create�ŃG�f�B�b�g�R���g���[�����쐬.																																			// ��ɃE�B���h�E�쐬�����Ƃ���.

	// �X�^�e�B�b�N�e�L�X�g�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pStatic = new CStatic();	// CStatic�I�u�W�F�N�g���쐬��, �|�C���^��m_pStatic�Ɋi�[.

	// �X�^�e�B�b�N�e�L�X�g�R���g���[���̍쐬.
	m_pStatic->Create(_T(""), 0, 450, 25, 200, 50, hwnd, (HMENU)(WM_APP + 3), lpCreateStruct->hInstance);	// m_pStatic->Create�ŃX�^�e�B�b�N�e�L�X�g���쐬.

	// ��ɃE�B���h�E�쐬�����Ƃ���.
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �����o�֐�OnDestroy
void CMainWindow::OnDestroy() {

	// �n���h���̍폜.
	DeleteCommandHandler(WM_APP + 1, BN_CLICKED);	// DeleteCommandHandler��WM_APP + 1�̃n���h�����폜.

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

// �����o�֐�OnClickedButton
int CMainWindow::OnClickedButton(WPARAM wParam, LPARAM lParam) {

	// �e�L�X�g�̓��e��\��.
	m_pEdit->GetText();	// m_pEdit->GetText�Ńe�L�X�g���擾.
	m_pStatic->SetText(m_pEdit->m_tstrText);	// m_pStatic->SetText��m_pEdit->m_tstrText��m_pStatic�ɃZ�b�g.

	// ���������̂�0��Ԃ�.
	return 0;	// 0��Ԃ�.

}
