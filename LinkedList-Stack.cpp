#include <iostream>

using namespace std;
class Link{
    public:
        int Data;// Data Items
        Link* pNext;// Pointer to the next Link in the linked list

        //Link();
        void InitLink(int id); //initializes function to class attribute
        void DisplayLink(); // Display value of items
};

//Initializes function to class attribute
void Link::InitLink(int data){
    Data = data;
    pNext = NULL;
};

void Link::DisplayLink(){
    cout << Data << " " << pNext << endl;
};

class LinkList{
    Link* pFirst; // Pointer to first Link in the list
    public:
        void InitLinkList();
        bool IsEmpty();
        void InsertFirst(int data); // Insert at the beginning of the list
        void RemoveFirst();
        void PrintFirst();
        void DeleteLinkFirst();

};

void LinkList::InitLinkList(){
    pFirst = NULL;
    cout << "Linked List Initialized" << endl;
};

void LinkList::InsertFirst(int data){

    //Allocate space in memory for new link
    Link* NewLink = new Link; //Make new link
    NewLink->InitLink(data); // Set Value of Link::Data to data


    NewLink->pNext = pFirst;//newLink --> old first
    pFirst = NewLink;//first --> newLink
    cout << "Inserted " << data << " at " << pFirst << endl;
};

void LinkList::RemoveFirst(){
    Link* pTemp = pFirst; //save first - temporary link
    pFirst = pFirst->pNext; //unlink it: first --> old next
    delete pTemp;//delete old first
};

void LinkList::PrintFirst(){
    cout << LinkList::pFirst -> Data << " " << LinkList::pFirst -> pNext << endl;
};

void LinkList::DeleteLinkFirst(){
    Link* pTemp = pFirst;
    pFirst = pFirst->pNext;
    delete pTemp;
};

bool LinkList::IsEmpty(){
    return pFirst == NULL;
};


int main(){

    Link L1;
    L1.InitLink(10);
    L1.DisplayLink();

    Link L2;
    L2.InitLink(20);
    L2.DisplayLink();

    L1.pNext = &L2;
    L1.DisplayLink();

    LinkList MyLinkList;
    // MyLinkList.pFirst = &L1; Can't insert directly to the pFirst pointer because private
    MyLinkList.InitLinkList();
    MyLinkList.InsertFirst(10);
    MyLinkList.InsertFirst(20);
    MyLinkList.InsertFirst(5);

    cout << "=========" << endl;
    MyLinkList.PrintFirst();
    MyLinkList.RemoveFirst();
    cout <<"=========" << endl;
    MyLinkList.PrintFirst();

    MyLinkList.DeleteLinkFirst();
    cout <<"=========" << endl;
    MyLinkList.PrintFirst();

    MyLinkList.DeleteLinkFirst();
    cout <<"=========" << endl;
    MyLinkList.PrintFirst();
    MyLinkList.DeleteLinkFirst();
    cout <<"=========" << endl;

    return 0;
}