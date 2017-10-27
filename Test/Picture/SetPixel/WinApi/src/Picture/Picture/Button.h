// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// ボタンクラス
class CButton : public CCustomControl {

	// publicメンバ
	public:

		// publicメンバ変数
		int m_nID;	// リソースID

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CButton();	// コンストラクタCButton
		CButton(HWND hParent, UINT nID);	// コンストラクタCButton(HWND hParent, UINT nID)
		HWND Load(HWND hParent, UINT nID);	// リソースのロード関数Load
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(ウィンドウクラス名指定バージョン.)

};