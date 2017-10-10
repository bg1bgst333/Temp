// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow
#include "MainDialog.h"	// CMainDialog
#include "resource.h"			// リソースファイル

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() : CWindow() {

	// メンバの初期化
	m_pMenuBar = NULL;	// m_pMenuBarをNULLで初期化.

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

	// メンバの終了処理.
	if (m_pMenuBar != NULL) {	// m_pMenuBarがNULLでなければ.
		delete m_pMenuBar;	// deleteでm_pMenuBarを解放.
		m_pMenuBar = NULL;	// m_pMenuBarをNULLで埋める.
	}

}

// メンバ関数RegisterClass(メニュー無しバージョン.)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラス名"CMainWindow"を登録.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"));	// // CWindow::RegisterClassで"CMainWindow"を登録し, 戻り値をそのまま返す.

}

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

	// メニューバーの作成.(動的に作成する場合.)
	m_pMenuBar = new CMenuBar();	// CMenuBarオブジェクトを作成し, ポインタをm_pMenuBarに格納.

	// メニューのロード.
	m_pMenuBar->LoadMenu(lpCreateStruct->hInstance, IDR_MAINMENU);	// LoadMenuでID_MAINMENUをロード.

	// メニューのセット.
	m_pMenuBar->SetMenu(hwnd);	// SetMenuでhwndにメニューをセット.

	// ハンドラの追加.
	//int(CWindow::*fp)(LPVOID) = (int(CWindow::*)(LPVOID))&CMainWindow::handler2;
	AddCommandHandler(ID_MENU_DIALOG, 0, (int(CWindow::*)(LPVOID))&CMainWindow::handler2/*OnMenuDialog*/);	// メニューハンドラの追加.

	// 常にウィンドウ作成成功とする.
	return 0;	// 成功なら0を返す.

}

// メンバ関数OnDestroy
void CMainWindow::OnDestroy() {

	// 自分のウィンドウハンドルが残っていたらマップから削除.
	if (CWindow::m_mapWindowMap.find(m_hWnd) != CWindow::m_mapWindowMap.end()) {	// findで見つかったら.
		CWindow::m_mapWindowMap.erase(m_hWnd);	// CWindow::m_mapWindowMap.eraseで削除.
	}

	// メッセージループ終了.
	PostQuitMessage(0);	// PostQuitMessageでメッセージループを抜けさせる.

}

// メンバ関数handler
int CMainWindow::handler2(LPVOID p) {

	// メッセージボックスの表示.
	MessageBox(m_hWnd, _T("handler!"), _T("Window"), MB_OK | MB_ICONASTERISK);	// "handler!"と表示.

	// 処理したので0
	return 0;

}