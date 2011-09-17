#include "LoadData.h"
#include "InfoRestaurant.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

LoadData::LoadData(string& filename) {
	Open(filename);
}

LoadData::~LoadData() {
	file.close();
}

void
LoadData::Open(string& filename) {

	file.open(filename); 

	if (! file.is_open()) {
		cout << "ファイルが開けませんでした！" << endl;
		exit(EXIT_FAILURE);
	}

}

void
LoadData::GetLine(InfoRestaurant& infoRestaurant) {

	string input;
	getline(file, input);

	// カンマの数をチェック
	if( count( input.begin(), input.end(), ',' ) != 3 ) {
		cout << "形式が不正です" << endl;
		exit(EXIT_FAILURE);
	}

	// カンマを半角スペースに変換
	replace( input.begin(), input.end(), ',' , ' ' );


	// istringstreamを利用して変数に格納
	istringstream iss_input( input );
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

}

bool
LoadData::Eof() {
	return file.eof();
}
