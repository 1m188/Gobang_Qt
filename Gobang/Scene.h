#ifndef SCENE_H
#define SCENE_H

#include <QWidget>

//������
class Scene : public QWidget
{
	Q_OBJECT

public:
	Scene(QWidget *parent);
	virtual ~Scene();

private:

public:
	virtual void init(); //��ʼ������Ԫ������
};

#endif // SCENE_H
