// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �O���錾
class CWindow;	// �E�B���h�E�N���X

// �n���h���̔����������i�[����\����
struct HandlerConditions {
	UINT nID;	// ���\�[�XID
	UINT nCode;	// �ʒm�R�[�h
	int (CWindow:: * hfp)(WPARAM wParam, LPARAM lParam);	// CWindow�N���X�����o�̃n���h���֐��ւ̃|�C���^hfp.
};