// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "File.h"	// CFile

// �o�C�i���t�@�C���N���X
class CBinaryFile : public CFile {

	// public�����o
	public:

		// public�����o�ϐ�
		BYTE *m_pBytes;	// �o�C�g��ւ̃|�C���^m_pBytes.
		DWORD m_dwSize;	// �t�@�C���T�C�Ym_dwSize.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CBinaryFile();	// �R���X�g���N�^CBinaryFile
		virtual ~CBinaryFile();	// �f�X�g���N�^~CBinaryFile

		// �����o�֐�
		virtual BOOL Read(LPCTSTR lpctszFileName);	// �o�C�i���̓ǂݍ��݊֐�Read
		virtual BOOL Write(LPCTSTR lpctszFileName);	// �o�C�i���̏������݊֐�Write
		void Set(BYTE *pBytes, DWORD dwSize);	// �o�b�t�@�̃Z�b�g�֐�Set
		void Clear();	// �o�b�t�@�̃N���A�֐�Clear

};