#include<iostream>
#include<ctime>
#include<math.h>

using namespace std;

string calculateMask(string inputm int density) {
	string mask = "";

	while (input.length() > 0) {
		if (rand() % (density + 1) == 0) {
			result += input[0];
			input.erase(0, 1);
			mask += ' ';
		}
		else {
			result += letters[rand() % letters.length()];
			mask += '@';
		}
	}

	return mask
}

void display(string message) cout << message;

string getString() {
	string output = "";
	cin >> output;
	return output;
}

int main(){

	srand(time(0));

	string message = "lorem ipsum";

	message = getString();
	
	const string letters = "0123456789abcdefghijklmnopqrstuvwxyz ";
	string mask = "";
	string result = "";

	int density = 7;
	//int totalCount = message.length() * density;
	
	mask = calculateMask(message, density);
	
	int sideL = sqrt(result.length()) * 2;
	for (int i = 1; i < result.length() + 1; i++) {
		display(result[i - 1]);
		if (i % sideL == 0) display("\n");
	}
	cout << endl;
	for (int i = 1; i < result.length() + 1; i++) {
		display(mask[i - 1]);
		display("@");
		if (i % sideL == 0) display("\n");
	}
}                                                                                                                                                                                                                                                                                             
