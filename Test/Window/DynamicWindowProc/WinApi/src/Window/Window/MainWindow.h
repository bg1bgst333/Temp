// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// メインウィンドウクラス
class CMainWindow : public CWindow {

	// publicメンバ
	public:

		// publicメンバ関数
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.(CWindowのオーバーライドメンバ関数.)

};