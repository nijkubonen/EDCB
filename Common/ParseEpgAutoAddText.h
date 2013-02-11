#ifndef __PARSE_EPG_AUTO_ADD_TEXT_H__
#define __PARSE_EPG_AUTO_ADD_TEXT_H__

#include "StructDef.h"

////////////////////////////////////////////////////////////////////////////
//予約情報ファイルの「EpgAutoAdd.txt」の読み込みと保存処理を行うためのクラス
//排他制御などは行っていないため、複数スレッドからのアクセスは上位層で排他制
//御を行うこと
////////////////////////////////////////////////////////////////////////////
class CParseEpgAutoAddText
{
public:
	//予約一覧のmap
	//キーは通し番号
	//Readのみで追加などの操作はメンバ関数使用すること
	map<DWORD, EPG_AUTO_ADD_DATA*> dataIDMap;

public:
	CParseEpgAutoAddText(void);
	~CParseEpgAutoAddText(void);

	//EpgAutoAdd.txtの読み込みを行う
	//引数：
	// file_path	EpgAutoAdd.txtのフルパス
	//戻り値：
	// TRUE（成功）、FALSE（失敗）
	BOOL ParseText(LPCWSTR filePath);
	//現在の情報をEpgAutoAdd.txtに上書き保存する
	//引数：
	// file_path	EpgAutoAdd.txtのフルパス(NULLで読み込み時のファイルパス使用)
	//戻り値：
	// TRUE（成功）、FALSE（失敗）
	BOOL SaveText(LPCWSTR filePath = NULL);

	//情報を追加する
	//引数：
	// item			追加する情報
	//戻り値：
	// TRUE（成功）、FALSE（失敗）
	BOOL AddData(EPG_AUTO_ADD_DATA* item);
	//情報を変更する
	//引数：
	// item			変更する情報
	//戻り値：
	// TRUE（成功）、FALSE（失敗）
	BOOL ChgData(EPG_AUTO_ADD_DATA* item);
	//情報を削除する
	//引数：
	// dataID	削除する情報のID
	//戻り値：
	// TRUE（成功）、FALSE（失敗）
	BOOL DelData(DWORD dataID);

protected:
	wstring loadFilePath;

	DWORD nextID;
protected:
	BOOL Parse1Line(string parseLine, EPG_AUTO_ADD_DATA* item );
	DWORD GetNextID();

};

#endif
