
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    cout << "argc: " <<  argc << endl;

    cout << "argv: [" << endl;

    for (int i = 0; i < argc; i ++) {
        cout << "  " << argv[i] << "," << endl;
    }

    cout << "]" << endl;

    return 0;
}

// hello.cpp
