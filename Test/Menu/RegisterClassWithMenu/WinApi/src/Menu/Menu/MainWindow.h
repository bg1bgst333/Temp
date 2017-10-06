// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow
#include "resource.h"			// リソースファイル

// メインウィンドウクラス
class CMainWindow : public CWindow {

	// publicメンバ
	public:

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// ウィンドウクラス登録関数RegisterClass(メニューID指定のバージョン.)(static関数)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(CWindowのオーバーライドメンバ関数.)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.(CWindowのオーバーライドメンバ関数.)
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// コマンド発生時のハンドラOnCommand.(CWindowのオーバーライドメンバ関数.)
		void OnItem1_1();	// Item1-1が選択された時のハンドラ.
		void OnItem1_2();	// Item1-2が選択された時のハンドラ.
		void OnItem1_3();	// Item1-3が選択された時のハンドラ.
		void OnItem2_1();	// Item2-1が選択された時のハンドラ.
		void OnItem2_2();	// Item2-2が選択された時のハンドラ.
		void OnItem2_3();	// Item2-3が選択された時のハンドラ.
		void OnItem3_1();	// Item3-1が選択された時のハンドラ.
		void OnItem3_2();	// Item3-2が選択された時のハンドラ.
		void OnItem3_3();	// Item3-3が選択された時のハンドラ.

};