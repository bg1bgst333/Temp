// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// ����̃w�b�_
#include <string>	// std::string
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �J�X�^���R���g���[���N���X
class CCustomControl : public CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		// static�����o�ϐ�
		static std::map<tstring, WNDPROC> m_mapBaseWindowProcMap;	// ����̃E�B���h�E�N���X�����L�[, ����̃E�B���h�E�v���V�[�W����l�Ƃ���}�b�vm_mapBaseWindowProcMap.
		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CCustomControl();	// �R���X�g���N�^CCustomControl
		// static�����o�֐�
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �J�X�^���R���g���[����p��StaticWindowProc.
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(�E�B���h�E�N���X���w��o�[�W����.)
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// StaticWindowProc����e�E�B���h�E�I�u�W�F�N�g���ƂɌĂяo�����T�u�E�B���h�E�v���V�[�W��DynamicWindowProc.
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g���̃n���h��OnHScroll.
		virtual void OnVScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g���̃n���h��OnVScroll.

};