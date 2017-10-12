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
	BYTE btBuf[1024];	// BYTE型バッファbtBuf(要素数1024)
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

	// ファイルの読み込み.
	ReadFile(hFile, btBuf, 1024, &dwReadBytes, NULL);	// ReadFileでhFileを読み込み, btBufに格納.
	btBuf[dwReadBytes] = 0x0;	// 末尾を0x0で埋める.

	// btBufを出力.
	printf("btBuf = %s\n", btBuf);	// printfでbtBufを出力.

	// 閉じる.
	CloseHandle(hFile);	// CloseHandleでhFileを閉じる.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}