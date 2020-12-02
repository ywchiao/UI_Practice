
#ifndef __LISTENER_H__
#define __LISTENER_H__

#include <map>
#include <memory>

#include "event.h"

class Listener {
  public:
    virtual ~Listener() = 0;

  public:
    virtual int on(std::shared_ptr<Event>) = 0;
};

inline Listener::~Listener() {} // C++ faq says define this anyways to
                                // increase speed.
#endif

// listener.h
