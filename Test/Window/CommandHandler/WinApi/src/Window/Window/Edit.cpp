// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "Edit.h"	// CEdit

// コンストラクタCEdit
CEdit::CEdit(HWND hParent, UINT nID) {

	// ボタンのロード.
	Load(hParent, nID);	// LoadでnIDのボタンをロード.

}

// メンバ関数Load
HWND CEdit::Load(HWND hParent, UINT nID) {

	// リソースIDのボタンのウィンドウハンドルを取得.
	m_nID = nID;	// メンバにセット.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItemでm_nIDのボタンウィンドウハンドルを取得し, m_hWndに格納.
	return m_hWnd;	// m_hWndを返す.

}

// メンバ関数SetText
void CEdit::SetText(tstring tstr) {

}

// メイン関数GetText
tstring CEdit::GetText() {

	// tstringオブジェクトの宣言.
	tstring tstrText;	// テキストtstrText

	// テキストの長さを取得.
	int iLen = GetWindowTextLength(m_hWnd);	// GetWindowTextLengthで長さを取得.

	// テキスト動的配列の作成.
	TCHAR *ptszText = new TCHAR[iLen + 1];	// ptszTextの作成.

	// テキストの取得.
	GetWindowText(m_hWnd, ptszText, iLen + 1);	// GetWindowTextでテキストを取得.

	// tstrTextに格納.
	tstrText = ptszText;	// tstrTextにptszTextをセット.

	// 配列の破棄.
	delete[] ptszText;	// ptszTextの破棄.

	// tstrTextを返す.
	return tstrText;

}