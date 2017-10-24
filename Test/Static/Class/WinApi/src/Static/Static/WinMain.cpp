// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication

// _tWinMain関数
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	int iRet;	// 戻り値

	// メインアプリケーションオブジェクトの生成
	CApplication *pApplication = new CMainApplication();	// newでCMainApplicationオブジェクトを生成し, CApplicationポインタに格納.

	// メインアプリケーションの初期化
	if (!pApplication->InitInstance(hInstance, lpCmdLine, nShowCmd)) {	// pApplication->InitInstanceで初期化し, 失敗した時.

		// 異常終了
		iRet = pApplication->ExitInstance();	// pApplication->ExitInstanceで終了処理し, 戻り値をiRetに格納.

	}
	else {	// 成功した時.

		// メッセージループと終了処理.
		iRet = pApplication->Run();	// pApplication->Runでメッセージループ処理.(中でExitInstanceも実行される.

	}

	// アプリケーションオブジェクトの破棄
	delete pApplication;	// deleteでpApplicationを破棄.

	// プログラムの終了
	return iRet;	// iRetを返す.

}