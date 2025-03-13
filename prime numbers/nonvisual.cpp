#include<fstream>
#include<chrono>
#include<thread>
#include<math.h>
#include<iostream>
#include<vector>

unsigned const int winX = 500;				//window width
unsigned const int winY = 300;				//window height

unsigned const int largeNumber = 50000;

std::vector<unsigned int> primeTable;	//the table of primes

unsigned long int n = 2;					//2487930371
unsigned long int num = 1;					//120885987

unsigned long int calcTo = 0;		//#of prime to calc

bool isPrime = true;

unsigned long  int temp1 = 0;
float temp2, et = 0;
int bTime = time(0);

int main() {
    srand(time(nullptr));

	//reading prime nubers
	std::string myText;

	std::ifstream MyReadFile("primes.txt");
	if(MyReadFile.is_open()){
		while (getline(MyReadFile, myText, ' ')) {
			primeTable.push_back(stoi(myText));
		}
		MyReadFile.close();
	}

	else {
		primeTable.push_back(2);
	}

	temp1 = 0;
	while (true){
		std::cout << "number of the Prime number to count to: ";
		std::cin >> myText;
		calcTo = stoi(myText);

		if (calcTo != 0) {
			if (calcTo <= primeTable.size()) {
				std::cout << primeTable[calcTo - 1] << " is prime number No" << calcTo << " (from the table)" << std::endl;
				continue;
			}
		}
		if (primeTable.size() < ceil(sqrt(calcTo)) + 10) {
			std::cout << "prime table size insufficient: " << primeTable.size() << " out of " << ceil(sqrt(calcTo)) + 10 << std::endl;
			std::cout << "computation time may increase" << std::endl;
		}
		while (true) {
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

			if(primeTable.size() > 0){
				for (int i = 0; i < primeTable.size(); i++){
					if (n == 2 || n == 3 || n == 5) break;
					if (n % primeTable[i] == 0) {
						isPrime = false;
						break;
					}
					if (primeTable[i] > ceil(sqrt(n))) break;
				}
			}
			if (primeTable[primeTable.size() - 1] < ceil(sqrt(n)) && isPrime) {
				for (int i = 0; i < ceil(sqrt(n)); i++) {
					if (n == 2 || n == 3 || n == 5) break;
					if (n % (primeTable[primeTable.size() - 1] + i) == 0) {
						isPrime = false;
						break;
					}
				}
			}
			if (isPrime) {
				temp1 = int(calcTo - num);
				
				if (num == calcTo) {
					std::cout << n << " is prime number No " << num << std::endl << "time elapsed: " << time(0) - bTime << 's' << std::endl;
					break;
				}

				if (temp1 % largeNumber == 0) {
					std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

					temp2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

					et = temp1 * temp2 / largeNumber;

					std::cout << temp1 / largeNumber << "\tt: " << temp2 << "\tet: " << et << "    \tn: " << n << "\tNo " << num << std::endl;
				}
				num++;
			}
			isPrime = true;
			n++;
		}
		temp1 = 0;
		temp2 = 0, et = 0;
		bTime = time(0);
		n = 2;
		num = 1;
	}
	return 0;
}
