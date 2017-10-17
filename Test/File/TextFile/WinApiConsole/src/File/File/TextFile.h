// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "BinaryFile.h"	// CBinaryFile

// テキストファイルクラス
class CTextFile : public CBinaryFile {

	// publicメンバ
	public:

		// publicメンバ変数
		TCHAR *m_ptszText;	// TCHARにデコード済みのテキストへのポインタm_ptszText.
		DWORD m_dwLen;	// テキストの長さm_dwLen.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CTextFile();	// コンストラクタCTextFile
		virtual ~CTextFile();	// コンストラクタ~CTextFile
		virtual BOOL Read(LPCTSTR lpctszFileName);	// テキストの読み込み関数Read
		void Clear();	// バッファのクリア関数Clear

};