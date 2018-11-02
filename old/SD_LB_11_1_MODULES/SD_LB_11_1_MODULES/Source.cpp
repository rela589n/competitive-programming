
#include "inputWorkers.h"
#include "outputWorkers.h"
#include "longestWorkerIllness.h"

struct some {
	int some;
	int y;
};

int main() {

	int n;
	worker_illness workers[100];


start:	cout << "Enter number of workers: ";
	cin >> n;
	form(workers, n);
	output(workers, n);

	scrollDown(3);


info:
	cout << "what you want to see?\n\t" <<
	"(1) - info about worker with longest ill\n\t" <<
	"(2) - info about all workers with growth duration of ill\n\n" <<
	"make your choise: ";
		char choise;
		cin >> choise;
		if (choise == '1') {
			worker_illness *long_ill = new worker_illness[n];
			int long_ill_len;
			worker_longest_illness(workers, n, long_ill, long_ill_len);
			cout << "\nInfo about workers with longest duration of issue:\n\n";
			output(long_ill, long_ill_len);
			delete[] long_ill;
		}
		else if (choise == '2') {
			sortIllenssUp(workers, 0, n - 1);
			cout << "\nInfo about workers with growth duration of ill:\n\n";
			output(workers, n);
		}

		cout << "Do you want to see another information?\n(1) - yes;\n(0) - no;\n";
		cin >> choise;
		if (choise == '1')
			goto info;

		cout << "Do you want to process for another workers?\n(1) - yes;\n(0) - no;\n";
		cin >> choise;
		if (choise == '1') {
			system("cls");
			goto start;
		}
		system("pause");
		return 0;
}
