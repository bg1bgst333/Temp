// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "Button.h"	// CButton

// コンストラクタCButton
CButton::CButton(HWND hParent, UINT nID) {

	// ボタンのロード.
	Load(hParent, nID);	// LoadでnIDのボタンをロード.

}

// メンバ関数Load
HWND CButton::Load(HWND hParent, UINT nID) {

	// リソースIDのボタンのウィンドウハンドルを取得.
	m_nID = nID;	// メンバにセット.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItemでm_nIDのボタンウィンドウハンドルを取得し, m_hWndに格納.
	return m_hWnd;	// m_hWndを返す.

}

// メンバ関数OnCommandButton
BOOL CButton::OnCommandButton(WPARAM wParam, LPARAM lParam) {

	// このボタンかどうかをチェック.
	if (LOWORD(wParam) == m_nID) {	// m_nIDと同じかチェック.

		// 通知コードのチェック
		switch (HIWORD(wParam)) {

			// クリック時.
			case BN_CLICKED:

				// BN_CLICKEDブロック
				{	
			
					// OnClickに任せる.
					OnClick();	// OnClickを呼ぶ.

					// TRUEを返す.
					return TRUE;	// 処理できたのでTRUE.

				}

				// 抜ける.
				break;	// breakで抜ける.

			// それ以外.
			default:

				// 抜ける.
				break;	// breakで抜ける.

		}

	}
	
	// コマンドを処理していないのでFALSE.
	return FALSE;	// FALSEを返す.

}

// メンバ関数OnClick
void CButton::OnClick(){

	// "Button1 Clicked!"と表示.
	MessageBox(m_hWnd, _T("Button1 Clicked!"), _T("Button"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Button1 Clicked!"と表示.

}