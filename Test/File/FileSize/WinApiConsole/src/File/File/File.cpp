// ヘッダのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>	// TCHAR型
#include <cstdio>	// C標準入出力
#include <iostream>	// C++標準入出力

// _tmain関数
int _tmain() {

	// 変数・配列の宣言・初期化
	TCHAR tszFileName[_MAX_PATH] = { 0 };	// ファイル名tszFileName(要素数_MAX_PATH)を0で初期化.
	HANDLE hFile;	// ファイルハンドルhFile
	BYTE *pbtBuf = NULL;	// BYTEバッファへのポインタpbtBufをNULLに初期化.
	DWORD dwFileSize;	// ファイルサイズdwFileSize.
	DWORD dwReadBytes;	// 読み込んだバイト数dwReadBytes.

	// ファイル名の入力
	std::wcout << _T("tszFileName: ");	// std::coutで"tszFileName: "を出力.
	std::wcin >> tszFileName;	// std::wcinでtszFileNameに入力されたファイル名を格納.

	// ファイルを開く.(対象となるファイルがShift_JISである必要がある.)
	hFile = CreateFile(tszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileでtszFileNameを開く.
	if (hFile == INVALID_HANDLE_VALUE) {	// hFileがINVALID_HANDLE_VALUEなら失敗.

		// エラー処理
		_tprintf(_T("CreateFile Error!\n"));	// _tprintfで"CreateFile Error!"と出力.
		return -1;	// -1を返す.

	}

	// ファイルサイズの取得.
	dwFileSize = GetFileSize(hFile, NULL);	// GetFileSizeでファイルサイズを取得.
	printf("dwFileSize = %lu\n", dwFileSize);	// printfでdwFileSizeを出力.

	// バッファの生成.
	pbtBuf = new BYTE[dwFileSize + 1];	// BYTE型動的配列を作成し, ポインタをpbtBufに格納.
	ZeroMemory(pbtBuf, dwFileSize + 1);	// ZeroMemoryで初期化.

	// ファイルの読み込み.
	ReadFile(hFile, pbtBuf, dwFileSize, &dwReadBytes, NULL);	// ReadFileでhFileを読み込み, pbtBufに格納.

	// btBufを出力.
	printf("pbtBuf = %s\n", pbtBuf);	// printfでpbtBufを出力.

	// バッファの破棄.
	delete[] pbtBuf;	// delete[]でpbtBufを破棄.

	// 閉じる.
	CloseHandle(hFile);	// CloseHandleでhFileを閉じる.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}