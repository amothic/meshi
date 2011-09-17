#include "RestaurantManager.h"
#include "InfoRestaurant.h"
#include "LoadData.h"
#include "SList.h"
#include <iostream>
using namespace std;

typedef SList<InfoRestaurant*> List;
typedef List::Node Node;

RestaurantManager::~RestaurantManager() {

	for (const Node* node = list.GetFirst(); node != NULL; node = node->next) {
		node->value delete;
	}

}

void
RestaurantManager::Set(string& filename) {

	LoadData loadData(filename);

	do {
		InfoRestaurant* infoRestaurant;
		infoRestaurant = new InfoRestaurant();

		loadData.GetLine(infoRestaurant);

		list.Unshift(infoRestaurant);
	} while(! loadData.Eof() );

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
