#include "Config.h"
#include "QFile"
#include "QApplication"

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
	//��ʼ��Ĭ�ϵ�����
	themeResourceUrl = ":/theme/Resoueces/theme/default.qss";

	QFile f("config.ini");
	//�ļ������������������
	if (f.exists())
	{
		f.open(QIODevice::ReadOnly);
		QString temp;
		//��ȡ������Դurl
		temp = f.readLine();
		temp.chop(1);
		themeResourceUrl = temp;
		f.close();
	}
	//�����½��ļ�������Ĭ�ϵ����ÿ�ʼ��Ϸ
	else
	{
		f.open(QIODevice::WriteOnly);
		f.close();
	}

	//���õ�ǰ������
	setTheme(themeResourceUrl);
}

void Config::uninit()
{
	QFile f("config.ini");
	f.open(QIODevice::WriteOnly | QIODevice::Truncate); //ֻд+�����������
	f.write(themeResourceUrl.toStdString().c_str());
	f.write("\n");
	f.close();
}

void Config::setTheme(QString themeResourceUrl)
{
	QFile f(themeResourceUrl);
	f.open(QIODevice::ReadOnly);
	qApp->setStyleSheet(f.readAll());
	f.close();
	this->themeResourceUrl = themeResourceUrl;
}