// Jake Ferner

// Add a list of numbers to an array then heapify
// Initial Example:
// 100 | 5 | 10 | 15
// a[1] is the parent
// a[2], a[3] are children
// we know that this satisfies the essentially full
//    requirement because of the way we are
//    constructing it.
// we will need to prove parental dominance

#include <iostream>
using namespace std;

void swap(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *ar, int size)
{
   for(int i = 1; i<=size; i++)
      cout << ar[i] << " ";
   cout << endl;
}

void heapify(int *ar, int size )
{
  // right now we only have one parent to worry about
  // we will need to adjust this eventually
  // test if root is bigger than left and right child
  int p = 1;

  cout << "Original Array" << endl;
  display(ar, size);
  cout << "\nsize = " << size;

  int i = size / 2;
  p = i;
  while (i > 0) { // iterate through each node
  // for (int i = size / 2; i > 0; i --) {
    cout << "p   = "  << p;
      // if there is a left child and (there is no right child or
      //  the left child is greater than the right child)
    if (2 * p <= size && (p * 2 + 1 > size || ar[2*p] > ar[2*p+1])) {
      cout << "Check Left Child" << endl;
      if (ar[2*p] > ar[p])
        {
          cout << "\tLeft Child Violation " << ar[2*p] << " > " << ar[p] << endl;
          swap(ar[p], ar[2*p]);
          p = 2 * p;
        }

      else { // decrement i and reset p
        i --;
        p = i;
       }
    }

      // if there is a right child
    else if (2 * p + 1 <= size) {
      cout << "\n\nCheck Right Child" << endl;
      if (ar[2*p+1] > ar[p])
        {
          cout << "\tRight Child Violation " << ar[2*p+1] << " > " << ar[p] << endl;
          swap(ar[p], ar[2*p+1]);
          p = 2 * p + 1;
        }
      else {
        i --;
        p = i;
       }

    }
    else {
      i --;
      p = i;
     }
  display(ar, size);

  }
  cout << "\n\nThis should be a heap with 15, 5 and 10" << endl;
  display(ar, size);

}

// new sort functionf
void HeapSort(int *ar, int size )
{
  // right now we only have one parent to worry about
  // we will need to adjust this eventually
  // test if root is bigger than left and right child
  int p = 1;

  heapify(ar, size);

  cout << "Original Array" << endl;
  display(ar, size);
  cout << "\nsize = " << size;


  while (size > 1) {
    p = 1;
    swap(ar[p], ar[size]);
    size --;
    while (2 * p <= size) {

      cout << "p   = "  << p;
        // if there is a left child and (there is no right child or
        //  the left child is greater than the right child)
      if (2 * p <= size && (p * 2 + 1 > size || ar[2*p] > ar[2*p+1])) {
        cout << "Check Left Child" << endl;
        if (ar[2*p] > ar[p])
          {
            cout << "\tLeft Child Violation " << ar[2*p] << " > " << ar[p] << endl;
            swap(ar[p], ar[2*p]);
            p = 2 * p;
          }

        else {
          
          break;
          }
      }

        // if there is a right child
      else if (2 * p + 1 <= size) {
        cout << "\n\nCheck Right Child" << endl;
        if (ar[2*p+1] > ar[p])
          {
            cout << "\tRight Child Violation " << ar[2*p+1] << " > " << ar[p] << endl;
            swap(ar[p], ar[2*p+1]);
            p = 2 * p + 1;
          }
        else {
          break;
          }

      }
      else {
        break;
        }
      display(ar, size);
      }
  }
  cout << "\n\nThis should be a heap with 15, 5 and 10" << endl;
  display(ar, size);

}
int main()
{

  // getting user to enter the array
  int n;
  cout << "Enter size of array: ";
  cin >> n;
  int a[n+1];
  
  int p = n/2;
  cout << "Enter numbers for array" << endl;
  for (int i = 1; i <= n; i ++){
    cin >> a[i];
  }

  // int a[] = {100, 5, 15, 10, 33, 7, 16, 24, 15, 37, 2, 25, 38, 5, 16, 11};
  // heapify(a, n);
  HeapSort(a, n); // implementation of the heap sort function

  cout << "\n\n\nBack in Main, this should be a heap" << endl;
  display(a, n);

   return 0;
}
