// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string
#include <tchar.h>	// TCHAR�^
// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// �s�N�`���[�R���g���[���N���X
class CPicture : public CCustomControl {

	// public�����o
	public:

		// public�����o�ϐ�
		int m_nID;	// ���\�[�XID m_nID
		HBITMAP m_hBitmap;	// �r�b�g�}�b�v�n���h��m_hBitmap
		tstring m_tstrImageName;	// �C���[�W��m_tstrImageName

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CPicture(HWND hParent, UINT nID);	// �R���X�g���N�^CPicture(HWND hParent, UINT nID)
		virtual ~CPicture();	// �f�X�g���N�^~CPicture()
		// �����o�֐�
		HWND Load(HWND hParent, UINT nID);	// ���\�[�X�̃��[�h�֐�Load
		BOOL LoadImage(HINSTANCE hInstance, LPCTSTR lpctszImageName);	// �摜�����[�h����֐�LoadImage
		void SetImage();	// �摜���Z�b�g(�\��)����֐�SetImage

};