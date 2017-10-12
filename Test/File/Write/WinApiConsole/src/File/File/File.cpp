// �w�b�_�̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>	// TCHAR�^
#include <cstdio>	// C�W�����o��
#include <iostream>	// C++�W�����o��

// _tmain�֐�
int _tmain() {

	// �ϐ��E�z��̐錾�E������
	TCHAR tszFileName[_MAX_PATH] = { 0 };	// �t�@�C����tszFileName(�v�f��_MAX_PATH)��0�ŏ�����.
	TCHAR tszFileContent[1024] = { 0 };		// �t�@�C�����etszFileContent(�v�f��1024)��0�ŏ�����.
	HANDLE hFile;	// �t�@�C���n���h��hFile
	DWORD dwWrittenBytes;	// �������񂾃o�C�g��dwWrittenBytes.
	char *pszFileContent = NULL;	// Shift_JIS������.
	int len;	// Shift_JIS�ϊ��ɕK�v�ȃo�b�t�@�̒���len.

	// �t�@�C�����̓���
	std::wcout << _T("tszFileName: ");	// std::wcout��"tszFileName: "���o��.
	_fgetts(tszFileName, _MAX_PATH, stdin);	// _fgetts�œ��͓��e��tszFileName�Ɋi�[.
	tszFileName[_tcslen(tszFileName) - 1] = _T('\0');	// _tcslen(tszFileName) - 1�Ԗڂ�'\0'���i�[.

	// �t�@�C�����e�̓���(1�s��, ���s������I���.)
	std::wcout << _T("---tszFileContent---") << std::endl;	// std::wcout��"---tszFileContent---"���o��.
	_fgetts(tszFileContent, 1024, stdin);	// _fgetts�œ��͓��e��tszFileContent�Ɋi�[.
	tszFileContent[_tcslen(tszFileContent) - 1] = _T('\0');	// _tcslen(tszFileContent) - 1�Ԗڂ�'\0'���i�[.

	// �t�@�C�����J��.
	hFile = CreateFile(tszFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��tszFileName���J��.
	if (hFile == INVALID_HANDLE_VALUE) {	// hFile��INVALID_HANDLE_VALUE�Ȃ玸�s.

		// �G���[����
		_tprintf(_T("CreateFile Error!\n"));	// _tprintf��"CreateFile Error!"�Əo��.
		return -1;	// -1��Ԃ�.

	}

	// �t�@�C���̏�������.
	len = WideCharToMultiByte(CP_ACP, 0, tszFileContent, -1, NULL, 0, NULL, NULL);	// WideCharToMultiByte�ŕK�v�Ȓ������擾.
	pszFileContent = new char[len];	// pszFileContent�̃��������m��.
	WideCharToMultiByte(CP_ACP, 0, tszFileContent, -1, pszFileContent, len, NULL, NULL);	// WideCharToMultiByte��Shift_JIS�ɕϊ�.
	WriteFile(hFile, pszFileContent, len - 1, &dwWrittenBytes, NULL);	// WriteFile�Ńt�@�C������������.

	// ����.
	CloseHandle(hFile);	// CloseHandle��hFile�����.
	delete [] pszFileContent;	// delete��pszFileContent�����.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}