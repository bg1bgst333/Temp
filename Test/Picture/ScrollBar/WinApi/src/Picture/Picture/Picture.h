// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string
#include <tchar.h>	// TCHAR�^
// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// �}�N����`
#define SCROLLBAR_THICKNESS 16	// �Ƃ肠�����X�N���[���o�[�̌����̓}�N����16�Ƃ��Ă���.

// �s�N�`���[�R���g���[���N���X
class CPicture : public CCustomControl {

	// public�����o
	public:

		// public�����o�ϐ�
		int m_nID;	// ���\�[�XID m_nID
		HBITMAP m_hBitmap;	// �r�b�g�}�b�v�n���h��m_hBitmap
		tstring m_tstrImageName;	// �C���[�W��m_tstrImageName
		int m_iImageWidth;	// ��m_iImageWidth
		int m_iImageHeight;	// ����m_iImageHeight
		HDC m_hMemDC;	// �������f�o�C�X�R���e�L�X�gm_hMemDC
		int m_iHScrollPos;	// �X�N���[���o�[�̐��������̈ʒum_iHScrollPos
		int m_iVScrollPos;	// �X�N���[���o�[�̐��������̈ʒum_iVScrollPos
		SCROLLINFO m_ScrollInfo;	// �X�N���[�����m_ScrollInfo.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CPicture();	// �R���X�g���N�^CPicture
		CPicture(HWND hParent, UINT nID);	// �R���X�g���N�^CPicture(HWND hParent, UINT nID)
		virtual ~CPicture();	// �f�X�g���N�^~CPicture()
		// �����o�֐�
		HWND Load(HWND hParent, UINT nID);	// ���\�[�X�̃��[�h�֐�Load
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(�E�B���h�E�N���X���w��o�[�W����.)
		BOOL LoadImage(HINSTANCE hInstance, LPCTSTR lpctszImageName);	// �摜�����[�h����֐�LoadImage
		void SetImage();	// �摜���Z�b�g(�\��)����֐�SetImage
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g���̃n���h��OnHScroll.
		virtual void OnVScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g���̃n���h��OnVScroll.

};