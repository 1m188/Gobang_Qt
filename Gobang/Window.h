#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

//��Ϸ������
class Window : public QWidget
{
	Q_OBJECT

public:
	Window();
	~Window();

	void show(); //��д�����show������ʹ�ó�ʼ�ĳ��������￪ʼ�����Ǵӹ��캯����ʼ
};

#endif // WINDOW_H
