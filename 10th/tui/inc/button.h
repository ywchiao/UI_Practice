
#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <map>
#include <string>

#ifdef _WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

#include "event.h"
#include "widget.h"

class Button : public Widget {
  public:
    Button(int, int, int, int, const std::string&);

  public:
    int on(std::shared_ptr<Event>) override;

  private:
    int on_click(std::shared_ptr<Event>);

    int paint(std::shared_ptr<Event>) override;
    int pressed(std::shared_ptr<Event>);
    int released(std::shared_ptr<Event>);

  private:
    bool visible_ = false;
    bool pressed_ = false;

    int x_ = 0;
    int y_ = 0;
    int width_ = 1;
    int height_ = 1;

    const std::string caption_;

  private:
    std::map<std::string, int (Button::*)(std::shared_ptr<Event>)>
        table_;
};

#endif

// button.h
