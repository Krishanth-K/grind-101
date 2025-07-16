#include <cctype>
#include <string>

using namespace std;

bool isPassing(string word)
{
	bool hasVowel = false, hasCons = false;

	for (const char &c : word)
	{
		// make sure string only contains alphabets and numbers
		if (!isalnum(c))
			return false;

		if (isalpha(c))
		{
			char lowerC = tolower(c);

			// it contains atleast one vowel
			if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' ||
			    lowerC == 'o' || lowerC == 'u')
				hasVowel = true;

			// it contains atleast one consonant
			else
				hasCons = true;
		}
	}

	return hasVowel && hasCons;
}

class Solution {
  public:
	bool isValid(string word)
	{
		if (word.size() >= 3 && isPassing(word))
			return true;

		return false;
	}
};
