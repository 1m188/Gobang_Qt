#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "Scene.h"

//��Ϸ��ʼ�ĳ���
class StartScene : public Scene
{
	Q_OBJECT

public:
	StartScene(QWidget *parent);
	~StartScene();

private:


public:
	void init();

	private slots:
	void newGameButtonClicked(); //������ʼ����Ϸ��ť
};

#endif // STARTSCENE_H
