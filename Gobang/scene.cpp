#include "scene.h"

Scene::Scene(QWidget *parent)
	: QWidget(parent), lineNum(15), whichPlayer(black), pos({}), blackPos({}), whitePos({})
{
	setWindowTitle(tr(u8"������"));
	setFixedSize(960, 960);
	QRect rect = frameGeometry();
	rect.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(rect.topLeft().x(), rect.topLeft().y() - 20);
	//ˢ�ױ���
	setPalette(QPalette(QColor(Qt::white)));

	//�߼��
	interval = static_cast<double>(width()) / (lineNum + 1);

	//��ʼ�������ӵ�����
	for (int i = 1; i <= lineNum; i++)
	{
		for (int j = 1; j <= lineNum; j++)
		{
			pos.push_back(QPair<int, int>(j, i));
		}
	}

	show();
}

Scene::~Scene()
{

}

void Scene::paintEvent(QPaintEvent *event)
{
	QPainter *painter = new QPainter(this);
	//��������
	painter->setPen(QPen(QColor(Qt::black)));
	for (int i = 1; i <= lineNum; i++)
	{
		painter->drawLine(0, i*interval, width(), i*interval);
		painter->drawLine(i*interval, 0, i*interval, height());
	}
	//������
	painter->setBrush(QBrush(Qt::black));
	for (QPair<int, int> i : blackPos)
	{
		painter->drawEllipse(i.first*interval, i.second*interval, interval, interval);
	}
	//������
	painter->setBrush(QBrush(Qt::white));
	for (QPair<int, int> i : whitePos)
	{
		painter->drawEllipse(i.first*interval, i.second*interval, interval, interval);
	}

	painter->end();
}

void Scene::mousePressEvent(QMouseEvent *event)
{
	
}