
#ifndef __MOUSE_LISTENER_H__
#define __MOUSE_LISTENER_H__

#include <map>

#include "event.h"
#include "listener.h"

class MouseListener : public Listener {
  public:
    MouseListener();

  protected:
    void emit(std::shared_ptr<Event>) override {};
    int on(std::shared_ptr<Event>) override;

  private:
    int on_click(std::shared_ptr<Event>);

  private:
    std::map<std::string, int (MouseListener::*)(std::shared_ptr<Event>)>
        table_;
};

#endif

// mouse_listener.h
