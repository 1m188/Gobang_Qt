#include "Director.h"

Director *Director::instance = nullptr; //��ʼ������ָ��

Director::Director() :window(nullptr)
{
}

Director::~Director()
{
}

Director * Director::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Director();
	}
	return instance;
}