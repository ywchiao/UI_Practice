
#ifndef __MOUSE_LISTENER_H__
#define __MOUSE_LISTENER_H__

#include "event.h"
#include "listener.h"

class MouseListener : public Listener {
  public:
    MouseListener();

  public:
    int on(std::shared_ptr<Event>);

  private:
    int on_click(std::shared_ptr<Event>);

  private:
    std::map<std::string, int (MouseListener::*)(std::shared_ptr<Event>)>
        table_;
};

#endif

// mouse_listener.h
