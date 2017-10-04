// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��WindowProc

// �����o�֐�InitInstance
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �ϐ��E�\���̂̐錾
	HWND hWnd;		// �E�B���h�E�n���h��
	WNDCLASS wc;	// �E�B���h�E�N���X�\����

	// �E�B���h�E�N���X�\���̂Ƀp�����[�^��ݒ�.
	wc.lpszClassName = _T("Application");	// �E�B���h�E�N���X��"Application"
	wc.style = CS_HREDRAW | CS_VREDRAW;	// �X�^�C��CS_HREDRAW | CS_VREDRAW
	wc.lpfnWndProc = WindowProc;		// �E�B���h�E�v���V�[�W��WindowProc
	wc.hInstance = hInstance;			// �A�v���P�[�V�����C���X�^���X�n���h��hInstance
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIcon�ŃA�C�R��IDI_APPLICATION�����[�h��, �n���h�����w��.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursor�ŃJ�[�\��IDC_ARROW�����[�h��, �n���h�����w��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObject��WHITE_BRUSH���擾��, �n���h�����w��.
	wc.lpszMenuName = NULL;	// ���j���[��NULL(�Ȃ�).
	wc.cbClsExtra = 0;	// 0���w��.
	wc.cbWndExtra = 0;	// 0���w��.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^.

		// �E�B���h�E�N���X�o�^���s�G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Application"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"��\��.
		return FALSE;	// FALSE��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(wc.lpszClassName, _T("Application"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�N���X"Application"�ȃE�B���h�E"Application"���쐬.
	if (hWnd == NULL) {	// hWnd��NULL�Ȃ�E�B���h�E�쐬���s.

		// �E�B���h�E�쐬���s�G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("Application"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"��\��.
		return FALSE;	// -2��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow�ŃE�B���h�E�\��.

	// ����������
	return TRUE;	// TRUE��Ԃ��Đ���I��.

}