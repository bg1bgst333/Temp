// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BinaryFile.h"	// CBinaryFile
#include "Profile.h"	// Profile

// �o�C�i���t�@�C���N���X
class CProfileManager : public CBinaryFile {

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CProfileManager();	// �R���X�g���N�^CProfileManager
		virtual ~CProfileManager();	// �f�X�g���N�^~CProfileManager
		// �����o�֐�
		BOOL Save(Profile prof);	// �Z�[�u
		BOOL Load(Profile *prof);	// ���[�h

};