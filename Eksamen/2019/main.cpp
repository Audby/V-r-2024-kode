#include "std_lib_facilities.h"
#include "Regresjon.h"
#include "RingBuf.h"


int main() {

    vector<double> x;
    vector<double> y;
    read_csv("data.csv", x, y);
    auto p = linreg(x, y);
    vector<double> y_pred = linpred(x, p.first, p.second);
    double r_2 = r2(y, y_pred);
    cout << p.first << " " << p.second << " " << r_2 << " " << endl;

    return 0;
}
