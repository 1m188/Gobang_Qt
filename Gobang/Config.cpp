#include "Config.h"

Config *Config::instance = nullptr; //��ʼ������ָ��

Config::Config()
{

}

Config::~Config()
{

}

Config * Config::getInstance()
{
	if (!instance)
	{
		instance = new Config();
	}
	return instance;
}

void Config::init()
{
}

void Config::uninit()
{
}