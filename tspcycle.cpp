// Ana Premovic
// 301452722
// apa109

#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
  // implement me
  cout << "default TSPCycle constructor" << endl;
}

// returns the length of the cycle
float TSPCycle::getLength() const {
  int numPoints = this->getSize();
  float length = 0.0;

  for(int i = 1; i < numPoints; i++) {
    Point p1 = m_points[i];
    Point p2 = m_points[i-1];
    length += p1.getDistance(p2);
  }
  length += m_points[numPoints-1].getDistance(m_points[0]);

  return length;
}
