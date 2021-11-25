#include "../lttools.cpp"

bool isANumber(char c) {
	return c >= '0' && c <= '9';
}

bool isValidIPV4(const char *str) {
	if (str == nullptr) {
		printf("string pointer is null\n");
		return false;
	}
	
	// [0-255].[0-255].[0-255].[0-255]
	// 01.1.1.1
	int sum = -1;
	int numberOfDots = 0;
	for (int i=0; ; ++i) {
		if (str[i] == '\0')break;
		
		if (str[i] == '.') {
			if (numberOfDots >= 3) {
				printf("number of dots is greater than 3\n");
				return false;
			}
			
			if (sum == -1) {
				printf("no digits before dot\n");
				return false;
			}
			
			numberOfDots++;
			sum = -1;
		} else if (isANumber(str[i])) {
			if (sum == -1) {
				sum = 0;
			}
			sum *= 10;
			sum += str[i] - '0';
			if (sum > 255) {
				printf("greater than 255\n");
				return false;
			}
		} else {
			printf("invalid char\n");
			return false;
		}
		
	}
	
	if (numberOfDots == 3 && sum > 0) {
		return true;
	} else {
		printf("address is less than 4 parts\n");
		return false;
	}
}



int main(int argc, char *argv[]) {
//	cout << isValidIPV4("") << endl;
//	cout << isValidIPV4("....") << endl;
//	cout << isValidIPV4("1.1.1.1") << endl;
//	cout << isValidIPV4("...") << endl;
//	cout << isValidIPV4("256.155.133.1") << endl;
//	cout << isValidIPV4("a.b.c.dd") << endl;
//	cout << isValidIPV4("1..3.3") << endl;
//	cout << isValidIPV4("1.3.3") << endl;
//	cout << isValidIPV4("1.3.3.") << endl;
	
	auto t = LT::Tester(isValidIPV4);
	t.test(nullptr).equals(false);
	t.test("").equals(false);
	t.test("....").equals(false);
	t.test("1.1.1.1").equals(true);
	t.test("...").equals(false);
	t.test("256.155.133.1").equals(false);
	t.test("a.b.c.dd").equals(false);
	t.test("1.3.3").equals(false);
	t.test("1.3.3.").equals(false);
}