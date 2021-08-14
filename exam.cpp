#include <iostream>
struct Node
{
public:
    int a, b, value;
    Node *down, *right;
    Node() : down(nullptr), right(nullptr) {}
};
class DataStructure
{
public:
    DataStructure(int na, int nb);
    void insert(int i, int j, int data);
    void display();

private:
    Node *HEAD;
};
DataStructure ::DataStructure(int na, int nb)
{
    HEAD = new Node();
    HEAD->a = na;
    HEAD->b = nb;
    HEAD->value = 0;
    Node *prevNode = HEAD;
    for (int i = 1; i <= na; i++)
    {
        Node *node = new Node();
        node->a = i;
        prevNode->down = node;
        prevNode = node;
    }
}
void DataStructure ::insert(int i, int j, int data)
{
    if (data == 0)
    {
        return;
    }
    Node *node = new Node();
    node->a = i;
    node->b = j;
    node->value = data;
    Node *d = HEAD->down;
    while (d)
    {
        if (d->a == i)
        {
            Node *r = d;
            while (r->right)
            {
                if (r->right->b > j)
                {
                    node->right = r->right;
                    r->right = node;
                    HEAD->value++;
                    return;
                }
                r = r->right;
            }
            r->right = node;
            HEAD->value++;
            break;
        }
        d = d->down;
    }
}
void DataStructure ::display()
{
    Node *d = HEAD->down;
    while (d)
    {
        Node *r = d->right;
        int nb = 1;
        while (r)
        {
            for (; nb < r->b; nb++)
            {
                std ::cout << 0 << '\t';
            }
            std ::cout << r->value << '\t';
            r = r->right;
            nb++;
        }
        for (; nb <= HEAD->b; nb++)
        {
            std ::cout << 0 << '\t';
        }
        std ::cout << std ::endl;
        d = d->down;
    }
}
int main()
{
    int m = 2, n = 2;
    DataStructure matrix(m, n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std ::cout << " Enter ␣ the ␣ data ␣ a t ␣" << i << " , ␣" << j << "␣ : ␣";
            int data;
            std ::cin >> data;
            matrix.insert(i, j, data);
        }
    }
    matrix.display();
}