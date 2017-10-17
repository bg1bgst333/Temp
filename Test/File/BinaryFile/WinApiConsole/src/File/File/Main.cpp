// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <cstdio>	// C�W�����o��
#include <iostream>		// C++�W�����o��
//�Ǝ��̃w�b�_
#include "ProfileManager.h"	// CProfileManager

// _tmain�֐�
int _tmain() {

	// �ϐ��̐錾
	Profile prof;	// Profile�\���̕ϐ�prof.
	Profile prof2;	// Profile�\���̕ϐ�prof2.

	// �\���̂ɒl���Z�b�g.
	prof.m_iNo = 10;	// �ԍ�10
	prof.m_tstrName = _T("Taro");	// ���O"Taro"
	prof.m_iAge = 20;	// �N��20
	prof.m_tstrAddress = _T("Tokyo");	// �Z��"Tokyo"

	// �v���t�@�C���}�l�[�W���̐���.
	CProfileManager *profman = new CProfileManager();	// CProfileManager�I�u�W�F�N�g���쐬��, �|�C���^��profman�Ɋi�[.
	profman->Save(prof);	// profman->Save��prof���Z�[�u.

	// �v���t�@�C���}�l�[�W���̔j��.
	delete profman;	// delete��profman��j��.

	// �v���t�@�C���}�l�[�W���̐���.
	CProfileManager *profman2 = new CProfileManager();	// CProfileManager�I�u�W�F�N�g���쐬��, �|�C���^��profman2�Ɋi�[.
	profman2->Load(&prof2);	// profman2->Load��prof2�Ƀ��[�h.

	// �\���̂̒l���o��.
	std::wcout << _T("prof2.m_iNo = ") << prof2.m_iNo << std::endl;	// prof2.m_iNo���o��.
	std::wcout << _T("prof2.m_tstrName = ") << prof2.m_tstrName << std::endl;	// prof2.m_tstrName���o��.
	std::wcout << _T("prof2.m_iAge = ") << prof2.m_iAge << std::endl;	// prof2.m_iAge���o��.
	std::wcout << _T("prof2.m_tstrAddress = ") << prof2.m_tstrAddress << std::endl;	// prof2.m_tstrAddress���o��.

	// �v���t�@�C���}�l�[�W���̔j��.
	delete profman2;	// delete��profman2��j��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}