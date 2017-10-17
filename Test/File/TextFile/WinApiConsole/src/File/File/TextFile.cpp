// ヘッダのインクルード
// 既定のヘッダ
#include <cstring>	// C文字列処理.
#include <wchar.h>	// ワイド文字.
// 独自のヘッダ
#include "TextFile.h"	// CTextFile

// コンストラクタCTextFile
CTextFile::CTextFile() : CBinaryFile(){

	// メンバの初期化
	m_ptszText = NULL;	// m_ptszTextにNULLをセット.
	m_dwLen = 0;	// m_dwLenに0をセット.

}

// デストラクタCTextFile
CTextFile::~CTextFile() {

	// ファイルとバッファをクリアする.
	Close();	// ファイルを閉じる.
	Clear();	// バッファを破棄.

}

// メンバ関数Read
BOOL CTextFile::Read(LPCTSTR lpctszFileName) {

	// 指定されたファイル名のファイルを読み込む.
	if (CBinaryFile::Read(lpctszFileName)) {	// 読み込みに成功したら.

		// 文字コード判定.
		if (m_dwSize >= 2 && m_pBytes[0] == 0xff && m_pBytes[1] == 0xfe) {	// UTF-16LEの場合.
			
			// テキスト配列の生成.
			m_ptszText = new TCHAR[m_dwSize - 2 + 1];	// (バイト数 - 2 + 1)分のTCHAR配列があれば十分かと思われる.
			wmemset(m_ptszText, _T('\0'), m_dwSize - 2 + 1);	// wmemsetでm_ptszTextを0で埋める.
			memcpy(m_ptszText, m_pBytes + 2, m_dwSize - 2);	// memcpyでm_pBytesの3バイト目からm_ptszTextにコピー.
			m_dwLen = _tcslen(m_ptszText);	// _tcslenの値をm_dwLenに格納.

			// 読み込み成功なのでTRUE.
			return TRUE;	// TRUEを返す.

		}

	}

	// 読み込み失敗なのでFALSE.
	return FALSE;	// FALSEを返す.

}

// メンバ関数Clear
void CTextFile::Clear() {

	// テキスト配列の解放.
	if (m_ptszText != NULL) {	// m_ptszTextがNULLでない時.
		delete[] m_ptszText;	// delete[]で解放.
		m_ptszText = NULL;		// m_ptszTextにNULLをセット.
	}
	m_dwLen = 0;	// m_dwLenに0をセット.

	// バイナリデータもクリア.
	CBinaryFile::Clear();	// CBinaryFile::Clearでクリア.

}