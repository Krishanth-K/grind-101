#include <algorithm>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class TimeMap {
  public:
	// data structure: hashmap => key -> [(value, timestamp)]. Always sorted by
	// timestamp
	std::unordered_map<string, vector<std::pair<string, int>>> map;

	TimeMap() {}

	void set(string key, string value, int timestamp)
	{
		if (map.find(key) == map.end())
			map[key] = {};

		auto &values = map.at(key);

		// append the new tuple
		values.push_back({value, timestamp});

		// // sort the values based on timestamp
		// std::sort(values.begin(), values.end(),
		//           [](auto &a, auto &b) { return a.second < b.second; });
	}

	string get(string key, int timestamp)
	{
		// return "" if no tuples present for the key
		if (map.find(key) == map.end())
			return "";

		auto &values = map.at(key);

		string res = "";

		// search for the max tuple less than timestamp
		res = search(values, timestamp);
		// for (const auto &tuple : values)
		// {
		// 	if (tuple.second > timestamp)
		// 		break;
		//
		// 	res = tuple.first;
		// }

		return res;
	}

	// perform binary search over the timestamp values
	string search(vector<std::pair<string, int>> &values, int timestamp)
	{
		// all tuples after timestamp
		if (values[0].second > timestamp)
			return "";

		// all tuples before timestamp
		if (values[values.size() - 1].second <= timestamp)
			return values[values.size() - 1].first;

		string res = "";
		int lo = 0, hi = values.size() - 1;

		while (lo < hi)
		{
			int mid = lo + (hi - lo) / 2;

			if (values[mid].second == timestamp)
				return values[mid].first;

			// search right half
			if (values[mid].second < timestamp)
			{
				res = values[mid].first;
				lo = mid + 1;
			}
			// search left half
			else
				hi = mid - 1;
		}

		if (values[lo].second <= timestamp)
			return values[lo].first;

		return res;
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
	Solution soln;
	return 0;
}
