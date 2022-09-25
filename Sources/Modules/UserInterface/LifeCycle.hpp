#ifndef USERINTERFACE_LIFECYCLE_H
#define USERINTERFACE_LIFECYCLE_H

namespace ogl {
	namespace userInterface {
		class LifeCycle
		{
		public:
			virtual ~LifeCycle() { ; }

			virtual void initialize() = 0;
			virtual void draw() = 0;
			virtual void loop() = 0;
			virtual void run() = 0;
		};
	}
}
#endif
