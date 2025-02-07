#include<iostream>
#include<windows.h>
#include<ctime>
#include<math.h>

using namespace std;

int main(){

	srand(time(0));

	string message = "lorem ipsum";

	cin >> message;
	
	const string letters = "abcdefghijklmnopqrstuvwxyz ";
	string mask = "";
	string result = "";

	int density = 5;
	//int totalCount = message.length() * density;
	
	while (message.length() > 0) {
		if (rand() % (density + 1) == 0) {
			result += message[0];
			message.erase(0, 1);
			mask += ' ';
		} else {
			result += letters[rand() % letters.length()];
			mask += '@';
		}
	}
	int sideL = sqrt(result.length()) * 2;
	for (int i = 1; i < result.length() + 1; i++) {
		cout << result[i - 1] << ' ';
		if (i % sideL == 0) cout << endl;
	}
	cout << endl;
	for (int i = 1; i < result.length() + 1; i++) {
		cout << mask[i - 1] << '@';
		if (i % sideL == 0) cout << endl;
	}
}                                                                                                                                                                                                                                                                                             
