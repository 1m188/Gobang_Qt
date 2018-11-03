#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "QMap"

class GameScene : public Scene
{
	Q_OBJECT

public:
	GameScene(QWidget *parent);
	~GameScene();

private:
	int lineNum; //�����ߵ�����
	double interval; //��֮��ļ��

	//���ӵ�ö��
	const enum player
	{
		black,
		white
	};
	player whichPlayer; //��ǰ�ȴ����ӵ�һ��

	QMap<player, QString> title; //�ڰ����Ӧ�ı����ַ���

	//�����������궼����x����y
	QVector<QPair<int, int>> pos; //��ǰ���п������ӵ�����
	QVector<QPair<int, int>> blackPos; //�����Ѿ����ӵ�����
	QVector<QPair<int, int>> whitePos; //����...

	//�ж���Ӯ
	bool isWin(QVector<QPair<int, int>>);
	//�ж�������֮���Ƿ���ĳ��Ԫ��
	bool isExist(QVector<QPair<int, int>>, QPair<int, int>);

protected:
	void paintEvent(QPaintEvent *) override; //��д�����¼����������̺�����
	void mousePressEvent(QMouseEvent *) override; //��д������¼���ȷ�����Ӻ��ж���Ӯ

public:
	void init(); //��ʼ��
};

#endif // GAMESCENE_H
