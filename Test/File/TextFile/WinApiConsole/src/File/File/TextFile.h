// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BinaryFile.h"	// CBinaryFile

// �e�L�X�g�t�@�C���N���X
class CTextFile : public CBinaryFile {

	// public�����o
	public:

		// public�����o�ϐ�
		TCHAR *m_ptszText;	// TCHAR�Ƀf�R�[�h�ς݂̃e�L�X�g�ւ̃|�C���^m_ptszText.
		DWORD m_dwLen;	// �e�L�X�g�̒���m_dwLen.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CTextFile();	// �R���X�g���N�^CTextFile
		virtual ~CTextFile();	// �R���X�g���N�^~CTextFile
		virtual BOOL Read(LPCTSTR lpctszFileName);	// �e�L�X�g�̓ǂݍ��݊֐�Read
		void Clear();	// �o�b�t�@�̃N���A�֐�Clear

};