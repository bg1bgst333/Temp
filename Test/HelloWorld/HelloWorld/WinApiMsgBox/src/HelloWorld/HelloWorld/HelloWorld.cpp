// �w�b�_�̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// "Hello, world!"�̕\��
	MessageBox(NULL, _T("Hello, world!"), _T("HelloWorld"), MB_OK);	// MessageBox��"Hello, world!"��\��.
															
	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}