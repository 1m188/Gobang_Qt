#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include "QApplication"
#include "QDeskTopWidget"
#include "QPainter"
#include "QMouseEvent"
#include "QMessageBox"
#include "cmath"

class Scene : public QWidget
{
	Q_OBJECT

public:
	Scene(QWidget *parent);
	~Scene();

private:
	int lineNum;
	double interval;

	const enum player
	{
		black,
		white
	};
	player whichPlayer;

	//�����������궼����x����y
	QVector<QPair<int, int>> pos;
	QVector<QPair<int, int>> blackPos;
	QVector<QPair<int, int>> whitePos;

	//�ж���Ӯ
	bool isWin(QVector<QPair<int, int>>);
	//�ж�������֮���Ƿ���ĳ��Ԫ��
	bool isExist(QVector<QPair<int, int>>, QPair<int, int>);

protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
};

#endif // SCENE_H
