// ヘッダのインクルード
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI

// 関数のプロトタイプ宣言
BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// 初期化関数InitInstance
int Run();	// メッセージループ処理関数Run
int ExitInstance();	// 終了処理関数ExitInstance
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャWindowProc

// _tWinMain関数
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	BOOL bRet;	// 初期化が成功したかを表す.

	// アプリケーションの初期化
	bRet = InitInstance(hInstance, lpCmdLine, nShowCmd);	// InitInstanceで初期化.
	if (!bRet) {	// bRetがFALSEの時.

		// 異常終了
		return ExitInstance();	// ExitInstanceの値を返す.

	}

	// メッセージループと終了処理.
	return Run();	// Runでメッセージループ処理を行い, 戻り値をそのまま返す.

}

// 初期化関数InitInstance
BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数・構造体の宣言
	HWND hWnd;					// ウィンドウハンドル
	WNDCLASS wc;				// ウィンドウクラス構造体

	// ウィンドウクラス構造体にパラメータを設定.
	wc.lpszClassName = _T("Application");	// ウィンドウクラス名"Application"
	wc.style = CS_HREDRAW | CS_VREDRAW;	// スタイルCS_HREDRAW | CS_VREDRAW
	wc.lpfnWndProc = WindowProc;		// ウィンドウプロシージャWindowProc
	wc.hInstance = hInstance;			// アプリケーションインスタンスハンドルhInstance
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアイコンIDI_APPLICATIONをロードし, ハンドルを指定.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでカーソルIDC_ARROWをロードし, ハンドルを指定.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObjectでWHITE_BRUSHを取得し, ハンドルを指定.
	wc.lpszMenuName = NULL;	// メニューはNULL(なし).
	wc.cbClsExtra = 0;	// 0を指定.
	wc.cbWndExtra = 0;	// 0を指定.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録.

		// ウィンドウクラス登録失敗エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Application"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"を表示.
		return FALSE;	// FALSEを返して異常終了.

	}

	// ウィンドウの作成
	hWnd = CreateWindow(wc.lpszClassName, _T("Application"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウクラス"Application"なウィンドウ"Application"を作成.
	if (hWnd == NULL) {	// hWndがNULLならウィンドウ作成失敗.

						// ウィンドウ作成失敗エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("Application"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"を表示.
		return FALSE;	// -2を返して異常終了.

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでウィンドウ表示.

	// 初期化成功
	return TRUE;	// TRUEを返して正常終了.

}

// メッセージループ処理関数Run
int Run() {

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

// 終了処理関数ExitInstance
int ExitInstance() {

	// 今回は常に成功時の0を返す.
	return 0;	// 0を返して正常終了.

}

// ウィンドウプロシージャWindowProc
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ウィンドウメッセージの処理
	switch (uMsg) {	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ウィンドウ作成成功
				return 0;	// 0を返すと, ウィンドウ作成成功ということになる.	

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// 終了メッセージの送信
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:	// 上記以外の値の時の既定処理.

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めDefWindowProcに既定の処理を任せる.

}