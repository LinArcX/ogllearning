#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <iostream>

class WindowManager
{
public:
	virtual void init() = 0;
	virtual void create_window() = 0;
	virtual void handle_events() = 0;
	virtual void swap_buffers() = 0;
	virtual void poll_events() = 0;
	virtual void release_resources() = 0;

	int get_width() const { return m_width; }
	int get_height() const { return m_height; }
	std::string get_app_name() const { return m_app_name; }

	void set_width(int width) { m_width = width; }
	void set_height(int heigth) { m_height = heigth; }
	void set_app_name(std::string name) { m_app_name = name; }

private:
	int m_width;
	int m_height;
	std::string m_app_name;
};
#endif // WINDOW_MANAGER_H

