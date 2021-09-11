#ifndef TUPLE_EL_HPP
#define TUPLE_EL_HPP

#include <cstdint>

// https://stackoverflow.com/a/52208842

namespace EnjoLib
{
// Contains the actual value for one item in the tuple. The 
// template parameter `i` allows the
// `Get` function to find the value in O(1) time
template<std::size_t i, typename Item>
struct TupleLeaf {
    Item value;
};

// TupleImpl is a proxy for the final class that has an extra 
// template parameter `i`.
template<std::size_t i, typename... Items>
struct TupleImpl;

// Base case: empty tuple
template<std::size_t i>
struct TupleImpl<i>{};

// Recursive specialization
template<std::size_t i, typename HeadItem, typename... TailItems>
struct TupleImpl<i, HeadItem, TailItems...> :
    public TupleLeaf<i, HeadItem>, // This adds a `value` member of type HeadItem
    public TupleImpl<i + 1, TailItems...> // This recurses
    {};

// Obtain a reference to i-th item in a tuple
template<std::size_t i, typename HeadItem, typename... TailItems>
HeadItem& Get(TupleImpl<i, HeadItem, TailItems...>& tuple) {
    // Fully qualified name for the member, to find the right one 
    // (they are all called `value`).
    return tuple.TupleLeaf<i, HeadItem>::value;
}

template<std::size_t i, typename HeadItem, typename... TailItems>
const HeadItem& Get(const TupleImpl<i, HeadItem, TailItems...>& tuple) {
    // Fully qualified name for the member, to find the right one 
    // (they are all called `value`).
    return tuple.TupleLeaf<i, HeadItem>::value;
}

// Templated alias to avoid having to specify `i = 0`
template<typename... Items>
using Tuple = TupleImpl<0, Items...>;

/// TODO: MakeTuple

}

#endif // TUPLE_HPP
