#include <iostream>
#include <string>
#include "mouseMoveEvent.h"
#include "mouseLeftClickEvent.h"

int main() {
	MouseMoveEvent::subscribe(new EventObserver<MouseMoveEvent>([](MouseMoveEvent* ev) {
		std::cout << "Observer1 was called with x=" + std::to_string(ev->x) + ", y=" + std::to_string(ev->y) << std::endl;
	}));
	MouseMoveEvent(500, 500).emit();

	auto obv2 = EventObserver<MouseMoveEvent>([](MouseMoveEvent* ev) {
		std::cout << "Observer2 was called with x=" + std::to_string(ev->x) + ", y=" + std::to_string(ev->y) << std::endl;
	});
	obv2.subscribe();

	MouseMoveEvent(400, 400).emit();

	obv2.unsubscribe();

	MouseMoveEvent(300, 300).emit();

	std::cout << std::endl;

	MouseLeftClickEvent(500, 500, false).emit();
	MouseLeftClickEvent(500, 500, true).emit();

	auto getLogger = [](std::string name) {
		return [name](MouseLeftClickEvent* ev) {
			auto msg = name + 
				" was called with x=" + 
				std::to_string(ev->x) + 
				", y=" + 
				std::to_string(ev->y) + 
				", shift clicked = " + 
				(ev->shiftKeyPressed ? "True" : "False");
			std::cout << msg << std::endl;
		};
	};

	MouseLeftClickEvent::subscribe(new EventObserver<MouseLeftClickEvent>(getLogger("Observer3")));

	// don't do this otherwise there are problems with the subscriber:
		// EventObserver<MouseLeftClickEvent>(getLogger("Observer4")).subscribe();
	// (you could do this instead) :
		// (new EventObserver<MouseLeftClickEvent>(getLogger("Observer4")))->subscribe();
	// name the EventObserver to solve the problem:
	auto obv4 = EventObserver<MouseLeftClickEvent>(getLogger("Observer4"));
	obv4.subscribe();
	obv4.subscribe();
	obv4.subscribe();

	MouseLeftClickEvent(500, 500, false).emit();

	obv4.unsubscribe(); //unsubscribes all 3 obv4 subscriptions

	MouseLeftClickEvent(500, 500, true).emit();
}
