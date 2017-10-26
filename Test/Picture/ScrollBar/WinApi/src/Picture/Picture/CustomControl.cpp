// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// static�����o�ϐ��̒�`.
std::map<tstring, WNDPROC> CCustomControl::m_mapBaseWindowProcMap;	// �x�[�X�E�B���h�E�v���V�[�W���}�b�v

// �R���X�g���N�^CCustomControl
CCustomControl::CCustomControl() : CWindow() {

}

// �E�B���h�E�v���V�[�W��StaticWindowProc
LRESULT CCustomControl::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �|�C���^�̐錾
	CWindow *pWindow = NULL;	// CWindow�I�u�W�F�N�g�|�C���^pWindow.

	// hwnd�ŃE�B���h�E�I�u�W�F�N�g�|�C���^����������, pWindow�Ɋi�[.
	if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()) {	// find�Ō���������.
		pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindow��hwnd�ň�����CWindow�I�u�W�F�N�g�|�C���^����.
	}

	// �E�B���h�E�I�u�W�F�N�g�擾�ł��Ȃ��ꍇ.
	if (pWindow == NULL) {	// pWindow��NULL.

		// �z��̐錾.
		TCHAR tszClassName[256] = { 0 };	// tszClassName��0�ŏ�����.

		// �E�B���h�E�n���h������E�B���h�E�N���X�����擾.
		GetClassName(hwnd, tszClassName, 256);	// GetClassName�ŃE�B���h�E�N���X�����擾.

		// tszClassName��m_mapBaseWindowProcMap�̃L�[�ɂ����.
		if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()) {	// �݂�������.

			// ����̃v���V�[�W���ɔC����.
			return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProc�ł��̃��b�Z�[�W��m_mapBaseWindowProcMap[tszClassName]�ɔC����.

		}
		else {

			// �����łȂ��Ȃ�, DefWindowProc�ɔC����.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);

		}

	}
	else {	// pWindow��������.

		// ���̃E�B���h�E��DynamicWindowProc�ɓn��.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProc�ɓn��.

	}

}

// �����o�֐�Create(�E�B���h�E�N���X���w��o�[�W����.)
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�̈ʒu�E�T�C�Y���Z�b�g.
	m_x = x;				// m_x��x����.
	m_y = y;				// m_y��y����.
	m_iWidth = iWidth;		// m_iWidth��iWidth����.
	m_iHeight = iHeight;	// m_iHeight = iHeight����.

	// �E�B���h�E�̍쐬
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindow�ŃE�B���h�E���쐬��, �n���h����m_hWnd�Ɋi�[.(�Ō�̈�����this(���g�̃|�C���^)��n��.)
	if (m_hWnd == NULL) {	// m_hWnd��NULL�Ȃ玸�s.

		// ���s�Ȃ�FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// OnCreate�͈ȍ~�Ă΂�Ȃ��̂ł����ŌĂ�ł���.
	CREATESTRUCT cs;	// CREATESTRUCT���ꉞ�p��.
	cs.hInstance = hInstance;	// hInstance�͗v�邩������Ȃ��̂�, ����͓n����悤�ɂ��Ă���.
	if (OnCreate(m_hWnd, &cs) != 0) {	// OnCreate��cs��n��.

		// �E�B���h�E��j������.
		DestroyWindow(m_hWnd);
		m_hWnd = NULL;
		return FALSE;

	}

	// ����̃E�B���h�E�v���V�[�W�����擾��, CCustomControl::StaticWindowProc�ɍ����ւ���.
	WNDPROC lpfnWndProc;	// ����̃v���V�[�W��lpfnWndProc.
	lpfnWndProc = (WNDPROC)GetWindowLong(m_hWnd, GWL_WNDPROC);	// GetWindowLong�Ńv���V�[�W��lpfnWndProc���擾.
	SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)StaticWindowProc);	// SetWindowLong�Ńv���V�[�W��CCustomControl::StaticWindowProc��ݒ�.

	// �}�b�v�ɃE�B���h�E�N���X�����Ȃ���Γo�^.
	if (CCustomControl::m_mapBaseWindowProcMap.find(lpctszClassName) == CCustomControl::m_mapBaseWindowProcMap.end()) {
		CCustomControl::m_mapBaseWindowProcMap.insert(std::pair<tstring, WNDPROC>(lpctszClassName, lpfnWndProc));	// �v���V�[�W����o�^.
	}

	// WM_CREATE��ʂ�Ȃ��̂ŃE�B���h�E�}�b�v�̓o�^���s��.
	if (CWindow::m_mapWindowMap.find(m_hWnd) == CWindow::m_mapWindowMap.end()) {	// �E�B���h�E�}�b�v�ɂȂ����.
		CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(m_hWnd, this));	// �o�^����.
	}

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �����o�֐�DynamicWindowProc
LRESULT CCustomControl::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

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

		// �E�B���h�E�̕`���v�����ꂽ��.
		case WM_PAINT:

			// WM_PAINT�u���b�N
			{

				// OnPaint�ɔC����.
				OnPaint();	// OnPaint���Ă�.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// �����̃��b�Z�[�W��DefWindowProc�ɓ����Ȃ���, �X�N���[���o�[���F���������삵�Ȃ�.
		case WM_NCHITTEST:
		case WM_NCLBUTTONDOWN:
		case WM_NCLBUTTONUP:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);

		// �����L�[�������ꂽ��.
		case WM_CHAR:

			// WM_CHAR�u���b�N
			{

				// OnChar�ɔC����.
				if (OnChar(wParam, LOWORD(lParam), HIWORD(lParam)) == -1) {	// -1�̎��͓��͂��L�����Z��.

					// ���̓L�����Z��.
					return 0;	// 0�������ŕԂ��Ɠ��̓L�����Z���ƂȂ�.

				}

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ���������X�N���[���o�[�C�x���g��.
		case WM_HSCROLL:

			// WM_HSCROLL�u���b�N
			{

				// OnHScroll�ɔC����.
				OnHScroll(LOWORD(wParam), HIWORD(wParam));	// OnHScroll�ɔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ���������X�N���[���o�[�C�x���g��.
		case WM_VSCROLL:

			// WM_VSCROLL�u���b�N
			{

				// OnVScroll�ɔC����.
				OnVScroll(LOWORD(wParam), HIWORD(wParam));	// OnVScroll�ɔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

	// �z��̐錾.
	TCHAR tszClassName[256] = { 0 };	// tszClassName��0�ŏ�����.

	// �E�B���h�E�n���h������E�B���h�E�N���X�����擾.
	GetClassName(hwnd, tszClassName, 256);	// GetClassName�ŃE�B���h�E�N���X�����擾.

	// tszClassName��m_mapBaseWindowProcMap�̃L�[�ɂ����.
	if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()) {	// �݂�������.

		// ����̃v���V�[�W���ɔC����.
		return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProc�ł��̃��b�Z�[�W��m_mapBaseWindowProcMap[tszClassName]�ɔC����.

	}
	else {

		// �����łȂ��Ȃ�, DefWindowProc�ɔC����.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}

}

// �����o�֐�OnDestroy
void CCustomControl::OnDestroy() {

}

// �����o�֐�OnPaint
void CCustomControl::OnPaint() {

}

// �����o�֐�OnHScroll
void CCustomControl::OnHScroll(UINT nSBCode, UINT nPos) {

}

// �����o�֐�OnVScroll
void CCustomControl::OnVScroll(UINT nSBCode, UINT nPos) {

}