
#include <functional>

#include "button.h"

/**
 *  Constructor.  Initialze the event handling table.
 *
 *  @param none.
 *  @return none.
 *  @since  0.1.0
 **/
Button::Button(int x, int y, int w, int h, const std::string& caption) :
 x_{x}, y_{y}, width_{w}, height_{h}, caption_{caption} {
    win_ = newwin(h, w, y, x);

    table_["click"] = &Button::on_click;
    table_["pressed"] = &Button::pressed;
    table_["released"] = &Button::released;
    table_["repaint"] = &Button::paint;
} // Button::Button()

/**
 *  Invoke registered event handling function for passed_in event.
 *
 *  @param std::shared_ptr<Event>: Pointer to the Event object.
 *  @return int: 0: successuf.
 *  @since  0.1.0
 **/
int Button::on(std::shared_ptr<Event> e) {
    return std::invoke(table_[e->event], this, e);
} // Button::on()

/**
 *  Draw the button to screen.
 *
 *  @param std::shared_ptr<Event>: pointer to the 'repaint' event
 *                                 object.
 *  @return int:  0: success.
 *  @since  0.1.0
 **/
int Button::paint(std::shared_ptr<Event>) {
    mvwprintw(win_, 0, (width_ - caption_.length()) / 2, caption_.c_str());

    if (pressed_) {
        mvwchgat(win_, 0, 0, -1, A_NORMAL, 0, nullptr);
    }
    else {
        mvwchgat(win_, 0, 0, -1, A_REVERSE, 0, nullptr);
    }

    wrefresh(win_);

    return 0;
} // Button::paint()

/**
 *  Set button 'state' to 'pressed'.
 *
 *  @param std::shared_ptr<Event>: pointer to the 'pressed' event
 *                                 object.
 *  @return int:  0: success.
 *               -1: outside the button's region.
 *  @since  0.1.0
 **/
int Button::pressed(std::shared_ptr<Event> e) {
    if ((e->x < x_ || e->y <  y_) ||
        (e->x >= (x_ + width_) || e->y >= (y_ + height_))) {
        return -1;
    }

    pressed_ = true;

    return 0;
} // Button::pressed()

/**
 *  Restore button 'state' to 'released'.
 *
 *  @param std::shared_ptr<Event>: pointer to the 'released' event
 *                                 object.
 *  @return int:  0: success.
 *               -1: outside the button's region.
 *  @since  0.1.0
 **/
int Button::released(std::shared_ptr<Event> e) {
    if ((e->x < x_ || e->y <  y_) ||
        (e->x >= (x_ + width_) || e->y >= (y_ + height_))) {
        return -1;
    }

    pressed_ = false;

    return 0;
} // Button::released()

/**
 *  Output 'click' to screen at location clicked.
 *
 *  @param std::shared_ptr<Event>: pointer to the 'click' event
 *                                 object.
 *  @return int: o: success.
 *  @since  0.1.0
 **/
int Button::on_click(std::shared_ptr<Event> e) {
    if ((e->x < x_ || e->y <  y_) ||
        (e->x > (x_ + width_) || e->y > (y_ + height_))) {
        return -1;
    }

    return 0;
} // Button::on_click()

// button.cpp
