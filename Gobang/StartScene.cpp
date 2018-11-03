#include "StartScene.h"
#include "Director.h"
#include "GameScene.h"
#include "QLabel"
#include "QPushButton"
#include "QGridLayout"
#include "QApplication"

StartScene::StartScene(QWidget *parent) :Scene(parent)
{
}

StartScene::~StartScene()
{
}

void StartScene::init()
{
	Director::getInstance()->getWindow()->setWindowTitle(tr(u8"������"));

	//�ؼ�
	QLabel *infoLabel = new QLabel(this);
	infoLabel->setAlignment(Qt::AlignCenter);
	infoLabel->setFont(QFont(u8"΢���ź�", 40));
	infoLabel->setText(tr(u8"��  ��  ��  ��  ��"));

	QPushButton *newGameButton = new QPushButton(this);
	newGameButton->setFont(QFont(u8"΢���ź�", 15));
	newGameButton->setText(tr(u8"��ʼ����Ϸ"));
	connect(newGameButton, &QPushButton::clicked, this, &StartScene::newGameButtonClicked);

	QPushButton *exitButton = new QPushButton(this);
	exitButton->setFont(QFont(u8"΢���ź�", 15));
	exitButton->setText(tr(u8"�˳�"));
	connect(exitButton, &QPushButton::clicked, QApplication::quit);

	//����
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(infoLabel, 0, 0, 10, 15);
	layout->addWidget(newGameButton, 10, 5, 4, 5);
	layout->addWidget(exitButton, 14, 5, 4, 5);
}

void StartScene::newGameButtonClicked()
{
	//��ʼ������ʾ��Ϸ������
	GameScene *gameScene = new GameScene(Director::getInstance()->getWindow());
	gameScene->init();
	gameScene->show();
	//���ز�ɾ����ʼ����
	hide();
	deleteLater();
}