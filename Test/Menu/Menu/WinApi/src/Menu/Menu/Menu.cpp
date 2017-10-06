// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
// �Ǝ��̃w�b�_
#include "resource.h"	// ���\�[�X�t�@�C��

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��WindowProc

// _tWinMain�֐�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// �E�B���h�E�n���h��
	MSG msg;					// ���b�Z�[�W�\����
	WNDCLASS wc;				// �E�B���h�E�N���X�\����

	// �E�B���h�E�N���X�\���̂Ƀp�����[�^��ݒ�.
	wc.lpszClassName = _T("Menu");	// �E�B���h�E�N���X��"Menu"
	wc.style = CS_HREDRAW | CS_VREDRAW;	// �X�^�C��CS_HREDRAW | CS_VREDRAW
	wc.lpfnWndProc = WindowProc;		// �E�B���h�E�v���V�[�W��WindowProc
	wc.hInstance = hInstance;			// �A�v���P�[�V�����C���X�^���X�n���h��hInstance
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIcon�ŃA�C�R��IDI_APPLICATION�����[�h��, �n���h�����w��.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursor�ŃJ�[�\��IDC_ARROW�����[�h��, �n���h�����w��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObject��WHITE_BRUSH���擾��, �n���h�����w��.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);	// IDR_MAINMENU��MAKEINTRESOURCE�ŕϊ����ă��j���[�Ɏw��.
	wc.cbClsExtra = 0;	// 0���w��.
	wc.cbWndExtra = 0;	// 0���w��.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^.

		// �E�B���h�E�N���X�o�^���s�G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Menu"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"��\��.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(wc.lpszClassName, _T("Menu"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�N���X"Menu"�ȃE�B���h�E"Menu"���쐬.
	if (hWnd == NULL){	// hWnd��NULL�Ȃ�E�B���h�E�쐬���s.

		// �E�B���h�E�쐬���s�G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("Menu"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"��\��.
		return -2;	// -2��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow�ŃE�B���h�E�\��.

	// ���b�Z�[�W���[�v�̏���
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�Ń��b�Z�[�W���擾��, msg�Ɋi�[.(0�ȉ��Ȃ�, �����𔲂���.)

		// ���b�Z�[�W�̕ϊ��Ƒ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ń��b�Z�[�W���E�B���h�E�v���V�[�W���ɑ��o.

	}

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h(msg.wParam)��߂�l�Ƃ��ĕԂ�.

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

		// ���j���[, �{�^��, �A�N�Z�����[�^�L�[�Ȃǂ̃R�}���h������������.
		case WM_COMMAND:

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃R�}���h(����̓��j���[����)���I�����ꂽ���𔻒肷��.
				switch (LOWORD(wParam)) {	// LOWORD(wParam)�őI�����ꂽ�R�}���h��ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// ID_ITEM1_1�������ꂽ��
					case ID_ITEM1_1:

						// ID_ITEM1_1�u���b�N
						{

							// "Menu Item1-1!"�ƕ\��
							MessageBox(NULL, _T("Menu Item1-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item1-1!"�ƕ\��.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ID_ITEM1_2�������ꂽ��
					case ID_ITEM1_2:

						// ID_ITEM1_2�u���b�N
						{
					
							// "Menu Item1-2!"�ƕ\��
							MessageBox(NULL, _T("Menu Item1-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item1-2!"�ƕ\��.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ID_ITEM1_3�������ꂽ��
					case ID_ITEM1_3:

						// ID_ITEM1_3�u���b�N
						{

							// "Menu Item1-3!"�ƕ\��
							MessageBox(NULL, _T("Menu Item1-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item1-3!"�ƕ\��.

						}

						// ������.
						break;	// break�Ŕ�����.


					// ID_ITEM2_1�������ꂽ��
					case ID_ITEM2_1:

						// ID_ITEM2_1�u���b�N
						{

							// "Menu Item2-1!"�ƕ\��
							MessageBox(NULL, _T("Menu Item2-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item2-1!"�ƕ\��.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ID_ITEM2_2�������ꂽ��
					case ID_ITEM2_2:

						// ID_ITEM2_2�u���b�N
						{

							// "Menu Item2-2!"�ƕ\��
							MessageBox(NULL, _T("Menu Item2-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item2-2!"�ƕ\��.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ID_ITEM2_3�������ꂽ��
					case ID_ITEM2_3:

						// ID_ITEM2_3�u���b�N
						{

							// "Menu Item2-3!"�ƕ\��
							MessageBox(NULL, _T("Menu Item2-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item2-3!"�ƕ\��.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ID_ITEM3_1�������ꂽ��
					case ID_ITEM3_1:

						// ID_ITEM3_1�u���b�N
						{

							// "Menu Item3-1!"�ƕ\��
							MessageBox(NULL, _T("Menu Item3-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item3-1!"�ƕ\��.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ID_ITEM3_2�������ꂽ��
					case ID_ITEM3_2:

						// ID_ITEM3_2�u���b�N
						{

							// "Menu Item3-2!"�ƕ\��
							MessageBox(NULL, _T("Menu Item3-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item3-2!"�ƕ\��.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ID_ITEM3_3�������ꂽ��
					case ID_ITEM3_3:

						// ID_ITEM3_3�u���b�N
						{

							// "Menu Item3-3!"�ƕ\��
							MessageBox(NULL, _T("Menu Item3-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item3-3!"�ƕ\��.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ����ȊO
					default:

						// ������.
						break;	// break�Ŕ�����.

				}

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