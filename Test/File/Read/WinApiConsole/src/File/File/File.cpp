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
	BYTE btBuf[1024];	// BYTE�^�o�b�t�@btBuf(�v�f��1024)
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

	// �t�@�C���̓ǂݍ���.
	ReadFile(hFile, btBuf, 1024, &dwReadBytes, NULL);	// ReadFile��hFile��ǂݍ���, btBuf�Ɋi�[.
	btBuf[dwReadBytes] = 0x0;	// ������0x0�Ŗ��߂�.

	// btBuf���o��.
	printf("btBuf = %s\n", btBuf);	// printf��btBuf���o��.

	// ����.
	CloseHandle(hFile);	// CloseHandle��hFile�����.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}