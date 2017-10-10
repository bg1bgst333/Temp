// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "MainDialog.h"	// CMainDialog
#include "resource.h"	// リソースファイル

// コンストラクタCMainDialog
CMainDialog::CMainDialog(UINT nIDTemplate, CWindow * pParent) : CDialog(nIDTemplate, pParent) {

	// メンバの初期化.
	m_pButton = NULL;	// m_pButtonをNULLで初期化.

}

// メンバ関数OnCLose
BOOL CMainDialog::OnClose() {

	// メンバの終了処理.
	if (m_pButton != NULL) {	// m_pButtonがNULLでない時.
		delete m_pButton;	// deleteでm_pButtonを破棄.
		m_pButton = NULL;	// m_pButtonにNULLをセット.
	}
	if (m_pEdit != NULL) {	// m_pEditがNULLでない時.
		delete m_pEdit;		// delete m_pEditを破棄.
		m_pEdit = NULL;		// m_pEditにNULLをセット.
	}

	// 親クラスのOnCloseに任せる.
	return CDialog::OnClose();	// CDialog::OnCloseの値を返す.

}

// メンバ関数OnInitDialog
BOOL CMainDialog::OnInitDialog(HWND hwndDlg) {

	// メンバにウィンドウハンドルをセット.
	m_hWnd = hwndDlg;	// m_hWndにhwndDlgをセット.

	// ボタンのロード.
	m_pButton = new CButton(m_hWnd, IDC_BUTTON1);	// ボタンの生成.

	// エディットコントロールのロード.
	m_pEdit = new CEdit(m_hWnd, IDC_EDIT1);			// エディットコントロールの生成.

	// 処理できたのでTRUE.
	return TRUE;

}

// メンバ関数OnCommand
BOOL CMainDialog::OnCommand(WPARAM wParam, LPARAM lParam) {
	
	// 変数の宣言.
	BOOL bRet;	// 処理されたかどうかを返す.

	// ボタンオブジェクトがあるかチェック.
	if (m_pButton != NULL){// m_pMenuBarがNULLでない場合.

		// m_pButton->OnCommandButtonに処理を任せる.
		bRet = m_pButton->OnCommandButton(this, wParam, lParam);	// OnCommandButtonにthis, wParam, lParamを渡してあとは任せ, 戻り値をそのまま返す.
		if (bRet) {	// 処理されたか.
			return bRet;	// 処理されたらbRetを返す.
		}

	}

	// コマンドを処理していないのでFALSE.
	return FALSE;	// FALSEを返す.

}
