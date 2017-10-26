// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "Picture.h"	// CPicture

// �R���X�g���N�^CPicture()
CPicture::CPicture() {

	// �����o�̏�����.
	m_hBitmap = NULL;	// m_hBitmap��NULL���Z�b�g.
	m_tstrImageName = _T("");	// m_tstrImageName��""���Z�b�g.
	m_iImageWidth = 0;	// m_iImageWidth��0�ɃZ�b�g.
	m_iImageHeight = 0;	// m_iImageHeight��0�ɃZ�b�g.
	m_nID = 0;	// m_nID��0�ɃZ�b�g.
	m_hMemDC = NULL;	// m_hMemDC��NULL���Z�b�g.
	m_iHScrollPos = 0;	// m_iHScrollPos��0���Z�b�g.
	m_iVScrollPos = 0;	// m_iVScrollPos��0���Z�b�g.

}

// �R���X�g���N�^CPicture(HWND hParent, UINT nID)
CPicture::CPicture(HWND hParent, UINT nID) {

	// �����o�̏�����.
	m_hBitmap = NULL;	// m_hBitmap��NULL���Z�b�g.
	m_tstrImageName = _T("");	// m_tstrImageName��""���Z�b�g.
	m_iImageWidth = 0;	// m_iImageWidth��0�ɃZ�b�g.
	m_iImageHeight = 0;	// m_iImageHeight��0�ɃZ�b�g.
	m_hMemDC = NULL;	// m_hMemDC��NULL���Z�b�g.
	m_iHScrollPos = 0;	// m_iHScrollPos��0���Z�b�g.
	m_iVScrollPos = 0;	// m_iVScrollPos��0���Z�b�g.

	// �s�N�`���[�R���g���[���̃��[�h.
	Load(hParent, nID);	// Load��nID�̃s�N�`���[�R���g���[�������[�h.

}

// �f�X�g���N�^~CPicture()
CPicture::~CPicture() {

	// �r�b�g�}�b�v�̔j��.
	if (m_hBitmap != NULL) {	// NULL�łȂ����.
		DeleteObject(m_hBitmap);	// DeleteObject��m_hBitmap��j��.
		m_hBitmap = NULL;	// m_hBitmap��NULL���Z�b�g.
	}
	// �f�o�C�X�R���e�L�X�g�̔j��.
	if (m_hMemDC != NULL) {	// NULL�łȂ����.
		DeleteDC(m_hMemDC);	// DeleteDC��m_hMemDC��j��.
		m_hMemDC = NULL;	// m_hMemDC��NULL���Z�b�g.
	}
	m_tstrImageName = _T("");	// m_tstrImageName��""���Z�b�g.
	m_iImageWidth = 0;	// m_iImageWidth��0�ɃZ�b�g.
	m_iImageHeight = 0;	// m_iImageHeight��0�ɃZ�b�g.
	m_nID = 0;	// m_nID��0�ɃZ�b�g.
	m_iHScrollPos = 0;	// m_iHScrollPos��0���Z�b�g.
	m_iVScrollPos = 0;	// m_iVScrollPos��0���Z�b�g.

}

// �����o�֐�Load
HWND CPicture::Load(HWND hParent, UINT nID) {

	// ���\�[�XID�̃s�N�`���[�R���g���[���̃E�B���h�E�n���h�����擾.
	m_nID = nID;	// �����o�ɃZ�b�g.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItem��m_nID�̃s�N�`���[�R���g���[���E�B���h�E�n���h�����擾��, m_hWnd�Ɋi�[.
	return m_hWnd;	// m_hWnd��Ԃ�.

}

// �����o�֐�Create
BOOL CPicture::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �����o�ɃZ�b�g.
	m_nID = (int)hMenu;	// hMenu��m_nID�ɑ��.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle | SS_BITMAP, x, y, iWidth, iHeight, hWndParent, (HMENU)m_nID, hInstance);	// CCustomControl::Create�Ńs�N�`���[�R���g���[�����쐬.

}

// �����o�֐�LoadImage
BOOL CPicture::LoadImage(HINSTANCE hInstance, LPCTSTR lpctszImageName) {

	// �\���̂̏�����.
	BITMAP bitmap = { 0 };	// �r�b�g�}�b�v�����i�[����BITMAP�^bitmap��0�ŏ�����.

	// �����o�ɃZ�b�g.
	m_tstrImageName = lpctszImageName;	// m_tstrImageName��lpctszImageName���Z�b�g.

	// �摜�̃��[�h.
	m_hBitmap = (HBITMAP)::LoadImage(hInstance, m_tstrImageName.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImage��m_tstrImageName�����[�h.(�Ƃ肠�����摜�t�@�C���Ƃ��ă��[�h.)
	if (m_hBitmap == NULL) {	// NULL�Ȃ玸�s.

		// �G���[����.
		m_tstrImageName = _T("");	// ���s�����̂�""���Z�b�g.

		// ���s�Ȃ̂�FALSE��Ԃ�.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �摜���畝�ƍ������擾.
	GetObject(m_hBitmap, sizeof(BITMAP), &bitmap);	// GetObject��m_hBitmap����r�b�g�}�b�v�����擾��, bitmap�Ɋi�[.
	m_iImageWidth = bitmap.bmWidth;	// bitmap.bmWidth��m_iImageWidth�Ɋi�[.
	m_iImageHeight = bitmap.bmHeight;	// bitmap.bmHeight��m_iImageHeight�Ɋi�[.

	// �����Ȃ̂�TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}

// �����o�֐�SetImage
void CPicture::SetImage() {

	// �ϐ��̐錾.
	HDC hDC;	// HDC�^�f�o�C�X�R���e�L�X�g�n���h��hDC.

	// �f�o�C�X�R���e�L�X�g�n���h���̎擾.
	hDC = GetDC(m_hWnd);	// GetDC��m_hWnd����f�o�C�X�R���e�L�X�g�n���h��hDC���擾.

	// �������f�o�C�X�R���e�L�X�g�̍쐬.
	m_hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDC�ō쐬�����f�o�C�X�R���e�L�X�g�n���h����m_hMemDC�Ɋi�[.

	// �摜�̕\��.
	SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_hBitmap);	// SendMessage��STM_SETIMAGE�𑗐M���邱�Ƃŉ摜��\��.

	// �X�N���[���o�[�̈ʒu��������.
	m_iHScrollPos = 0;	// m_iHScrollPos��0���Z�b�g.
	m_iVScrollPos = 0;	// m_iVScrollPos��0���Z�b�g.

	// �f�o�C�X�R���e�L�X�g�̉��.
	ReleaseDC(m_hWnd, hDC);	// ReleaseDC��hDC�����.

}

// �����o�֐�OnPaint
void CPicture::OnPaint() {

	// �ϐ��̐錾.
	HDC hDC;			// �f�o�C�X�R���e�L�X�g�n���h��HDC�^hDC
	PAINTSTRUCT ps;		// PAINTSTRUCT�\���̕ϐ�ps
	HBITMAP hOld;		// �ȑO�̃r�b�g�}�b�v�n���h��hOld
	int iDrawWidth;		// ���ۂ̕`�敝.
	int iDrawHeight;	// ���ۂ̕`�捂��.

	// �`��J�n.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaint�ŕ`��J�n.

	// �r�b�g�}�b�v�̑I��.
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObject��m_hBitmap��I��.

	// �r�b�g�]���ɂ��`��.
	iDrawWidth = m_iWidth - SCROLLBAR_THICKNESS;	// ���ۂɂ̓R���g���[���� - �X�N���[���o�[�̌���.
	iDrawHeight = m_iHeight - SCROLLBAR_THICKNESS;	// ���ۂɂ̓R���g���[������ - �X�N���[���o�[�̌���.
	BitBlt(hDC, 0, 0, iDrawWidth, iDrawHeight, m_hMemDC, m_iHScrollPos, m_iVScrollPos, SRCCOPY);	// BitBlt��m_hMemDC����hDC�Ƀr�b�g�]�����邱�Ƃŕ`�悳���.

	// �Â��r�b�g�}�b�v���đI�����Ė߂�.
	SelectObject(m_hMemDC, hOld);	// SelectObject��hOld��I��.

	// �X�N���[���o�[�ݒ�.
	// ��
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// �T�C�Y���Z�b�g.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// �t���O���Z�b�g.
	m_ScrollInfo.nPage = iDrawWidth;	// �����Z�b�g.
	m_ScrollInfo.nMin = 0;	// �ŏ��l���Z�b�g.
	m_ScrollInfo.nMax = m_iImageWidth;	// �ő�l���Z�b�g.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, FALSE);	// SetScrollInfo�ŃZ�b�g.
															// �c
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// �T�C�Y���Z�b�g.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// �t���O���Z�b�g.
	m_ScrollInfo.nPage = iDrawHeight;	// �������Z�b�g.
	m_ScrollInfo.nMin = 0;	// �ŏ��l���Z�b�g.
	m_ScrollInfo.nMax = m_iImageHeight;	// �ő�l���Z�b�g.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, FALSE);	// SetScrollInfo�ŃZ�b�g.

	// �`��I��.
	EndPaint(m_hWnd, &ps);	// EndPaint�ŕ`��I��.

}

// �����o�֐�OnHScroll
void CPicture::OnHScroll(UINT nSBCode, UINT nPos) {

	// �X�N���[�����擾.
	m_ScrollInfo.fMask = SIF_POS;	// �ʒu�����ύX���[�h(���ꂪ�Ȃ���, �X�N���[���o�[�����̈ʒu�ɖ߂��Ă��܂��̂Œ���!���������O!)
	GetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo);	// �}�X�N��ݒ肵�Ă���GetScrollInfo.(����������!)

	// �X�N���[���o�[����.
	switch (nSBCode) {	// nSBCode���ƂɐU�蕪��.

		// ��ԍ�
		case SB_LEFT:

			// �ʒu���ŏ��l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// ��ԉE
		case SB_RIGHT:

			// �ʒu���ő�l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1��
		case SB_LINELEFT:

			// nPos��0�łȂ���΃f�N�������g.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1��E
		case SB_LINERIGHT:

			// nPos���ő�l-1�łȂ���΃C���N�������g.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1�y�[�W��
		case SB_PAGELEFT:

			// nPage�����炷.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1�y�[�W�E
		case SB_PAGERIGHT:

			// nPage�����₷.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBTRACK:

			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBPOSITION:

			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// ����ȊO.
		default:

			break;

	}

	// �X�N���[�����ݒ�.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);
	// �����o�ɂ��Z�b�g.
	m_iHScrollPos = m_ScrollInfo.nPos;
	// �����̈���쐬���ĉ�ʂ̍X�V.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRect�Ŗ����̈�쐬.

}

// �����o�֐�OnVScroll
void CPicture::OnVScroll(UINT nSBCode, UINT nPos) {

	// �X�N���[�����擾.
	m_ScrollInfo.fMask = SIF_POS;	// �ʒu�����ύX���[�h(���ꂪ�Ȃ���, �X�N���[���o�[�����̈ʒu�ɖ߂��Ă��܂��̂Œ���!���������O!)
	GetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo);	// �}�X�N��ݒ肵�Ă���GetScrollInfo.(����������!)

	// �X�N���[���o�[����.
	switch (nSBCode) {	// nSBCode���ƂɐU�蕪��.

		// ��ԏ�
		case SB_TOP:

			// �ʒu���ŏ��l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// ��ԉ�
		case SB_BOTTOM:

			// �ʒu���ő�l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1�s��
		case SB_LINEUP:

			// nPos��0�łȂ���΃f�N�������g.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1�s��
		case SB_LINEDOWN:

			// nPos���ő�l-1�łȂ���΃C���N�������g.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1�y�[�W��
		case SB_PAGEUP:

			// nPage�����炷.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1�y�[�W��
		case SB_PAGEDOWN:

			// nPage�����₷.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBTRACK:
	
			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBPOSITION:

			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// ����ȊO.
		default:

			break;

	}

	// �X�N���[�����ݒ�.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);
	// �����o�ɂ��Z�b�g.
	m_iVScrollPos = m_ScrollInfo.nPos;
	// �����̈���쐬���ĉ�ʂ̍X�V.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRect�Ŗ����̈�쐬.

}