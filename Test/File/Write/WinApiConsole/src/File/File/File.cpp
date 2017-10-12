// ヘッダのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>	// TCHAR型
#include <cstdio>	// C標準入出力
#include <iostream>	// C++標準入出力

// _tmain関数
int _tmain() {

	// 変数・配列の宣言・初期化
	TCHAR tszFileName[_MAX_PATH] = { 0 };	// ファイル名tszFileName(要素数_MAX_PATH)を0で初期化.
	TCHAR tszFileContent[1024] = { 0 };		// ファイル内容tszFileContent(要素数1024)を0で初期化.
	HANDLE hFile;	// ファイルハンドルhFile
	DWORD dwWrittenBytes;	// 書き込んだバイト数dwWrittenBytes.
	char *pszFileContent = NULL;	// Shift_JIS文字列.
	int len;	// Shift_JIS変換に必要なバッファの長さlen.

	// ファイル名の入力
	std::wcout << _T("tszFileName: ");	// std::wcoutで"tszFileName: "を出力.
	_fgetts(tszFileName, _MAX_PATH, stdin);	// _fgettsで入力内容をtszFileNameに格納.
	tszFileName[_tcslen(tszFileName) - 1] = _T('\0');	// _tcslen(tszFileName) - 1番目に'\0'を格納.

	// ファイル内容の入力(1行分, 改行したら終わり.)
	std::wcout << _T("---tszFileContent---") << std::endl;	// std::wcoutで"---tszFileContent---"を出力.
	_fgetts(tszFileContent, 1024, stdin);	// _fgettsで入力内容をtszFileContentに格納.
	tszFileContent[_tcslen(tszFileContent) - 1] = _T('\0');	// _tcslen(tszFileContent) - 1番目に'\0'を格納.

	// ファイルを開く.
	hFile = CreateFile(tszFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileでtszFileNameを開く.
	if (hFile == INVALID_HANDLE_VALUE) {	// hFileがINVALID_HANDLE_VALUEなら失敗.

		// エラー処理
		_tprintf(_T("CreateFile Error!\n"));	// _tprintfで"CreateFile Error!"と出力.
		return -1;	// -1を返す.

	}

	// ファイルの書き込み.
	len = WideCharToMultiByte(CP_ACP, 0, tszFileContent, -1, NULL, 0, NULL, NULL);	// WideCharToMultiByteで必要な長さを取得.
	pszFileContent = new char[len];	// pszFileContentのメモリを確保.
	WideCharToMultiByte(CP_ACP, 0, tszFileContent, -1, pszFileContent, len, NULL, NULL);	// WideCharToMultiByteでShift_JISに変換.
	WriteFile(hFile, pszFileContent, len - 1, &dwWrittenBytes, NULL);	// WriteFileでファイルを書き込む.

	// 閉じる.
	CloseHandle(hFile);	// CloseHandleでhFileを閉じる.
	delete [] pszFileContent;	// deleteでpszFileContentを解放.

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}