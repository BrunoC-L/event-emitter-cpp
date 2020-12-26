#pragma once
#include "mouseEvent.h"

#define TYPE MouseMoveEvent
#define PARENTS : public MouseEvent
#define MEMBERS 
#define PARAMETERS int x, int y
#define MEMBERS_SET MEMBER_SET(x) MEMBER_SET(y)

EVENT_CLASS(TYPE, PARENTS, MEMBERS, PARAMETERS)
