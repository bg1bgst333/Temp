// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication

// _tWinMain�֐�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��̐錾.
	int iRet;	// �߂�l���󂯎��int�^�ϐ�iRet.

	// ���C���A�v���P�[�V�����I�u�W�F�N�g�̍쐬.
	CApplication *pApplication = new CMainApplication();	// new��CMainApplication�I�u�W�F�N�g���쐬��, CApplication�I�u�W�F�N�g�|�C���^pApplication�Ɋi�[.

	// ���C���A�v���P�[�V�����̏�����.
	if (!pApplication->InitInstance(hInstance, lpCmdLine, nShowCmd)) {	// pApplication->InitInstance�ŏ�����.

		// ���s������ExitInstance���Ă�.
		iRet = pApplication->ExitInstance();	// pApplication->ExitInstance���Ă�, �߂�l��iRet�Ɋi�[.

	}
	else {	// ����������.

		// ���b�Z�[�W���[�v�ƏI������.
		iRet = pApplication->Run();	// pApplication->Run�Ń��b�Z�[�W���[�v����.(����ExitInstance�����s�����.)

	}

	// �A�v���P�[�V�����I�u�W�F�N�g�̔j��.
	delete pApplication;	// delete��pApplication��j��.

	// �v���O�����̏I��.
	return iRet;	// iRet��Ԃ�.

}