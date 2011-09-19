#include "LoadData.h"
#include "InfoRestaurant.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

LoadData::LoadData(const string& filename) {
	Open(filename);
}

LoadData::~LoadData() {
	file.close();
}

void
LoadData::Open(const string& filename) {

	file.open(filename.c_str()); 

	if (! file.is_open()) {
		cout << "ファイルが開けませんでした！" << endl;
		exit(EXIT_FAILURE);
	}

}

bool
LoadData::GetLine(InfoRestaurant& infoRestaurant) {

	string input;
	getline(file, input);

	// ファイルの最後に到達したとき、falseを返す
	if(! file) {
		return false;
	}

	// カンマの数をチェック
	if( count( input.begin(), input.end(), ',' ) != 3 ) {
		cout << "形式が不正です" << endl;
		exit(EXIT_FAILURE);
	}

	// 末尾の空白を取り除く
	input = input.substr( 0 , input.find_last_not_of( ' ' )+1 );


	// カンマを半角スペースに変換
	replace( input.begin(), input.end(), ',' , ' ' );

	// istringstreamを利用して変数に格納
	istringstream iss_input(input);
	bool cheap, near, light;
	string name;

	iss_input >> cheap >> near >> light >> name;

	// 読み込みのエラーチェック
	if( iss_input.fail() == true || iss_input.eof() == false )
	{
		cout << "正常に読み込めませんでした" << endl;
		exit(EXIT_FAILURE);
	}

	infoRestaurant.Set(cheap, near, light, name);

	return true;

}

bool
LoadData::Eof() {
	return file.eof();
}
