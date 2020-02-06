#include "QApplication"
#include "Director.h"
#include "Config.h"

int main(int argc, char *argv[])
{
#ifdef RELEASE
    QApplication::addLibraryPath("./plugins"); // 发布版本从程序所在目录下寻找相关组件
#endif

    QApplication a(argc, argv);
    Config::getInstance()->init();
    Director::getInstance()->setWindow(new Window());
    Director::getInstance()->getWindow()->show();
    a.exec();
    Config::getInstance()->uninit();
    return 0;
}
