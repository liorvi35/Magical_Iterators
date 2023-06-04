/**
 * @brief this file contains implementations of magical container header
 *
 * @since 04/06/2023
 * @author Lior Vinman
 */

#ifndef MAGICAL_CONTAINER_HPP

    /**
     * flag to insure header is not included more than once
     */
    #define MAGICAL_CONTAINER_HPP

    #include <iostream>
    #include <vector>
    #include <algorithm>

    /**
     * mentioning the namespace
     */
    namespace ariel {}


    class MagicalContainer
    {
        public:

            /**
             * magical container itself to store values
             */
            std::vector<int> _container;

            /**
             * vector to order
             */
            std::vector<int> _order;

            /**
             * default ctor
             */
            MagicalContainer() {}

            /**
             * adds element into magical container
             * @param int elem to add
             */
            void addElement(int);

            /**
             * removes element from magical container
             * @param int elem to remove
             */
            void removeElement(int);

            /**
             * getter for containers size
             * @return size of container
             */
            size_t size() const;

        class AscendingIterator
        {
            public:

                MagicalContainer &_container;

                size_t _index;

                AscendingIterator(MagicalContainer&);

                AscendingIterator(MagicalContainer&, size_t);

                AscendingIterator(const AscendingIterator&);

                ~AscendingIterator() {}

                AscendingIterator begin() const;

                AscendingIterator end() const;

                AscendingIterator& operator=(const AscendingIterator&);

                bool operator==(const AscendingIterator&) const;

                bool operator!=(const AscendingIterator&) const;

                bool operator<(const AscendingIterator&) const;

                bool operator>(const AscendingIterator&) const;

                int operator*();

                AscendingIterator& operator++();
        };
        class PrimeIterator
        {
            public:

                MagicalContainer &_container;
                
                size_t _index;

                PrimeIterator(MagicalContainer&);
                
                PrimeIterator(MagicalContainer&, size_t);
                
                PrimeIterator(const PrimeIterator&);
                
                ~PrimeIterator(){}

                PrimeIterator begin() const;
                
                PrimeIterator end() const;

                PrimeIterator& operator=(const PrimeIterator&);
                
                bool operator==(const PrimeIterator&) const;
                
                bool operator!=(const PrimeIterator&) const;
                
                bool operator<(const PrimeIterator&) const;
                
                bool operator>(const PrimeIterator&) const;
                
                int operator*();
                
                PrimeIterator& operator++();
        };
        class SideCrossIterator
        {
            public:

                MagicalContainer &_container;
                
                size_t _index;

                SideCrossIterator(MagicalContainer&);
                
                SideCrossIterator(MagicalContainer&, size_t);
                
                SideCrossIterator(const SideCrossIterator&);
                
                ~SideCrossIterator(){}

                SideCrossIterator begin() const;
                
                SideCrossIterator end() const;

                SideCrossIterator& operator=(const SideCrossIterator&);
                
                bool operator==(const SideCrossIterator&) const;
                
                bool operator!=(const SideCrossIterator&) const;
                
                bool operator<(const SideCrossIterator&) const;
                
                bool operator>(const SideCrossIterator&) const;
                
                int operator*();
                
                SideCrossIterator& operator++();
        };
    };

#endif
