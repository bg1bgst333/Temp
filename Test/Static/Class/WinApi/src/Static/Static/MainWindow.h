// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "MenuWindow.h"	// CMenuWindow
#include "Edit.h"	// CEdit

// メインウィンドウクラス
class CMainWindow : public CMenuWindow {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMainWindow();	// コンストラクタCMainWindow()
		virtual ~CMainWindow();	// デストラクタ~CMainWindow()
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass(メニュー無しバージョン.)(static関数)
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// ウィンドウクラス登録関数RegisterClass(メニューID指定のバージョン.)(static関数)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウサイズが変更された時のハンドラOnSize.
		virtual int OnMenuDialog(WPARAM wParam, LPARAM lParam);	// [Menu]-[Dialog]が選択された時のハンドラOnMenuDialog.

};