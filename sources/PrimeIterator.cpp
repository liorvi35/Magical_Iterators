/**
 * this file contains implementations for prime iterator
 *
 * @since 04/06/2023
 * @author Lior Vinman
 */

#include "MagicalContainer.hpp"

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& c) : _container(c), _index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& c, size_t i) : _container(c), _index(i) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &pi) : _container(pi._container), _index(pi._index) {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& pi)
{
    if(this != &pi)
    {
        this->_container = pi._container;
        this->_index = pi._index;
    }
    return (*this);
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& pi) const
{
    return (this->_index == pi._index);
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& pi) const
{
    return !((*this) == pi);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& pi) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& pi) const
{
    return false;
}

int MagicalContainer::PrimeIterator::operator*()
{
    return this->_container._container[_index];
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{
    ++(this->_index);
    return (*this);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
{
    return PrimeIterator((*this));
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
{
    return PrimeIterator(this->_container, _container.size());
}

