#include "RestaurantManager.h"
#include "InfoRestaurant.h"
#include <iostream>
using namespace std;

typedef SList<InfoRestaurant*> List;
typedef List::Node Node;

RestaurantManager::~RestaurantManager() {
	//;TODO
	// Listに登録されたクラスをdeleteする
}

void
RestaurantManager::Set(string& filename) {
	//;TODO
	// データを読み出すクラスを作成

	//;TODO
	// データを読み出すループを作成
	{
	InfoRestaurant* infoRestaurant;
	infoRestaurant = new InfoRestaurant(cheap, near, light, name);
	list.Unshift(infoRestaurant);
	}

}

void
RestaurantManager::Get(bool cheap, bool near, bool light) const {

	for (const Node* node = list.GetFirst(); node != NULL; node = node->next) {

		if ( node->m_cheap == cheap && 
				node->m_near == near && node->m_light == light) {
			Show(node->m_name);
		}
	}

}

void
RestaurantManager::Show(string& name) const {
	cout << ---- << endl;
	cout << name << endl;
}
