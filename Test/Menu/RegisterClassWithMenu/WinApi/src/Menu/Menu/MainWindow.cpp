// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow

// メンバ関数RegisterClass(メニューID指定のバージョン.)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// ウィンドウクラス名"CMainWindow"を登録.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), nID);	// CWindow::RegisterClassで"CMainWindow"とnIDを登録し, 戻り値をそのまま返す.

}

// メンバ関数Create
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// CWindow::Createのウィンドウクラス名指定バージョンを使う.
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createのウィンドウクラス名に"CMainWindow"を指定.

}

// メンバ関数OnCreate
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// メッセージボックスの表示.
	MessageBox(hwnd, _T("MainWindow OnCreate!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"MainWindow OnCreate!"と表示.

	// 常にウィンドウ作成成功とする.
	return 0;	// 成功なら0を返す.

}

// メンバ関数OnCommand
BOOL CMainWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	// どのコマンド(今回はメニュー項目)が選択されたかを判定する.
	switch (LOWORD(wParam)) {	// LOWORD(wParam)で選択されたコマンドのIDが取得できるので, その値で判定する.

		// ID_ITEM1_1が押された時
		case ID_ITEM1_1:

			// ID_ITEM1_1ブロック
			{

				// OnItem1_1に任せる.
				OnItem1_1();

			}

			// 抜ける.
			break;	// breakで抜ける.

		// ID_ITEM1_2が押された時
		case ID_ITEM1_2:

			// ID_ITEM1_2ブロック
			{

				// OnItem1_2に任せる.
				OnItem1_2();

			}

			// 抜ける.
			break;	// breakで抜ける.

		// ID_ITEM1_3が押された時
		case ID_ITEM1_3:

			// ID_ITEM1_3ブロック
			{

				// OnItem1_3に任せる.
				OnItem1_3();

			}

			// 抜ける.
			break;	// breakで抜ける.


		// ID_ITEM2_1が押された時
		case ID_ITEM2_1:

			// ID_ITEM2_1ブロック
			{

				// OnItem2_1に任せる.
				OnItem2_1();

			}

			// 抜ける.
			break;	// breakで抜ける.

		// ID_ITEM2_2が押された時
		case ID_ITEM2_2:

			// ID_ITEM2_2ブロック
			{

				// OnItem2_2に任せる.
				OnItem2_2();

			}

			// 抜ける.
			break;	// breakで抜ける.

		// ID_ITEM2_3が押された時
		case ID_ITEM2_3:

			// ID_ITEM2_3ブロック
			{

				// OnItem2_3に任せる.
				OnItem2_3();

			}

			// 抜ける.
			break;	// breakで抜ける.

		// ID_ITEM3_1が押された時
		case ID_ITEM3_1:

			// ID_ITEM3_1ブロック
			{

				// OnItem3_1に任せる.
				OnItem3_1();

			}

			// 抜ける.
			break;	// breakで抜ける.

		// ID_ITEM3_2が押された時
		case ID_ITEM3_2:

			// ID_ITEM3_2ブロック
			{

				// OnItem3_2に任せる.
				OnItem3_2();

			}

			// 抜ける.
			break;	// breakで抜ける.

		// ID_ITEM3_3が押された時
		case ID_ITEM3_3:

			// ID_ITEM3_3ブロック
			{

				// OnItem3_3に任せる.
				OnItem3_3();

			}

			// 抜ける.
			break;	// breakで抜ける.

		// それ以外
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// コマンドを処理したのでTRUE.
	return TRUE;	// TRUEを返す.

}

// メンバ関数OnItem1_1
void CMainWindow::OnItem1_1() {

	// "Menu Item1-1!"と表示
	MessageBox(NULL, _T("Menu Item1-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item1-1!"と表示.

}

// メンバ関数OnItem1_2
void CMainWindow::OnItem1_2() {

	// "Menu Item1-2!"と表示
	MessageBox(NULL, _T("Menu Item1-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item1-2!"と表示.

}

// メンバ関数OnItem1_3
void CMainWindow::OnItem1_3() {

	// "Menu Item1-3!"と表示
	MessageBox(NULL, _T("Menu Item1-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item1-3!"と表示.

}

// メンバ関数OnItem2_1
void CMainWindow::OnItem2_1() {

	// "Menu Item2-1!"と表示
	MessageBox(NULL, _T("Menu Item2-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item2-1!"と表示.

}

// メンバ関数OnItem2_2
void CMainWindow::OnItem2_2() {

	// "Menu Item2-2!"と表示
	MessageBox(NULL, _T("Menu Item2-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item2-2!"と表示.

}

// メンバ関数OnItem2_3
void CMainWindow::OnItem2_3() {

	// "Menu Item2-3!"と表示
	MessageBox(NULL, _T("Menu Item2-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item2-3!"と表示.

}

// メンバ関数OnItem3_1
void CMainWindow::OnItem3_1() {

	// "Menu Item3-1!"と表示
	MessageBox(NULL, _T("Menu Item3-1!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item3-1!"と表示.

}

// メンバ関数OnItem3_2
void CMainWindow::OnItem3_2() {

	// "Menu Item3-2!"と表示
	MessageBox(NULL, _T("Menu Item3-2!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item3-2!"と表示.

}

// メンバ関数OnItem3_3
void CMainWindow::OnItem3_3() {

	// "Menu Item3-3!"と表示
	MessageBox(NULL, _T("Menu Item3-3!"), _T("Menu"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"Menu Item3-3!"と表示.

}