// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow
#include "MenuBar.h"	// CMenuBar

// メニューウィンドウクラス
class CMenuWindow : public CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		CMenuBar *m_pMenuBar;	// CMenuBarオブジェクトポインタm_pMenuBar.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMenuWindow();	// コンストラクタCMenuWindow
		virtual ~CMenuWindow();	// デストラクタ~CMenuWindow
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass(メニュー無しバージョン.)(static関数)
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// ウィンドウクラス登録関数RegisterClass(メニューID指定のバージョン.)(static関数)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// ウィンドウクラス名登録関数RegisterClass(ウィンドウクラス名の指定のバージョン.)(static関数)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID);	// ウィンドウクラス登録関数RegisterClass(ウィンドウクラス名, メニューID指定のバージョン.)(static関数)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(ウィンドウクラス名指定バージョン.)

};