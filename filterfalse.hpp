
#pragma once
#include "Itertool.hpp"
#include <vector>
using namespace std;
#include <iostream>

namespace itertools {

    template<typename T,typename F>
    class filterfalse {
        T collect; 
        F func;

    public:

        filterfalse(   F func,T collect):func(func),collect(collect){}

        auto operator[]( typename T::iterator nIndex) const{return 0;}

        class iterator {
        private:
            filterfalse *Myacumulate;
            typename T::iterator it; 

        public:
            iterator(   filterfalse *Accumulate,typename T::iterator place) {
                this->it=place;
                Myacumulate = Accumulate;
            }

            auto  operator*()  {
                return Myacumulate->operator[](it);
            }

            iterator& operator++() {
                it++;
                return *this;
            }

            iterator& operator++(int) {
                iterator temp= *this;
                it++;
                return temp;
            }

            bool operator!=(const iterator &other) const { return this->it != other.it; }
        };

         iterator begin() {
            return iterator{this, this->collect.begin()};
        }

        iterator end() {
            return iterator{this, this->collect.end()};
        }

    };
}
