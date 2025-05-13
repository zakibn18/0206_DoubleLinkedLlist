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

    // Kondisi jika if previous null sama dengan null
    else
    {
      START = newNode;
    }
  }
}

// pembuatan fungtion search untuk mencari data
bool search(int rollNo, Node **previous, Node **current)
{
  *previous = NULL;
  *current = START;
  while (current != NULL && (*current)->noMhs != rollNo)
  {
    *previous = *current;
    *current = (*current)->next;
  }
  return (*current != NULL);
}

// penbuatan prosrdur delete untuk menghapus data
void deleteNode()
{
  Node *previous, *current;
  int rollNo;

  cout << "\nEnter the roll Number if the student whose record is to be deleted : ";
  cin >> rollNo; // step 3: get the roll number number to be deleted

  if (START == NULL)
  {
    cout << "list is empty" << endl;
    return;
  }

  current = START; // step 1: start from the first node
  previous = NULL;

  // located the node to be deleted
  while (current != NULL && current->noMhs != rollNo)
  {
    previous = current;
    current = current->next;
  }

  if (current == NULL)
  {
    cout << "\033[31mThe record with roll number " << rollNo << "not found\033[0m" << endl;
    return;
  }

  //node tobe deleted in the first node
  if (current = START)
  {
    START = START->next;
    if (START != NULL)
    {
      START->perv = NULL;
    }
  }
  else
  { //node to be deleted is not the first node
    previous->next = current->next;
    if (current->next != NULL)
    { // if there's a seccessor, update its prev pointer
      current->next->perv = previous;
    }
  }
  
  delete current;
  cout << "\x1b[32mRecord with roll number " << rollNo << "deleted\x1b[0m" << endl;
}

// method untuk mengecek apakah list kosong
bool listEmpty()
{
  return (START == NULL);
}

//prosedur tarverse unutk menampilkan data secara urut
void traverse()
{
  if (listEmpty())
  {
    cout << "\nList is empty\n";
  }
  else
  {
    cout << "\nRecords in desecnding order of roll number are: \n" << endl;
    Node *currentNode = START;
    while (currentNode != NULL)
      currentNode = currentNode->next;

    while (currentNode != NULL)
    {
      cout << currentNode->noMhs << " " << currentNode->name << endl;
      currentNode = currentNode->perv;
    }
  }
}


// prosedur unutuk mencari data dan menampilkan data yang dicari jika ada
void searchData()
{
  if (listEmpty() == true)
  {
    cout << "\nList is empty" << endl;
  }
  Node *prev, *curr;
  prev = curr = NULL;
  cout << "\nEnter the roll number of the student whose record you want to search :";
  int num;
  cin >> num;
  if (search(num, &prev, &curr) == false)
    cout << "\nRecord not found" << endl;
  else
  {
    cout << "\nRecord found" << endl;
    cout << "\nRoll Number" << endl;
    cout << "\nName" << curr->name << endl;
  }
}

int main()
{
  
}