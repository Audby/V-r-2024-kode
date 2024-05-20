#include "Regresjon.h"


double sum(vector<double>& x) {
    int size = x.size();
    double sum=0;
    for (int i=0; i<size-1; i++) {
        sum += x[i];
    }
    return sum;
}

double mean(vector<double>& x) {
    return sum(x) / x.size();
}

void read_csv(string filename, vector<double>& x, vector<double>& y) {
    ifstream file{filename};
    if (!file) {
        throw runtime_error("Couldn't read file" + filename);
    }
    double xVal=0;
    double yVal=0;

    while(file >> xVal >> yVal) {
        x.push_back(xVal);
        y.push_back(yVal);
    }
}

pair<double, double> linreg(vector<double>& x, vector<double>& y) {
    double xBar = mean(x);
    double yBar = mean(y);
    double var = 0;
    double cov = 0;
    for (int i = 0; i<x.size(); i++) {
        var += (pow(x[i]-xBar,2));
    }    
    var = var/x.size();
    for (int i = 0; i< x.size(); i++) {
        cov += (x[i] - xBar) * (y[i]-yBar);
    }
    cov = cov / x.size();
    double a = cov / var;
    double b = yBar - a*xBar;
    return {a,b};
}

vector<double> linpred(vector<double>& x, double a, double b) {
    vector<double> yVec;

    for (int i = 0; i < x.size(); i++) {
        yVec.push_back(b + x[i]*a);
    }
    return yVec;
}

double r2(vector<double>& y, vector<double>& y_pred) {
    double teller=0;
    double nevner=0;
    double yBar = mean(y);
    for (int i = 0; i<y.size(); i++) {
        teller += pow(y[i]-y_pred[i], 2);
        nevner += pow(y[i]-yBar, 2);
    }
    double r2 = 1-(teller/nevner);
    return r2;
}

