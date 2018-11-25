#include "SettingScene.h"
#include "Director.h"
#include "StartScene.h"
#include "QLabel"
#include "QPushButton"
#include "QGridLayout"

SettingScene::SettingScene(Window *parent)
	: Scene(parent)
{

}

SettingScene::~SettingScene()
{

}

void SettingScene::init()
{
	//�ؼ�
	QLabel *infoLabel = new QLabel(this);
	infoLabel->setAlignment(Qt::AlignCenter);
	infoLabel->setFont(QFont(u8"΢���ź�", 40));
	infoLabel->setText(tr(u8"��  ��"));

	QPushButton *themeChooseButton = new QPushButton(this);
	themeChooseButton->setFont(QFont(u8"΢���ź�", 15));
	themeChooseButton->setText(tr(u8"����ѡ��"));

	QPushButton *returnToStartScene = new QPushButton(this);
	returnToStartScene->setFont(QFont(u8"΢���ź�", 15));
	returnToStartScene->setText(tr(u8"���ؿ�ʼ����"));
	connect(returnToStartScene, &QPushButton::clicked, this, &SettingScene::returnToStartSceneButtonClicked);

	//����
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(infoLabel, 0, 0, 10, 15);
	layout->addWidget(themeChooseButton, 10, 5, 3, 5);
	layout->addWidget(returnToStartScene, 13, 5, 3, 5);
}

void SettingScene::returnToStartSceneButtonClicked()
{
	StartScene *startScene = new StartScene(Director::getInstance()->getWindow());
	startScene->init();
	startScene->show();
	deleteLater();
}