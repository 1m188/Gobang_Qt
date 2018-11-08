#include "Window.h"
#include "QApplication"
#include "QDeskTopWidget"
#include "StartScene.h"

Window::Window() : QWidget(Q_NULLPTR)
{
	//��������
	setAttribute(Qt::WA_DeleteOnClose, true);
	setAttribute(Qt::WA_QuitOnClose, true);

	//���ڱ���ʹ�С����
	setWindowTitle(tr(u8"������"));
	setFixedSize(960, 960);

	//�ƶ�����Ļ����
	QRect rect = frameGeometry();
	rect.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(rect.topLeft());
}

Window::~Window()
{

}

void Window::show()
{
	//��ʼ����
	StartScene *startScene = new StartScene(this);
	startScene->init();
	startScene->show();

	QWidget::show();
}