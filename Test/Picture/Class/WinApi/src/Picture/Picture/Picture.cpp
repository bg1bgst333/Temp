// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "Picture.h"	// CPicture

// コンストラクタCPicture(HWND hParent, UINT nID)
CPicture::CPicture(HWND hParent, UINT nID) {

	// メンバの初期化.
	m_hBitmap = NULL;	// m_hBitmapにNULLをセット.
	m_tstrImageName = _T("");	// m_tstrImageNameに""をセット.

	// ピクチャーコントロールのロード.
	Load(hParent, nID);	// LoadでnIDのピクチャーコントロールをロード.

}

// デストラクタ~CPicture()
CPicture::~CPicture() {

	// ビットマップの破棄.
	if (m_hBitmap != NULL) {	// NULLでなければ.
		DeleteObject(m_hBitmap);	// DeleteObjectでm_hBitmapを破棄.
		m_hBitmap = NULL;	// m_hBitmapにNULLをセット.
	}

}

// メンバ関数Load
HWND CPicture::Load(HWND hParent, UINT nID) {

	// リソースIDのピクチャーコントロールのウィンドウハンドルを取得.
	m_nID = nID;	// メンバにセット.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItemでm_nIDのピクチャーコントロールウィンドウハンドルを取得し, m_hWndに格納.
	return m_hWnd;	// m_hWndを返す.

}

// メンバ関数LoadImage
BOOL CPicture::LoadImage(HINSTANCE hInstance, LPCTSTR lpctszImageName) {

	// メンバにセット.
	m_tstrImageName = lpctszImageName;	// m_tstrImageNameにlpctszImageNameをセット.

	// 画像のロード.
	m_hBitmap = (HBITMAP)::LoadImage(hInstance, m_tstrImageName.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImageでm_tstrImageNameをロード.(とりあえず画像ファイルとしてロード.)
	if (m_hBitmap == NULL) {	// NULLなら失敗.

		// エラー処理.
		m_tstrImageName = _T("");	// 失敗したので""をセット.

		// 失敗なのでFALSEを返す.
		return FALSE;	// FALSEを返す.

	}

	// 成功なのでTRUEを返す.
	return TRUE;	// TRUEを返す.

}

// メンバ関数SetImage
void CPicture::SetImage() {

	// 画像の表示.
	SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_hBitmap);	// SendMessageでSTM_SETIMAGEを送信することで画像を表示.

}