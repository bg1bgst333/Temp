// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <cstring>	// C�����񏈗�
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// static�����o�ϐ��̒�`.
TCHAR CWindow::m_tszClassName[256];	// �E�B���h�E�N���X��

// static�����o�֐�RegisterClass
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// �\���̂̐錾
	WNDCLASS wc;	// �E�B���h�E�N���X�\����

	// �E�B���h�E�N���X���������o�ɃZ�b�g.
	_tcscpy_s(m_tszClassName, lpctszClassName);	// _tcscpy_s��lpctszClassName��m_tszClassName�ɃR�s�[.

	// �E�B���h�E�N���X�\���̂Ƀp�����[�^��ݒ�.
	wc.lpszClassName = m_tszClassName;	// �E�B���h�E�N���X����m_tszClassName���Z�b�g.
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
	if (!::RegisterClass(&wc)) {	// WindowsAPI��RegisterClass�ŃE�B���h�E�N���X��o�^.

		// �E�B���h�E�N���X�o�^���s�G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Window"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"��\��.
		return FALSE;	// FALSE��Ԃ��Ĉُ�I��.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// �����Ȃ̂�TRUE��Ԃ�.

}

// �����o�֐�Create
BOOL CWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�̍쐬
	m_hWnd = CreateWindow(CWindow::m_tszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, NULL);	// CreateWindow�ŃE�B���h�E���쐬��, �n���h����m_hWnd�Ɋi�[.
	if (m_hWnd == NULL) {	// m_hWnd��NULL�Ȃ玸�s.

		// ���s�Ȃ�FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �����o�֐�ShowWindow
BOOL CWindow::ShowWindow(int nCmdShow){

	// �E�B���h�E�̕\��
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPI��ShowWindow��m_hWnd��\��.

}

// �E�B���h�E�v���V�[�W��WindowProc
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �E�B���h�E���b�Z�[�W�̏���
	switch (uMsg) {	// uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �E�B���h�E�쐬����
				return 0;	// 0��Ԃ���, �E�B���h�E�쐬�����Ƃ������ƂɂȂ�.	

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// �I�����b�Z�[�W�̑��M
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ��L�ȊO�̎�.
		default:	// ��L�ȊO�̒l�̎��̊��菈��.

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂�DefWindowProc�Ɋ���̏�����C����.

}