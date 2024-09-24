#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define DEBUG

void process_value(double current, 
                    double &count,
                    double &avg, 
                    double &avg2)
{
    //D(X) =  M(X^2) − ( M(X) )^2.
    double current2 = current * current;
    count += 1.0;
    avg = avg + (current-avg)/count;
    avg2 = avg2 + (current2-avg2)/count;
}

#ifdef DEBUG
bool test_disp()
{
    double count = 0;
    double avg = 0.0;
    double avg2 = 0.0;
    double arr[10] = {909.0, -7.0,  88.0,  33.0, 0.25, 
                     -110.0,  32.0, 43.2,  4.0,  765.3};
    for(auto d : arr )
    {
        process_value(d, count, avg, avg2);
    }
    double etalon = 112688.488625;
    double disp = avg2 - (avg * avg);
    if ( abs(disp - etalon) > 0.00001 )
    {
        cerr << std::setprecision (10) << "test failed d = " << disp 
             << " etalon = " << etalon 
             << " avg = " << avg 
             << " avg2 = " << avg2 << endl;
        return false;
    }
    return true;
}
#endif

int main(int argc, char ** argv)
{
#ifdef DEBUG
    if ( !test_disp() )
    {
        return 0;
    }
#endif
    double count = 0;
    double avg = 0.0;
    double avg2 = 0.0;
    double current;
    double current2;
    double disp = 0.0;
    string line;
    while (getline(cin, line))
    {
        try
        {
            //D(X) =  M(X^2) − ( M(X) )^2.
            current = stod(line);
            process_value(current, count, avg, avg2);
        }
        catch(...)
        {
            cerr << count << " wrong input " << line << endl;
        }
    }
    disp = avg2 - (avg * avg);
    cout << std::setprecision (10) << disp << endl;
    return 0;
}
