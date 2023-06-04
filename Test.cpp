/**
* this file contains test cases for part A assignment 5
* @author Lior Vinman
* @since 04/06/2023
*/

#include "doctest.h" // test module

#include "sources/MagicalContainer.hpp" // assignment header


TEST_CASE("Checking initialization of the comperator and iterator, basic functionallity")
{
	int a = 1, b = 2, c = 3;
	
	// initialization
	CHECK_NOTHROW(MagicalContainer c);
	MagicalContainer magic_container;
	
	// adding elem and no-throwing check
	CHECK_NOTHROW(magic_container.addElement(a));
	CHECK_NOTHROW(magic_container.size());
	CHECK(magic_container.size() == 1);
	CHECK_NOTHROW(magic_container.removeElement(a));
	
	// adding elemes
	magic_container.addElement(1);
	magic_container.addElement(2);
	magic_container.addElement(3);
	
	// checking iterator over container
	CHECK_NOTHROW(MagicalContainer::SideCrossIterator magic_iterator(magic_container));
	CHECK_NOTHROW(MagicalContainer::PrimeIterator magic_iterator(magic_container));
	CHECK_NOTHROW(MagicalContainer::AscendingIterator magic_iterator(magic_container));
}

TEST_CASE("Testing the removements of elemnts from the container and iterator")
{
	int a = 1, b = 2, c = 3;
	
	// initialaizing container
	MagicalContainer magic_container;
	CHECK(magic_container.size() == 0);
	
	// adding elems
	magic_container.addElement(a);
	magic_container.addElement(b);
	magic_container.addElement(c);
	CHECK(magic_container.size() == 3);
	
	// removing elems
	magic_container.removeElement(a);
	CHECK(magic_container.size() == 2);
	
	// checking iterator
	MagicalContainer::AscendingIterator magic_iterator(magic_container);
	CHECK(*magic_iterator == 2);
	++magic_iterator;
	CHECK(*magic_iterator == 3);
	++magic_iterator;
}

TEST_CASE("Testing the `Ascending` Iterator, using it over the `MagicalContainer`")
{	
	// filling the container
	MagicalContainer magic_container;
	for(int i = 1; i <= 5; i++)
	{
		magic_container.addElement(i);
	}
	
	// initialaizing the ascending iterator
	MagicalContainer::AscendingIterator ascending_iterator(magic_container);
	
	// running the iterator over the magic container
	CHECK(*ascending_iterator == 1);
	++ascending_iterator;
	CHECK(*ascending_iterator == 2);
	++ascending_iterator;
	CHECK(*ascending_iterator == 3);
	++ascending_iterator;
	CHECK(*ascending_iterator == 4);
	++ascending_iterator;
	CHECK(*ascending_iterator == 5);
	++ascending_iterator;
	
	// testing the sizes
	CHECK(ascending_iterator == MagicalContainer::AscendingIterator(magic_container, magic_container.size()));
}

TEST_CASE("Testing the `SideCross` Iterator, using it over the `MagicalContainer`")
{	
	// filling the container
	MagicalContainer magic_container;
	for(int i = 1; i <= 5; i++)
	{
		magic_container.addElement(i);
	}
	
	// initialaizing the ascending iterator
	MagicalContainer::SideCrossIterator side_cross_iterator(magic_container);
	
	// running the iterator over the magic container
	CHECK(*side_cross_iterator == 1);
	++side_cross_iterator;
	CHECK(*side_cross_iterator == 2);
	++side_cross_iterator;
	CHECK(*side_cross_iterator == 3);
	++side_cross_iterator;
	CHECK(*side_cross_iterator == 4);
	++side_cross_iterator;
	CHECK(*side_cross_iterator == 5);
	++side_cross_iterator;
	
	// testing the sizes
	CHECK(side_cross_iterator == MagicalContainer::SideCrossIterator(magic_container, magic_container.size()));
}

TEST_CASE("Testing the `Prime` Iterator, using it over the `MagicalContainer`")
{	
	// filling the container
	MagicalContainer magic_container;
	for(int i = 1; i <= 5; i++)
	{
		magic_container.addElement(i);
	}
	
	// initialaizing the ascending iterator
	MagicalContainer::PrimeIterator prime_iterator(magic_container);
	
	// running the iterator over the magic container
	CHECK(*prime_iterator == 2);
	++prime_iterator;
	CHECK(*prime_iterator == 3);
	++prime_iterator;
	CHECK(*prime_iterator == 5);
	++prime_iterator;
	
	// testing the sizes
	CHECK(prime_iterator == MagicalContainer::PrimeIterator(magic_container, magic_container.size()));
}


TEST_CASE("Testing the comparement of iterators, those with the same type (ascending, sidecross, prime)")
{
	// filling the container
	MagicalContainer magic_container;
	for(int i = 1; i <= 5; i++)
	{
		magic_container.addElement(i);
	}
	
	// creating the `Ascending` iterators
	MagicalContainer::AscendingIterator ascending_iterator_1(magic_container);
	MagicalContainer::AscendingIterator ascending_iterator_2(magic_container, 2);
	
	// creating the `SideCross` iterators
	MagicalContainer::SideCrossIterator side_cross_iterator_1(magic_container);
	MagicalContainer::SideCrossIterator side_cross_iterator_2(magic_container, 4);
	
	// creating the `Prime` iterators
	MagicalContainer::PrimeIterator prime_iterator_1(magic_container);
	MagicalContainer::PrimeIterator prime_iterator_2(magic_container, 3);
	
	// checking the `==` operator
	CHECK(ascending_iterator_1 == ascending_iterator_1);
	CHECK(side_cross_iterator_1 == side_cross_iterator_1);
	CHECK(prime_iterator_1 == prime_iterator_1);
	
	// checking the `!=` operator
	CHECK(ascending_iterator_1 != ascending_iterator_2);
	CHECK(side_cross_iterator_1 != side_cross_iterator_2);
	CHECK(prime_iterator_1 != prime_iterator_2);
	
	// checking the `<` operator
	CHECK(ascending_iterator_1 < ascending_iterator_2);
	CHECK(side_cross_iterator_1 < side_cross_iterator_2);
	CHECK(prime_iterator_1 < prime_iterator_2);
	
	// checking the `>` operator
	CHECK(ascending_iterator_2 > ascending_iterator_1);
	CHECK(side_cross_iterator_2 > side_cross_iterator_1);
	CHECK(prime_iterator_2 > prime_iterator_1);
}

