// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "BinaryFile.h"	// CBinaryFile
#include "Profile.h"	// Profile

// バイナリファイルクラス
class CProfileManager : public CBinaryFile {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CProfileManager();	// コンストラクタCProfileManager
		virtual ~CProfileManager();	// デストラクタ~CProfileManager
		// メンバ関数
		BOOL Save(Profile prof);	// セーブ
		BOOL Load(Profile *prof);	// ロード

};