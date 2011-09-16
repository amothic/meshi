#include "InfoRestaurant.h"
using namespace std;

InfoRestaurant::InfoRestaurant(bool cheap, bool near, bool light, string& name)
{
	Set(cheap, near, light, name);
}

// 情報をセットする関数
void
InfoRestaurant::Set(bool cheap, bool near, bool light, string& name)
{
	m_cheap = cheap;
	m_near	= near;
	m_light = light;
	m_name  = name;
}

