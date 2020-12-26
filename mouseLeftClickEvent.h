#pragma once
#include "mouseEvent.h"

#define TYPE MouseLeftClickEvent
#define PARENTS : public MouseEvent
#define MEMBERS bool shiftKeyPressed;
#define PARAMETERS int x, int y, bool shiftKeyPressed
#define MEMBERS_SET MEMBER_SET(x) MEMBER_SET(y) MEMBER_SET(shiftKeyPressed)

EVENT_CLASS(TYPE, PARENTS, MEMBERS, PARAMETERS)
