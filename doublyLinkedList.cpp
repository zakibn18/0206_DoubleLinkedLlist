#include <iostream>
using namespace std;

struct Node
{
  // deklarasi noMhs dan name untuk menapung data
  int noMhs;
  string name;
  // dekalrasi pointer next dan pref untuk penunjukan data sebelum dan sesudah
  Node *next;
  Node *prev;
};

// Deklarasi poiter START dan pemberian nilai
Node *START;

// Deklarasi prosedur addNode
void addNode()
{
  // pembuatan node dan pemberian value untuk data noMhs dan name
  Node *newNode = new Node(); // step 1 Buat node baru
  cout << "\nEnter the roll number if the student : ";
  cin >> newNode->noMhs;
  cout << "\nEnter the name of the student : ";
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
    if (START != NULL)
    {
      START->prev = newNode;
    }

    // memberi nilai prev = null dan start = node baru
    newNode->prev = NULL; // step 5: make the new node point to null
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
    newNode->prev = previous;

    // Kondisi jika current tidak sama dengan NULL
    if (current != NULL)
    {
      current->prev = newNode;
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

  // node tobe deleted in the first node
  if (current = START)
  {
    START = START->next;
    if (START != NULL)
    {
      START->prev = NULL;
    }
  }
  else
  { // node to be deleted is not the first node
    previous->next = current->next;
    if (current->next != NULL)
    { // if there's a seccessor, update its prev pointer
      current->next->prev = previous;
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

// prosedur tarverse unutk menampilkan data secara urut
void traverse()
{
  if (listEmpty())
  {
    cout << "\nList is empty\n";
  }
  else
  {
    cout << "\nRecords in desecnding order of roll number are: \n"
         << endl;
    Node *currentNode = START;
    while (currentNode != NULL)
      currentNode = currentNode->next;

    while (currentNode != NULL)
    {
      cout << currentNode->noMhs << " " << currentNode->name << endl;
      currentNode = currentNode->prev;
    }
  }
}

void revtraverse()
{
    if (listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in descending order of roll number are:" << endl;
        Node *currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;

        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
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
  // perulangan selama bernilai benar untuk program utama double Linked List
  while (true)
  {
    try
    {
      cout << endl
           << "Menu";
      cout << endl
           << "1. Menambah data kedalam list" << endl;
      cout << "2. Menghapus data dari dalam list" << endl;
      cout << "3. Menampilkan semua data didalam list meningkat" << endl;
      cout << "4. Menampilkan semua data didalam list menurun" << endl;
      cout << "5. Mencari data dalam list" << endl;
      cout << "6. keluar" << endl;
      cout << endl
           << "Masukkan pilihan (1-6) : ";
      char ch;
      cin >> ch;

      switch (ch)
      {
      case '1':
        addNode();
        break;
      case '2':
        deleteNode();
        break;
      case '3':
        traverse();
        break;
      case '4':
        revtraverse();
        break;
      case '5':
        searchData();
        break;
      case '6':
        return 0;
      default:
        cout << "\nInvalid option" << endl;
        break;
      }
    }
    catch (exception &e)
    {
      cout << "Check for the values entered." << endl;
    }
  }
}