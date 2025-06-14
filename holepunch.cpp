#include<iostream>
#include<ctime>
#include<math.h>

using namespace std;

string calculateResult(string input, int density, string charactrs) {
	string mask = "", finalMask = "";
	string message = "", finalMessage = "";
	string temp = input;

	while (temp.length() > 0) {
		if (rand() % (density + 1) == 0) {
			message += temp[0];
			temp.erase(0, 1);
			mask += ' ';
		}
		else {
			message += charactrs[rand() % charactrs.length()];
			mask += '@';
		}
	}

	for (int i = 0; i < message.length() * 2; i++) {
		if (i % 2 == 0) {
			finalMessage += message[i / 2];
			finalMask += mask[i / 2];
		} else {
			finalMessage += charactrs[rand() % charactrs.length()];
			finalMask += "@";
		}
	}

	return message + "\n" + mask;
}

void display(string message) {
	cout << message; 
}

void display(char message) {
	cout << message;
}

string getString() {
	string output = "";
	cin >> output;
	return output;
}

int main(){

	srand(time(0));

	string message = "lorem ipsum";

	message = getString();
	
	message.reserve();

	const string letters = "0123456789abcdefghijklmnopqrstuvwxyz ";
	string mask = "";
	string result = "";
	string output2;
	int temp = 0;
	int density = 7;
	
	string output = calculateResult(message, density, letters);
	output2 = output;

	result = output.erase(output.find_first_of('\n', 0), output.length());
	mask = output2.erase(0, output2.find_first_of('\n', 0) + 1);

	int sideL = sqrt((output.length() - 1) / 2 ) * 2;

	for (int i = 1; i < result.length() + 1; i++) {
		display(result[i - 1]);
		if (i % sideL == 0) display("\n");
	}
	display('\n');

	for (int i = 1; i < result.length() + 1; i++) {
		display(mask[i - 1]);
		if (i % sideL == 0) display("\n");
	}
}                                                                                                                                                                                                                                                                                             
