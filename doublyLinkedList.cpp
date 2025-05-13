#include <iostream>
using namespace std;

struct Node
{
  // deklarasi noMhs dan name untuk menapung data 
  int noMhs;
  string name;
  // dekalrasi pointer next dan pref untuk penunjukan data sebelum dan sesudah
  Node *next;
  Node * perv;
};

// Deklarasi poiter START dan pemberian nilai
Node *START;

// Deklarasi prosedur addNode
void addNode()
{
  //pembuatan node dan pemberian value untuk data noMhs dan name
  Node *newNode = new Node(); // step 1 Buat node baru
  cout << "\nEnter the roll number if the student : ";
  cin >> newNode->noMhs;
  cout<< "\nEnter the name of the student : ";
  cin >> newNode->name;
}

int main()
{
  
}