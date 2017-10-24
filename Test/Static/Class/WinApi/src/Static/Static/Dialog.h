// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// ダイアログクラスCDialog
class CDialog : public CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		UINT m_nIDTemplate;		// ダイアログのリソースID, m_nIDTemplate
		CWindow *m_pParent;		// 親ウィンドウm_pParent

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CDialog(UINT nIDTemplate, CWindow *pParent);	// コンストラクタCDialog
		// メンバ関数
		virtual INT_PTR DoModal();	// モーダルダイアログ表示関数DoModal
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// StaticWindowProcから各ウィンドウオブジェクトごとに呼び出されるサブウィンドウプロシージャDynamicWindowProc.
		virtual BOOL OnClose();			// 閉じられた時のハンドラOnClose.
		virtual BOOL OnInitDialog(HWND hwndDlg);	// ダイアログ初期化時のハンドラOnInitDialog.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// コマンド発生時のハンドラOnCommand.

};