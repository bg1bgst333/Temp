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
		int m_nID;	// ���\�[�XID

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CPicture(HWND hParent, UINT nID);	// �R���X�g���N�^CPicture(HWND hParent, UINT nID)
		HWND Load(HWND hParent, UINT nID);	// ���\�[�X�̃��[�h�֐�Load

};