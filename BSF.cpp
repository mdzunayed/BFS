#include <bits/stdc++.h>
using namespace std;
int size = 100;
int qu[100];
int front = -1;
int rear = -1;
void enq(int val)
{
  if (rear == -1 && front == -1)
  {
    front = 0;
    rear = 0;
    qu[rear] = val;
  }
  else if (front != (rear + 1) % size)
  {
    rear = (rear + 1) % size;
    qu[rear] = val;
  }
}

int deq()
{
  if (rear == front)
  {
    int x = qu[rear];
    front = -1;
    rear = -1;
    return x;
  }
  else
  {
    int x = qu[front];
    front = (front + 1) % size;
    return x;
  }
}
int source, destination;

int adj[100][100];
char color[100];
int parent[100];
int dis[100];
int node, edge;

void bfs(int s_node)
{
  for (int i = 0; i < 100; i++)
  {
    color[i] = 'W';
    dis[i] = INT_MIN;
    parent[i] = -1;
  }
  dis[s_node] = 0;
  parent[s_node] = -1;
  enq(s_node);

  while (1)
  {
    if (front == -1 && rear == -1)
    {
      break;
    }
    int x = qu[front];
    int u = deq();
    color[x] = 'G';
    cout << x << " ";
    for (int i = 0; i < node; i++)
    {
      if (adj[x][i] == 1)
      {
        if (color[i] == 'W')
        {
          parent[i] = x;
          dis[i] = dis[x] + 1;
          enq(i);
        }
      }
    }
    color[x] = 'B';
  }
}

int main()
{

  cout << "Enter the number of node : ";
  cin >> node;
  cout << "Enter the number of edge : ";
  cin >> edge;

  int x, y;
  for (int i = 0; i < edge; i++)
  {
    cin >> x >> y;
    adj[x][y] = 1;
    adj[y][x] = 1;
  }
  cout << "Explore sequence : ";
  bfs(0);
  cout << "\nEnter a source : ";
  cin >> source;
  cout << "Enter a destination : ";
  cin >> destination;
  if (color[destination] == 'W')
  {
    cout << "NO Path" << endl;
  }
  else
  {
    int arr[100];
    int i = 0;
    int p = destination;
    while (p != -1)
    {
      arr[i] = p;
      p = parent[p];
      i++;
    }
    sort(arr,arr+i);
    cout<<"The path of "<<source<<" node to "<<destination<<" node is : ";
    for (int t = 0; t < i; t++)
    {
      cout << arr[t] << " ";
    }
  }
}
