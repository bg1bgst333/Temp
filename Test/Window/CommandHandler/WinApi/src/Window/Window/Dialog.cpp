// ヘッダのインクルード
// 独自のヘッダ
#include "Dialog.h"	// CDialog

// コンストラクタCDialog
CDialog::CDialog(UINT nIDTemplate, CWindow *pParent) {

	// メンバの初期化
	m_nIDTemplate = nIDTemplate;	// m_nIDTemplateにnIDTemplateをセット.
	m_pParent = pParent;	// m_pParentにpParentをセット.

}

// メンバ関数DoModal
INT_PTR CDialog::DoModal() {

	// 変数の宣言
	HINSTANCE hInstance;	// アプリケーションインスタンスハンドル

	// hInstanceを取得
	hInstance = (HINSTANCE)GetWindowLong(m_pParent->m_hWnd, GWL_HINSTANCE);	// GetWindowLongでアプリケーションインスタンスハンドルを取得し, hInstanceに格納.

	// ダイアログの表示.
	return DialogBoxParam(hInstance, MAKEINTRESOURCE(m_nIDTemplate), m_pParent->m_hWnd, (DLGPROC)CWindow::StaticWindowProc, (LPARAM)this);	// DialogBoxParamでダイアログ表示.(thisを渡す)

}

// メンバ関数DynamicWindowProc
LRESULT CDialog::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ウィンドウメッセージ処理
	switch (uMsg) {

		// ウィンドウが閉じられた時.
		case WM_CLOSE:

			// WM_CLOSEブロック
			{

				// OnCloseに任せる.
				return OnClose();

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// ダイアログの初期化時.
		case WM_INITDIALOG:

			// WM_INITDIALOGブロック
			{

				// OnInitDialogに任せる.
				return OnInitDialog(hwnd);

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// コマンドが発生した時.
		case WM_COMMAND:

			// WM_COMMANDブロック
			{

				// OnCommandに任せる.
				return OnCommand(wParam, lParam);	// wParamとlParamを渡して任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// 処理できてないのでFALSE.
	return FALSE;

}

// メンバ関数OnClose
BOOL CDialog::OnClose() {

	// ダイアログの終了.
	EndDialog(m_hWnd, IDCANCEL);	// EndDialogでIDCANCELを指定してダイアログ終了.

	// 自分のウィンドウハンドルが残っていたらマップから削除.
	if (CWindow::m_mapWindowMap.find(m_hWnd) != CWindow::m_mapWindowMap.end()) {	// findで見つかったら.
		CWindow::m_mapWindowMap.erase(m_hWnd);	// CWindow::m_mapWindowMap.eraseで削除.
	}

	// 処理できたのでTRUE.
	return TRUE;

}

// メンバ関数OnInitDialog
BOOL CDialog::OnInitDialog(HWND hwndDlg) {

	// メンバにウィンドウハンドルをセット.
	m_hWnd = hwndDlg;	// m_hWndにhwndDlgをセット.

	// 処理できたのでTRUE.
	return TRUE;

}

// メンバ関数OnCommand.
BOOL CDialog::OnCommand(WPARAM wParam, LPARAM lParam) {

	// 処理できたのでTRUE.
	return TRUE;

}