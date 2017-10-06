// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <cstring>	// C�����񏈗�
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// static�����o�ϐ��̒�`.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// �E�B���h�E�}�b�v

// �R���X�g���N�^CWindow
CWindow::CWindow(){

	// �����o�̏�����
	m_hWnd = NULL;	// m_hWnd��NULL�ŏ�����.

}

// �f�X�g���N�^~CWindow
CWindow::~CWindow(){

	// �����o�̏I������
	if (m_hWnd != NULL) {	// m_hWnd��NULL�łȂ���.

		// �E�B���h�E�̔j��.
		DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
		m_hWnd = NULL;	// NULL���Z�b�g.

	}

}

// static�����o�֐�RegisterClass(������hInstance�����̃o�[�W����.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance){

	// �\���̂̐錾
	WNDCLASS wc;	// �E�B���h�E�N���X�\����

	// �E�B���h�E�N���X�\���̂Ƀp�����[�^��ݒ�.
	wc.lpszClassName = _T("CWindow");	// �E�B���h�E�N���X����"CWindow"���Z�b�g.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// �X�^�C��CS_HREDRAW | CS_VREDRAW
	wc.lpfnWndProc = StaticWindowProc;		// �E�B���h�E�v���V�[�W��StaticWindowProc
	wc.hInstance = hInstance;			// �A�v���P�[�V�����C���X�^���X�n���h��hInstance
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIcon�ŃA�C�R��IDI_APPLICATION�����[�h��, �n���h�����w��.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursor�ŃJ�[�\��IDC_ARROW�����[�h��, �n���h�����w��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObject��WHITE_BRUSH���擾��, �n���h�����w��.
	wc.lpszMenuName = NULL;	// ���j���[��NULL(�Ȃ�).
	wc.cbClsExtra = 0;	// 0���w��.
	wc.cbWndExtra = 0;	// 0���w��.

	// �E�B���h�E�N���X�̓o�^
	if (!::RegisterClass(&wc)) {	// WindowsAPI��RegisterClass�ŃE�B���h�E�N���X��o�^.

		// �E�B���h�E�N���X�o�^���s�G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Menu"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"��\��.
		return FALSE;	// FALSE��Ԃ��Ĉُ�I��.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// �����Ȃ̂�TRUE��Ԃ�.

}

// static�����o�֐�RegisterClass(�E�B���h�E�N���X��, ���j���[ID�w��̃o�[�W����.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID) {

	// �\���̂̐錾
	WNDCLASS wc;	// �E�B���h�E�N���X�\����

	// �E�B���h�E�N���X�\���̂Ƀp�����[�^��ݒ�.
	wc.lpszClassName = lpctszClassName;	// �E�B���h�E�N���X����lpszClassName���Z�b�g.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// �X�^�C��CS_HREDRAW | CS_VREDRAW
	wc.lpfnWndProc = StaticWindowProc;		// �E�B���h�E�v���V�[�W��StaticWindowProc
	wc.hInstance = hInstance;			// �A�v���P�[�V�����C���X�^���X�n���h��hInstance
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIcon�ŃA�C�R��IDI_APPLICATION�����[�h��, �n���h�����w��.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursor�ŃJ�[�\��IDC_ARROW�����[�h��, �n���h�����w��.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObject��WHITE_BRUSH���擾��, �n���h�����w��.
	wc.lpszMenuName = MAKEINTRESOURCE(nID);	// nID����MAKEINTRESOURCE�ŕϊ����ă��j���[�Ɏw��.
	wc.cbClsExtra = 0;	// 0���w��.
	wc.cbWndExtra = 0;	// 0���w��.

	// �E�B���h�E�N���X�̓o�^
	if (!::RegisterClass(&wc)) {	// WindowsAPI��RegisterClass�ŃE�B���h�E�N���X��o�^.

		// �E�B���h�E�N���X�o�^���s�G���[����
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Menu"), MB_OK | MB_ICONHAND);	// MessageBox��"RegisterClass failed!"��\��.
		return FALSE;	// FALSE��Ԃ��Ĉُ�I��.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// �����Ȃ̂�TRUE��Ԃ�

}

// �E�B���h�E�v���V�[�W��StaticWindowProc
LRESULT CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �|�C���^�̏�����
	CWindow *pWindow = NULL;	// CWindow�I�u�W�F�N�g�|�C���^pWIndow��NULL�ɏ�����.

	// �E�B���h�E���b�Z�[�W����
	switch (uMsg) {

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �|�C���^�̏�����
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT�\���̂ւ̃|�C���^lpCreateStruct��NULL.
				// lParam����lpCreateStruct�����o��.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�^�ɃL���X�g����lpCreateStruct�Ɋi�[.
				if (lpCreateStruct != NULL) {	// lpCreateStruct��NULL�łȂ����.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParams��CWindow *�^�ɃL���X�g��, pWindow�Ɋi�[.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// CWindow::m_mapWindowMap��hwnd��pWindow�̃y�A��o�^.
				}

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO�̎�.
		default:

			// default�u���b�N
			{

				// hwnd��CWindow�I�u�W�F�N�g�|�C���^����������, pWindow�Ɋi�[.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()) {	// find�ŃL�[��hwnd�Ƃ���CWindow�I�u�W�F�N�g�|�C���^������������.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindow��hwnd�ň�����CWindow�I�u�W�F�N�g�|�C���^���i�[.
				}

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

	// CWindow�I�u�W�F�N�g�|�C���^���擾�ł��Ȃ������ꍇ, �擾�ł����ꍇ�ŕ�����.
	if (pWindow == NULL) {	// pWindow��NULL

		// DefWindowProc�ɔC����.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�ɂ��̂܂܈�����n����, ���̒l��߂�l�Ƃ���.

	}
	else {	// pWindow��NULL�łȂ�.

		// ����CWindow�I�u�W�F�N�g��DynamicWindowProc�ɓn��.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProc�ɂ��̂܂܈�����n����, ���̒l��߂�l�Ƃ���.

	}

}

// �����o�֐�Create
BOOL CWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�̍쐬
	m_hWnd = CreateWindow(_T("CWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindow�ŃE�B���h�E���쐬��, �n���h����m_hWnd�Ɋi�[.(�E�B���h�E�N���X����"CWindow".�Ō�̈�����this(���g�̃|�C���^)��n��.)
	if (m_hWnd == NULL) {	// m_hWnd��NULL�Ȃ玸�s.

		// ���s�Ȃ�FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �����o�֐�Create(�E�B���h�E�N���X���w��o�[�W����.)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�̍쐬
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindow�ŃE�B���h�E���쐬��, �n���h����m_hWnd�Ɋi�[.(�Ō�̈�����this(���g�̃|�C���^)��n��.)
	if (m_hWnd == NULL) {	// m_hWnd��NULL�Ȃ玸�s.

							// ���s�Ȃ�FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �����o�֐�ShowWindow
BOOL CWindow::ShowWindow(int nCmdShow){

	// �E�B���h�E�̕\��
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPI��ShowWindow��m_hWnd��\��.

}

// �����o�֐�DynamicWindowProc
LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �E�B���h�E���b�Z�[�W����
	switch (uMsg) {

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// OnCreate�ɔC����.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwnd��lParam��OnCreate�ɓn��, ���Ƃ͔C����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// OnDestroy�ɔC����.
				OnDestroy();	// OnDestroy���Ă�.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// �R�}���h������������.
		case WM_COMMAND:

			// WM_COMMAND�u���b�N
			{

				// OnCommand�ɔC����.
				return OnCommand(wParam, lParam) ? 0 : 1;	// wParam��lParam��n���ĔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

	// DefWindowProc�ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�ɂ��̂܂܈�����n����, ���̒l��߂�l�Ƃ���.

}

// �����o�֐�OnCreate
int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ��ɃE�B���h�E�쐬�����Ƃ���.
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �����o�֐�OnDestroy
void CWindow::OnDestroy() {

	// ���b�Z�[�W���[�v�I��.
	PostQuitMessage(0);	// PostQuitMessage�Ń��b�Z�[�W���[�v�𔲂�������.

}

// �����o�֐�OnCommand
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	// �R�}���h�����������̂�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}
