// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string
#include <tchar.h>	// TCHAR型
// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// スタティックテキストコントロールクラス
class CStatic : public CCustomControl {

	// publicメンバ
	public:

		// publicメンバ変数
		int m_nID;	// リソースID
		tstring m_tstrText;	// テキスト

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CStatic(HWND hParent, UINT nID);	// コンストラクタCStatic(HWND hParent, UINT nID)
		HWND Load(HWND hParent, UINT nID);	// リソースのロード関数Load
		void SetText(tstring tstrText);	// テキストの設定関数SetText
		void GetText();	// テキストの取得関数GetText

};