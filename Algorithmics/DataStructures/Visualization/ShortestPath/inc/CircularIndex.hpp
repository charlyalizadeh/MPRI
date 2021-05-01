/* I think there must some datastructures that work like that but I only needed something very simple */
#ifndef CIRCULARINDEX_H
#define CIRCULARINDEX_H


class CircularIndex {
    public:
        CircularIndex(int size = 0);

        void go_up();
        void go_down();
        int get_current() const;
        void set_size(int size);



    private:
        int m_size;
        int m_current;
};

#endif
