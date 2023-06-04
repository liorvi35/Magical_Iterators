/**
 * this file contains implementations for ascending iterator
 *
 * @since 04/06/2023
 * @author Lior Vinman
 */

#include "MagicalContainer.hpp"

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& c) : _container(c), _index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& c, size_t i) : _container(c), _index(i) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &ai) : _container(ai._container), _index(ai._index) {}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& ai)
{
    if(this != &ai)
    {
        this->_container = ai._container;
        this->_index = ai._index;
    }
    return (*this);
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& ai) const
{
    return (this->_index == ai._index);
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& ai) const
{
    return !((*this) == ai);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& ai) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& ai) const
{
    return false;
}

int MagicalContainer::AscendingIterator::operator*()
{
    return this->_container._container[_index];
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{
    ++(this->_index);
    return (*this);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
{
    return AscendingIterator((*this));
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
{
    return AscendingIterator(this->_container, _container.size());
}
