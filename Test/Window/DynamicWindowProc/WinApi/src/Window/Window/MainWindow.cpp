// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow

// �����o�֐�OnCreate
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���b�Z�[�W�{�b�N�X�̕\��.
	MessageBox(hwnd, _T("MainWindow OnCreate!"), _T("Window"), MB_OK | MB_ICONASTERISK);	// MessageBox��"MainWindow OnCreate!"�ƕ\��.

	// ��ɃE�B���h�E�쐬�����Ƃ���.
	return 0;	// �����Ȃ�0��Ԃ�.

}
