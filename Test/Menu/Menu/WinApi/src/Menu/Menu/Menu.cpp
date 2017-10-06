// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI
// 独自のヘッダ
#include "resource.h"	// リソースファイル

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャWindowProc

// _tWinMain関数
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数・配列の宣言・初期化
	HWND hWnd;					// ウィンドウハンドル
	MSG msg;					// メッセージ構造体
	WNDCLASS wc;				// ウィンドウクラス構造体

	// ウィンドウクラス構造体にパラメータを設定.
	wc.lpszClassName = _T("Menu");	// ウィンドウクラス名"Menu"
	wc.style = CS_HREDRAW | CS_VREDRAW;	// スタイルCS_HREDRAW | CS_VREDRAW
	wc.lpfnWndProc = WindowProc;		// ウィンドウプロシージャWindowProc
	wc.hInstance = hInstance;			// アプリケーションインスタンスハンドルhInstance
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアイコンIDI_APPLICATIONをロードし, ハンドルを指定.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでカーソルIDC_ARROWをロードし, ハンドルを指定.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObjectでWHITE_BRUSHを取得し, ハンドルを指定.
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);	// IDR_MAINMENUをMAKEINTRESOURCEで変換してメニューに指定.
	wc.cbClsExtra = 0;	// 0を指定.
	wc.cbWndExtra = 0;	// 0を指定.

	// ウィンドウクラスの登録
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録.

		// ウィンドウクラス登録失敗エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Menu"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"を表示.
		return -1;	// -1を返して異常終了.

	}

	// ウィンドウの作成
	hWnd = CreateWindow(wc.lpszClassName, _T("Menu"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウクラス"Menu"なウィンドウ"Menu"を作成.
	if (hWnd == NULL){	// hWndがNULLならウィンドウ作成失敗.

		// ウィンドウ作成失敗エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("Menu"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"を表示.
		return -2;	// -2を返して異常終了.

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでウィンドウ表示.

	// メッセージループの処理
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージを取得し, msgに格納.(0以下なら, ここを抜ける.)

		// メッセージの変換と送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageでメッセージをウィンドウプロシージャに送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

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

		// メニュー, ボタン, アクセラレータキーなどのコマンドが発生した時.
		case WM_COMMAND:

			// WM_COMMANDブロック
			{

				// どのコマンド(今回はメニュー項目)が選択されたかを判定する.
				switch (LOWORD(wParam)) {	// LOWORD(wParam)で選択されたコマンドのIDが取得できるので, その値で判定する.

					// ID_ITEM1_1が押された時
					case ID_ITEM1_1:

						// ID_ITEM1_1ブロック
						{

							// "Menu Item1-1!"と表示
							MessageBox(NULL, _T("Menu Item1-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item1-1!"と表示.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// ID_ITEM1_2が押された時
					case ID_ITEM1_2:

						// ID_ITEM1_2ブロック
						{
					
							// "Menu Item1-2!"と表示
							MessageBox(NULL, _T("Menu Item1-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item1-2!"と表示.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// ID_ITEM1_3が押された時
					case ID_ITEM1_3:

						// ID_ITEM1_3ブロック
						{

							// "Menu Item1-3!"と表示
							MessageBox(NULL, _T("Menu Item1-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item1-3!"と表示.

						}

						// 抜ける.
						break;	// breakで抜ける.


					// ID_ITEM2_1が押された時
					case ID_ITEM2_1:

						// ID_ITEM2_1ブロック
						{

							// "Menu Item2-1!"と表示
							MessageBox(NULL, _T("Menu Item2-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item2-1!"と表示.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// ID_ITEM2_2が押された時
					case ID_ITEM2_2:

						// ID_ITEM2_2ブロック
						{

							// "Menu Item2-2!"と表示
							MessageBox(NULL, _T("Menu Item2-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item2-2!"と表示.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// ID_ITEM2_3が押された時
					case ID_ITEM2_3:

						// ID_ITEM2_3ブロック
						{

							// "Menu Item2-3!"と表示
							MessageBox(NULL, _T("Menu Item2-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item2-3!"と表示.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// ID_ITEM3_1が押された時
					case ID_ITEM3_1:

						// ID_ITEM3_1ブロック
						{

							// "Menu Item3-1!"と表示
							MessageBox(NULL, _T("Menu Item3-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item3-1!"と表示.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// ID_ITEM3_2が押された時
					case ID_ITEM3_2:

						// ID_ITEM3_2ブロック
						{

							// "Menu Item3-2!"と表示
							MessageBox(NULL, _T("Menu Item3-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item3-2!"と表示.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// ID_ITEM3_3が押された時
					case ID_ITEM3_3:

						// ID_ITEM3_3ブロック
						{

							// "Menu Item3-3!"と表示
							MessageBox(NULL, _T("Menu Item3-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item3-3!"と表示.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// それ以外
					default:

						// 抜ける.
						break;	// breakで抜ける.

				}

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