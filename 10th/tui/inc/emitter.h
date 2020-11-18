
#ifndef __EMITTER_H__
#define __EMITTER_H__

#include <memory>

#include "event.h"

class Emitter {
  public:
    virtual ~Emitter() = 0;

  public:
    virtual void emit(std::shared_ptr<Event>) = 0;
};

inline Emitter::~Emitter() {} // C++ faq says define this anyways to
                                // increase speed.
#endif

// emitter.h
