#ifndef INFO_RESTAURANT_H_
#define INFO_RESTAURANT_H_

#include <string>

// レストランの情報を扱うクラス
class InfoRestaurant {

	public:
		InfoRestaurant(bool cheap, bool near, bool light, std::string& name);

	public:
		// 情報をセットする関数
		void Set(bool cheap, bool near, bool light, std::string& name);

	public:
		bool m_cheap;		// 値段が安いかどうか
		bool m_near;		// 場所が近いかどうか		
		bool m_light;		// 食事が軽いかどうか

	public:
		std::string m_name;	// お店の名前

}

#endif // #ifndef INFO_RESTAURANT_H_
