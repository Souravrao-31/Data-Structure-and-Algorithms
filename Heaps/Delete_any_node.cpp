/*
Delete any node from tree.
  100 30 40 20 10 22 25 5 7
  delete -3
  3=>20

  jis number ko delete krna h usko maximum(INT_MAX) se replace krnge
  kyuki heap tree mai top priority element hi delete hota h.
  to usko top mai le lr ayenge

  uphepify krnge
  inf 100 40 30 10 22 25 5 7

  swap(inf,(n-1))
  swap(inf,7)
  pop

  7 100 40 30 10 22 25 5
  down heapify
  100 30 40 7 10 22 25 5

  so here we just deleted the node we wanted.
  T(n) = O(log n)
*/

