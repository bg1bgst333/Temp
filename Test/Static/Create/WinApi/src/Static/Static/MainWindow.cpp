// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() : CMenuWindow() {

	// メンバの初期化
	m_pButton = NULL;	// m_pButtonをNULLで初期化.
	m_pEdit = NULL;	// m_pEditをNULLで初期化.
	m_pStatic = NULL;	// m_pStaticをNULLで初期化.

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

	// メンバの終了処理.
	if (m_pStatic != NULL) {
		delete m_pStatic;	// deleteでm_pStaticを解放.
		m_pStatic = NULL;	// m_pStaticにNULLをセット.
	}
	if (m_pEdit != NULL) {
		delete m_pEdit;	// deleteでm_pEditを解放.
		m_pEdit = NULL;	// m_pEditにNULLをセット.
	}
	if (m_pButton != NULL) {
		delete m_pButton;	// deleteでm_pButtonを解放.
		m_pButton = NULL;	// m_pButtonにNULLをセット.
	}

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

	// ボタンオブジェクトの生成.
	m_pButton = new CButton();	// CButtonオブジェクトを作成し, ポインタをm_pButtonに格納.

	// ボタンの作成.
	m_pButton->Create(_T("Button"), 0, 25, 330, 200, 50, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// m_pButton->Createでボタンを作成.

	// ハンドラの追加.
	AddCommandHandler((WM_APP + 1), BN_CLICKED, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnClickedButton);	// ボタンハンドラOnClickedButtonの追加.

	// エディットコントロールオブジェクトの作成.
	m_pEdit = new CEdit();	// CEditオブジェクトを作成し, ポインタをm_pEditに格納.

	// エディットコントロールの作成.
	m_pEdit->Create(_T(""), WS_BORDER | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL, 25, 25, 400, 300, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// m_pEdit->Createでエディットコントロールを作成.																																			// 常にウィンドウ作成成功とする.

	// スタティックテキストコントロールオブジェクトの作成.
	m_pStatic = new CStatic();	// CStaticオブジェクトを作成し, ポインタをm_pStaticに格納.

	// スタティックテキストコントロールの作成.
	m_pStatic->Create(_T(""), 0, 450, 25, 200, 50, hwnd, (HMENU)(WM_APP + 3), lpCreateStruct->hInstance);	// m_pStatic->Createでスタティックテキストを作成.

	// 常にウィンドウ作成成功とする.
	return 0;	// 成功なら0を返す.

}

// メンバ関数OnDestroy
void CMainWindow::OnDestroy() {

	// ハンドラの削除.
	DeleteCommandHandler(WM_APP + 1, BN_CLICKED);	// DeleteCommandHandlerでWM_APP + 1のハンドラを削除.

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

// メンバ関数OnClickedButton
int CMainWindow::OnClickedButton(WPARAM wParam, LPARAM lParam) {

	// テキストの内容を表示.
	m_pEdit->GetText();	// m_pEdit->GetTextでテキストを取得.
	m_pStatic->SetText(m_pEdit->m_tstrText);	// m_pStatic->SetTextでm_pEdit->m_tstrTextをm_pStaticにセット.

	// 処理したので0を返す.
	return 0;	// 0を返す.

}
