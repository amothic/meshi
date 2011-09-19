#ifndef LOAD_DATA_H_
#define LOAD_DATA_H_

#include "InfoRestaurant.h"
#include <fstream>
#include <string>

// データをファイルからロードするためのクラス
class LoadData {

	public:
		LoadData(const std::string& filename);
		virtual ~LoadData();

	public:
		void Open(const std::string& filename);

		bool GetLine(InfoRestaurant& infoRestaurant);
		bool Eof();

	private:
		std::ifstream file;

};

#endif // #ifndef LOAD_DATA_H_
