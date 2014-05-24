//三角形の計算

#include <iostream>
#include <math.h>
#define RadToDec 57.29577951f;
#define DecToRad 0.017453293f;
using namespace std;

void showSelection();
void threeline();
void twoline();
void oneline();

double a;
double b;
double c;
double arga;
double argb;
double argc;
double rada;
double radb;
double radc;

int main()
{
	char choice=0;

	showSelection();

	while (choice != 'q')
	{
		cout << "a=";
		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "c=";
		cin >> c;
		cout << "α=";
		cin >> arga;
		cout << "β=";
		cin >> argb;
		cout << "γ=";
		cin >> argc;

		if (a != 0){
			if (b != 0){
				if (c != 0)
					threeline();
				else
					twoline();
			}
			else if (c != 0)
				twoline();
			else
				oneline();
		}
		else if (b != 0){
			if (c != 0)
				twoline();
			else
				oneline();
		}
		else if(c!=0){
			if (arga == 0 && argb == 0 || arga == 0 && argc == 0 || argb == 0 && argc == 0){
				cout << "それでは求められません";
			}
			oneline();
		}
		else
		{
			cout << "それでは求められません\n";
		}
		cout << "終わるならｑを押してください";
		cin >> choice;
	}//end while

	cout << "終了します\n";
	return 0;
}

//選択画面作成
void showSelection()
{
	cout << "\n";
	cout << "三角形の計算\n";
	cout << "辺の値と角度を入力してください。\n";
	cout << "求めたい値のところは0を入力してください。\n";
	cout << "\n";
}

//3辺の値
void threeline()
{
	arga = (double)acos((b * b + c * c - a * a) / (2 * b * c)) * RadToDec;
	argb = (double)acos((c * c + a * a - b * b) / (2 * c * a)) * RadToDec;
	argc = (double)acos((a * a + b * b - c * c) / (2 * a * b)) * RadToDec;

	cout << "3角の大きさはα=" << arga << ",β=" << argb << ",γ=" << argc << "です。\n";

}

void twoline()
{
	if (arga != 0){
		rada = arga * DecToRad;
		a = (double)sqrt(c * c + b * b - 2 * c * b * cosf(rada));
		argc = (double)asin(c * sinf(rada) / a) * RadToDec;
		argb = (double)asin(b * sinf(rada) / a) * RadToDec;

		cout << "残りの辺の長さはa=" << a << ",角はβ=" << argb << ",γ=" << argc << "です。\n";
	}
	else if (argb != 0){
		radb = argb*DecToRad;
		b = (double)sqrt(a * a + c * c - 2 * a * c * cosf(radb));
		arga = (double)asin(a * sinf(radb) / b) * RadToDec;
		argc = (double)asin(c * sinf(radb) / b) * RadToDec;

		cout << "残りの辺の長さはb=" << b << ",角はα=" << arga << ",γ=" << argc << "です。\n";
	}
	else{
		radc = argc*DecToRad;
		c = (double)sqrt(a * a + b * b - 2 * a * b * cosf(radc));
		arga = (double)asin(a * sinf(radc) / c) * RadToDec;
		argb = (double)asin(b * sinf(radc) / c) * RadToDec;
		cout << "残りの辺の長さはc=" << c << ",角はα=" << arga << ",β=" << argb << "です。\n";

	}

}

void oneline()
{

	if (arga == 0){
		arga = 180 - argb - argc;
		rada = arga *  DecToRad;
		radb = argb *  DecToRad;
		radc = argc *  DecToRad;
		if (a != 0){
			b = a * sinf(radb) / sinf(rada);
			c = a * sinf(radc) / sinf(rada);

			cout << "残りの角の大きさはα=" << arga << ",辺の長さはb=" << b << ",c=" << c << "です。\n";
		}
		else if (b != 0){
			a = b * sinf(radb) / sinf(rada);
			c = b * sinf(radc) / sinf(rada);

			cout << "残りの角の大きさはα=" << arga << ",辺の長さはa=" << a << ",c=" << c << "です。\n";
		}
		else{
			a = c * sinf(radb) / sinf(rada);
			b = c * sinf(radc) / sinf(rada);

			cout << "残りの角の大きさはα=" << arga << ",辺の長さはa=" << a << ",b=" << b << "です。\n";
		}
	}
	else if (argb == 0){
		argb = 180 - arga - argc;
		rada = arga *  DecToRad;
		radb = argb *  DecToRad;
		radc = argc *  DecToRad;
		if (a != 0){
			b = a * sinf(radb) / sinf(rada);
			c = a * sinf(radc) / sinf(rada);

			cout << "残りの角の大きさはβ=" << argb << ",辺の長さはb=" << b << ",c=" << c << "です。\n";
		}
		else if (b != 0){
			a = b * sinf(radb) / sinf(rada);
			c = b * sinf(radc) / sinf(rada);

			cout << "残りの角の大きさはβ=" << argb << ",辺の長さはa=" << a << ",c=" << c << "です。\n";
		}
		else{
			a = c * sinf(radb) / sinf(rada);
			b = c * sinf(radc) / sinf(rada);

			cout << "残りの角の大きさはβ=" << argb << ",辺の長さはa=" << a << ",b=" << b << "です。\n";
		}
	}
	else{
		argc = 180 - arga - argb;
		rada = arga *  DecToRad;
		radb = argb *  DecToRad;
		radc = argc *  DecToRad;

		if (a != 0){
			b = a * sinf(radb) / sinf(rada);
			c = a * sinf(radc) / sinf(rada);

			cout << "残りの角の大きさはγ=" << argc << ",辺の長さはb=" << b << ",c=" << c << "です。\n";
		}
		else if (b != 0){
			a = b * sinf(radb) / sinf(rada);
			c = b * sinf(radc) / sinf(rada);

			cout << "残りの角の大きさはγ=" << argc << ",辺の長さはa=" << a << ",c=" << c << "です。\n";
		}
		else{
			a = c * sinf(radb) / sinf(rada);
			b = c * sinf(radc) / sinf(rada);

			cout << "残りの角の大きさはγ=" << argc << ",辺の長さはa=" << a << ",b=" << b << "です。\n";
		}
	}
}