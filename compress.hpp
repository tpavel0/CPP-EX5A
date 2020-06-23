
#pragma once
#include <vector>
#include "Itertool.hpp"
using namespace std;
#include <iostream>

namespace itertools {

    template<typename T,typename F=plus>
    class compress { 
        T collect;   
        vector<bool> vec;

    public:
        compress(T collect , vector<bool> vec):collect(collect),vec(vec){}

        auto operator[]( typename T::iterator nIndex) const
        {
            return 0;
        }


        class iterator {
        private:
            const compress *Myacumulate;
            typename T::iterator it;
            
        public:
            iterator( const compress *Accumulate,typename T::iterator place) {
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

         iterator begin()  {
            return iterator{this, this->collect.begin()};
        }

        iterator end()  {
            return iterator{this, this->collect.end()};
        }

    };
}
