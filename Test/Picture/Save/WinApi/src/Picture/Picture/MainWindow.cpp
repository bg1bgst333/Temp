// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow() : CMenuWindow() {

	// �����o�̏�����
	m_pButton = NULL;	// m_pButton��NULL�ŏ�����.
	m_pEdit = NULL;	// m_pEdit��NULL�ŏ�����.
	m_pStatic = NULL;	// m_pStatic��NULL�ŏ�����.
	m_pPicture = NULL;	// m_pPicture��NULL�ŏ�����.
	m_pButton2 = NULL;	// m_pButton2��NULL�ŏ�����.

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow() {

	// �����o�̏I������.
	if (m_pButton2 != NULL) {
		delete m_pButton2;	// delete��m_pButton2�����.
		m_pButton2 = NULL;	// m_pButton2��NULL���Z�b�g.
	}
	if (m_pPicture != NULL) {
		delete m_pPicture;	// delete��m_pPicture�����.
		m_pPicture = NULL;	// m_pPicture��NULL���Z�b�g.
	}
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

	// �s�N�`���[�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pPicture = new CPicture();	// CPicture�I�u�W�F�N�g���쐬, �|�C���^��m_pPicture�Ɋi�[.

	// �s�N�`���[�R���g���[���̍쐬.
	m_pPicture->Create(_T(""), SS_REALSIZECONTROL, 450, 80, 400, 300, hwnd, (HMENU)(WM_APP + 4), lpCreateStruct->hInstance);	// m_pStatic->Create�Ńs�N�`���[�R���g���[�����쐬.(SS_REALSIZECONTROL�̓R���g���[���̑傫���ɍ��킹�ďk������, SS_REALSIZEIMAGE�͉摜�T�C�Y�ɍ��킹�ăR���g���[�����g�傷��.)

	// �{�^���I�u�W�F�N�g�̐���2.
	m_pButton2 = new CButton();	// CButton�I�u�W�F�N�g���쐬��, �|�C���^��m_pButton2�Ɋi�[.

	// �{�^���̍쐬2.
	m_pButton2->Create(_T("Button2"), 0, 25, 390, 200, 50, hwnd, (HMENU)(WM_APP + 5), lpCreateStruct->hInstance);	// m_pButton2->Create�Ń{�^�����쐬.

	// �n���h���̒ǉ�.
	AddCommandHandler((WM_APP + 5), BN_CLICKED, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnClickedButton2);	// �{�^���n���h��OnClickedButton2�̒ǉ�.

	// ��ɃE�B���h�E�쐬�����Ƃ���.
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �����o�֐�OnDestroy
void CMainWindow::OnDestroy() {

	// �n���h���̍폜.
	DeleteCommandHandler(WM_APP + 5, BN_CLICKED);	// DeleteCommandHandler��WM_APP + 5�̃n���h�����폜.
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

	// �ϐ��̐錾.
	HINSTANCE hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h��hInstance.

	// �C���X�^���X�n���h���̎擾.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWLP_HINSTANCE);	// GetWindowLong�ŃC���X�^���X�n���h�����擾.

	// �e�L�X�g�Ŏw�肳�ꂽ�p�X�̉摜��\��.
	m_pEdit->GetText();	// m_pEdit->GetText�Ńe�L�X�g���擾.
	if (m_pPicture->LoadImage(hInstance, m_pEdit->m_tstrText.c_str())){	// m_pPicture->LoadImage��m_pEdit->m_tstrText�����[�h.
		m_pPicture->SetImage();	// m_pPicture->SetImage�ŕ\��.
	}

	// ���������̂�0��Ԃ�.
	return 0;	// 0��Ԃ�.

}

// �����o�֐�OnClickedButton2
int CMainWindow::OnClickedButton2(WPARAM wParam, LPARAM lParam) {

	// �e�L�X�g�Ŏw�肳�ꂽ�p�X�̉摜��\��.
	m_pEdit->GetText();	// m_pEdit->GetText�Ńe�L�X�g���擾.
	m_pPicture->SaveImage(m_pEdit->m_tstrText.c_str());	// m_pPicture->SaveImage��m_pEdit->m_tstrText�ɕۑ�.

	// ���������̂�0��Ԃ�.
	return 0;	// 0��Ԃ�.

}
