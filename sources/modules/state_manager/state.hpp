#ifndef STATE_H
#define STATE_H

namespace ogl {
	class State {
	public:
		virtual ~State() { }
		virtual void action() = 0;
	};
}
#endif
