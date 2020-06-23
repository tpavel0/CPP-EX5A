#pragma once
#include <vector>
using namespace std;
#include <iostream>
#include "Itertool.hpp"
namespace itertools {
    class range {
    public:
        int start;
        int endd;
        
        range() {
            this->start = 0;
            this->endd = 0;
        }

        range(int a, int b) {
            this->start = a;
            this->endd = b;
        }
        range(range &other){
            this->start = other.start;
            this->endd = other.endd;
        }

        int size() {
            return this->endd;
        }

        range operator+=(int number) {
            range temp = range(number, number);
        }

        class iterator {
        public:
            iterator( int nIndex) {
                Myindex = nIndex;
            }

            iterator(){
                Myindex=-1;
            }

            const int &operator*() const { 
                return Myindex;
            }

            iterator &operator++() {
                Myindex++;
                return *this;
            }

            iterator &operator++(int) {
                Myindex++;
                return *this;
            }

            bool operator!=(const iterator &other) const {
                return Myindex != other.Myindex;
            }

            int get() {
                return this->Myindex;
            }

            int Myindex =-1;
        };
        iterator begin() const;
        iterator end() const;

    };

    typename range::iterator range::begin() const {
        return range::iterator{ this->start};
    }
    typename range::iterator range::end() const {
        return range::iterator{ this->endd};
    }
}
