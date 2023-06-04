//
// Created by yarin on 5/29/23.
//

#include "MagicalContainer.hpp"

void MagicalContainer::addElement(int num) {
    this->_container.emplace_back(num);
    // lower bound checks for the element that is not the less of the num given
    auto it = std::lower_bound(_order.begin(), _order.end(), num);
    _order.insert(it, num);
}

void MagicalContainer::removeElement(int num) {
   return;
}

size_t MagicalContainer::size() const {
    return this->_container.size();
}