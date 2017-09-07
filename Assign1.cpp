#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

void fib(int n);

void e(int n);

void pi(int n);

void printHelpMessage();

void runProgram(int n, std::string test);

int main(int argc, char* argv[]){

	int args = argc;

	if(args == 3){
		int n = std::stoi(argv[2]);
		std::string test = argv[1];

		runProgram(n, test);
	}
	else printHelpMessage();

	return 0;
}

void fib(int n){
	if(n < 0 || n > 40){
		std::cout << "Valid ranges for the Fibonacci[n] parameter are:0 to 40" << std::endl;
		return;
	}

	if(n == 0){
		std::cout << "0" << std::endl;
		return;
	}

	if(n == 1){
		std::cout << "1" << std::endl;
		return;
	}

	int prev = 0;
	int curr = 1;
	int sum = 0;

	for(int i = 2; i <= n; i++){
		sum = prev + curr;
		prev = curr;
		curr = sum;
	}
	std::cout << sum << std::endl;
}

void runProgram(int n, std::string test){
	if(test == "fib") fib(n);
	else if(test == "e") e(n);
	else if(test == "pi") pi(n);
	else{
		printHelpMessage();
	}
}

void printHelpMessage(){
	std::cout << "--- Assign 1 Help ---" << std::endl;
	std::cout << " -fib [n] : Compute the fibonacci of [n]" << std::endl;
	std::cout << " -e [n] : Compute the value of 'e' using [n] iterations" << std::endl;
	std::cout << " -pi [n] : Compute Pi to [n] digits" << std::endl;
}

//Found with help from www.geeksforgeeks.org
void e(int n){
	if(n < 1 || n > 30){
		std::cout << "Valid ranges for the 'e'[n] parameter are: 1 to 30" << std::endl;
		return;
	}

	double sum = 1.0;
	double x = 1.0;

	for(int i = n-1; i > 0; --i)
		sum = 1 + x * sum/i;

	std::cout << sum << std::endl;
}

void pi(int n){
	if(n < 1 || n > 10){
		std::cout << "Valid ranges for the 'pi'[n] parameter are: 1 to 10" << std::endl;
		return;
	}

	double pie = 0.0;

	for(int i = 0; i < 2500000; i++){
		pie += 4*(pow(-1, i) / (2.0 * i + 1));
	}

	std::cout << std::setprecision(n+1) << pie << std::endl;
}
