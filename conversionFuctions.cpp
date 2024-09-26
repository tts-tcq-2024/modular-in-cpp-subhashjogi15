#include "TelCoColorCoder.h"
 
namespace TelCoColorCoder 
{
    ColorPair GetColorFromPairNumber(int pairNumber) {
		int zeroBasedPairNumber = pairNumber - 1;
		MajorColor majorColor = static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
		MinorColor minorColor = static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
		return ColorPair(majorColor, minorColor);
    }
    
	int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
		return major * numberOfMinorColors + minor + 1;
	}

	void printColorCodingManual() {
		int pairNumber = 1;
    	for (int majorColorIterator = 0; majorColorIterator < 5; ++majorColorIterator) {
        for (int minorColorIterator = 0; minorColorIterator < 5; ++minorColorIterator) {
            std::cout << "Pair Number " << pairNumber << ": " << TelCoColorCoder::MajorColorNames[majorColorIterator] << " - " << TelCoColorCoder::MinorColorNames[minorColorIterator] << std::endl;
            ++pairNumber;
        }
    }
	}
}
