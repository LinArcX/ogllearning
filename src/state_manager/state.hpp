#pragma once

class State {
public:
	virtual ~State() {}
	virtual void action() = 0;
};
