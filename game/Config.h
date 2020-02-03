#ifndef CONFIG_H
#define CONFIG_H

#include "QString"

//������
class Config
{
private:
	Config(); //��ֹ�Զ�����

	static Config *instance; //����ָ��

	QString themeResourceUrl; //������Դurl

public:
	Config(const Config &) = delete;
	Config &operator=(const Config &) = delete;
	~Config();

	static Config *getInstance(); //��ȡ����ָ��

	void init(); //��ʼ����������
	void uninit(); //��������
	void setTheme(QString themeResourceUrl); //���õ�ǰ����
};

#endif // CONFIG_H
