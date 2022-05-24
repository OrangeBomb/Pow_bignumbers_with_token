#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


#define MAX 100000

int multiply(int x, int res[], int res_size) {

	int carry = 0;

	for (int i = 0; i < res_size; i++) {
		int prod = res[i] * x + carry;

		res[i] = prod % 10;

		carry = prod / 10;
	}


	while (carry) {
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}


void power(int x, int n, string& strP)
{

	if (n == 0) {
        strP = "1";
		
	}

	int res[MAX];
	int res_size = 0;
	int temp = x;//2

	while (temp != 0) {
		res[res_size++] = temp % 10;
		temp = temp / 10;
	}


	for (int i = 2; i <= n; i++)
		res_size = multiply(x, res, res_size);

	for (int i = res_size - 1; i >= 0; i--)
		strP.push_back(res[i]+48);

}

int main() {
	int exponent;
	cin >> exponent;
	int base = 2;
	string str;
	power(base, exponent, str);
	cout << str;
    bool ind = false;

    setlocale(LC_ALL, "ru");
    srand(time(0));


    string token = str;
    int cont = 0;

    for (int i = 0; i < str.size(); i++) {
        if (i == 0) {
            int buf = token[0];
            token[i] = (((token[i] - 48) * (rand() % 1000)) % 10) + 48;
            if (token[0] > buf) {
                token[0] = buf;
            }
        }
        else {
            token[i] = (((token[i] - 48) * (rand() % 1000)) % 10) + 48;
        }

    }
    if (str.size() > 7) {
        for (int i = 0; i < str.size() / 7; i++) {
            for (int j = rand() % 7; j < 7; j++) {
                token[cont] = 48;
                cont++;
            }
        }
    }
    else {
        for (int i = 0; i < str.size(); i++) {
            if (rand() % 2 == 0) {
                token[cont] = 48;
                cont++;
            }
        }
    }

    while (token[0] == 48)
    {
        if (token.size() == 1) {
            break;
        }
        token.erase(token.begin());
    }
    cout << endl << setw(20) << left << "token = " << token;


    ind = false;
    string decod = "0";
    clock_t start;
    start = clock();
    long double mils = 0;
    int min = 0;
    int hour = 0;

    while (true) {

        mils = (clock() - start) / (double)CLOCKS_PER_SEC;

        if (mils > 60) {
            min++;
            mils = 0;
        }
        if (min == 60) {
            hour++;
            min = 0;
        }

        if (decod == token) {
            cout << "\n\n БЕРГАМОТА ПОЛНЫЙ РОТ оно закончило!!!!" << endl;
            break;
        }

        for (int j = decod.size() - 1; j >= 0; j--) {

            if (j == 0 && decod[j] == 57) {
                decod[j] = 48;
                decod.insert(decod.begin(), 49);
                break;
            }
            else {
                decod[j] = ((decod[j] + 1) % 48 % 10) + 48;
                if (decod[j] != 48) {
                    break;
                }
            }

        }
    }
    cout << setw(10) << left << "\ndecode = " << decod << endl << "with time = "
        << hour << " hours "
        << min << " mins "
        << fixed << setprecision(10) << mils << " sec ";
}


