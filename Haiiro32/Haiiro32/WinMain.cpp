// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// "Hello, Haiiro32!"と表示.
	MessageBox(NULL, _T("Hello, Haiiro32!"), _T("Haiiro32"), MB_OK);	// MessageBoxで"Hello, Haiiro32!"と表示.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}