#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

class GameManager
{
public:
	virtual ~GameManager() { ; }

	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void loop() = 0;
	virtual void run() = 0;
};
#endif
