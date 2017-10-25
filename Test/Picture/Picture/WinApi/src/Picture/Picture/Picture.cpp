// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI
// 独自のヘッダ
#include "resource.h"	// リソースファイル

// 関数のプロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャWindowProc
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ダイアログプロシージャ関数DialogProc.

// _tWinMain関数
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数・配列の宣言・初期化
	HWND hWnd;					// ウィンドウハンドル
	MSG msg;					// メッセージ構造体
	WNDCLASS wc;				// ウィンドウクラス構造体

	// ウィンドウクラス構造体にパラメータを設定.
	wc.lpszClassName = _T("Picture");	// ウィンドウクラス名"Picture"
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
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Picture"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"を表示.
		return -1;	// -1を返して異常終了.

	}

	// ウィンドウの作成
	hWnd = CreateWindow(wc.lpszClassName, _T("Picture"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウクラス"Picture"なウィンドウ"Picture"を作成.
	if (hWnd == NULL){	// hWndがNULLならウィンドウ作成失敗.

		// ウィンドウ作成失敗エラー処理
		MessageBox(NULL, _T("CreateWindow failed!"), _T("Picture"), MB_OK | MB_ICONHAND);	// MessageBoxで"CreateWindow failed!"を表示.
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

					// ID_MENU_DIALOGが押された時
					case ID_MENU_DIALOG:

						// ID_MENU_DIALOGブロック
						{

							// 変数の宣言
							HINSTANCE hInstance;	// アプリケーションインスタンスハンドル

							// hInstanceを取得
							hInstance = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);	// GetWindowLongでアプリケーションインスタンスハンドルを取得し, hInstanceに格納.

							// ダイアログボックスの表示
							DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG), hwnd, DialogProc);	// DialogBoxでダイアログボックスを表示.(ダイアログの処理はDialogProcに書いてある.)

							// 処理したので0.																		// 0を返す.
							return 0;	// 処理したので戻り値として0を返す.

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

// ダイアログプロシージャDialogProc.
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ダイアログのメッセージ処理
	switch (uMsg) {	// uMsgの内容で判断.

		// ダイアログの初期化時.
		case WM_INITDIALOG:

			// WM_INITDIALOGブロック
			{

				// TRUEを返す.
				return TRUE;	// 処理できたのでTRUE.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// ボタン, アクセラレータキーなどのコマンドが発生した時.
		case WM_COMMAND:

			// WM_COMMANDブロック
			{

				// どのコマンド(今回はボタン)が選択されたかを判定する.
				switch (LOWORD(wParam)) {	// LOWORD(wParam)で選択されたコマンドのIDが取得できるので, その値で判定する.

					// IDC_BUTTON1が押された時
					case IDC_BUTTON1:

						// IDC_BUTTON1ブロック
						{

#if 1
							// 変数・ポインタの宣言
							HWND hEdit;				// エディットコントロールのウィンドウハンドルhEdit.
							int iLen;				// テキストの長さiLen.
							TCHAR *ptszText;		// テキストへのポインタptszText.
							HINSTANCE hInstance;	// アプリケーションインスタンスハンドルhInstance.
							HBITMAP hBitmap;		// ビットマップハンドルhBitmap.
							HWND hPicture;			// ピクチャーコントロールのウィンドウハンドルhPicture.

							// エディットコントロールIDC_EDIT1のテキストを取得.
							hEdit = GetDlgItem(hwndDlg, IDC_EDIT1);	// GetDlgItemでIDC_EDIT1のウィンドウハンドルを取得.
							iLen = GetWindowTextLength(hEdit);	// GetWindowTextLengthでテキストの長さを取得.
							ptszText = new TCHAR[iLen + 1];	// newでTCHAR動的配列を生成し, ポインタをptszTextに格納.
							GetWindowText(hEdit, ptszText, iLen + 1);	// GetWindowTextでテキストを取得.
							
							// 画像のロード.
							hPicture = GetDlgItem(hwndDlg, IDC_PICTURE1);	// GetDlgItemでIDC_PICTURE1のウィンドウハンドルを取得.
							hInstance = (HINSTANCE)GetWindowLong(hwndDlg, GWLP_HINSTANCE);	// GetWindowLongでインスタンスハンドルを取得.
							hBitmap = (HBITMAP)LoadImage(hInstance, ptszText, IMAGE_BITMAP, 320, 240, LR_LOADFROMFILE);	// LoadImageでビットマップをロード.
							if (hBitmap != NULL) {	// NULLでないなら.

								// 画像の表示.
								SendMessage(hPicture, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);	// SendMessageでSTM_SETIMAGEを送信することで画像を表示.
								DeleteObject(hBitmap);	// DeleteObjectでhBitmapを破棄.

							}

							// 破棄処理.
							delete[] ptszText;	// ptszTextを破棄.

#else
							// 変数・ポインタの宣言
							HWND hEdit;			// エディットコントロールのウィンドウハンドルhEdit.
							int iLen;			// テキストの長さiLen.
							TCHAR *ptszText;	// テキストへのポインタptszText.
							HWND hStatic;		// スタティックコントロールのウィンドウハンドルhStatic.

							// エディットコントロールIDC_EDIT1のテキストを取得し, スタティックテキストIDC_STATIC1にセット.
							hEdit = GetDlgItem(hwndDlg, IDC_EDIT1);	// GetDlgItemでIDC_EDIT1のウィンドウハンドルを取得.
							iLen = GetWindowTextLength(hEdit);	// GetWindowTextLengthでテキストの長さを取得.
							ptszText = new TCHAR[iLen + 1];	// newでTCHAR動的配列を生成し, ポインタをptszTextに格納.
							GetWindowText(hEdit, ptszText, iLen + 1);	// GetWindowTextでテキストを取得.
							hStatic = GetDlgItem(hwndDlg, IDC_STATIC1);	// GetDlgItemでIDC_STATIC1のウィンドウハンドルを取得.
							SetWindowText(hStatic, ptszText);	// SetWindowTextでhStaticにptszTextを反映.
							delete[] ptszText;	// ptszTextを破棄.
#endif

							// TRUEを返す.
							return TRUE;	// 処理できたのでTRUE.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// IDOKが押された時.
					case IDOK:

						// IDOKブロック
						{

							// ダイアログを終了する.
							EndDialog(hwndDlg, IDOK);	// EndDialogでダイアログを終了する.

							// TRUEを返す.
							return TRUE;	// 処理できたのでTRUE.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// IDCANCELが押された時.
					case IDCANCEL:

						// IDCANCELブロック
						{

							// ダイアログを終了する.
							EndDialog(hwndDlg, IDCANCEL);	// EndDialogでダイアログを終了する.

							// TRUEを返す.
							return TRUE;	// 処理できたのでTRUE.

						}

						// 抜ける.
						break;	// breakで抜ける.

					// それ以外.
					default:

						// 抜ける.
						break;	// breakで抜ける.

				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// ダイアログが閉じられた時.
		case WM_CLOSE:	// ダイアログが閉じられた時.(uMsgがWM_CLOSEの時.)

			// WM_CLOSEブロック
			{

				// ダイアログを終了する.
				EndDialog(hwndDlg, IDCANCEL);	// EndDialogでダイアログを終了する.

				// TRUEを返す.
				return TRUE;	// 処理できたのでTRUE.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// それ以外.
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// ここに来るときは処理できていない.
	return FALSE;	// 処理できていないのでFALSE.

}