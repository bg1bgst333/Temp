// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// �A�v���P�[�V�����N���XCApplication
class CApplication {

	// public�����o
	public:

		// public�����o�֐�
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) = 0;	// �������֐�InitInstance(�������z�֐�)
		virtual int Run();	// ���b�Z�[�W���[�v�����֐�Run
		virtual int ExitInstance();	// �I�������֐�ExitInstance

};