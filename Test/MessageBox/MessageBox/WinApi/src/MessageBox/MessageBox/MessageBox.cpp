// �w�b�_�̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// _tWinMain�֐�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// ���b�Z�[�W�{�b�N�X�̕\��
	MessageBox(NULL, _T("Message"), _T("Title"), MB_OK);	// MessageBox�Ŗ{��"Message", �^�C�g��"Title"�̃��b�Z�[�W�{�b�N�X��\��.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}