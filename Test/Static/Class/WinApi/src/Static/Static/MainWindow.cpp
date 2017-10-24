// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow
#include "MainDialog.h"	// CMainDialog
#include "resource.h"	// リソースファイル

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() : CMenuWindow() {

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

}

// メンバ関数RegisterClass(メニュー無しバージョン.)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラス名"CMainWindow"を登録.
	return CMenuWindow::RegisterClass(hInstance, _T("CMainWindow"));	// CMenuWindow::RegisterClassで"CMainWindow"を登録し, 戻り値をそのまま返す.

}

// メンバ関数RegisterClass(メニューID指定のバージョン.)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// ウィンドウクラス名"CMainWindow"を登録.
	return CMenuWindow::RegisterClass(hInstance, _T("CMainWindow"), nID);	// CMenuWindow::RegisterClassで"CMainWindow"とnIDを登録し, 戻り値をそのまま返す.

}

// メンバ関数Create
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// CMenuWindow::Createのウィンドウクラス名指定バージョンを使う.
	return CMenuWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CMenuWindow::Createのウィンドウクラス名に"CMainWindow"を指定.

}

// メンバ関数OnCreate
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// メニューバーの作成.(動的に作成する場合.)
	m_pMenuBar = new CMenuBar();	// CMenuBarオブジェクトを作成し, ポインタをm_pMenuBarに格納.

	// メニューのロード.
	m_pMenuBar->LoadMenu(lpCreateStruct->hInstance, IDR_MAINMENU);	// LoadMenuでID_MAINMENUをロード.

	// メニューのセット.
	m_pMenuBar->SetMenu(hwnd);	// SetMenuでhwndにメニューをセット.

	// メニューハンドラを追加.
	AddCommandHandler(ID_MENU_DIALOG, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnMenuDialog);	// AddCommandHandlerでOnMenuDialogを追加.

	// 常にウィンドウ作成成功とする.
	return 0;	// 成功なら0を返す.

}

// メンバ関数OnDestroy
void CMainWindow::OnDestroy() {

	// メニューハンドラの削除.
	DeleteCommandHandler(ID_MENU_DIALOG, 0);	// DeleteCommandHandlerで(ID_MENU_DIALOG, 0)のハンドラを削除.

	// 自分のウィンドウハンドルが残っていたらマップから削除.
	if (CWindow::m_mapWindowMap.find(m_hWnd) != CWindow::m_mapWindowMap.end()) {	// findで見つかったら.
		CWindow::m_mapWindowMap.erase(m_hWnd);	// CWindow::m_mapWindowMap.eraseで削除.
	}

	// メッセージループ終了.
	PostQuitMessage(0);	// PostQuitMessageでメッセージループを抜けさせる.

}

// メンバ関数OnSize
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

}

// メンバ関数OnMenuDialog
int CMainWindow::OnMenuDialog(WPARAM wParam, LPARAM lParam) {

	// オブジェクトの生成.
	CMainDialog dlg(IDD_DIALOG, CWindow::m_mapWindowMap[m_hWnd]);	// コンストラクタにリソースIDとメニューバーのオーナーウィンドウオブジェクトポインタ(ウィンドウマップで探す.)を指定.

	// ダイアログの表示.
	dlg.DoModal();	// dlg.DoModalでダイアログを表示.

	// 処理したので0を返す.
	return 0;	// 0を返す.

}
