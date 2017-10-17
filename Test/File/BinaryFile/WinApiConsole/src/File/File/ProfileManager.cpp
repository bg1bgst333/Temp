// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "ProfileManager.h"	// CProfileManager

// �R���X�g���N�^CProfileManager
CProfileManager::CProfileManager() : CBinaryFile(){

}

// �f�X�g���N�^~CProfileManager
CProfileManager::~CProfileManager() {

}

// �����o�֐�Save
BOOL CProfileManager::Save(Profile prof) {

	// "profile.bin"�ɃZ�[�u.
	Set((BYTE *)&prof, sizeof(prof));	// prof���o�b�t�@�ɃR�s�[.
	return Write(_T("profile.bin"));	// Write�ŏ�������.

}

// �����o�֐�Load
BOOL CProfileManager::Load(Profile * prof) {

	// "profile.bin"���烍�[�h.
	if (Read(_T("profile.bin"))) {	// profile.bin����ǂݍ���.
		// �R�s�[.
		Profile *p = (Profile *)m_pBytes;	// m_pBytes��(Profile *)�^p�ɃL���X�g.
		*prof = *p;	// �\���̂̃R�s�[.
		// ����.
		return TRUE;	// TRUE��Ԃ�.
	}

	// ���s.
	return FALSE;	// FALSE��Ԃ�.

}
