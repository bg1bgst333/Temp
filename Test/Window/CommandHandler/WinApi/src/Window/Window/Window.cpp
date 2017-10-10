// ヘッダのインクルード
// 既定のヘッダ
#include <cstring>	// C文字列処理
// 独自のヘッダ
#include "Window.h"	// CWindow

// staticメンバ変数の定義.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// ウィンドウマップ
std::map<UINT, HandlerConditions*> CWindow::m_mapHandlerMap;	// ハンドラマップ

// コンストラクタCWindow
CWindow::CWindow(){

	// メンバの初期化
	m_hWnd = NULL;	// m_hWndをNULLで初期化.

}

// デストラクタ~CWindow
CWindow::~CWindow(){

	// メンバの終了処理
	if (m_hWnd != NULL) {	// m_hWndがNULLでない時.

		// ウィンドウの破棄.
		DestroyWindow(m_hWnd);	// DestroyWindowでm_hWndを破棄.
		m_hWnd = NULL;	// NULLをセット.

	}

}

// staticメンバ関数RegisterClass(引数がhInstanceだけのバージョン.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance){

	// 構造体の宣言
	WNDCLASS wc;	// ウィンドウクラス構造体

	// ウィンドウクラス構造体にパラメータを設定.
	wc.lpszClassName = _T("CWindow");	// ウィンドウクラス名に"CWindow"をセット.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// スタイルCS_HREDRAW | CS_VREDRAW
	wc.lpfnWndProc = StaticWindowProc;		// ウィンドウプロシージャStaticWindowProc
	wc.hInstance = hInstance;			// アプリケーションインスタンスハンドルhInstance
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアイコンIDI_APPLICATIONをロードし, ハンドルを指定.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでカーソルIDC_ARROWをロードし, ハンドルを指定.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObjectでWHITE_BRUSHを取得し, ハンドルを指定.
	wc.lpszMenuName = NULL;	// メニューはNULL(なし).
	wc.cbClsExtra = 0;	// 0を指定.
	wc.cbWndExtra = 0;	// 0を指定.

	// ウィンドウクラスの登録
	if (!::RegisterClass(&wc)) {	// WindowsAPIのRegisterClassでウィンドウクラスを登録.

		// ウィンドウクラス登録失敗エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Edit"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"を表示.
		return FALSE;	// FALSEを返して異常終了.

	}

	// 成功ならTRUE.
	return TRUE;	// 成功なのでTRUEを返す.

}

// staticメンバ関数RegisterClass(ウィンドウクラス名指定のバージョン)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName) {

	// 構造体の宣言
	WNDCLASS wc;	// ウィンドウクラス構造体

	// ウィンドウクラス構造体にパラメータを設定.
	wc.lpszClassName = lpctszClassName;	// ウィンドウクラス名にlpszClassNameをセット.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// スタイルCS_HREDRAW | CS_VREDRAW
	wc.lpfnWndProc = StaticWindowProc;		// ウィンドウプロシージャStaticWindowProc
	wc.hInstance = hInstance;			// アプリケーションインスタンスハンドルhInstance
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアイコンIDI_APPLICATIONをロードし, ハンドルを指定.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでカーソルIDC_ARROWをロードし, ハンドルを指定.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObjectでWHITE_BRUSHを取得し, ハンドルを指定.
	wc.lpszMenuName = NULL;	// メニューはNULL(なし).
	wc.cbClsExtra = 0;	// 0を指定.
	wc.cbWndExtra = 0;	// 0を指定.

	// ウィンドウクラスの登録
	if (!::RegisterClass(&wc)) {	// WindowsAPIのRegisterClassでウィンドウクラスを登録.

		// ウィンドウクラス登録失敗エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Edit"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"を表示.
		return FALSE;	// FALSEを返して異常終了.

	}

	// 成功ならTRUE.
	return TRUE;	// 成功なのでTRUEを返す.

}

// staticメンバ関数RegisterClass(ウィンドウクラス名, メニューID指定のバージョン.)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID) {

	// 構造体の宣言
	WNDCLASS wc;	// ウィンドウクラス構造体

	// ウィンドウクラス構造体にパラメータを設定.
	wc.lpszClassName = lpctszClassName;	// ウィンドウクラス名にlpszClassNameをセット.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// スタイルCS_HREDRAW | CS_VREDRAW
	wc.lpfnWndProc = StaticWindowProc;		// ウィンドウプロシージャStaticWindowProc
	wc.hInstance = hInstance;			// アプリケーションインスタンスハンドルhInstance
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアイコンIDI_APPLICATIONをロードし, ハンドルを指定.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでカーソルIDC_ARROWをロードし, ハンドルを指定.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObjectでWHITE_BRUSHを取得し, ハンドルを指定.
	wc.lpszMenuName = MAKEINTRESOURCE(nID);	// nIDををMAKEINTRESOURCEで変換してメニューに指定.
	wc.cbClsExtra = 0;	// 0を指定.
	wc.cbWndExtra = 0;	// 0を指定.

	// ウィンドウクラスの登録
	if (!::RegisterClass(&wc)) {	// WindowsAPIのRegisterClassでウィンドウクラスを登録.

		// ウィンドウクラス登録失敗エラー処理
		MessageBox(NULL, _T("RegisterClass failed!"), _T("Edit"), MB_OK | MB_ICONHAND);	// MessageBoxで"RegisterClass failed!"を表示.
		return FALSE;	// FALSEを返して異常終了.

	}

	// 成功ならTRUE.
	return TRUE;	// 成功なのでTRUEを返す

}

// ウィンドウプロシージャStaticWindowProc
LRESULT CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ポインタの初期化
	CWindow *pWindow = NULL;	// CWindowオブジェクトポインタpWIndowをNULLに初期化.

	// ウィンドウメッセージ処理
	switch (uMsg) {

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ポインタの初期化
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT構造体へのポインタlpCreateStructをNULL.
				// lParamからlpCreateStructを取り出す.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCT型にキャストしてlpCreateStructに格納.
				if (lpCreateStruct != NULL) {	// lpCreateStructがNULLでなければ.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParamsはCWindow *型にキャストし, pWindowに格納.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// CWindow::m_mapWindowMapにhwndとpWindowのペアを登録.
				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// ダイアログの作成が開始された時.
		case WM_INITDIALOG:

			// WM_INITDIALOGブロック
			{

				// lParamを取り出す.
				if (lParam != NULL) {	// lParamがNULLでなければ.
					pWindow = (CWindow *)lParam;	// lParamはCWindow *型にキャストし, pWindowに格納.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// CWindow::m_mapWindowMapにhwndとpWindowのペアを登録.
				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外の時.
		default:

			// defaultブロック
			{

				// hwndでCWindowオブジェクトポインタが引けたら, pWindowに格納.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()) {	// findでキーをhwndとするCWindowオブジェクトポインタが見つかったら.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindowにhwndで引けるCWindowオブジェクトポインタを格納.
				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// CWindowオブジェクトポインタが取得できなかった場合, 取得できた場合で分ける.
	if (pWindow == NULL) {	// pWindowがNULL

		// DefWindowProcに任せる.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcにそのまま引数を渡して, その値を戻り値とする.

	}
	else {	// pWindowがNULLでない.

		// そのCWindowオブジェクトのDynamicWindowProcに渡す.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProcにそのまま引数を渡して, その値を戻り値とする.

	}

}

// メンバ関数Create
BOOL CWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウの作成
	m_hWnd = CreateWindow(_T("CWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindowでウィンドウを作成し, ハンドルをm_hWndに格納.(ウィンドウクラス名は"CWindow".最後の引数にthis(自身のポインタ)を渡す.)
	if (m_hWnd == NULL) {	// m_hWndがNULLなら失敗.

		// 失敗ならFALSE.
		return FALSE;	// FALSEを返す.

	}

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// メンバ関数Create(ウィンドウクラス名指定バージョン.)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindowでウィンドウを作成し, ハンドルをm_hWndに格納.(最後の引数にthis(自身のポインタ)を渡す.)
	if (m_hWnd == NULL) {	// m_hWndがNULLなら失敗.

							// 失敗ならFALSE.
		return FALSE;	// FALSEを返す.

	}

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// メンバ関数ShowWindow
BOOL CWindow::ShowWindow(int nCmdShow){

	// ウィンドウの表示
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPIのShowWindowでm_hWndを表示.

}

// メンバ関数AddCommandHandler
void CWindow::AddCommandHandler(UINT nID, UINT nCode, int(CWindow::*handler)(LPVOID p)) {

	// HandlerConditionsの生成.
	HandlerConditions *pCond = new HandlerConditions();
	pCond->nID = nID;
	pCond->nCode = nCode;
	pCond->h = handler;
	CWindow::m_mapHandlerMap.insert(std::pair<UINT, HandlerConditions*>(pCond->nID, pCond));

}

// メンバ関数DynamicWindowProc
LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ウィンドウメッセージ処理
	switch (uMsg) {

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// OnCreateに任せる.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwndとlParamをOnCreateに渡し, あとは任せる.

			}
			
			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// OnDestroyに任せる.
				OnDestroy();	// OnDestroyを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// ウィンドウが閉じられた時.
		case WM_CLOSE:

			// WM_CLOSEブロック
			{

				// 処理できていないなら, とじない.
				if (!OnClose()) {	// FALSEなら.
					return 0;	// 0を返す.
				}

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
				return OnCommand(wParam, lParam) ? 0 : 1;	// wParamとlParamを渡して任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// DefWindowProcに任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcにそのまま引数を渡して, その値を戻り値とする.

}

// メンバ関数OnCreate
int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 常にウィンドウ作成成功とする.
	return 0;	// 成功なら0を返す.

}

// メンバ関数OnDestroy
void CWindow::OnDestroy() {

	// メッセージループ終了.
	PostQuitMessage(0);	// PostQuitMessageでメッセージループを抜けさせる.

}

// メンバ関数OnClose
BOOL CWindow::OnClose() {

	// 処理できたのでTRUE.
	return TRUE;

}

// メンバ関数OnInitDialog
BOOL CWindow::OnInitDialog(HWND hwndDlg) {

	// 処理できたのでTRUE.
	return TRUE;

}

// メンバ関数OnCommand
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	// LOWORD(wParam)でマップからハンドラ情報を引き出す.
	HandlerConditions *pCond = CWindow::m_mapHandlerMap[LOWORD(wParam)];
	if (pCond != NULL) {
		if (pCond->nCode == HIWORD(wParam)) {
			int ret = (this->*pCond->h)(this);	// ハンドラを呼び出す.
			if (ret == 0) {	// 0なら処理をした.
				return TRUE;
			}
		}
	}

	// コマンドを処理していないのでFALSE.
	return FALSE;	// FALSEを返す.

}

// メンバ関数handler
//int CWindow::handler(LPVOID p) {

//	return 1;

//}
