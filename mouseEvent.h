#pragma once
#include "event.h"

class MouseEvent : public Event {
public:
	int x, y;
};
