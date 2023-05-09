// Ana Premovic
// 301452722
// apa109

#include "tspsolver.hpp"

// list MUST have at least 3 points
TSPSolver::TSPSolver(ListOfPoints &list) {
  // implement me

  m_list = list;

  // add the first 3 points of m_list to m_solution
  for(int i = 0; i < 3; i++) {
    m_solution.addPoint(m_list.getPointAt(i));
  }

  cout << "parameterized TSPSolver constructor" << endl;
}

void TSPSolver::solve() {
  int solSize = m_solution.getSize(); // changes each iteration
  int listSize = m_list.getSize(); // stays the same

  // listInd refers to m_list
  // solInd refers to m_solution
  
  for(int listInd = solSize; listInd < listSize; listInd++) {
    
    int minIndex = 0;

    // minimize:
    float minDistance = m_solution.getPointAt(0).getDistance(m_list.getPointAt(listInd)) + 
                        m_solution.getPointAt(1).getDistance(m_list.getPointAt(listInd)) -
                        m_solution.getPointAt(1).getDistance(m_solution.getPointAt(0));

    for(int solInd = 1; solInd < solSize; solInd++) {
      int curIndex = solInd;
      float curDistance;

      // if we are on the last index, get the distance from the last point back to the first point
      if(solInd == solSize-1) {
        curDistance = m_solution.getPointAt(solInd).getDistance(m_list.getPointAt(listInd)) + 
                      m_solution.getPointAt(0).getDistance(m_list.getPointAt(listInd)) -
                      m_solution.getPointAt(0).getDistance(m_solution.getPointAt(solInd));
      }
      else {
        curDistance = m_solution.getPointAt(solInd).getDistance(m_list.getPointAt(listInd)) + 
                      m_solution.getPointAt(solInd+1).getDistance(m_list.getPointAt(listInd)) -
                      m_solution.getPointAt(solInd+1).getDistance(m_solution.getPointAt(solInd));
      }
      
      if(curDistance < minDistance) {
        // new index chosen
        minDistance = curDistance;
        minIndex = curIndex;
      }
    }

    // add where it increase the cycle length by the lowest amount
    m_solution.addAfter(m_list.getPointAt(listInd), minIndex);
    // update size
    solSize = m_solution.getSize();
  }
}

TSPCycle& TSPSolver::getSolution() {
  // implement me
  return m_solution;
}

