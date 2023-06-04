/**
 * this file contains implementations for side cross iterator
 *
 * @since 04/06/2023
 * @author Lior Vinman
 */

#include "MagicalContainer.hpp"

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& c) : _container(c), _index(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& c, size_t i) : _container(c), _index(i) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& si) : _container(si._container), _index(si._index) {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& si)
{
    if (this != &si)
    {
        this->_container = si._container;
        this->_index = si._index;
    }
    return (*this);
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& si) const
{
    return (this->_index == si._index);
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& si) const
{
    return !((*this) == si);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& si) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& si) const
{
    return false;
}

int MagicalContainer::SideCrossIterator::operator*()
{
    return this->_container._container[_index];
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{
    ++(this->_index);
    return (*this);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
{
    return SideCrossIterator((*this));
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
{
    return SideCrossIterator(this->_container, _container.size());
}

