// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��WindowProc

// �����o�֐�InitInstance
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��E�\���̂̐錾
	HWND hWnd;	// HWND�^�E�B���h�E�n���h��hWnd
	WNDCLASS wc;	// WNDCLASS�^�E�B���h�E�N���X�\����wc

	// �E�B���h�E�N���X�\����wc�Ƀp�����[�^��ݒ�.
	wc.lpszClassName = _T("Aoi");	// �E�B���h�E�N���X���͂Ƃ肠����"Aoi"�Ƃ���.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// �X�^�C���͂Ƃ肠����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;	// �E�B���h�E�v���V�[�W���͉��Œ�`����WindowProc.
	wc.hInstance = hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h���͈�����hInstance���g��.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);	// LoadIcon�ŃA�v���P�[�V��������̃A�C�R�������[�h.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);	// LoadCursor�ŃA�v���P�[�V��������̃J�[�\�������[�h.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObject�Ŕ��u���V��w�i�F�Ƃ���.
	wc.lpszMenuName = NULL;	// �Ƃ肠�������j���[�͂Ȃ�(NULL�ɂ���.)
	wc.cbClsExtra = 0;	// �Ƃ肠����0���w��.
	wc.cbWndExtra = 0;	// �Ƃ肠����0���w��.

	// �E�B���h�E�N���X�̓o�^.
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^����.

		// �߂�l��0�Ȃ�o�^���s�Ȃ̂ŃG���[����.
		MessageBox(NULL, _T("�\�����ʃG���[���������܂���!(-1)"), _T("Aoi"), MB_OK);	// MessageBox��"�\�����ʃG���[���������܂���!(-1)"�ƕ\��.
		return FALSE;	// FALSE��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(wc.lpszClassName, _T("Aoi"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�N���X��"Aoi"�ȃE�B���h�E"Aoi"���쐬.
	if (hWnd == NULL) {	// hWnd��NULL�Ȃ�E�B���h�E�쐬���s.

		// �G���[����.
		MessageBox(NULL, _T("�\�����ʃG���[���������܂���!(-2)"), _T("Aoi"), MB_OK);	// MessageBox��"�\�����ʃG���[���������܂���!(-2)"�ƕ\��.
		return FALSE;	// FALSE��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̕\��.
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow�ŃE�B���h�E��\��.

	// ����������.
	return TRUE;	// TRUE��Ԃ��Đ���I��.

}