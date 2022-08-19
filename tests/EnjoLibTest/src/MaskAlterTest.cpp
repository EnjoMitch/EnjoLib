#include "MaskAlterTest.h"
#include <Util/VecD.hpp>
#include <Util/Str.hpp>
#include <Util/CoutBuf.hpp>
#include <Util/CharManipulations.hpp>
#include <bitset>

using namespace EnjoLib;

/*
template<class BidirIt>
bool next_permutation(BidirIt first, BidirIt last)
{
  auto r_first = std::make_reverse_iterator(last);
  auto r_last = std::make_reverse_iterator(first);
  auto left = std::is_sorted_until(r_first, r_last);
  if(left != r_last){
    auto right = std::upper_bound(r_first, left, *left);
    std::iter_swap(left, right);
  }
  std::reverse(left.base(), last);
  return left != r_last;
}
*/
void first_combination(size_t item[], size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        item[i] = i;
    }
}

bool next_combination(size_t item[], size_t n, size_t N)
{
    for (size_t i = 1; i <= n; ++i) {
        if (item[n-i] < N-i) {
            ++item[n-i];
            for (size_t j = n-i+1; j < n; ++j) {
                item[j] = item[j-1] + 1;
            }
            return true;
        }
    }
    return false;
}

template <int bits>
VecD ToBinary(int number)
{
    std::string binary = std::bitset<bits>(number).to_string(); //to binary
    //LOGL << "Binary = " << binary << Nl;
    VecD ret;
    CharManipulations cman;
    for (const char c : binary)
    {
        ret.Add(cman.ToDouble(Str(c)));
    }
    return ret;
}

MaskAlterTest::MaskAlterTest()
{
    VecD mask;
    for (int i = 0; i < 4; ++i)
    {
        mask.Add(0);
    }
    /*
    std::sort(mask.begin(), mask.end());
    do {
        std::cout << s << '\n';
    } while(next_permutation(mask.begin(), mask.end()));
    */
    for (int i = 0; i < mask.size(); ++i)
    {
        for (int j = 0; j < mask.size(); ++j)
        {
            if (i == j)
            {
                //continue;
            }
            mask.at(j) = !mask.at(j);
            //LOGL << mask.Print() << Nl;
        }
    }

    //LOGL << ToBinary<8>(4).Print() << Nl;
}


MaskAlterTest::~MaskAlterTest()
{
    //dtor
}


