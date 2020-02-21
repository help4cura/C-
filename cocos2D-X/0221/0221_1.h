#pragma once
#include "cocos2d.h"

class Example : public cocos2d::Scene
{
  public:

  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(Example);

  private:

};