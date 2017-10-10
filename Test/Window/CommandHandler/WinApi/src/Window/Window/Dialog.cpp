// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Dialog.h"	// CDialog

// �R���X�g���N�^CDialog
CDialog::CDialog(UINT nIDTemplate, CWindow *pParent) {

	// �����o�̏�����
	m_nIDTemplate = nIDTemplate;	// m_nIDTemplate��nIDTemplate���Z�b�g.
	m_pParent = pParent;	// m_pParent��pParent���Z�b�g.

}

// �����o�֐�DoModal
INT_PTR CDialog::DoModal() {

	// �ϐ��̐錾
	HINSTANCE hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h��

	// hInstance���擾
	hInstance = (HINSTANCE)GetWindowLong(m_pParent->m_hWnd, GWL_HINSTANCE);	// GetWindowLong�ŃA�v���P�[�V�����C���X�^���X�n���h�����擾��, hInstance�Ɋi�[.

	// �_�C�A���O�̕\��.
	return DialogBoxParam(hInstance, MAKEINTRESOURCE(m_nIDTemplate), m_pParent->m_hWnd, (DLGPROC)CWindow::StaticWindowProc, (LPARAM)this);	// DialogBoxParam�Ń_�C�A���O�\��.(this��n��)

}

// �����o�֐�DynamicWindowProc
LRESULT CDialog::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �E�B���h�E���b�Z�[�W����
	switch (uMsg) {

		// �E�B���h�E������ꂽ��.
		case WM_CLOSE:

			// WM_CLOSE�u���b�N
			{

				// OnClose�ɔC����.
				return OnClose();

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// �_�C�A���O�̏�������.
		case WM_INITDIALOG:

			// WM_INITDIALOG�u���b�N
			{

				// OnInitDialog�ɔC����.
				return OnInitDialog(hwnd);

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// �R�}���h������������.
		case WM_COMMAND:

			// WM_COMMAND�u���b�N
			{

				// OnCommand�ɔC����.
				return OnCommand(wParam, lParam);	// wParam��lParam��n���ĔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

	// �����ł��ĂȂ��̂�FALSE.
	return FALSE;

}

// �����o�֐�OnClose
BOOL CDialog::OnClose() {

	// �_�C�A���O�̏I��.
	EndDialog(m_hWnd, IDCANCEL);	// EndDialog��IDCANCEL���w�肵�ă_�C�A���O�I��.

	// �����̃E�B���h�E�n���h�����c���Ă�����}�b�v����폜.
	if (CWindow::m_mapWindowMap.find(m_hWnd) != CWindow::m_mapWindowMap.end()) {	// find�Ō���������.
		CWindow::m_mapWindowMap.erase(m_hWnd);	// CWindow::m_mapWindowMap.erase�ō폜.
	}

	// �����ł����̂�TRUE.
	return TRUE;

}

// �����o�֐�OnInitDialog
BOOL CDialog::OnInitDialog(HWND hwndDlg) {

	// �����o�ɃE�B���h�E�n���h�����Z�b�g.
	m_hWnd = hwndDlg;	// m_hWnd��hwndDlg���Z�b�g.

	// �����ł����̂�TRUE.
	return TRUE;

}

// �����o�֐�OnCommand.
BOOL CDialog::OnCommand(WPARAM wParam, LPARAM lParam) {

	// �����ł����̂�TRUE.
	return TRUE;

}