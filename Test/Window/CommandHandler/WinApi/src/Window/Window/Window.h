// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI
#include <map>			// std::map
// 独自のヘッダ
#include "HandlerConditions.h"	// ハンドラ条件

// ウィンドウクラス
class CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		HWND m_hWnd;	// ウィンドウハンドルm_hWnd
		// staticメンバ変数
		static std::map<HWND, CWindow *> m_mapWindowMap;	// ウィンドウハンドルをキー, CWindowオブジェクトポインタを値とするマップm_mapWindowMap.
		static std::map<UINT, HandlerConditions*> m_mapHandlerMap;	// nIDをキー, HandlerConditionsポインタを値とするマップm_mapHandlerMap.
		
		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CWindow();	// コンストラクタCWindow
		virtual ~CWindow();	// デストラクタ~CWindow
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass(引数がhInstanceだけのバージョン.)(static関数)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// ウィンドウクラス登録関数RegisterClass(ウィンドウクラス名指定のバージョン)(static関数)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID);	// ウィンドウクラス登録関数RegisterClass(ウィンドウクラス名, メニューID指定のバージョン.)(static関数)
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャStaticWindowProc
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(ウィンドウクラス名指定バージョン.)
		virtual BOOL ShowWindow(int nCmdShow);	// ウィンドウ表示関数ShowWindow
		virtual void AddCommandHandler(UINT nID, UINT nCode, int(CWindow::*handler)(LPVOID p));	// コマンドハンドラの追加
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// StaticWindowProcから各ウィンドウオブジェクトごとに呼び出されるサブウィンドウプロシージャDynamicWindowProc.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual BOOL OnClose();			// 閉じられた時のハンドラOnClose.
		virtual BOOL OnInitDialog(HWND hwndDlg);	// ダイアログ初期化時のハンドラOnInitDialog.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// コマンド発生時のハンドラOnCommand.
		//virtual int handler(LPVOID p);

};