// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <cstdio>	// C�W�����o��
#include <iostream>		// C++�W�����o��
//�Ǝ��̃w�b�_
#include "TextFile.h"	// CTextFile

// _tmain�֐�
int _tmain() {

	// �e�L�X�g�t�@�C���I�u�W�F�N�g�̐���.
	CTextFile *pTextFile = new CTextFile();	// new��CTextFile�I�u�W�F�N�g���쐬��, �|�C���^��pTextFile�Ɋi�[.

	// "test.txt"�̓ǂݍ���.
	pTextFile->Read(_T("test.txt"));	// pTextFile->Read��"test.txt"��ǂݍ���.

	// ���e���o��.(Shift_JIS�ɕϊ����Ă���, �o��.)
	int len = WideCharToMultiByte(CP_ACP, 0, pTextFile->m_ptszText, -1, NULL, 0, NULL, NULL);	// �K�v�ȃo�b�t�@�T�C�Y���v�Z.
	char *pszText = new char[len];	// len�̕������̃o�b�t�@pszText�𐶐�.
	WideCharToMultiByte(CP_ACP, 0, pTextFile->m_ptszText, -1, pszText, len, NULL, NULL);	// pTextFile->m_ptszText��pszText�ɕϊ�.
	std::cout << "pszText = " << pszText << std::endl;	// pszText���o��.
	delete[] pszText;	// delete[]��pszText��j��.

	// �e�L�X�g�t�@�C���I�u�W�F�N�g�̔j��.
	delete pTextFile;	// delete��pTextFile��j��.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}