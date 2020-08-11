/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>
using namespace std;
// constraints
#define MAXN 50000
#define MAXM 100000

struct edge{
    int dest, timeI, timeF;
};

// input data
int N, M;
int source, destination, currTime, minTime=1000000000;
vector<vector<edge> > graph;

int sol(int start){
    if(start == destination)
        return currTime;

    // insert more code here
    for(edge &c : graph[start]){
        if(c.timeI >= currTime){
            currTime=c.timeF;
            int a= sol(c.dest);
            if(a==1000000000)
                currTime=0;
            if(a<minTime)
                minTime=a;
        }
    }
    return 1000000000;
}


int main() {
//  uncomment the following lines if you want to read/write from files
 freopen("input1.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    cin>>N;
    cin>>source>>destination;
    cin>>M;

    graph.resize(N);

    for (int i=0; i<M; i++) {
        int city1, time1, city2, time2;
        cin>>city1>>time1>>city2>>time2;

        // insert your code here
        graph[city1].push_back({city2, time1, time2});
    }


    currTime=0;

    sol(source);

    if(minTime==1000000000)
        cout<<"IMPOSSIBLE"<<endl;
    else

    printf("%d\n", minTime); // change 42 with actual answer
    return 0;
}
