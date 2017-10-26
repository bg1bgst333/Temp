// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string
#include <tchar.h>	// TCHAR型
// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// マクロ定義
#define SCROLLBAR_THICKNESS 16	// とりあえずスクロールバーの厚さはマクロで16としておく.

// ピクチャーコントロールクラス
class CPicture : public CCustomControl {

	// publicメンバ
	public:

		// publicメンバ変数
		int m_nID;	// リソースID m_nID
		HBITMAP m_hBitmap;	// ビットマップハンドルm_hBitmap
		tstring m_tstrImageName;	// イメージ名m_tstrImageName
		int m_iImageWidth;	// 幅m_iImageWidth
		int m_iImageHeight;	// 高さm_iImageHeight
		HDC m_hMemDC;	// メモリデバイスコンテキストm_hMemDC
		int m_iHScrollPos;	// スクロールバーの水平方向の位置m_iHScrollPos
		int m_iVScrollPos;	// スクロールバーの垂直方向の位置m_iVScrollPos
		SCROLLINFO m_ScrollInfo;	// スクロール情報m_ScrollInfo.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CPicture();	// コンストラクタCPicture
		CPicture(HWND hParent, UINT nID);	// コンストラクタCPicture(HWND hParent, UINT nID)
		virtual ~CPicture();	// デストラクタ~CPicture()
		// メンバ関数
		HWND Load(HWND hParent, UINT nID);	// リソースのロード関数Load
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(ウィンドウクラス名指定バージョン.)
		BOOL LoadImage(HINSTANCE hInstance, LPCTSTR lpctszImageName);	// 画像をロードする関数LoadImage
		void SetImage();	// 画像をセット(表示)する関数SetImage
		virtual void OnPaint();	// ウィンドウの描画を要求された時のハンドラOnPaint.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// 水平方向スクロールバーイベント時のハンドラOnHScroll.
		virtual void OnVScroll(UINT nSBCode, UINT nPos);	// 垂直方向スクロールバーイベント時のハンドラOnVScroll.

};