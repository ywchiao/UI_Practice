
#ifndef __EVENT_H__
#define __EVENT_H__

#include <memory>
#include <string>

struct Event {
    Event(const std::string& event_) : event{ event_ } {};
    Event(const std::string& event_, int x_, int y_, int z_) :
        event{ event_ }, x{ x_ }, y{ y_ }, z{ z_ } {};

    virtual ~Event() = default;

    int source;
    int target;
    std::string event;

    union {
        struct {
            int key;
        };
        struct {
            int x;
            int y;
            int z;
        };
    };
};

#endif

// event.h
