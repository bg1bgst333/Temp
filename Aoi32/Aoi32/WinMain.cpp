// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// "Hello, Aoi32!"�ƕ\��.
	MessageBox(NULL, _T("Hello, Aoi32!"), _T("Aoi32"), MB_OK);	// MessageBox��Hello, Aoi32!"�ƕ\��.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}