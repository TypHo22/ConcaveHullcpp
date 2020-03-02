#ifndef CONCAVEALGORITHM_H
#define CONCAVEALGORITHM_H

#include<memory>
#include<vector>
#include<algorithm>
#include<math.h>
#include<point.h>

template<typename T>
void concave(std::vector<Point<T>>& pointVec,int kNearest, std::vector<int>& p)
{
    pointVec.erase(pointVec.begin() + 4);
   Point<T>* startPoint  = &pointVec[0];
    p.erase(p.begin()+4);
   int b = 0;
   for (unsigned int a = 0; a < pointVec.size(); a++)
   {
        if(startPoint->getY() > pointVec[a].getY())
        {
            startPoint = &pointVec[a];
            b = a;
        }
   }

   Point<T> botPoint = *startPoint; //bottompoint with the least Y-Value

   pointVec.erase(pointVec.begin() + 4);////////////probleme// nimm startPoint  heraus und mach irgendwo als const. loescht immer nur letztes element




   std::vector<double>distVec;
   calcDist(distVec,pointVec,botPoint);

}
template <typename T>
void calcDist(std::vector<double>&distVec,std::vector<Point<T>>&pointVec,Point<T> &botPoint)
{
    for(unsigned int a = 0; a < pointVec.size();a++)
    {
        distVec.push_back(botPoint.calcDist(pointVec[a]));
    }
}

#endif // CONCAVEALGORITHM_H
