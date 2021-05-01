#include "../inc/CircularIndex.hpp"

CircularIndex::CircularIndex(int size): m_size(size), m_current(0) {}

void CircularIndex::go_up() {
    if(m_current > 0)
        m_current--;
    else
        m_current = m_size - 1;
}
void CircularIndex::go_down() {
    if(m_current < m_size - 1)
        m_current++;
    else
        m_current = 0;
}
int CircularIndex::get_current() const {
    return m_current;
}
void CircularIndex::set_size(int size) {
    m_size = size;
}
