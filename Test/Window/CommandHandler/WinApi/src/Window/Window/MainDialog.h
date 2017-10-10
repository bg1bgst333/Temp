// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Dialog.h"	// CDialog
#include "Button.h"	// CButton
#include "Edit.h"	// CEdit

// メインダイアログクラスCMainDialog
class CMainDialog : public CDialog {

	// publicメンバ
	public:

		// publicメンバ変数
		CButton *m_pButton;	// ボタンオブジェクトポインタm_pButton
		CEdit *m_pEdit;		// エディットコントロールオブジェクトポインタm_pEdit

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMainDialog(UINT nIDTemplate, CWindow *pParent);	// コンストラクタCMainDialog
		// メンバ関数
		virtual BOOL OnClose();			// 閉じられた時のハンドラOnClose.
		virtual BOOL OnInitDialog(HWND hwndDlg);	// ダイアログ初期化時のハンドラOnInitDialog.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// コマンド発生時のハンドラOnCommand.

};