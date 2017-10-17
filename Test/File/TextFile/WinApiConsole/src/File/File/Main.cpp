// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <cstdio>	// C標準入出力
#include <iostream>		// C++標準入出力
//独自のヘッダ
#include "TextFile.h"	// CTextFile

// _tmain関数
int _tmain() {

	// テキストファイルオブジェクトの生成.
	CTextFile *pTextFile = new CTextFile();	// newでCTextFileオブジェクトを作成し, ポインタをpTextFileに格納.

	// "test.txt"の読み込み.
	pTextFile->Read(_T("test.txt"));	// pTextFile->Readで"test.txt"を読み込む.

	// 内容を出力.(Shift_JISに変換してから, 出力.)
	int len = WideCharToMultiByte(CP_ACP, 0, pTextFile->m_ptszText, -1, NULL, 0, NULL, NULL);	// 必要なバッファサイズを計算.
	char *pszText = new char[len];	// lenの分だけのバッファpszTextを生成.
	WideCharToMultiByte(CP_ACP, 0, pTextFile->m_ptszText, -1, pszText, len, NULL, NULL);	// pTextFile->m_ptszTextをpszTextに変換.
	std::cout << "pszText = " << pszText << std::endl;	// pszTextを出力.
	delete[] pszText;	// delete[]でpszTextを破棄.

	// テキストファイルオブジェクトの破棄.
	delete pTextFile;	// deleteでpTextFileを破棄.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}