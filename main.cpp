#include "RestaurantManager.h"
#include <iostream>
using namespace std;

const string FILE_NAME = "data.txt";

int main() {
	RestaurantManager manager;

	manager.Set(FILE_NAME);
	manager.Get(1,1,1);

}
