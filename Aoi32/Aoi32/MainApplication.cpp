// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��WindowProc

// �����o�֐�InitInstance
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �E�B���h�E�N���X�̓o�^.
	CWindow::RegisterClass(hInstance, _T("Aoi"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X��"Aoi"��o�^.

	// CWindow�I�u�W�F�N�g�̍쐬.
	m_pMainWindow = new CWindow();	// CWindow�I�u�W�F�N�g���쐬��, m_pMainWindow�Ɋi�[.

	// �E�B���h�E�̍쐬.
	if (!m_pMainWindow->Create(_T("Aoi"), _T("Aoi"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWindow->Create�ŃE�B���h�E�쐬�Ɏ��s������.

		// ���s�Ȃ�FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �E�B���h�E�̕\��.
	m_pMainWindow->ShowWindow(SW_SHOW);	// m_pMainWindow->ShowWindow�ŃE�B���h�E��\��.

	// ����������
	return TRUE;	// TRUE��Ԃ��Đ���I��.

}