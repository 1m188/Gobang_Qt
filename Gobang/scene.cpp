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
		painter->drawEllipse(i.first*interval - interval / 2, i.second*interval - interval / 2, interval, interval);
	}
	//������
	painter->setBrush(QBrush(Qt::white));
	for (QPair<int, int> i : whitePos)
	{
		painter->drawEllipse(i.first*interval - interval / 2, i.second*interval - interval / 2, interval, interval);
	}

	painter->end();
}

void Scene::mousePressEvent(QMouseEvent *event)
{
	for (QVector<QPair<int, int>>::iterator it = pos.begin(); it != pos.end(); it++)
	{
		int x = it->first;
		int y = it->second;
		if (sqrt(pow(x*interval - event->pos().x(), 2) + pow(y*interval - event->pos().y(), 2)) < 10)
		{
			if (whichPlayer == black)
			{
				blackPos.push_back(*it);
				whichPlayer = white;
			}
			else if (whichPlayer == white)
			{
				whitePos.push_back(*it);
				whichPlayer = black;
			}
			pos.erase(it);
			break;
		}
	}

	update();

	//�ж���Ӯ
	if (whichPlayer == black)
	{
		if (isWin(whitePos))
		{
			QMessageBox::about(this, tr(u8"��Ϸ����"), tr(u8"����ʤ��"));
			for (QVector<QPair<int, int>>::const_iterator it = blackPos.begin(); it != blackPos.end(); it++)
			{
				pos.push_back(*it);
			}
			blackPos.clear();
			for (QVector<QPair<int, int>>::const_iterator it = whitePos.begin(); it != whitePos.end(); it++)
			{
				pos.push_back(*it);
			}
			whitePos.clear();
			whichPlayer = black;
		}
	}
	else if (whichPlayer == white)
	{
		if (isWin(blackPos))
		{
			QMessageBox::about(this, tr(u8"��Ϸ����"), tr(u8"����ʤ��"));
			for (QVector<QPair<int, int>>::const_iterator it = blackPos.begin(); it != blackPos.end(); it++)
			{
				pos.push_back(*it);
			}
			blackPos.clear();
			for (QVector<QPair<int, int>>::const_iterator it = whitePos.begin(); it != whitePos.end(); it++)
			{
				pos.push_back(*it);
			}
			whitePos.clear();
			whichPlayer = black;
		}
	}
}

bool Scene::isWin(QVector<QPair<int, int>> chess)
{
	//���·���
	for (QVector<QPair<int, int>>::const_iterator it = chess.begin(); it != chess.end(); it++)
	{
		int num = 1;
		for (int i = 1; isExist(chess, QPair<int, int>{it->first, it->second + i}); i++)
		{
			num++;
		}
		for (int i = 1; isExist(chess, QPair<int, int>{it->first, it->second - i}); i++)
		{
			num++;
		}
		if (num == 5)
		{
			return true;
		}
	}
	//���ҷ���
	for (QVector<QPair<int, int>>::const_iterator it = chess.begin(); it != chess.end(); it++)
	{
		int num = 1;
		for (int i = 1; isExist(chess, QPair<int, int>{it->first + i, it->second}); i++)
		{
			num++;
		}
		for (int i = 1; isExist(chess, QPair<int, int>{it->first - i, it->second}); i++)
		{
			num++;
		}
		if (num == 5)
		{
			return true;
		}
	}

	return false;
}

bool Scene::isExist(QVector<QPair<int, int>> judgeAim, QPair<int, int> element)
{
	for (QVector<QPair<int, int>>::const_iterator it = judgeAim.begin(); it != judgeAim.end(); it++)
	{
		if (it->first == element.first&&it->second == element.second)
		{
			return true;
		}
	}
	return false;
}