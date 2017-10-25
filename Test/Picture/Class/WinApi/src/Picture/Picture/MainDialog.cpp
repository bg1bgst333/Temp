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
	m_pPicture = NULL;	// m_pPictureをNULLで初期化.

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
	if (m_pPicture != NULL) {	// m_pPictureがNULLでないとき.
		delete m_pPicture;	// delete m_pPictureを破棄.
		m_pPicture = NULL;		// m_pPictureにNULLをセット.
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

	// ピクチャーコントロールのロード.
	m_pPicture = new CPicture(m_hWnd, IDC_PICTURE1);	// ピクチャーコントロールの生成.

	// ボタンハンドラを追加.
	AddCommandHandler(IDC_BUTTON1, BN_CLICKED, (int(CWindow::*)(WPARAM, LPARAM))&CMainDialog::OnClickedButton1);	// AddCommandHandlerでOnClickedButton1を追加.

	// 処理できたのでTRUE.
	return TRUE;

}

// メンバ関数OnClickedButton1
int CMainDialog::OnClickedButton1(WPARAM wParam, LPARAM lParam) {

	// 変数の宣言.
	HINSTANCE hInstance;	// アプリケーションインスタンスハンドルhInstance.
	HBITMAP hBitmap;	// ビットマップハンドルhBitmap.

	// インスタンスハンドルの取得.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWLP_HINSTANCE);	// GetWindowLongでインスタンスハンドルを取得.

	// エディットコントロールのテキストに書かれたパスの画像をロードする.
	m_pEdit->GetText();	// m_pEdit->GetTextでエディットコントロールからテキストを取得.(m_pEdit->m_tstrTextに格納されている.)
	
	// 画像のロード.
	hBitmap = (HBITMAP)LoadImage(hInstance, m_pEdit->m_tstrText.c_str(), IMAGE_BITMAP, 320, 240, LR_LOADFROMFILE);	// LoadImageで画像をロード.
	if (hBitmap != NULL) {	// hBitmapがNULLでなければ.

		// 画像の表示.
		SendMessage(m_pPicture->m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);	// SendMessageでSTM_SETIMAGEを送信することで画像を表示.

		// ビットマップの破棄.
		DeleteObject(hBitmap);	// DeleteObjectでビットマップを破棄.

	}

	// 処理したので0を返す.
	return 0;	// 0を返す.

}