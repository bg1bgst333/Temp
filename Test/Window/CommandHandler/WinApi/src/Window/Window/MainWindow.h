// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow
#include "MenuBar.h"	// CMenuBar

// メインウィンドウクラス
class CMainWindow : public CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		CMenuBar *m_pMenuBar;	// CMenuBarオブジェクトポインタm_pMenuBar.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMainWindow();	// コンストラクタCMainWindow()
		virtual ~CMainWindow();	// デストラクタ~CMainWindow()
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass(メニュー無しバージョン.)(static関数)
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// ウィンドウクラス登録関数RegisterClass(メニューID指定のバージョン.)(static関数)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(CWindowのオーバーライドメンバ関数.)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.(CWindowのオーバーライドメンバ関数.)
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.(CWindowのオーバーライドメンバ関数.)
		virtual int handler2(LPVOID p);	// ハンドラ関数handler

};