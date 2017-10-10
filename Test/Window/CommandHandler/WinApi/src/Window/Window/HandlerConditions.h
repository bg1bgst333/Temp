// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI
// 独自のヘッダ
#include "Window.h"	// CWindow

// 前方宣言.
class CWindow;

// ハンドラの発生条件を格納する構造体
struct HandlerConditions {
	UINT nID;	// リソースID
	UINT nCode;	// 通知コード
	int (CWindow::* h)(LPVOID p);	// ハンドラ
};