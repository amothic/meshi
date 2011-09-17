#ifndef LOAD_DATA_H_
#define LOAD_DATA_H_

#include "InfoRestaurant.h"
#include <fstream>
#include <string>

// データをファイルからロードするためのクラス
class LoadData {

	public:
		LoadData(std::string& filename)
		virtual ~LoadData();

	public:
		void Open(std::string& filename);

		void GetLine(InfoRestaurant& infoRestaurant);
		bool Eof();

	private:
		ifstream file;

}

#endif // #ifndef LOAD_DATA_H_
