// ヘッダのインクルード
// 独自のヘッダ
#include "Application.h"	// CApplication

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

	// 今回は常に成功時の0を返す.
	return 0;	// 0を返して正常終了.

}