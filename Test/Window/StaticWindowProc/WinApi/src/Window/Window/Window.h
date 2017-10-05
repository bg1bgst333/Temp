// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI

// ウィンドウクラス
class CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		HWND m_hWnd;	// ウィンドウハンドルm_hWnd
		// staticメンバ変数
		static TCHAR m_tszClassName[256];	// ウィンドウクラス名m_tszClassName

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName = _T("CWindow"));	// ウィンドウクラス登録関数RegisterClass(デフォルト引数は"CWindow")(static関数)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, WNDPROC lpfnWndProc);	// ウィンドウクラス登録関数RegisterClass(ウィンドウプロシージャも渡すバージョン.)(static関数)
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャStaticWindowProc
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(ウィンドウクラス名も渡すバージョン.)
		virtual BOOL ShowWindow(int nCmdShow);	// ウィンドウ表示関数ShowWindow

};