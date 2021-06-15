#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>
#include <ML/CrossValidation.hpp>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

TEST(CV_test_stratified)
{
    const int sizeData = 0;
    const CrossValidation cvv(3, sizeData);
    const int icv0 = 0;
    const int icv1 = 1;
    const int icv2 = 2;

    CHECK_EQUAL(false, cvv.IsTrainStratified(icv0, 0));
    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv0, 1));
    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv0, 2));

    CHECK_EQUAL(false, cvv.IsTrainStratified(icv0, 3));
    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv0, 4));
    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv0, 5));


    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv1, 0));
    CHECK_EQUAL(false, cvv.IsTrainStratified(icv1, 1));
    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv1, 2));

    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv1, 3));
    CHECK_EQUAL(false, cvv.IsTrainStratified(icv1, 4));
    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv1, 5));


    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv2, 0));
    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv2, 1));
    CHECK_EQUAL(false, cvv.IsTrainStratified(icv2, 2));

    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv2, 3));
    CHECK_EQUAL(true,  cvv.IsTrainStratified(icv2, 4));
    CHECK_EQUAL(false, cvv.IsTrainStratified(icv2, 5));
}

TEST(CV_test_shuffled)
{
    const int sizeData = 9;
    const CrossValidation cvv(3, sizeData);

    const int icv0 = 0;
    const int icv1 = 1;
    const int icv2 = 2;

    CHECK_EQUAL(false,  cvv.IsTrainShuffled(icv0, 0));
    CHECK_EQUAL(false,  cvv.IsTrainShuffled(icv0, 1));
    CHECK_EQUAL(false,  cvv.IsTrainShuffled(icv0, 2));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv0, 3));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv0, 4));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv0, 5));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv0, 6));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv0, 7));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv0, 8));

    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv1, 0));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv1, 1));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv1, 2));
    CHECK_EQUAL(false,  cvv.IsTrainShuffled(icv1, 3));
    CHECK_EQUAL(false,  cvv.IsTrainShuffled(icv1, 4));
    CHECK_EQUAL(false,  cvv.IsTrainShuffled(icv1, 5));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv1, 6));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv1, 7));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv1, 8));

    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv2, 0));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv2, 1));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv2, 2));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv2, 3));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv2, 4));
    CHECK_EQUAL(true,  cvv.IsTrainShuffled(icv2, 5));
    CHECK_EQUAL(false,  cvv.IsTrainShuffled(icv2, 6));
    CHECK_EQUAL(false,  cvv.IsTrainShuffled(icv2, 7));
    CHECK_EQUAL(false,  cvv.IsTrainShuffled(icv2, 8));
}
