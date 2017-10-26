// ヘッダのインクルード
// 独自のヘッダ
#include "Application.h"	// CApplication

// コンストラクタCApplication
CApplication::CApplication(){

	// メンバの初期化
	m_pMainWindow = NULL;	// m_pMainWindowをNULLで初期化.

}

// メンバ関数Run
int CApplication::Run(){

	// 構造体の宣言
	MSG msg;	// メッセージ構造体

	// メッセージループの処理
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得し, msgに格納.(0以下なら, ここを抜ける.)

		// メッセージの変換と送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageでメッセージをウィンドウプロシージャに送出.

	}

	// 終了処理
	return ExitInstance();	// ExitInstanceの値を返す.

}

// メンバ関数ExitIntance
int CApplication::ExitInstance(){

	// ハンドラマップの破棄.
	std::map<DWORD, HandlerConditions *>::iterator itor = CWindow::m_mapHandlerMap.begin();	// ハンドラマップのイテレータを取得.
	while (itor != CWindow::m_mapHandlerMap.end()) {	// ハンドラマップの終端まで繰り返す.
		delete itor->second;	// itor->secondがHandlerConditionsオブジェクトポインタなので, deleteでこれを破棄.
		itor++;	// イテレータを進める.
	}

	// メインウィンドウの破棄.
	if (m_pMainWindow != NULL) {	// m_pMainWindowがNULLでない時.

		// 破棄する.
		delete m_pMainWindow;	// deleteでm_pMainWindowを破棄.
		m_pMainWindow = NULL;	// m_pMainWindowにNULLをセット.

	}

	// 正常終了
	return 0;	// 0を返して正常終了.

}