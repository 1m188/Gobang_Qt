#include "Window.h"
#include "QApplication"
#include "QDeskTopWidget"
#include "GameScene.h"

Window::Window(QWidget *parent)
	: QWidget(parent)
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
	QWidget::show();

	//��Ϸ����
	GameScene *gameScene = new GameScene(this);
	gameScene->init();
	gameScene->show();
}