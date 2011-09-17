#include "RestaurantManager.h"
#include "InfoRestaurant.h"
#include "LoadData.h"
#include "SList.h"
#include <iostream>
using namespace std;

RestaurantManager::~RestaurantManager() {

	for (const Node* node = list.GetFirst(); node != NULL; node = node->next) {
		delete node->value;
	}

}

void
RestaurantManager::Set(string& filename) {

	LoadData loadData(filename);

	do {
		InfoRestaurant* infoRestaurant;
		infoRestaurant = new InfoRestaurant();

		loadData.GetLine(*infoRestaurant);

		list.Unshift(infoRestaurant);
	} while(! loadData.Eof() );

}

void
RestaurantManager::Get(bool cheap, bool near, bool light) const {

	for (const Node* node = list.GetFirst(); node != NULL; node = node->next) {

		if ( node->value->m_cheap == cheap && 
				node->value->m_near == near && node->value->m_light == light) {
			Show(node->value->m_name);
		}
	}

}

void
RestaurantManager::Show(string& name) const {

	cout << "----" << endl;
	cout <<  name  << endl;
}
