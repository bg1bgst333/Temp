// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
// �Ǝ��̃w�b�_
#include "resource.h"	// ���\�[�X�t�@�C��

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��WindowProc
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �_�C�A���O�v���V�[�W���֐�DialogProc.

// _tWinMain�֐�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��E�z��̐錾�E������
	HWND hWnd;					// �E�B���h�E�n���h��
	MSG msg;					// ���b�Z�[�W�\����
	WNDCLASS wc;				// �E�B���h�E�N���X�\����

	// �E�B���h�E�N���X�\���̂Ƀp�����[�^��ݒ�.
	wc.lpszClassName = _T("Picture");	// �E�B���h�E�N���X��"Picture"
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Picture"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"��\��.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(wc.lpszClassName, _T("Picture"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�N���X"Picture"�ȃE�B���h�E"Picture"���쐬.
	if (hWnd == NULL){	// hWnd��NULL�Ȃ�E�B���h�E�쐬���s.

		// �E�B���h�E�쐬���s�G���[����
		MessageBox(NULL, _T("CreateWindow failed!"), _T("Picture"), MB_OK | MB_ICONHAND);	// MessageBox��"CreateWindow failed!"��\��.
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

					// ID_MENU_DIALOG�������ꂽ��
					case ID_MENU_DIALOG:

						// ID_MENU_DIALOG�u���b�N
						{

							// �ϐ��̐錾
							HINSTANCE hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h��

							// hInstance���擾
							hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);	// GetWindowLong�ŃA�v���P�[�V�����C���X�^���X�n���h�����擾��, hInstance�Ɋi�[.

							// �_�C�A���O�{�b�N�X�̕\��
							DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG), hwnd, DialogProc);	// DialogBox�Ń_�C�A���O�{�b�N�X��\��.(�_�C�A���O�̏�����DialogProc�ɏ����Ă���.)

							// ���������̂�0.																		// 0��Ԃ�.
							return 0;	// ���������̂Ŗ߂�l�Ƃ���0��Ԃ�.

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

// �_�C�A���O�v���V�[�W��DialogProc.
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �_�C�A���O�̃��b�Z�[�W����
	switch (uMsg) {	// uMsg�̓��e�Ŕ��f.

		// �_�C�A���O�̏�������.
		case WM_INITDIALOG:

			// WM_INITDIALOG�u���b�N
			{

				// TRUE��Ԃ�.
				return TRUE;	// �����ł����̂�TRUE.

			}

			// ������.
			break;	// break�Ŕ�����.

		// �{�^��, �A�N�Z�����[�^�L�[�Ȃǂ̃R�}���h������������.
		case WM_COMMAND:

			// WM_COMMAND�u���b�N
			{

				// �ǂ̃R�}���h(����̓{�^��)���I�����ꂽ���𔻒肷��.
				switch (LOWORD(wParam)) {	// LOWORD(wParam)�őI�����ꂽ�R�}���h��ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

					// IDC_BUTTON1�������ꂽ��
					case IDC_BUTTON1:

						// IDC_BUTTON1�u���b�N
						{

#if 1
							// �ϐ��E�|�C���^�̐錾
							HWND hEdit;				// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit.
							int iLen;				// �e�L�X�g�̒���iLen.
							TCHAR *ptszText;		// �e�L�X�g�ւ̃|�C���^ptszText.
							HINSTANCE hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h��hInstance.
							HBITMAP hBitmap;		// �r�b�g�}�b�v�n���h��hBitmap.
							HWND hPicture;			// �s�N�`���[�R���g���[���̃E�B���h�E�n���h��hPicture.

							// �G�f�B�b�g�R���g���[��IDC_EDIT1�̃e�L�X�g���擾.
							hEdit = GetDlgItem(hwndDlg, IDC_EDIT1);	// GetDlgItem��IDC_EDIT1�̃E�B���h�E�n���h�����擾.
							iLen = GetWindowTextLength(hEdit);	// GetWindowTextLength�Ńe�L�X�g�̒������擾.
							ptszText = new TCHAR[iLen + 1];	// new��TCHAR���I�z��𐶐���, �|�C���^��ptszText�Ɋi�[.
							GetWindowText(hEdit, ptszText, iLen + 1);	// GetWindowText�Ńe�L�X�g���擾.
							
							// �摜�̃��[�h.
							hPicture = GetDlgItem(hwndDlg, IDC_PICTURE1);	// GetDlgItem��IDC_PICTURE1�̃E�B���h�E�n���h�����擾.
							hInstance = (HINSTANCE)GetWindowLong(hwndDlg, GWLP_HINSTANCE);	// GetWindowLong�ŃC���X�^���X�n���h�����擾.
							hBitmap = (HBITMAP)LoadImage(hInstance, ptszText, IMAGE_BITMAP, 320, 240, LR_LOADFROMFILE);	// LoadImage�Ńr�b�g�}�b�v�����[�h.
							if (hBitmap != NULL) {	// NULL�łȂ��Ȃ�.

								// �摜�̕\��.
								SendMessage(hPicture, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);	// SendMessage��STM_SETIMAGE�𑗐M���邱�Ƃŉ摜��\��.
								DeleteObject(hBitmap);	// DeleteObject��hBitmap��j��.

							}

							// �j������.
							delete[] ptszText;	// ptszText��j��.

#else
							// �ϐ��E�|�C���^�̐錾
							HWND hEdit;			// �G�f�B�b�g�R���g���[���̃E�B���h�E�n���h��hEdit.
							int iLen;			// �e�L�X�g�̒���iLen.
							TCHAR *ptszText;	// �e�L�X�g�ւ̃|�C���^ptszText.
							HWND hStatic;		// �X�^�e�B�b�N�R���g���[���̃E�B���h�E�n���h��hStatic.

							// �G�f�B�b�g�R���g���[��IDC_EDIT1�̃e�L�X�g���擾��, �X�^�e�B�b�N�e�L�X�gIDC_STATIC1�ɃZ�b�g.
							hEdit = GetDlgItem(hwndDlg, IDC_EDIT1);	// GetDlgItem��IDC_EDIT1�̃E�B���h�E�n���h�����擾.
							iLen = GetWindowTextLength(hEdit);	// GetWindowTextLength�Ńe�L�X�g�̒������擾.
							ptszText = new TCHAR[iLen + 1];	// new��TCHAR���I�z��𐶐���, �|�C���^��ptszText�Ɋi�[.
							GetWindowText(hEdit, ptszText, iLen + 1);	// GetWindowText�Ńe�L�X�g���擾.
							hStatic = GetDlgItem(hwndDlg, IDC_STATIC1);	// GetDlgItem��IDC_STATIC1�̃E�B���h�E�n���h�����擾.
							SetWindowText(hStatic, ptszText);	// SetWindowText��hStatic��ptszText�𔽉f.
							delete[] ptszText;	// ptszText��j��.
#endif

							// TRUE��Ԃ�.
							return TRUE;	// �����ł����̂�TRUE.

						}

						// ������.
						break;	// break�Ŕ�����.

					// IDOK�������ꂽ��.
					case IDOK:

						// IDOK�u���b�N
						{

							// �_�C�A���O���I������.
							EndDialog(hwndDlg, IDOK);	// EndDialog�Ń_�C�A���O���I������.

							// TRUE��Ԃ�.
							return TRUE;	// �����ł����̂�TRUE.

						}

						// ������.
						break;	// break�Ŕ�����.

					// IDCANCEL�������ꂽ��.
					case IDCANCEL:

						// IDCANCEL�u���b�N
						{

							// �_�C�A���O���I������.
							EndDialog(hwndDlg, IDCANCEL);	// EndDialog�Ń_�C�A���O���I������.

							// TRUE��Ԃ�.
							return TRUE;	// �����ł����̂�TRUE.

						}

						// ������.
						break;	// break�Ŕ�����.

					// ����ȊO.
					default:

						// ������.
						break;	// break�Ŕ�����.

				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// �_�C�A���O������ꂽ��.
		case WM_CLOSE:	// �_�C�A���O������ꂽ��.(uMsg��WM_CLOSE�̎�.)

			// WM_CLOSE�u���b�N
			{

				// �_�C�A���O���I������.
				EndDialog(hwndDlg, IDCANCEL);	// EndDialog�Ń_�C�A���O���I������.

				// TRUE��Ԃ�.
				return TRUE;	// �����ł����̂�TRUE.

			}

			// ������.
			break;	// break�Ŕ�����.

		// ����ȊO.
		default:

			// ������.
			break;	// break�Ŕ�����.

	}

	// �����ɗ���Ƃ��͏����ł��Ă��Ȃ�.
	return FALSE;	// �����ł��Ă��Ȃ��̂�FALSE.

}