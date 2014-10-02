// Compile in CLI on osx and boost via macport:
// $ clang++ -std=c++11 -I /opt/local/include -Wl,/opt/local/lib/libboost_unit_test_framework.a bob_test.cpp
// $ ./a.out
// Running 15 test cases...
//
// *** No errors detected

#include <string>
using namespace std;

namespace bob {
	auto qm = '?';
	string hey(string s) {
		auto msg = "Whatever.";
		auto uc = true;	// uppercase
		auto num = false; // only digits
		auto alpha = false; // letters
		auto space = 0;
		for (char&c : s) {
			// Shout unless lowercase
			if (islower(c)) {
				uc = false;
			}
			// See if alphanumeric is present
			if (isalpha(c)) {
				alpha = true;
			}
			if (isdigit(c)) {
				num = true;
			}
			// Prolonged silence
			if (isspace(c)) {
				space++;
			}
		}
		// uppercase
		if (uc) {
			msg = "Whoa, chill out!";
		}
		if (num && !alpha) {
			msg = "Whatever.";
		}
		// Question, look at last char
		char const& back = s.back();
		if (back == qm && (num || !uc)) {
			msg = "Sure.";
		}
		if (s.length() == 0) {
			msg = "Fine. Be that way!";
		}
		if (s.length() == space) {
			msg = "Fine. Be that way!";
		}
		return msg;
	}
}