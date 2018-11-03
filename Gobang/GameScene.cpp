#include "GameScene.h"
#include "Director.h"
#include "StartScene.h"
#include "QPainter"
#include "QMouseEvent"
#include "QMessageBox"

GameScene::GameScene(QWidget *parent) :Scene(parent)
{
}

GameScene::~GameScene()
{
}

void GameScene::init()
{
	//��ʼ����Ϸ��ر���
	lineNum = 15;
	whichPlayer = black;
	title = QMap<player, QString>{ {black,tr(u8"������-���������") },{white,tr(u8"������-���������") } };
	pos = {};
	blackPos = {};
	whitePos = {};

	//��ʼ�����ڱ���
	Director::getInstance()->getWindow()->setWindowTitle(title[whichPlayer]);

	//ˢ�ױ���
	setAutoFillBackground(true);
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

	//�ػ�����
	update();
}

void GameScene::paintEvent(QPaintEvent *event)
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

	return QWidget::paintEvent(event);
}

void GameScene::mousePressEvent(QMouseEvent *event)
{
	//�ж�����
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
			Director::getInstance()->getWindow()->setWindowTitle(title[whichPlayer]); //���贰�ڱ���
			pos.erase(it);
			break;
		}
	}

	update(); //ˢ�µ�ǰ�����̺�����

	//�ж���Ӯ
	if ((whichPlayer == black&&isWin(whitePos)) || (whichPlayer == white&&isWin(blackPos)))
	{
		//�����������һ�ֵĻ����ؿ�ʼ����
		if (QMessageBox::information(this, tr(u8"��Ϸ����"), tr(QString(u8"��Ϸ������").toUtf8() + (whichPlayer == black ? u8"��" : u8"��") + u8"��ʤ���Ƿ���Ҫ����һ�֣�"), QMessageBox::Yes, QMessageBox::No) == QMessageBox::No)
		{
			StartScene *startScene = new StartScene(Director::getInstance()->getWindow());
			startScene->init();
			startScene->show();
			hide();
			deleteLater();
			return QWidget::mousePressEvent(event);
		}
	}
	else
	{
		return QWidget::mousePressEvent(event);
	}

	//���³�ʼ���������
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
	Director::getInstance()->getWindow()->setWindowTitle(title[whichPlayer]); //���贰�ڱ���

	return QWidget::mousePressEvent(event);
}

bool GameScene::isWin(QVector<QPair<int, int>> chess)
{
	//�����ж��Ƿ���һ��Ӯ�ˣ�����еĻ������жϵĹ�����ֱ��return true������������return false

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

	//�������·���
	for (QVector<QPair<int, int>>::const_iterator it = chess.begin(); it != chess.end(); it++)
	{
		int num = 1;
		for (int i = 1; isExist(chess, QPair<int, int>{it->first - i, it->second - i}); i++)
		{
			num++;
		}
		for (int i = 1; isExist(chess, QPair<int, int>{it->first + i, it->second + i}); i++)
		{
			num++;
		}
		if (num == 5)
		{
			return true;
		}
	}

	//�������·���
	for (QVector<QPair<int, int>>::const_iterator it = chess.begin(); it != chess.end(); it++)
	{
		int num = 1;
		for (int i = 1; isExist(chess, QPair<int, int>{it->first + i, it->second - i}); i++)
		{
			num++;
		}
		for (int i = 1; isExist(chess, QPair<int, int>{it->first - i, it->second + i}); i++)
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

bool GameScene::isExist(QVector<QPair<int, int>> judgeAim, QPair<int, int> element)
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