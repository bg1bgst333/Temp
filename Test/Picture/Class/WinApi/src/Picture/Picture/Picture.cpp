// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "Picture.h"	// CPicture

// コンストラクタCPicture(HWND hParent, UINT nID)
CPicture::CPicture(HWND hParent, UINT nID) {

	// ピクチャーコントロールのロード.
	Load(hParent, nID);	// LoadでnIDのピクチャーコントロールをロード.

}

// メンバ関数Load
HWND CPicture::Load(HWND hParent, UINT nID) {

	// リソースIDのピクチャーコントロールのウィンドウハンドルを取得.
	m_nID = nID;	// メンバにセット.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItemでm_nIDのピクチャーコントロールウィンドウハンドルを取得し, m_hWndに格納.
	return m_hWnd;	// m_hWndを返す.

}
