// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "Static.h"	// CStatic

// コンストラクタCStatic(HWND hParent, UINT nID)
CStatic::CStatic(HWND hParent, UINT nID) {

	// ボタンのロード.
	Load(hParent, nID);	// LoadでnIDのスタティックテキストコントロールをロード.

}

// メンバ関数Load
HWND CStatic::Load(HWND hParent, UINT nID) {

	// リソースIDのスタティックテキストコントロールのウィンドウハンドルを取得.
	m_nID = nID;	// メンバにセット.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItemでm_nIDのスタティックテキストコントロールウィンドウハンドルを取得し, m_hWndに格納.
	return m_hWnd;	// m_hWndを返す.

}

// メンバ関数SetText
void CStatic::SetText(tstring tstrText) {

	// テキストのセット.
	m_tstrText = tstrText;	// m_tstrTextにtstrTextを格納.
	SetWindowText(m_hWnd, tstrText.c_str());	// SetWindowTextでtstrTextをセット.

}

// メンバ関数GetText
void CStatic::GetText() {

	// テキストの長さを取得.
	int iLen = GetWindowTextLength(m_hWnd);	// GetWindowTextLengthで長さを取得.

	// テキスト動的配列の作成.
	TCHAR *ptszText = new TCHAR[iLen + 1];	// ptszTextの作成.

	// テキストの取得.
	GetWindowText(m_hWnd, ptszText, iLen + 1);	// GetWindowTextでテキストを取得.

	// m_tstrTextに格納.
	m_tstrText = ptszText;	// m_tstrTextにptszTextをセット.

	// 配列の破棄.
	delete[] ptszText;	// ptszTextの破棄.

}