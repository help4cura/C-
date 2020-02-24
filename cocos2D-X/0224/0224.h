#ifndef _EXAMPLE_02_H_
#define _EXAMPLE_02_H_

#include "cocos2d.h"

class Example02 : public cocos2d::Scene
{

public:

  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(Example02);

private:

};

#endif