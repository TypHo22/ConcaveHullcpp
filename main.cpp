#include <QCoreApplication>


#include <vector>
#include <fstream>
#include <string>

#include <concaveAlgorithm.h>
#include <point.h>

using namespace std;
int main(int argc, char *argv[])
{

    std::vector<int> p = {0,1,2,3,4,5,6,7,8,9,10};
    ifstream file ( "myPoints.csv" );

    string value;
    string delim = ",";
    vector<Point<float>>myPoints;
    while (file.eof() == false)
    {
        getline ( file, value, ';' );
        size_t found = value.find(delim);
        string ff =  value.substr(0,found - 1);

        Point<float> aPoint(stof(value.substr(0,found - 1)),stof(value.substr(found + 1, value.size() -1)));
        myPoints.push_back(aPoint);
    }
    file.close();

    concave(myPoints,3,p);



    QCoreApplication a(argc, argv);
    return a.exec();
}
