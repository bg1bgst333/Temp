// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <string>		// std::string

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// プロファイル構造体タグTagProfile
typedef struct TagProfile {

	// メンバ
	int m_iNo;	// 番号.
	tstring m_tstrName;	// 名前.
	int m_iAge;	// 年齢.
	tstring m_tstrAddress;	// 住所.

} Profile;	// Profile型