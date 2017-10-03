// ヘッダのインクルード
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// "Hello, world!"の表示
	MessageBox(NULL, _T("Hello, world!"), _T("HelloWorld"), MB_OK);	// MessageBoxで"Hello, world!"を表示.
															
	// プログラムの終了
	return 0;	// 0を返して正常終了.

}