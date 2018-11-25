#ifndef CONFIG_H
#define CONFIG_H

#include "QString"

//������
class Config
{
private:
	Config(); //��ֹ�Զ�����

	static Config *instance; //����ָ��

public:
	Config(const Config &) = delete;
	Config &operator=(const Config &) = delete;
	~Config();

	static Config *getInstance(); //��ȡ����ָ��

	void init(); //��ʼ����������
	void uninit(); //��������
};

#endif // CONFIG_H
