// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <string>		// std::string

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �v���t�@�C���\���̃^�OTagProfile
typedef struct TagProfile {

	// �����o
	int m_iNo;	// �ԍ�.
	tstring m_tstrName;	// ���O.
	int m_iAge;	// �N��.
	tstring m_tstrAddress;	// �Z��.

} Profile;	// Profile�^