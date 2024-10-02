#include "TelCoColorCoder.h"

numberWithPair expectedNumberWithPairManual[25] = {
{1, "White", "Blue"}, {2, "White", "Orange"}, {3, "White", "Green"}, {4, "White", "Brown"}, {5, "White", "Slate"},
{6, "Red", "Blue"}, {7, "Red", "Orange"}, {8, "Red", "Green"}, {9, "Red", "Brown"}, {10, "Red", "Slate"},
{11, "Black", "Blue"}, {12, "Black", "Orange"}, {13, "Black", "Green"}, {14, "Black", "Brown"}, {15, "Black", "Slate"},
{16, "Yellow", "Blue"}, {17, "Yellow", "Orange"}, {18, "Yellow", "Green"}, {19, "Yellow", "Brown"}, {20, "Yellow", "Slate"},
{21, "Violet", "Blue"}, {22, "Violet", "Orange"}, {23, "Violet", "Green"}, {24, "Violet", "Brown"}, {25, "Violet", "Slate"},
};

void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor, TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair: " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor, int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number: " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void testgenerateColorCodingManual() {
    numberWithPair numberWithPairManual[25] = generateColorCodingManual();
    EXPECT_EQ(numberWithPairManual, expectedNumberWithPairManual);
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    testgenerateColorCodingManual();

    return 0;
}
