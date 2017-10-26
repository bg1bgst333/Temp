// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string
#include <tchar.h>	// TCHAR型
// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// ピクチャーコントロールクラス
class CPicture : public CCustomControl {

	// publicメンバ
	public:

		// publicメンバ変数
		int m_nID;	// リソースID m_nID
		HBITMAP m_hBitmap;	// ビットマップハンドルm_hBitmap
		tstring m_tstrImageName;	// イメージ名m_tstrImageName

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CPicture(HWND hParent, UINT nID);	// コンストラクタCPicture(HWND hParent, UINT nID)
		virtual ~CPicture();	// デストラクタ~CPicture()
		// メンバ関数
		HWND Load(HWND hParent, UINT nID);	// リソースのロード関数Load
		BOOL LoadImage(HINSTANCE hInstance, LPCTSTR lpctszImageName);	// 画像をロードする関数LoadImage
		void SetImage();	// 画像をセット(表示)する関数SetImage

};