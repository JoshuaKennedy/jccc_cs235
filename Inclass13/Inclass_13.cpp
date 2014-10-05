// CIS 235 Linked List Exercise

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#include <ctime>

struct node
{
    int data;
    
    node * p;
};

void addFront(node* & start, int);
void print(ostream & , node *);
void cleanUp(node*);
ostream& operator<<(ostream&, const node*);
void build(node*&, int numberNodes, int lowValue, int highValue);
int countNodes(const node*); // Student Written
bool isEmpty(const node*); // Student Written
int sumOfAllNodes(const node*); // Student Written
int valueOfLastNode(const node*); // Student Written
const node* addressOfLastNode(const node*); // Student Written

int main()
{
    node* a = NULL;

    node* b = NULL;

    node* c = NULL;
    
    cout << "number of nodes in a to start is " << countNodes(a) << " is empty " << isEmpty(a) << endl;

    addFront(a,40);
    addFront(b,45);
    addFront(a,30);
    addFront(b,35);
    addFront(a,50);
    addFront(b,55);
    addFront(a,10);
    addFront(b,15);
    addFront(a,60);
    addFront(b,65);
    addFront(b,75);
    addFront(b,85);
    
    cout << "The Linked List a is " << a << endl;

    cout << "number of nodes in a is " << countNodes(a) << " is empty " << isEmpty(a) << endl;
    
    cout << "sum of all nodes in a is " << sumOfAllNodes(a) << endl;
    
    cout << "value of last node in a is " << valueOfLastNode(a) << endl;
    
    cout << "address of last node in a is " << static_cast< const void *>(addressOfLastNode(a)) << endl;
    
    cout << "The Linked List b is " << b << endl;

    cout << "number of nodes in b is " << countNodes(b) << " is empty " << isEmpty(b) << endl;
    
    cout << "sum of all nodes in b is " << sumOfAllNodes(b) << endl;
    
    cout << "value of last node in b is is " << valueOfLastNode(b) << endl;

    cout << "address of last node in b is " << static_cast< const void *>(addressOfLastNode(b)) << endl;
    
    build(c,6,50,100);
    
    
    
    cout << "The Linked List c is " << c << endl;
    
    cout << "number of nodes in c is " << countNodes(c) << " is empty " << isEmpty(c) << endl;

    cout << "sum of all nodes in c is " << sumOfAllNodes(c) << endl;

    cout << "value of last node in c is is " << valueOfLastNode(c) << endl;

    cout << "address of last node in c is " << static_cast< const void *>(addressOfLastNode(c)) << endl;
    
    cleanUp(a);
    cleanUp(b);
    cleanUp(c);
    
    return 0;
}

int countNodes(const node* p)
{
    int x = 0;
    
    const node* walker = p;
    
    while(walker != nullptr)
    {
        x++;
        
        walker = walker->p;
    }

    return x;
}


int sumOfAllNodes(const node* p)
{
    const node* walker = p;
    
    int x = 0;
    
    while(walker!=nullptr)
    {
        x += (*walker).data;
        
        
        
        walker= walker->p;
    }
    
    return x;
}

bool isEmpty(const node* p)
{
    return (p == nullptr);
}

int valueOfLastNode(const node* p)
{
    const node* walker = p;
    
    while(walker->p == nullptr)
    {
        walker = walker->p;
    }

    return walker->data;
}

const node* addressOfLastNode(const node* p)
{
    const node* walker = p;
    
    while(walker->p == nullptr)
    {
        walker = walker->p;
    }
    
    return walker;
}

void addFront(node*& start, int x)
{
    node* t = new node;
    
    t->data = x;
    
    if(start != NULL) // NOT NECESSARY
        t->p = start;
    else
        t->p = NULL;
    
    start = t;
}

void print(ostream& w, node* s)
{
    node* walker = s;

    while (walker != NULL)
    {
        w << walker->data << ' ';
        
        walker = walker->p;
    }
    
    w << endl;
}

void cleanUp(node* s)
{
    node* walker, *prev;

    walker = s;
    
    while (walker != NULL)
    {
        prev = walker;

        walker = walker->p;
        
        delete prev;
    }
}

ostream& operator<<(ostream & w, const node * s)
{
    if ( s==NULL)
    {
        w << "EMPTY LIST\n";
        
        return w;
    }
    
    const node* walker = s;
    int ct = 0;
    
    while (walker != NULL)
    {
        w << walker->data << ' ';
        
        walker = walker->p;
        
        ct++;
        
        if (ct % 10 == 0) cout << endl;
    }
    
    return w;
}

void build( node * & a, int numberNodes, int lowValue, int highValue )
{
    int valueToAdd;
    
    srand((unsigned int)time(0));
    
    int range = highValue - lowValue + 1;
    
    for(int i = 0; i < numberNodes; i++)
    {
        valueToAdd = rand() % range + lowValue;
        
        addFront(a, valueToAdd);
    }
}
