// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��WindowProc

// _tWinMain�֐�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��̐錾
	int iRet;	// �߂�l

	// ���C���A�v���P�[�V�����I�u�W�F�N�g�̐���
	CApplication *pApplication = new CMainApplication();	// new��CMainApplication�I�u�W�F�N�g�𐶐���, CApplication�|�C���^�Ɋi�[.

	// ���C���A�v���P�[�V�����̏�����
	if (!pApplication->InitInstance(hInstance, lpCmdLine, nShowCmd)) {	// pApplication->InitInstance�ŏ�������, ���s������.

		// �ُ�I��
		iRet = pApplication->ExitInstance();	// pApplication->ExitInstance�ŏI��������, �߂�l��iRet�Ɋi�[.

	}
	else {	// ����������.

		// ���b�Z�[�W���[�v�ƏI������.
		iRet = pApplication->Run();	// pApplication->Run�Ń��b�Z�[�W���[�v����.(����ExitInstance�����s�����.

	}

	// �A�v���P�[�V�����I�u�W�F�N�g�̔j��
	delete pApplication;	// delete��pApplication��j��.

	// �v���O�����̏I��
	return iRet;	// iRet��Ԃ�.

}

// �E�B���h�E�v���V�[�W��WindowProc
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

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