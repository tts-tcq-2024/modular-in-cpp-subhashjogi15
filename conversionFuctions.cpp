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

	numberWithPair[] generateColorCodingManual() {
		int pairNumber = 1;
		int iterator = 0;
		numberWithPair generatedManual[25];
    	for (int majorColorIterator = 0; majorColorIterator < 5; ++majorColorIterator) {
	        for (int minorColorIterator = 0; minorColorIterator < 5; ++minorColorIterator) {
				generatedManual[(iterator)].pairNumber = pairNumber;
				generatedManual[(iterator)].majorColor = TelCoColorCoder::MajorColorNames[majorColorIterator];
				generatedManual[(iterator)].minorColor = TelCoColorCoder::MinorColorNames[minorColorIterator];
				iterator++;
				pairNumber++
	        }
    	}
		return generatedManual;
	}
}
