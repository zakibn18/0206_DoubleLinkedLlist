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

  // Insert the new Node in the list
  // kondisi jika start == null atau noMhs node baru <= noMhs start
  if (START == NULL || newNode->noMhs <= START->noMhs)
  {
    // kondisi jika start tidak kosong dan noMhs Node baru selama noMhs
    if (START != NULL && newNode->noMhs == START->noMhs)
    {
      cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
      return;
    }

    // Jika list kosong maka node next nya adalah START
    newNode->next = START;
    // kondisi jika start tidak memiliki nilai atau tidak kosong
    if ( START != NULL)
    {
      START->perv = newNode;
    }

    // memberi nilai prev = null dan start = node baru
    newNode->perv = NULL; // step 5: make the new node point to null 
    START = newNode;      // step 6: make teh new node the first node
  }

  // Kondisi jika semua kondisi if tidak terpenuhi
  else
  {
    // set nilai current = start dan nilai previous NULL
    Node *current = START;
    Node *previous = NULL;

    // Looping selema current != NULL da noMhs dari current lebih kecil dari node baru
    while (current != NULL && current->noMhs < newNode->noMhs)
    {
      previous = current;
      current = current->next;
    }

    // set Nilai next node baru = current dan prev node baru = previous
    newNode->next = current;
    newNode->perv = previous;

    // Kondisi jika current tidak sama dengan NULL
    if (current != NULL)
    {
      current->perv = newNode;
    }

    // Kondisi jika previous tidak sama dengan null 
    if (previous != NULL)
    {
      previous->next = newNode;
    }

   
  }
}



int main()
{
  
}