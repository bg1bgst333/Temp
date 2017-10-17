// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "ProfileManager.h"	// CProfileManager

// コンストラクタCProfileManager
CProfileManager::CProfileManager() : CBinaryFile(){

}

// デストラクタ~CProfileManager
CProfileManager::~CProfileManager() {

}

// メンバ関数Save
BOOL CProfileManager::Save(Profile prof) {

	// "profile.bin"にセーブ.
	Set((BYTE *)&prof, sizeof(prof));	// profをバッファにコピー.
	return Write(_T("profile.bin"));	// Writeで書き込み.

}

// メンバ関数Load
BOOL CProfileManager::Load(Profile * prof) {

	// "profile.bin"からロード.
	if (Read(_T("profile.bin"))) {	// profile.binから読み込み.
		// コピー.
		Profile *p = (Profile *)m_pBytes;	// m_pBytesを(Profile *)型pにキャスト.
		*prof = *p;	// 構造体のコピー.
		// 成功.
		return TRUE;	// TRUEを返す.
	}

	// 失敗.
	return FALSE;	// FALSEを返す.

}
