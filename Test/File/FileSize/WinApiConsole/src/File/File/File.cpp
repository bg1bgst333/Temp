// �w�b�_�̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>	// TCHAR�^
#include <cstdio>	// C�W�����o��
#include <iostream>	// C++�W�����o��

// _tmain�֐�
int _tmain() {

	// �ϐ��E�z��̐錾�E������
	TCHAR tszFileName[_MAX_PATH] = { 0 };	// �t�@�C����tszFileName(�v�f��_MAX_PATH)��0�ŏ�����.
	HANDLE hFile;	// �t�@�C���n���h��hFile
	BYTE *pbtBuf = NULL;	// BYTE�o�b�t�@�ւ̃|�C���^pbtBuf��NULL�ɏ�����.
	DWORD dwFileSize;	// �t�@�C���T�C�YdwFileSize.
	DWORD dwReadBytes;	// �ǂݍ��񂾃o�C�g��dwReadBytes.

	// �t�@�C�����̓���
	std::wcout << _T("tszFileName: ");	// std::cout��"tszFileName: "���o��.
	std::wcin >> tszFileName;	// std::wcin��tszFileName�ɓ��͂��ꂽ�t�@�C�������i�[.

	// �t�@�C�����J��.(�ΏۂƂȂ�t�@�C����Shift_JIS�ł���K�v������.)
	hFile = CreateFile(tszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��tszFileName���J��.
	if (hFile == INVALID_HANDLE_VALUE) {	// hFile��INVALID_HANDLE_VALUE�Ȃ玸�s.

		// �G���[����
		_tprintf(_T("CreateFile Error!\n"));	// _tprintf��"CreateFile Error!"�Əo��.
		return -1;	// -1��Ԃ�.

	}

	// �t�@�C���T�C�Y�̎擾.
	dwFileSize = GetFileSize(hFile, NULL);	// GetFileSize�Ńt�@�C���T�C�Y���擾.
	printf("dwFileSize = %lu\n", dwFileSize);	// printf��dwFileSize���o��.

	// �o�b�t�@�̐���.
	pbtBuf = new BYTE[dwFileSize + 1];	// BYTE�^���I�z����쐬��, �|�C���^��pbtBuf�Ɋi�[.
	ZeroMemory(pbtBuf, dwFileSize + 1);	// ZeroMemory�ŏ�����.

	// �t�@�C���̓ǂݍ���.
	ReadFile(hFile, pbtBuf, dwFileSize, &dwReadBytes, NULL);	// ReadFile��hFile��ǂݍ���, pbtBuf�Ɋi�[.

	// btBuf���o��.
	printf("pbtBuf = %s\n", pbtBuf);	// printf��pbtBuf���o��.

	// �o�b�t�@�̔j��.
	delete[] pbtBuf;	// delete[]��pbtBuf��j��.

	// ����.
	CloseHandle(hFile);	// CloseHandle��hFile�����.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}