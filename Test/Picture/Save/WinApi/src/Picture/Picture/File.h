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

// �t�@�C���N���X
class CFile {

	// public�����o
	public:
		
		// public�����o�ϐ�
		HANDLE m_hFile;	// �t�@�C���n���h��m_hFile
		tstring m_tstrFileName;	// �t�@�C����m_tstrFileName

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CFile();
		virtual ~CFile();
		// �����o�֐�
		virtual BOOL Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition);	// �����o�֐�Open
		virtual void Close();	// �����o�֐�Close
		virtual DWORD Read(LPVOID lpBuf, DWORD dwBytes);	// �����o�֐�Read
		virtual DWORD Write(LPVOID lpBuf, DWORD dwBytes);	// �����o�֐�Write

};
