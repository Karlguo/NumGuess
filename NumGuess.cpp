//first experiment 
//editer: sunflower

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


//decide whether to play this game 
int choose(){
	char YN('Y');
	cout << "Do you want to play(Y/N)?" << endl;
	cin >> YN;

	if (YN == 'N' || YN == 'n'){
		cout << "Bye!" << endl;
		return 0;
	}
	else {
		if (YN != 'Y' && YN != 'y'){
			cout << "Please input the correct value!" << endl;
			return 1;
		}
		else return 2;
	}
}



int run(int win, int lose){
	int input[3] = { -1, -1, -1 }, output[3] = { -1, -1, -1 },
		times(1), A, B, k(0), choice(1);

	srand(time(NULL));

	while (choice == 1)
		choice = choose();
	if (choice == 0){
		cout << "You have played" << win + lose << ", and win" << win << ", lose"
			<< lose << "!" << endl;
		return 0;
	}
	else {
		while (k <= 2){
			int random;
			bool T = true;
			random = rand() % 10;
			for (int i = 0; i <= k; ++i) {		//ensure the numbers are different 
				if (random == output[i]){
					T = false;
					break;
				}
			}
			if (T){
				output[k] = random;
				++k;
			}
		}
		while (times <= 7){
			A = 0;
			B = 0;
			cout << "Please input what you guess: " << endl;
			for (int i = 0; i <= 2; ++i){
				cin >> input[i];
				if (cin.fail()){
					cout << "the number you input is wrong! Please input again!" << endl;
					cin.sync();
					cin.clear();
					--i;
				}
			}
			for (int i = 0; i <= 2; ++i)
				if (output[i] == input[i])	++A;
			for (int i = 0; i <= 2; ++i)
				for (int j = 0; j <= 2; ++j)
					if (input[i] == output[j]) ++B;
			if (A == 3){
				cout << "Congratulations! You are right!" << endl;
				++win;
				break;
			}
			++times;
			cout << A << 'A' << B - A << 'B' << endl;
		}
		if (times == 8){
			cout << "I am sorry to tell you that you have not guess the right numbers within 7 times! The true number is: " <<
				output[0] << output[1] << output[2] << endl;
			++lose;
		}
		run(win, lose);
	}
}

int main(){
	int win(0), lose(0);			//to initialise the win and lose 
	run(win, lose);
	return 0;
}
