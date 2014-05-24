//�O�p�`�̌v�Z

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
		cout << "��=";
		cin >> arga;
		cout << "��=";
		cin >> argb;
		cout << "��=";
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
				cout << "����ł͋��߂��܂���";
			}
			oneline();
		}
		else
		{
			cout << "����ł͋��߂��܂���\n";
		}
		cout << "�I���Ȃ炑�������Ă�������";
		cin >> choice;
	}//end while

	cout << "�I�����܂�\n";
	return 0;
}

//�I����ʍ쐬
void showSelection()
{
	cout << "\n";
	cout << "�O�p�`�̌v�Z\n";
	cout << "�ӂ̒l�Ɗp�x����͂��Ă��������B\n";
	cout << "���߂����l�̂Ƃ����0����͂��Ă��������B\n";
	cout << "\n";
}

//3�ӂ̒l
void threeline()
{
	arga = (double)acos((b * b + c * c - a * a) / (2 * b * c)) * RadToDec;
	argb = (double)acos((c * c + a * a - b * b) / (2 * c * a)) * RadToDec;
	argc = (double)acos((a * a + b * b - c * c) / (2 * a * b)) * RadToDec;

	cout << "3�p�̑傫���̓�=" << arga << ",��=" << argb << ",��=" << argc << "�ł��B\n";

}

void twoline()
{
	if (arga != 0){
		rada = arga * DecToRad;
		a = (double)sqrt(c * c + b * b - 2 * c * b * cosf(rada));
		argc = (double)asin(c * sinf(rada) / a) * RadToDec;
		argb = (double)asin(b * sinf(rada) / a) * RadToDec;

		cout << "�c��̕ӂ̒�����a=" << a << ",�p�̓�=" << argb << ",��=" << argc << "�ł��B\n";
	}
	else if (argb != 0){
		radb = argb*DecToRad;
		b = (double)sqrt(a * a + c * c - 2 * a * c * cosf(radb));
		arga = (double)asin(a * sinf(radb) / b) * RadToDec;
		argc = (double)asin(c * sinf(radb) / b) * RadToDec;

		cout << "�c��̕ӂ̒�����b=" << b << ",�p�̓�=" << arga << ",��=" << argc << "�ł��B\n";
	}
	else{
		radc = argc*DecToRad;
		c = (double)sqrt(a * a + b * b - 2 * a * b * cosf(radc));
		arga = (double)asin(a * sinf(radc) / c) * RadToDec;
		argb = (double)asin(b * sinf(radc) / c) * RadToDec;
		cout << "�c��̕ӂ̒�����c=" << c << ",�p�̓�=" << arga << ",��=" << argb << "�ł��B\n";

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

			cout << "�c��̊p�̑傫���̓�=" << arga << ",�ӂ̒�����b=" << b << ",c=" << c << "�ł��B\n";
		}
		else if (b != 0){
			a = b * sinf(radb) / sinf(rada);
			c = b * sinf(radc) / sinf(rada);

			cout << "�c��̊p�̑傫���̓�=" << arga << ",�ӂ̒�����a=" << a << ",c=" << c << "�ł��B\n";
		}
		else{
			a = c * sinf(radb) / sinf(rada);
			b = c * sinf(radc) / sinf(rada);

			cout << "�c��̊p�̑傫���̓�=" << arga << ",�ӂ̒�����a=" << a << ",b=" << b << "�ł��B\n";
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

			cout << "�c��̊p�̑傫���̓�=" << argb << ",�ӂ̒�����b=" << b << ",c=" << c << "�ł��B\n";
		}
		else if (b != 0){
			a = b * sinf(radb) / sinf(rada);
			c = b * sinf(radc) / sinf(rada);

			cout << "�c��̊p�̑傫���̓�=" << argb << ",�ӂ̒�����a=" << a << ",c=" << c << "�ł��B\n";
		}
		else{
			a = c * sinf(radb) / sinf(rada);
			b = c * sinf(radc) / sinf(rada);

			cout << "�c��̊p�̑傫���̓�=" << argb << ",�ӂ̒�����a=" << a << ",b=" << b << "�ł��B\n";
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

			cout << "�c��̊p�̑傫���̓�=" << argc << ",�ӂ̒�����b=" << b << ",c=" << c << "�ł��B\n";
		}
		else if (b != 0){
			a = b * sinf(radb) / sinf(rada);
			c = b * sinf(radc) / sinf(rada);

			cout << "�c��̊p�̑傫���̓�=" << argc << ",�ӂ̒�����a=" << a << ",c=" << c << "�ł��B\n";
		}
		else{
			a = c * sinf(radb) / sinf(rada);
			b = c * sinf(radc) / sinf(rada);

			cout << "�c��̊p�̑傫���̓�=" << argc << ",�ӂ̒�����a=" << a << ",b=" << b << "�ł��B\n";
		}
	}
}