#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "QMap"

//��Ϸ������
class GameScene : public Scene
{
	Q_OBJECT

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

public:
	GameScene(Window *parent);
	~GameScene();

	void init() override; //��ʼ��

protected:
	void paintEvent(QPaintEvent *event) override; //��д�����¼����������̺�����
	void mousePressEvent(QMouseEvent *event) override; //��д������¼���ȷ�����Ӻ��ж���Ӯ
};

#endif // GAMESCENE_H
