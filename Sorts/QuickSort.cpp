#include <bits/stdc++.h>
using namespace std;

void QuickSort(int s, int e, vector<int> &V)
{
    if (s >= e)
        return;
    if (e - s == 1)
    {
        if (V[e] > V[s])
            swap(V[e], V[s]);
        return;
    }
    int pivot = V[e];
    int i = e - 1, j = s;
    while (j < i)
    {
        if (V[i] <= pivot)
        {
            i--;
        }
        else if (V[j] >= pivot)
        {
            j++;
        }
        else
        {
            swap(V[i], V[j]);
        }
        for (auto i : V)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    i++;
    swap(V[i], V[pivot]);
    for (auto i : V)
    {
        cout << i << " ";
    }
    cout << endl;
    if (i > 0)
        QuickSort(s, i - 1, V);
    if (i < V.size())
        QuickSort(s, (i + 2), V);
}

int main()
{
    vector<int> V = {10, 80, 30, 90, 40, 50, 70};
    QuickSort(0, 6, V);
    for (auto i : V)
    {
        cout << i << " ";
    }
    cout << endl;
}