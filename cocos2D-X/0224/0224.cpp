#include "Label.h"

USING_NS_CC;

cocos2d::Scene * Example02::createScene()
{
  return Example02::create();
}

bool Example02::init() 
{
  if (!Scene::init()) 
  {
    return false;
  }
}

Example02::CREATE_FUNC(Example02) {

}
