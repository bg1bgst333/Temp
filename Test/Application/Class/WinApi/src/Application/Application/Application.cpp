// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Application.h"	// CApplication

// �����o�֐�Run
int CApplication::Run(){

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

// �����o�֐�ExitIntance
int CApplication::ExitInstance(){

	// ����͏�ɐ�������0��Ԃ�.
	return 0;	// 0��Ԃ��Đ���I��.

}