// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// staticメンバ変数の定義.
std::map<tstring, WNDPROC> CCustomControl::m_mapBaseWindowProcMap;	// ベースウィンドウプロシージャマップ

// コンストラクタCCustomControl
CCustomControl::CCustomControl() : CWindow() {

}

// ウィンドウプロシージャStaticWindowProc
LRESULT CCustomControl::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ポインタの宣言
	CWindow *pWindow = NULL;	// CWindowオブジェクトポインタpWindow.

	// hwndでウィンドウオブジェクトポインタが引けたら, pWindowに格納.
	if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()) {	// findで見つかったら.
		pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindowにhwndで引けるCWindowオブジェクトポインタを代入.
	}

	// ウィンドウオブジェクト取得できない場合.
	if (pWindow == NULL) {	// pWindowがNULL.

		// 配列の宣言.
		TCHAR tszClassName[256] = { 0 };	// tszClassNameを0で初期化.

		// ウィンドウハンドルからウィンドウクラス名を取得.
		GetClassName(hwnd, tszClassName, 256);	// GetClassNameでウィンドウクラス名を取得.

		// tszClassNameがm_mapBaseWindowProcMapのキーにあれば.
		if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()) {	// みつかったら.

			// 既定のプロシージャに任せる.
			return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProcでこのメッセージをm_mapBaseWindowProcMap[tszClassName]に任せる.

		}
		else {

			// そうでないなら, DefWindowProcに任せる.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);

		}

	}
	else {	// pWindowがあった.

		// そのウィンドウのDynamicWindowProcに渡す.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProcに渡す.

	}

}

// メンバ関数Create(ウィンドウクラス名指定バージョン.)
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの位置・サイズをセット.
	m_x = x;				// m_xにxを代入.
	m_y = y;				// m_yにyを代入.
	m_iWidth = iWidth;		// m_iWidthにiWidthを代入.
	m_iHeight = iHeight;	// m_iHeight = iHeightを代入.

	// ウィンドウの作成
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindowでウィンドウを作成し, ハンドルをm_hWndに格納.(最後の引数にthis(自身のポインタ)を渡す.)
	if (m_hWnd == NULL) {	// m_hWndがNULLなら失敗.

		// 失敗ならFALSE.
		return FALSE;	// FALSEを返す.

	}

	// OnCreateは以降呼ばれないのでここで呼んでおく.
	CREATESTRUCT cs;	// CREATESTRUCTを一応用意.
	cs.hInstance = hInstance;	// hInstanceは要るかもしれないので, これは渡せるようにしておく.
	if (OnCreate(m_hWnd, &cs) != 0) {	// OnCreateにcsを渡す.

		// ウィンドウを破棄する.
		DestroyWindow(m_hWnd);
		m_hWnd = NULL;
		return FALSE;

	}

	// 既定のウィンドウプロシージャを取得し, CCustomControl::StaticWindowProcに差し替える.
	WNDPROC lpfnWndProc;	// 既定のプロシージャlpfnWndProc.
	lpfnWndProc = (WNDPROC)GetWindowLong(m_hWnd, GWL_WNDPROC);	// GetWindowLongでプロシージャlpfnWndProcを取得.
	SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)StaticWindowProc);	// SetWindowLongでプロシージャCCustomControl::StaticWindowProcを設定.

	// マップにウィンドウクラス名がなければ登録.
	if (CCustomControl::m_mapBaseWindowProcMap.find(lpctszClassName) == CCustomControl::m_mapBaseWindowProcMap.end()) {
		CCustomControl::m_mapBaseWindowProcMap.insert(std::pair<tstring, WNDPROC>(lpctszClassName, lpfnWndProc));	// プロシージャを登録.
	}

	// WM_CREATEを通らないのでウィンドウマップの登録も行う.
	if (CWindow::m_mapWindowMap.find(m_hWnd) == CWindow::m_mapWindowMap.end()) {	// ウィンドウマップになければ.
		CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(m_hWnd, this));	// 登録する.
	}

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// メンバ関数DynamicWindowProc
LRESULT CCustomControl::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

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

		// ウィンドウの描画を要求された時.
		case WM_PAINT:

			// WM_PAINTブロック
			{

				// OnPaintに任せる.
				OnPaint();	// OnPaintを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// これらのメッセージはDefWindowProcに投げないと, スクロールバーが認識せず動作しない.
		case WM_NCHITTEST:
		case WM_NCLBUTTONDOWN:
		case WM_NCLBUTTONUP:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);

		// 文字キーが押された時.
		case WM_CHAR:

			// WM_CHARブロック
			{

				// OnCharに任せる.
				if (OnChar(wParam, LOWORD(lParam), HIWORD(lParam)) == -1) {	// -1の時は入力をキャンセル.

					// 入力キャンセル.
					return 0;	// 0をここで返すと入力キャンセルとなる.

				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// 水平方向スクロールバーイベント時.
		case WM_HSCROLL:

			// WM_HSCROLLブロック
			{

				// OnHScrollに任せる.
				OnHScroll(LOWORD(wParam), HIWORD(wParam));	// OnHScrollに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// 垂直方向スクロールバーイベント時.
		case WM_VSCROLL:

			// WM_VSCROLLブロック
			{

				// OnVScrollに任せる.
				OnVScroll(LOWORD(wParam), HIWORD(wParam));	// OnVScrollに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// マウスの左クリックが行われた時.
		case WM_LBUTTONDOWN:

			// WM_LBUTTONDOWNブロック
			{

				// 変数の宣言
				POINT pt;	// POINT構造体変数pt.

				// 座標の取り出し.
				pt.x = LOWORD(lParam);	// lParamの下位ワードが座標x.
				pt.y = HIWORD(lParam);	// lParamの上位ワードが座標y.

				// OnLButtonDownに任せる.
				if (OnLButtonDown(wParam, pt) == -1) {	// -1の時は入力をキャンセル.

					// 入力キャンセル.
					return 0;	// 0をここで返すと入力キャンセルとなる.

				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// 配列の宣言.
	TCHAR tszClassName[256] = { 0 };	// tszClassNameを0で初期化.

	// ウィンドウハンドルからウィンドウクラス名を取得.
	GetClassName(hwnd, tszClassName, 256);	// GetClassNameでウィンドウクラス名を取得.

	// tszClassNameがm_mapBaseWindowProcMapのキーにあれば.
	if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()) {	// みつかったら.

		// 既定のプロシージャに任せる.
		return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProcでこのメッセージをm_mapBaseWindowProcMap[tszClassName]に任せる.

	}
	else {

		// そうでないなら, DefWindowProcに任せる.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}

}

// メンバ関数OnDestroy
void CCustomControl::OnDestroy() {

}

// メンバ関数OnPaint
void CCustomControl::OnPaint() {

}

// メンバ関数OnHScroll
void CCustomControl::OnHScroll(UINT nSBCode, UINT nPos) {

}

// メンバ関数OnVScroll
void CCustomControl::OnVScroll(UINT nSBCode, UINT nPos) {

}

// メンバ関数OnLButtonDown
int CCustomControl::OnLButtonDown(UINT nFlags, POINT pt) {

	// キャンセルではないので0を返す.
	return 0;	// 0を返す.

}
