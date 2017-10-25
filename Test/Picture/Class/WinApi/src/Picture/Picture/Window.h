// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
#include <map>			// std::map
// �Ǝ��̃w�b�_
#include "HandlerConditions.h"	// �n���h������

// �E�B���h�E�N���X
class CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		HWND m_hWnd;	// �E�B���h�E�n���h��m_hWnd
		// static�����o�ϐ�
		static std::map<HWND, CWindow *> m_mapWindowMap;	// �E�B���h�E�n���h�����L�[, CWindow�I�u�W�F�N�g�|�C���^��l�Ƃ���}�b�vm_mapWindowMap.
		static std::map<DWORD, HandlerConditions *> m_mapHandlerMap;	// nID���L�[, HandlerConditions�|�C���^��l�Ƃ���}�b�vm_mapHandlerMap.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CWindow();	// �R���X�g���N�^CWindow
		virtual ~CWindow();	// �f�X�g���N�^~CWindow
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(������hInstance�����̃o�[�W����.)(static�֐�)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�E�B���h�E�N���X���w��̃o�[�W����)(static�֐�)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�E�B���h�E�N���X��, ���j���[ID�w��̃o�[�W����.)(static�֐�)
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �E�B���h�E�v���V�[�W��StaticWindowProc
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(�E�B���h�E�N���X���w��o�[�W����.)
		virtual BOOL ShowWindow(int nCmdShow);	// �E�B���h�E�\���֐�ShowWindow
		virtual void AddCommandHandler(UINT nID, UINT nCode, int(CWindow:: * handler)(WPARAM wParam, LPARAM lParam));	// �R�}���h�n���h���ǉ��֐�AddCommandHandler
		virtual void DeleteCommandHandler(UINT nID, UINT nCode);	// �R�}���h�n���h���폜�֐�DeleteCommandHandler
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// StaticWindowProc����e�E�B���h�E�I�u�W�F�N�g���ƂɌĂяo�����T�u�E�B���h�E�v���V�[�W��DynamicWindowProc.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
		virtual BOOL OnClose();			// ����ꂽ���̃n���h��OnClose.
		virtual BOOL OnInitDialog(HWND hwndDlg);	// �_�C�A���O���������̃n���h��OnInitDialog.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h�������̃n���h��OnCommand.
		virtual int OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);		// �����L�[�������ꂽ���̃n���h��OnChar.

};