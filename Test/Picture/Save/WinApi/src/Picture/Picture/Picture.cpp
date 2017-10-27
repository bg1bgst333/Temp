// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "Picture.h"	// CPicture
#include "BinaryFile.h"	// CBinaryFile

// コンストラクタCPicture()
CPicture::CPicture() {

	// メンバの初期化.
	m_hBitmap = NULL;	// m_hBitmapにNULLをセット.
	m_tstrImageName = _T("");	// m_tstrImageNameに""をセット.
	m_iImageWidth = 0;	// m_iImageWidthを0にセット.
	m_iImageHeight = 0;	// m_iImageHeightを0にセット.
	m_nID = 0;	// m_nIDを0にセット.
	m_hMemDC = NULL;	// m_hMemDCにNULLをセット.
	m_iHScrollPos = 0;	// m_iHScrollPosに0をセット.
	m_iVScrollPos = 0;	// m_iVScrollPosに0をセット.

}

// コンストラクタCPicture(HWND hParent, UINT nID)
CPicture::CPicture(HWND hParent, UINT nID) {

	// メンバの初期化.
	m_hBitmap = NULL;	// m_hBitmapにNULLをセット.
	m_tstrImageName = _T("");	// m_tstrImageNameに""をセット.
	m_iImageWidth = 0;	// m_iImageWidthを0にセット.
	m_iImageHeight = 0;	// m_iImageHeightを0にセット.
	m_hMemDC = NULL;	// m_hMemDCにNULLをセット.
	m_iHScrollPos = 0;	// m_iHScrollPosに0をセット.
	m_iVScrollPos = 0;	// m_iVScrollPosに0をセット.

	// ピクチャーコントロールのロード.
	Load(hParent, nID);	// LoadでnIDのピクチャーコントロールをロード.

}

// デストラクタ~CPicture()
CPicture::~CPicture() {

	// ビットマップの破棄.
	if (m_hBitmap != NULL) {	// NULLでなければ.
		DeleteObject(m_hBitmap);	// DeleteObjectでm_hBitmapを破棄.
		m_hBitmap = NULL;	// m_hBitmapにNULLをセット.
	}
	// メモリデバイスコンテキストの破棄.
	if (m_hMemDC != NULL) {	// NULLでなければ.
		DeleteDC(m_hMemDC);	// DeleteDCでm_hMemDCを破棄.
		m_hMemDC = NULL;	// m_hMemDCにNULLをセット.
	}
	m_tstrImageName = _T("");	// m_tstrImageNameに""をセット.
	m_iImageWidth = 0;	// m_iImageWidthを0にセット.
	m_iImageHeight = 0;	// m_iImageHeightを0にセット.
	m_nID = 0;	// m_nIDを0にセット.
	m_iHScrollPos = 0;	// m_iHScrollPosに0をセット.
	m_iVScrollPos = 0;	// m_iVScrollPosに0をセット.

}

// メンバ関数Load
HWND CPicture::Load(HWND hParent, UINT nID) {

	// リソースIDのピクチャーコントロールのウィンドウハンドルを取得.
	m_nID = nID;	// メンバにセット.
	m_hWnd = GetDlgItem(hParent, m_nID);	// GetDlgItemでm_nIDのピクチャーコントロールウィンドウハンドルを取得し, m_hWndに格納.
	return m_hWnd;	// m_hWndを返す.

}

// メンバ関数Create
BOOL CPicture::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// メンバにセット.
	m_nID = (int)hMenu;	// hMenuをm_nIDに代入.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle | SS_BITMAP, x, y, iWidth, iHeight, hWndParent, (HMENU)m_nID, hInstance);	// CCustomControl::Createでピクチャーコントロールを作成.

}

// メンバ関数LoadImage
BOOL CPicture::LoadImage(HINSTANCE hInstance, LPCTSTR lpctszImageName) {

	// 構造体の初期化.
	BITMAP bitmap = { 0 };	// ビットマップ情報を格納するBITMAP型bitmapを0で初期化.

	// ビットマップの破棄.
	if (m_hBitmap != NULL) {	// NULLでなければ.
		DeleteObject(m_hBitmap);	// DeleteObjectでm_hBitmapを破棄.
		m_hBitmap = NULL;	// m_hBitmapにNULLをセット.
	}

	// メンバにセット.
	m_tstrImageName = lpctszImageName;	// m_tstrImageNameにlpctszImageNameをセット.

	// 画像のロード.
	m_hBitmap = (HBITMAP)::LoadImage(hInstance, m_tstrImageName.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LoadImageでm_tstrImageNameをロード.(とりあえず画像ファイルとしてロード.)
	if (m_hBitmap == NULL) {	// NULLなら失敗.

		// エラー処理.
		m_tstrImageName = _T("");	// 失敗したので""をセット.

		// 失敗なのでFALSEを返す.
		return FALSE;	// FALSEを返す.

	}

	// 画像から幅と高さを取得.
	GetObject(m_hBitmap, sizeof(BITMAP), &bitmap);	// GetObjectでm_hBitmapからビットマップ情報を取得し, bitmapに格納.
	m_iImageWidth = bitmap.bmWidth;	// bitmap.bmWidthをm_iImageWidthに格納.
	m_iImageHeight = bitmap.bmHeight;	// bitmap.bmHeightをm_iImageHeightに格納.

	// 成功なのでTRUEを返す.
	return TRUE;	// TRUEを返す.

}

// メンバ関数SaveImage
BOOL CPicture::SaveImage(LPCTSTR lpctszImageName) {

	// 変数の初期化.
	BITMAPINFO bi = { 0 };			// ビットマップ情報biを0で初期化.
	LPBYTE lpBitsPixel = NULL;		// ピクセル列へのポインタlpBitsPixelをNULLで初期化.
	BITMAPFILEHEADER bfh = { 0 };	// ビットマップファイル情報bfhを0で初期化.

	// ビットマップ情報のセット.(これらはセットしておかないといけない.)
	bi.bmiHeader.biBitCount = 24;	// ひとまず24bitビットマップに限定.
	bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);	// BITMAPINFOHEADERのサイズ.
	bi.bmiHeader.biWidth = m_iImageWidth;	// 画像幅m_iImageWidth.
	bi.bmiHeader.biHeight = m_iImageHeight;	// 画像高さm_iImageHeight
	bi.bmiHeader.biPlanes = 1;	// とりあえず1でいい.
	bi.bmiHeader.biCompression = BI_RGB;	// RGB

	// DDBからDIBのピクセル列を取得.(ピクセル列のサイズはGetDIBitsで取れる.)
	HDC hDC = GetDC(m_hWnd);	// GetDCでデバイスコンテキストハンドルの取得.
	GetDIBits(hDC, m_hBitmap, 0, m_iImageHeight, NULL, &bi, DIB_RGB_COLORS);	// GetDIBitsでピクセル列のサイズ(bi.bmiHeader.biSizeImage)を取得.
	lpBitsPixel = new BYTE[bi.bmiHeader.biSizeImage];	// メモリ確保.
	GetDIBits(hDC, m_hBitmap, 0, m_iImageHeight, lpBitsPixel, &bi, DIB_RGB_COLORS);	// GetDIBitsでDDBからDIBのピクセル列を取得.
	ReleaseDC(m_hWnd, hDC);	// ReleaseDCでデバイスコンテキストの解放.

	// ビットマップファイル情報のセット.(24bitビットマップの場合.)
	bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);	// ピクセル列以外のサイズ.(つまりヘッダのサイズ)
	bfh.bfSize = bfh.bfOffBits + bi.bmiHeader.biSizeImage;	// 全体のサイズはヘッダ + ピクセル列.
	bfh.bfType = 0x4d42;	// 0x4d42("BM")はビットマップであるという意味.
	bfh.bfReserved1 = 0;	// ここは0でいい.
	bfh.bfReserved2 = 0;	// ここも0でいい.

	// ビットマップバイナリのファイル書き込み.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFileオブジェクトを作成し, ポインタをpBinaryFileに格納.
	pBinaryFile->Set((BYTE *)&bfh, sizeof(BITMAPFILEHEADER));	// pBinaryFile->SetでBITMAPFILEHEADERのbfhをセット.
	pBinaryFile->Write(lpctszImageName);	// pBinaryFile->Write(ファイル名引数ありバージョン)でファイルを開いて書き込み.
	pBinaryFile->Set((BYTE *)&bi, sizeof(BITMAPINFOHEADER));	// pBinaryFile->SetでBITMAPINFOHEADERのbi(正確にはbi.bmiHeader)をセット.
	pBinaryFile->Write();	// pBinaryFile->Write(ファイル名引数なしバージョン)で書き込み.
	pBinaryFile->Set(lpBitsPixel, sizeof(BYTE) * bi.bmiHeader.biSizeImage);	// pBinaryFile->SetでlpBitsPixelをセット.
	pBinaryFile->Write();	// pBinaryFile->Write(ファイル名引数なしバージョン)で書き込み.
	delete pBinaryFile;	// pBinaryFileを解放.

	// メモリ列の解放.
	delete[] lpBitsPixel;	// lpBitsPixelを解放.

	// ファイル名を差し替える.
	m_tstrImageName = lpctszImageName;	// m_tstrImageNameにlpctszImageNameをセット.

	// とりあえずTRUEとする.
	return TRUE;	// TRUEを返す.

}

// メンバ関数SetImage
void CPicture::SetImage() {

	// 変数の宣言.
	HDC hDC;	// HDC型デバイスコンテキストハンドルhDC.

	// メモリデバイスコンテキストの破棄.
	if (m_hMemDC != NULL) {	// NULLでなければ.
		DeleteDC(m_hMemDC);	// DeleteDCでm_hMemDCを破棄.
		m_hMemDC = NULL;	// m_hMemDCにNULLをセット.
	}

	// デバイスコンテキストハンドルの取得.
	hDC = GetDC(m_hWnd);	// GetDCでm_hWndからデバイスコンテキストハンドルhDCを取得.

	// メモリデバイスコンテキストの作成.
	m_hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCで作成したデバイスコンテキストハンドルをm_hMemDCに格納.

	// 画像の表示.
	SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_hBitmap);	// SendMessageでSTM_SETIMAGEを送信することで画像を表示.

	// スクロールバーの位置を初期化.
	m_iHScrollPos = 0;	// m_iHScrollPosに0をセット.
	m_iVScrollPos = 0;	// m_iVScrollPosに0をセット.

	// デバイスコンテキストの解放.
	ReleaseDC(m_hWnd, hDC);	// ReleaseDCでhDCを解放.

}

// メンバ関数OnPaint
void CPicture::OnPaint() {

	// 変数の宣言.
	HDC hDC;			// デバイスコンテキストハンドルHDC型hDC
	PAINTSTRUCT ps;		// PAINTSTRUCT構造体変数ps
	HBITMAP hOld;		// 以前のビットマップハンドルhOld
	int iDrawWidth;		// 実際の描画幅.
	int iDrawHeight;	// 実際の描画高さ.

	// 描画開始.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaintで描画開始.

	// ビットマップの選択.
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObjectでm_hBitmapを選択.

	// ビット転送による描画.
	iDrawWidth = m_iWidth - SCROLLBAR_THICKNESS;	// 実際にはコントロール幅 - スクロールバーの厚さ.
	iDrawHeight = m_iHeight - SCROLLBAR_THICKNESS;	// 実際にはコントロール高さ - スクロールバーの厚さ.
	BitBlt(hDC, 0, 0, iDrawWidth, iDrawHeight, m_hMemDC, m_iHScrollPos, m_iVScrollPos, SRCCOPY);	// BitBltでm_hMemDCからhDCにビット転送することで描画される.

	// 古いビットマップを再選択して戻す.
	SelectObject(m_hMemDC, hOld);	// SelectObjectでhOldを選択.

	// スクロールバー設定.
	// 横
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// サイズをセット.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// フラグをセット.
	m_ScrollInfo.nPage = iDrawWidth;	// 幅をセット.
	m_ScrollInfo.nMin = 0;	// 最小値をセット.
	m_ScrollInfo.nMax = m_iImageWidth;	// 最大値をセット.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, FALSE);	// SetScrollInfoでセット.
															// 縦
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// サイズをセット.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// フラグをセット.
	m_ScrollInfo.nPage = iDrawHeight;	// 高さをセット.
	m_ScrollInfo.nMin = 0;	// 最小値をセット.
	m_ScrollInfo.nMax = m_iImageHeight;	// 最大値をセット.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, FALSE);	// SetScrollInfoでセット.

	// 描画終了.
	EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

}

// メンバ関数OnHScroll
void CPicture::OnHScroll(UINT nSBCode, UINT nPos) {

	// スクロール情報取得.
	m_ScrollInfo.fMask = SIF_POS;	// 位置だけ変更モード(これがないと, スクロールバーが元の位置に戻ってしまうので注意!こっちが前!)
	GetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo);	// マスクを設定してからGetScrollInfo.(こっちが後!)

	// スクロールバー処理.
	switch (nSBCode) {	// nSBCodeごとに振り分け.

		// 一番左
		case SB_LEFT:

			// 位置を最小値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// 一番右
		case SB_RIGHT:

			// 位置を最大値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1列左
		case SB_LINELEFT:

			// nPosが0でなければデクリメント.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1列右
		case SB_LINERIGHT:

			// nPosが最大値-1でなければインクリメント.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1ページ左
		case SB_PAGELEFT:

			// nPage分減らす.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1ページ右
		case SB_PAGERIGHT:

			// nPage分増やす.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// つまみをドラッグ中.
		case SB_THUMBTRACK:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// つまみをドラッグ後.
		case SB_THUMBPOSITION:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// それ以外.
		default:

			break;

	}

	// スクロール情報設定.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);
	// メンバにもセット.
	m_iHScrollPos = m_ScrollInfo.nPos;
	// 無効領域を作成して画面の更新.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRectで無効領域作成.

}

// メンバ関数OnVScroll
void CPicture::OnVScroll(UINT nSBCode, UINT nPos) {

	// スクロール情報取得.
	m_ScrollInfo.fMask = SIF_POS;	// 位置だけ変更モード(これがないと, スクロールバーが元の位置に戻ってしまうので注意!こっちが前!)
	GetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo);	// マスクを設定してからGetScrollInfo.(こっちが後!)

	// スクロールバー処理.
	switch (nSBCode) {	// nSBCodeごとに振り分け.

		// 一番上
		case SB_TOP:

			// 位置を最小値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// 一番下
		case SB_BOTTOM:

			// 位置を最大値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1行上
		case SB_LINEUP:

			// nPosが0でなければデクリメント.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1行下
		case SB_LINEDOWN:

			// nPosが最大値-1でなければインクリメント.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1ページ上
		case SB_PAGEUP:

			// nPage分減らす.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1ページ下
		case SB_PAGEDOWN:

			// nPage分増やす.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// つまみをドラッグ中.
		case SB_THUMBTRACK:
	
			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// つまみをドラッグ後.
		case SB_THUMBPOSITION:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// それ以外.
		default:

			break;

	}

	// スクロール情報設定.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);
	// メンバにもセット.
	m_iVScrollPos = m_ScrollInfo.nPos;
	// 無効領域を作成して画面の更新.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRectで無効領域作成.

}

// メンバ関数OnLButtonDown
int CPicture::OnLButtonDown(UINT nFlags, POINT pt) {

	// 描画開始.
	HDC hDC = GetDC(m_hWnd);	// GetDCで描画開始.

	// ビットマップの選択.
	HBITMAP hOld = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObjectでm_hBitmapを選択.

	// 推された場所に黒い点をセット.
	SetPixel(m_hMemDC, pt.x + m_iHScrollPos, pt.y + m_iVScrollPos, RGB(0x0, 0x0, 0x0));	// SetPixelで黒い点をセット.

	// 古いビットマップを再選択して戻す.
	SelectObject(m_hMemDC, hOld);	// SelectObjectでhOldを選択.

	// 描画終了.
	ReleaseDC(m_hWnd, hDC);	// ReleaseDCで描画終了.

	// 画面更新.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRectで画面更新.

	// キャンセルしないので0を返す.
	return 0;	// 0を返す.

}
