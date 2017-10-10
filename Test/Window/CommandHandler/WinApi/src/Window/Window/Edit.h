// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string
#include <tchar.h>	// TCHAR型
// 独自のヘッダ
#include "Window.h"	// CWindow

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// エディットコントロールクラスCEdit
class CEdit : public CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		int m_nID;	// リソースID
		tstring tstrText;	// テキスト

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CEdit(HWND hParent, UINT nID);	// コンストラクタCEdit
		// メンバ関数
		HWND Load(HWND hParent, UINT nID);	// リソースのロード関数Load
		void SetText(tstring tstr);	// テキストの設定.
		tstring GetText();	// テキストの取得.

};