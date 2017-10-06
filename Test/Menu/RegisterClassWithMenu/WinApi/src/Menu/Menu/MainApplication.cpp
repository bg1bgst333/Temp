// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow

// �����o�֐�InitInstance
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// ���C���E�B���h�E�N���X�̓o�^
	CMainWindow::RegisterClass(hInstance, IDR_MAINMENU);	// CMainWindow::RegisterClass�ŃE�B���h�E�N���X"CWindow"��o�^.

	// CWindow�I�u�W�F�N�g�̍쐬
	m_pMainWindow = new CMainWindow();	// CMainWindow�I�u�W�F�N�g���쐬��, m_pMainWindow�Ɋi�[.

	// �E�B���h�E�̍쐬
	if (!m_pMainWindow->Create(_T("Menu"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWindow->Create�ŃE�B���h�E�쐬�Ɏ��s������.

		// ���s�Ȃ�FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �E�B���h�E�̕\��
	m_pMainWindow->ShowWindow(SW_SHOW);	// m_pMainWindow->ShowWindow�ŃE�B���h�E��\��.

	// ����������
	return TRUE;	// TRUE��Ԃ��Đ���I��.

}