// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow

// �����o�֐�RegisterClass(���j���[ID�w��̃o�[�W����.)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// �E�B���h�E�N���X��"CMainWindow"��o�^.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), nID);	// CWindow::RegisterClass��"CMainWindow"��nID��o�^��, �߂�l�����̂܂ܕԂ�.

}

// �����o�֐�Create
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// CWindow::Create�̃E�B���h�E�N���X���w��o�[�W�������g��.
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�̃E�B���h�E�N���X����"CMainWindow"���w��.

}

// �����o�֐�OnCreate
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���b�Z�[�W�{�b�N�X�̕\��.
	MessageBox(hwnd, _T("MainWindow OnCreate!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"MainWindow OnCreate!"�ƕ\��.

	// ��ɃE�B���h�E�쐬�����Ƃ���.
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �����o�֐�OnCommand
BOOL CMainWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	// �ǂ̃R�}���h(����̓��j���[����)���I�����ꂽ���𔻒肷��.
	switch (LOWORD(wParam)) {	// LOWORD(wParam)�őI�����ꂽ�R�}���h��ID���擾�ł���̂�, ���̒l�Ŕ��肷��.

		// ID_ITEM1_1�������ꂽ��
		case ID_ITEM1_1:

			// ID_ITEM1_1�u���b�N
			{

				// OnItem1_1�ɔC����.
				OnItem1_1();

			}

			// ������.
			break;	// break�Ŕ�����.

		// ID_ITEM1_2�������ꂽ��
		case ID_ITEM1_2:

			// ID_ITEM1_2�u���b�N
			{

				// OnItem1_2�ɔC����.
				OnItem1_2();

			}

			// ������.
			break;	// break�Ŕ�����.

		// ID_ITEM1_3�������ꂽ��
		case ID_ITEM1_3:

			// ID_ITEM1_3�u���b�N
			{

				// OnItem1_3�ɔC����.
				OnItem1_3();

			}

			// ������.
			break;	// break�Ŕ�����.


		// ID_ITEM2_1�������ꂽ��
		case ID_ITEM2_1:

			// ID_ITEM2_1�u���b�N
			{

				// OnItem2_1�ɔC����.
				OnItem2_1();

			}

			// ������.
			break;	// break�Ŕ�����.

		// ID_ITEM2_2�������ꂽ��
		case ID_ITEM2_2:

			// ID_ITEM2_2�u���b�N
			{

				// OnItem2_2�ɔC����.
				OnItem2_2();

			}

			// ������.
			break;	// break�Ŕ�����.

		// ID_ITEM2_3�������ꂽ��
		case ID_ITEM2_3:

			// ID_ITEM2_3�u���b�N
			{

				// OnItem2_3�ɔC����.
				OnItem2_3();

			}

			// ������.
			break;	// break�Ŕ�����.

		// ID_ITEM3_1�������ꂽ��
		case ID_ITEM3_1:

			// ID_ITEM3_1�u���b�N
			{

				// OnItem3_1�ɔC����.
				OnItem3_1();

			}

			// ������.
			break;	// break�Ŕ�����.

		// ID_ITEM3_2�������ꂽ��
		case ID_ITEM3_2:

			// ID_ITEM3_2�u���b�N
			{

				// OnItem3_2�ɔC����.
				OnItem3_2();

			}

			// ������.
			break;	// break�Ŕ�����.

		// ID_ITEM3_3�������ꂽ��
		case ID_ITEM3_3:

			// ID_ITEM3_3�u���b�N
			{

				// OnItem3_3�ɔC����.
				OnItem3_3();

			}

			// ������.
			break;	// break�Ŕ�����.

		// ����ȊO
		default:

			// ������.
			break;	// break�Ŕ�����.

	}

	// �R�}���h�����������̂�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �����o�֐�OnItem1_1
void CMainWindow::OnItem1_1() {

	// "Menu Item1-1!"�ƕ\��
	MessageBox(NULL, _T("Menu Item1-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item1-1!"�ƕ\��.

}

// �����o�֐�OnItem1_2
void CMainWindow::OnItem1_2() {

	// "Menu Item1-2!"�ƕ\��
	MessageBox(NULL, _T("Menu Item1-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item1-2!"�ƕ\��.

}

// �����o�֐�OnItem1_3
void CMainWindow::OnItem1_3() {

	// "Menu Item1-3!"�ƕ\��
	MessageBox(NULL, _T("Menu Item1-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item1-3!"�ƕ\��.

}

// �����o�֐�OnItem2_1
void CMainWindow::OnItem2_1() {

	// "Menu Item2-1!"�ƕ\��
	MessageBox(NULL, _T("Menu Item2-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item2-1!"�ƕ\��.

}

// �����o�֐�OnItem2_2
void CMainWindow::OnItem2_2() {

	// "Menu Item2-2!"�ƕ\��
	MessageBox(NULL, _T("Menu Item2-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item2-2!"�ƕ\��.

}

// �����o�֐�OnItem2_3
void CMainWindow::OnItem2_3() {

	// "Menu Item2-3!"�ƕ\��
	MessageBox(NULL, _T("Menu Item2-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item2-3!"�ƕ\��.

}

// �����o�֐�OnItem3_1
void CMainWindow::OnItem3_1() {

	// "Menu Item3-1!"�ƕ\��
	MessageBox(NULL, _T("Menu Item3-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item3-1!"�ƕ\��.

}

// �����o�֐�OnItem3_2
void CMainWindow::OnItem3_2() {

	// "Menu Item3-2!"�ƕ\��
	MessageBox(NULL, _T("Menu Item3-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item3-2!"�ƕ\��.

}

// �����o�֐�OnItem3_3
void CMainWindow::OnItem3_3() {

	// "Menu Item3-3!"�ƕ\��
	MessageBox(NULL, _T("Menu Item3-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBox��"Menu Item3-3!"�ƕ\��.

}