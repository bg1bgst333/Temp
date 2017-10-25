// 独自のヘッダ
#include "Button.h"	// CButton

// コンストラクタCButton
CButton::CButton() : CCustomControl() {

}

// コンストラクタCButton(HWND hParent, UINT nID)
CButton::CButton(HWND hParent, UINT nID) {

	// ボタンのロード.
	Load(hParent, nID);	// LoadでnIDのボタンをロード.

}

// メンバ関数Load
HWND CButton::Load(HWND hParent, UINT nID) {

	// リソースIDのボタンのウィンドウハンドルを取得.
	m_nID = nID;	// メンバにセット.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItemでm_nIDのボタンウィンドウハンドルを取得し, m_hWndに格納.
	return m_hWnd;	// m_hWndを返す.

}

// メンバ関数Create
BOOL CButton::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// メンバにセット.
	m_nID = (int)hMenu;	// hMenuをm_nIDに代入.
	return CCustomControl::Create(_T("Button"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, (HMENU)m_nID, hInstance);	// CCustomControl::Createでボタンを作成.

}