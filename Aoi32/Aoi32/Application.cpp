// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Application.h"	// CApplication

// �R���X�g���N�^CApplication
CApplication::CApplication() {

	// �����o�̏�����.
	m_pMainWindow = NULL;	// m_pMainWindow��NULL�ŏ�����.

}

// �����o�֐�Run
int CApplication::Run() {

	// �\���̂̐錾.
	MSG msg;	// MSG�^���b�Z�[�W�\����msg

	// ���b�Z�[�W���[�v�̏���.
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�ŃE�B���h�E���b�Z�[�W���擾��, msg�Ɋi�[.(0�ȉ��Ȃ�, �����𔲂���.)

		// ���b�Z�[�W�̕ϊ��Ƒ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ń��b�Z�[�W���E�B���h�E�v���V�[�W��WindowProc�ɑ��o.

	}

	// �I������.
	return ExitInstance();	// �I��������ExitInstance�ɔC��, ���̖߂�l�����̂܂ܕԂ�.

}

// �����o�֐�ExitInstance
int CApplication::ExitInstance() {

	// ���C���E�B���h�E�̔j��.
	if (m_pMainWindow != NULL) {	// m_pMainWindow��NULL�łȂ���.

		// �j������.
		delete m_pMainWindow;	// delete��m_pMainWindow��j��.
		m_pMainWindow = NULL;	// m_pMainWindow��NULL���Z�b�g.

	}

	// �Ƃ肠����, ����͏�ɐ�������0��Ԃ�.
	return 0;	// 0��Ԃ��Đ���I��.

}