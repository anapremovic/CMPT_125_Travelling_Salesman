// Ana Premovic
// 301452722
// apa109

#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  

  Point q(3,4,"Q");
  //distance should be 5
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;

}


// gets a list of points and runs the solver on this list
// used in test1 and test2 below
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  solver.solve();
  TSPCycle solution = solver.getSolution();


  cout << "Solution found is: " << endl;
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength() << endl;
}

void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    string s;
    s = 'A'+i;
    p = Point(i,0,s);
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<50;i++) {
    p = Point(rand() % 1000, rand() % 1000,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  // some coordinates values more than 20, so we do not use draw here

  testSolver(inputTSP);
}

void test4() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i = 0; i < 10; i++) {
    string s;
    s = 'A'+i;
    p = Point(i,i,s);
    inputTSP.addPoint(p);
  }

  for (int i = 0; i < 10; i++) {
    string s;
    s = 'A'+i+10;
    p = Point(10-i,10+i,s);
    inputTSP.addPoint(p);
  }
  
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test5() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i = 0 ; i < 26; i++) {
    string s;
    s = 'A'+i;
    p = Point(rand() % 20, rand() % 20, s);
    inputTSP.addPoint(p);
  }
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

// testing with only 3 points
void test6() {
  Point p[3] = {Point(1,2, "A"),
                Point(2,3, "B"),
                Point(3,4, "C")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for(int i = 0; i < 3; i++) {
    inputTSP.addPoint(p[i]);
  }

  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();

  testSolver(inputTSP);
}

void test7() {
  Point p[13] = {Point(4,4,"A"),
                 Point(4,7,"B"),
                 Point(4,9,"C"),
                 Point(4,11,"D"),
                 Point(6,11,"E"),
                 Point(8,11,"F"),
                 Point(10,11,"G"),
                 Point(10,9,"H"),
                 Point(10,7,"I"),
                 Point(10,5,"J"),
                 Point(8,5,"K"),
                 Point(6,5,"L"),
                 Point(4,5,"M")};
  
  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i = 0; i < 13; i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}



int main() {

  cout << "****Test point**" << endl;
  testPoint();
  cout << "****End of test point**" << endl << endl;

  cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;
 
  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;

  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test3**:" << endl << endl;

  cout << "****test4**:" << endl;
  test4();
  cout << "****end of test4**:" << endl << endl;

  cout << "****test5**:" << endl;
  test5();
  cout << "****end of test5**:" << endl << endl;

  cout << "****test6**:" << endl;
  test6();
  cout << "****end of test6**:" << endl << endl;

  cout << "****test7**:" << endl;
  test7();
  cout << "****end of test7**:" << endl << endl;

  return 0;
}
