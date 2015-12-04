#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}


void test(int size) {
    cout << endl << "=======================================" << endl;
    cout << "Running '" << __func__ << "' with size <" << size << ">..." << endl;

	Hashtable H_l(size);
	Hashtable H_q(size);
	Hashtable H_d(size);

	int i;
	for (i = 0; i < (size/10)*9; i ++) {
		// Print stats per size/10
		if (i % (size/10) == 0 && i != 0) {
			cout << "---(" << i << "/" << size << ") at load factor " << (float)i/(float)size << "----------------" << endl;
			cout << "linear:    \t";
			H_l.printStats();
			cout << "quadratic: \t";
			H_q.printStats();
			cout << "doublehash:\t";
			H_d.printStats();
		}

		int next_num = rand() + 1;
		H_l.linsert(next_num);
		H_q.qinsert(next_num);
		H_d.dinsert(next_num);
	}
	
	cout << "---(" << i << "/" << size << ") at load factor " << (float)i/(float)size << "----------------" << endl;
	cout << "linear:    \t";
	H_l.printStats();
	cout << "quadratic: \t";
	H_q.printStats();
	cout << "doublehash:\t";
	H_d.printStats();
	
}

int main(int argc, char *argv[]) {
	int n, m;
	srand(time(0));

	if (argc == 1) {
		cout << "Running your test code..." << endl;
		/* ADD YOUR TEST CODE HERE */
		test(10000);
		test(1000000);
		return 0;
	}
	
	if (argc != 4) {
		usage(argv);
	}
	n = atoi(argv[2]);
	m = atoi(argv[3]);
	Hashtable H(m);
	
	switch(argv[1][0]) {
	case 'l':
		for (int i=0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		//    H.print();
		cout << "Linear: ";  
		H.printStats();
		break;
	case 'q':
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		//    H.print();
		cout << "Quadratic: ";
		H.printStats();
		break;
	case 'd':
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1);
		}
		//    H.print();
		cout << "Double Hashing: "; 
		H.printStats();
		break;
	default:
		usage(argv);
	}
}

