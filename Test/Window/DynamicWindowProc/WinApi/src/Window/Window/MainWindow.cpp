// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow

// メンバ関数OnCreate
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// メッセージボックスの表示.
	MessageBox(hwnd, _T("MainWindow OnCreate!"), _T("Window"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"MainWindow OnCreate!"と表示.

	// 常にウィンドウ作成成功とする.
	return 0;	// 成功なら0を返す.

}
