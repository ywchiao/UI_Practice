
#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <vector>

#ifdef _WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

#include "listener.h"

class Widget : public Listener {
  protected:
    void emit(std::shared_ptr<Event>) override {};
    int on(std::shared_ptr<Event>) override { return 0; };

    virtual int paint(std::shared_ptr<Event>) = 0;

  protected:
    int state_ = 0;

    WINDOW *win_ = nullptr;

  private:
    std::vector<std::shared_ptr<Widget>> children_;
};

#endif

// widget.h
