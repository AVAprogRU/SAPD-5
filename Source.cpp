#include <iostream>
#include <vector>

using namespace std;
void found(vector<int>& a, int n) {
	int q, k;
	cout << "Поиск элемента.\nЧтобы искать по порядковой позиции введите 1.\nЧтобы искать по содержимому нажмите 2\n";
	cin >> q;
	if (q == 1) {
		cout << "Введите порядковую позицию : ";
		cin >> k;
		if (k > n - 1) {
			cout << "Выход за границу\n";
			return;
		}
		cout << "Порядковая позиция : " << k << " значение : " << a[k] << endl;
		return;
	}
	else if (q == 2) {
		cout << "Введите значение : ";
		cin >> k;
		for (int i = 0; i < n; i++) {
			if (a[i] == k) {
				cout << "Порядковая позиция : " << i << " значение : " << k << endl;
				return;
			}
		}
		cout << "Элемент не найден.\n";
	}
	else {
		cout << "Error\n";
		return;
	}
}
void show(vector<int>& a) {
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
}
void foundu(vector<int>& a) {
	int f = 0;
	int stec = a[0] - 1;
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] == a[i + 1] && a[i] != stec) {
			f++;
			stec = a[i];
			if (i == a.size() - 1)
				f++;
		}
	}
	cout << "Повтор : " << f << endl;
}
void sort(vector<int>& a, int n) {
	int min, x, per = 0, sr = 0;
	int indx;
	for (int i = 0; i < n - 1; i++) {
		indx = i;
		min = a[i];
		for (int j = i; j < n; j++) {
			sr++;
			if (a[j] < min) {
				min = a[j];
				indx = j;

			}
		}
		if (i != indx) {
			swap(a[i], a[indx]);
			per++;
		}
	}
	cout << "Сортировка закончена.\n";
	cout << "Cравнений : " << sr << endl << "Перестановок : " << per << endl;
}

void main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите количество элементов массива : ";
	int n;
	cin >> n;
	vector<int> a = {};
	for (int i = 0; i < n; i++) {
		int ar;
		cout << i + 1 << " элемент : ";
		cin >> ar;
		a.push_back(ar);
	}
	int k = 5;
	while (k != 0) {
		switch (k)
		{
		case 1: {
			found(a, a.size());
			break;
		}case 2: {
			cout << "Добавление элемента.\nВведите значение : ";
			int neww;
			cin >> neww;
			a.push_back(neww);
			sort(a, a.size());
			show(a);
			break;
		}case 3: {
			cout << "Удаление элемента.\nВведите порядковую позицию : ";
			int del;
			cin >> del;
			if (del > a.size() || del < 0) {
				cout << "Выход за границу\n";
				break;
			}
			a.erase(a.begin() + del);
			sort(a, a.size());
			show(a);
			break;
		}case 4: {
			cout << "Сортировка.\n";
			sort(a, a.size());
			break;
		}case 5: {
			cout << "Меню\n";
			cout << "1 - поиск\n";
			cout << "2 - Добавление элемента.\n";
			cout << "3 - Удаление элемента.\n";
			cout << "4 - Сортировка.\n";
			cout << "5 - Меню\n";
			cout << "0 - выход\n";
		}case 6: {
			show(a);
			break;
		}case 7: {
			sort(a, a.size());
			foundu(a);
			break;
		}
		}
		cout << "команда : ";
		cin >> k;
	}
}
