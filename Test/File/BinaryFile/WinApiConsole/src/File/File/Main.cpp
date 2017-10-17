// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <cstdio>	// C標準入出力
#include <iostream>		// C++標準入出力
//独自のヘッダ
#include "ProfileManager.h"	// CProfileManager

// _tmain関数
int _tmain() {

	// 変数の宣言
	Profile prof;	// Profile構造体変数prof.
	Profile prof2;	// Profile構造体変数prof2.

	// 構造体に値をセット.
	prof.m_iNo = 10;	// 番号10
	prof.m_tstrName = _T("Taro");	// 名前"Taro"
	prof.m_iAge = 20;	// 年齢20
	prof.m_tstrAddress = _T("Tokyo");	// 住所"Tokyo"

	// プロファイルマネージャの生成.
	CProfileManager *profman = new CProfileManager();	// CProfileManagerオブジェクトを作成し, ポインタをprofmanに格納.
	profman->Save(prof);	// profman->Saveでprofをセーブ.

	// プロファイルマネージャの破棄.
	delete profman;	// deleteでprofmanを破棄.

	// プロファイルマネージャの生成.
	CProfileManager *profman2 = new CProfileManager();	// CProfileManagerオブジェクトを作成し, ポインタをprofman2に格納.
	profman2->Load(&prof2);	// profman2->Loadでprof2にロード.

	// 構造体の値を出力.
	std::wcout << _T("prof2.m_iNo = ") << prof2.m_iNo << std::endl;	// prof2.m_iNoを出力.
	std::wcout << _T("prof2.m_tstrName = ") << prof2.m_tstrName << std::endl;	// prof2.m_tstrNameを出力.
	std::wcout << _T("prof2.m_iAge = ") << prof2.m_iAge << std::endl;	// prof2.m_iAgeを出力.
	std::wcout << _T("prof2.m_tstrAddress = ") << prof2.m_tstrAddress << std::endl;	// prof2.m_tstrAddressを出力.

	// プロファイルマネージャの破棄.
	delete profman2;	// deleteでprofman2を破棄.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}