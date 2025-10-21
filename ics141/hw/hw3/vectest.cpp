#include "vector.h"

int main() // Here is a start:

{

        Vector<int> intVec{1,3,5,7,9};

        Vector<double> doubleVec{1.5,2.5,3.5,4.5};

        Vector<int> iv{intVec};

        Vector<double> dv{doubleVec};

        cout << "intVec" << intVec << endl;

// "intVec(1, 3, 5, 7, 9)"

        cout << "iv" << iv << endl;

// "iv(1, 3, 5, 7, 9)"

        cout << "doubleVec" << doubleVec << endl;

// "doubleVec(1.5, 2.5, 3.5, 4.5)"

cout << "dv" << dv << endl;


// "dv(1.5, 2.5, 3.5, 4.5)"


        // add at least one test case for each method defined in Vector
        20 + intVec;
        cout << intVec <<endl;

        30* intVec;
        cout << intVec <<endl;
        Vector<int> intVec2{1,3,5,9};
        bool x = (intVec == intVec2 );
        cout << "INTVEC " << intVec  << endl;
        cout << "INTVEC2" << intVec2 <<endl;
        intVec = intVec2  + intVec; 
        cout<< "ASSIGNED " << intVec<<endl;
        int element = intVec * intVec2;
        cout << "CHECKING INDEXING2 " << element <<endl;
        return 0;

}

