#include "0221_1.h"

USING_NS_CC;

cocos2d::Scene * Example::createScene() 
{
    return Example::create();
}

bool Example::init() 
{
  if (!Scene::init()) 
  {
    return false;
  }

    auto pSprite = Sprite::create("Images/charIcon/cal_6_Icon.png");
    auto pSprite2 = Sprite::create("Images/charIcon/jun_Icon.png");
    auto pSprite3 = Sprite::create("Images/charIcon/matsuri_Icon.png");

    pSprite->setPosition(Vec2(640, 360));
    pSprite2->setPosition(Vec2(640, 360));
    pSprite3->setPosition(Vec2(640, 360));

    pSprite->setAnchorPoint(Vec2(0.8, 0.8));
    pSprite2->setAnchorPoint(Vec2(0.4, 0.4));
    pSprite3->setAnchorPoint(Vec2(0.0, 0.0));

    pSprite3->setZOrder(3);
    pSprite2->setZOrder(2);
    pSprite->setZOrder(1);

    //pSprite->setTextureRect(Rect(0, 0, 64, 64));
    //pSprite->setColor(Color3B(0, 175, 0));
    //pSprite->setColor(Color3B::MAGENTA);
    //pSprite->setScale(2.0f);
    //pSprite->setOpacity(50);
    //pSprite->setVisible(false);
    //pSprite->setRotation(90.0f);
    pSprite->setFlippedX(true);

    this->addChild(pSprite);
    this->addChild(pSprite2);
    this->addChild(pSprite3);

    return true;
}

