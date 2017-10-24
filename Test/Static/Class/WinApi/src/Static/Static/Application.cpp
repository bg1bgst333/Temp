// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Application.h"	// CApplication

// �R���X�g���N�^CApplication
CApplication::CApplication(){

	// �����o�̏�����
	m_pMainWindow = NULL;	// m_pMainWindow��NULL�ŏ�����.

}

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

	// �n���h���}�b�v�̔j��.
	std::map<DWORD, HandlerConditions *>::iterator itor = CWindow::m_mapHandlerMap.begin();	// �n���h���}�b�v�̃C�e���[�^���擾.
	while (itor != CWindow::m_mapHandlerMap.end()) {	// �n���h���}�b�v�̏I�[�܂ŌJ��Ԃ�.
		delete itor->second;	// itor->second��HandlerConditions�I�u�W�F�N�g�|�C���^�Ȃ̂�, delete�ł����j��.
		itor++;	// �C�e���[�^��i�߂�.
	}

	// ���C���E�B���h�E�̔j��.
	if (m_pMainWindow != NULL) {	// m_pMainWindow��NULL�łȂ���.

		// �j������.
		delete m_pMainWindow;	// delete��m_pMainWindow��j��.
		m_pMainWindow = NULL;	// m_pMainWindow��NULL���Z�b�g.

	}

	// ����I��
	return 0;	// 0��Ԃ��Đ���I��.

}