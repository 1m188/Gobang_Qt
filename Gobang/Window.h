#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

//��Ϸ������
class Window : public QWidget
{
	Q_OBJECT

public:
	Window(QWidget *parent = Q_NULLPTR);
	~Window();

private:

public:
	void show(); //��д�����show������ʹ�ó�ʼ�ĳ��������￪ʼ�����Ǵӹ��캯����ʼ
};

#endif // WINDOW_H
