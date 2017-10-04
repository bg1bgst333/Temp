// �w�b�_�̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// �֐��̃v���g�^�C�v�錾
BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// �������֐�InitInstance
int Run();	// ���b�Z�[�W���[�v�����֐�Run
int ExitInstance();	// �I�������֐�ExitInstance
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��WindowProc

// _tWinMain�֐�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��̐錾
	BOOL bRet;	// ��������������������\��.

	// �A�v���P�[�V�����̏�����
	bRet = InitInstance(hInstance, lpCmdLine, nShowCmd);	// InitInstance�ŏ�����.
	if (!bRet) {	// bRet��FALSE�̎�.

		// �ُ�I��
		return ExitInstance();	// ExitInstance�̒l��Ԃ�.

	}

	// ���b�Z�[�W���[�v�ƏI������.
	return Run();	// Run�Ń��b�Z�[�W���[�v�������s��, �߂�l�����̂܂ܕԂ�.

}

// �������֐�InitInstance
BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��E�\���̂̐錾
	HWND hWnd;					// �E�B���h�E�n���h��
	WNDCLASS wc;				// �E�B���h�E�N���X�\����

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

// ���b�Z�[�W���[�v�����֐�Run
int Run() {

	// �\���̂̐錾
	MSG msg;	// ���b�Z�[�W�\����

	// ���b�Z�[�W���[�v�̏���
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�Ń��b�Z�[�W���擾��, msg�Ɋi�[.(0�ȉ��Ȃ�, �����𔲂���.)

		// ���b�Z�[�W�̕ϊ��Ƒ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ń��b�Z�[�W���E�B���h�E�v���V�[�W���ɑ��o.

	}

	// �I������
	return ExitInstance();	// ExitInstance�̒l��Ԃ�.

}

// �I�������֐�ExitInstance
int ExitInstance() {

	// ����͏�ɐ�������0��Ԃ�.
	return 0;	// 0��Ԃ��Đ���I��.

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