#ifndef RESTAURANT_MANAGER_H_
#define RESTAURANT_MANAGER_H_

// レストランの情報を管理するクラス
class RestaurantManager {

	public:
		virtual ~RestaurantManager();

	public:
		// ファイルからデータを読み出す
		// 読みだしたデータは、リストに登録する
		void Set(std::string& filename);

		// 対象のデータを取り出して、Show()に渡す
		void Get(bool cheap, bool near, bool light) const;

		// 渡された文字列を出力する
		void Show(std::string& name) const;

}

#endif // #ifndef RESTAURANT_MANAGER_H_