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
	m_pEdit = NULL;	// m_pEditをNULLで初期化.
	m_pStatic = NULL;	// m_pStaticをNULLで初期化.
}

// メンバ関数OnCLose
BOOL CMainDialog::OnClose() {

	// ボタンハンドラの削除.
	DeleteCommandHandler(IDC_BUTTON1, BN_CLICKED);	// DeleteCommandHandlerで(IDC_BUTTON1, BN_CLICKED)のハンドラを削除.

	// メンバの終了処理.
	if (m_pButton != NULL) {	// m_pButtonがNULLでない時.
		delete m_pButton;	// deleteでm_pButtonを破棄.
		m_pButton = NULL;	// m_pButtonにNULLをセット.
	}
	if (m_pEdit != NULL) {	// m_pEditがNULLでない時.
		delete m_pEdit;		// delete m_pEditを破棄.
		m_pEdit = NULL;		// m_pEditにNULLをセット.
	}
	if (m_pStatic != NULL) {	// m_pStaticがNULLでないとき.
		delete m_pStatic;	// delete m_pStaticを破棄.
		m_pStatic = NULL;		// m_pStaticにNULLをセット.
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

	// スタティックテキストコントロールのロード.
	m_pStatic = new CStatic(m_hWnd, IDC_STATIC1);	// スタティックテキストコントロールの生成.

	// ボタンハンドラを追加.
	AddCommandHandler(IDC_BUTTON1, BN_CLICKED, (int(CWindow::*)(WPARAM, LPARAM))&CMainDialog::OnClickedButton1);	// AddCommandHandlerでOnClickedButton1を追加.

	// 処理できたのでTRUE.
	return TRUE;

}

// メンバ関数OnClickedButton1
int CMainDialog::OnClickedButton1(WPARAM wParam, LPARAM lParam) {

	// スタティックテキストコントロールにエディットコントロールのテキストをセットする.
	m_pEdit->GetText();	// m_pEdit->GetTextでエディットコントロールからテキストを取得.(m_pEdit->m_tstrTextに格納されている.)
	m_pStatic->SetText(m_pEdit->m_tstrText);	// m_pStatic->SetTextでm_pEdit->m_tstrTextをスタティックテキストコントロールにセットする.

	// 処理したので0を返す.
	return 0;	// 0を返す.

}
