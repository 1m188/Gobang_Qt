#pragma once

#include "Window.h"

// 场景类
class Scene : public QWidget
{
    Q_OBJECT

public:
    Scene(Window *parent);
    virtual ~Scene();

    virtual void init(); // 初始化场景元素内容
};
