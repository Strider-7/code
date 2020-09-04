#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int firstPetrolPump(vector<int> a, vector<int> b)
{
    int res = -1, n = a.size();

    for (int i = 0; i < n; i++)
    {
        int curr = 0, required = 0;
        int j = i;
        for (int j = 0; j < n; j++)
        {

            curr += a[(i + j) % n];
            required = b[(i + j) % n];
            // cout << j << " " << curr << " " << required << endl;
            curr -= required;
            if (curr < 0)
                break;
        }
        if (curr >= 0)
            return i + 1;
    }
    return res;
}

int firstPP(int petrol[], int dist[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        int j = i;
        while (true)
        {
            curr += petrol[j] - dist[j];
            if (curr < 0)
                break;
            j = (j + 1) % n;
            if (j == i)
                return i + 1;
        }
    }
    return -1;
}

int firstPetrolPump2(vector<int> a, vector<int> b)
{
    int res = -2, n = a.size();

    deque<int> dq;
    int i = 0, curr = 0;
    while (dq.size() < n)
    {
        curr += a[i] - b[i];
        dq.push_back(i);
        while (curr < 0 && !dq.empty())
        {
            int x = dq.front();
            dq.pop_front();
            curr += a[x] - b[x];
        }
        i = (i + 1) % n;
    }
    if (curr >= 0)
        res = dq.front();

    return res + 1;
}

// incorrect probably
int firstPetrolPump3(int petrol[], int dist[], int n)
{
    int start = 0, curr = 0, prev = 0;
    for (int i = 0; i < n; i++)
    {
        curr += petrol[i] - dist[i];
        if (curr < 0)
        {
            start = i + 1;
            prev = curr;
            curr = 0;
        }
    }
    return (curr + prev >= 0) ? start + 1 : -1;
}
// correct
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int start = 0;
    int tank = 0;
    int sum_gas = 0;
    int sum_cost = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        sum_gas += gas[i];
        sum_cost += cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0)
        {
            tank = 0;
            start = i + 1;
        }
    }
    if (sum_gas < sum_cost)
        return -1;
    return start;
}

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump arr[], int n)
{
    int start = 0;
    int end = 1;

    int curr_petrol = arr[start].petrol - arr[start].distance;

    while (end != start || curr_petrol < 0)
    {
        while (curr_petrol < 0 && start != end)
        {
            curr_petrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1) % n;
            if (start == 0)
                return -1;
        }
        curr_petrol += arr[end].petrol - arr[end].distance;

        end = (end + 1) % n;
    }
    return start;
}

int main()
{
    vector<int> a = {4, 6, 7, 4};
    vector<int> b = {6, 5, 3, 5};

    int x[] = {4, 6, 7, 4};
    int y[] = {6, 5, 3, 5};
    cout << firstPP(x, y, 4) << endl;
    cout << firstPetrolPump(a, b) << endl;
    cout << firstPetrolPump2(a, b) << endl;
    cout << firstPetrolPump3(x, y, 4) << endl;

    return 0;
}