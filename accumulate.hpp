
#pragma once
#include <vector>
#include "Itertool.hpp"
using namespace std;
#include <iostream>

namespace itertools {
    class plus
    {
    public:
        template <typename T>
         T operator()(const T a, const T b)const{
            return a + b;
        }
    };

    template<typename T,typename F=plus>
    class accumulate {  
         T collect; 
         F func;

    public:

        accumulate(T collect , F f=plus()):collect(collect),func(f){}

        auto operator[]( typename T::iterator nIndex) const 
        {
            return 0;
        }

        class iterator {
        private:
            accumulate *Myacumulate;
            typename T::iterator it;

        public:
            iterator(  accumulate *Accumulate,typename T::iterator place) {
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

            bool operator!=(const iterator &other) const{
            return this->it != other.it; 
            }

        };

         iterator begin()  {
            return iterator{this, this->collect.begin()};
        }

        iterator end() {
            return iterator{this, this->collect.end()};
        }

    };
}









