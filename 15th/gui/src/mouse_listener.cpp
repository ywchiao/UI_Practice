
#include <functional>

#include "mouse_listener.h"

/**
 *  Constructor.  Initialze the event handling table.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
MouseListener::MouseListener() {
    table_["click"] = &MouseListener::on_click;
} // MouseListener::MouseListener()

/**
 *  Invoke registered event handling function for passed_in event.
 *
 *  @param std::shared_ptr<Event>: Pointer to the Event object.
 *  @return int: 0: successuf.
 *  @since  0.1.0
 **/
int MouseListener::on(std::shared_ptr<Event> e) {
    return std::invoke(table_[e->event], this, e);
} // MouseListener::on()

/**
 *  Output 'click' to screen at location clicked.
 *
 *  @param std::shared_ptr<Event>: pointer to the 'click' event
 *                                 object.
 *  @return int: o: success.
 *  @since  0.1.0
 **/
int MouseListener::on_click(std::shared_ptr<Event> e) {
//    mvprintw(e->y, e->x, e->event.c_str());
//    mvprintw(e->y+1, e->x, "mouseinterval: %d\n", mouseinterval(-1));

    return 0;
} // MouseListener::on_click()

// mouse_listener.cpp
