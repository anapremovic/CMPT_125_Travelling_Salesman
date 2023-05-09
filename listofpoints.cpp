// Ana Premovic
// 301452722
// apa109

#include "listofpoints.hpp"
#include <iostream>
using namespace std;


ListOfPoints::ListOfPoints() {
  // there is nothing that needs to be initialized
  cout << "default ListOfPoints constructor" << endl;
}

void ListOfPoints::addAfter(Point& newPt, int index) {
  // check that the give index is valid
  int length = m_points.size();
  if(length <= index) {
    cout << "Index out of range" << endl;
    // if invalid, DO NOTHING
    return;
  }

  m_points.insert(m_points.begin()+index+1, newPt);
}

void ListOfPoints::addPoint(Point& newPt)  {
  m_points.push_back(newPt);
}

Point& ListOfPoints::getPointAt(unsigned int i) {
  return m_points[i];
}

int ListOfPoints::getSize() const {
  return m_points.size();
}

void ListOfPoints::printList() const {
  int length = m_points.size();
  for(int i=0; i < length; i++) {
    cout << m_points[i].getName() << " = (" << m_points[i].getX() << ", " << m_points[i].getY() << ")" << endl;
  }
}

void ListOfPoints::draw() const {
  // create and populate grid with default characters
  char arr[MAX_X][MAX_Y];
  
  for(int row = 0; row < MAX_X; row++) {
    for(int col = 0; col < MAX_Y; col++) {
      arr[row][col] = '-';
    }
  }

  // set points into the grid
  for (auto i = m_points.begin(); i != m_points.end(); ++i) {
    Point p = *i;
    int x = p.getX();
    int y = p.getY();
    if(x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y) {
      arr[x][MAX_Y-y-1] = p.getName()[0];
    }
  }

  // print grid
  for(int col = 0; col < MAX_Y; col++) {
    for(int row = 0; row < MAX_X; row++) {
      cout << arr[row][col] << " ";
    }
    cout << endl;
  }
}
 
