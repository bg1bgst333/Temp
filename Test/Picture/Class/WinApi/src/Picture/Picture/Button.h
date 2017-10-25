// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// ボタンクラスCButton
class CButton : public CWindow{
	
	// publicメンバ
	public:

		// publicメンバ変数
		int m_nID;	// リソースID

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CButton(HWND hParent, UINT nID);	// コンストラクタCButton
		// メンバ関数
		HWND Load(HWND hParent, UINT nID);	// リソースのロード関数Load
		virtual BOOL OnCommandButton(WPARAM wParam, LPARAM lParam);	// どのボタンが押されたかを振り分けるハンドラOnCommandButton.
		virtual void OnClick();	// クリックされた時のハンドラOnClick

};