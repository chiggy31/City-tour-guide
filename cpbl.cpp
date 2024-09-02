#include <iostream>
#include "bits/stdc++.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#include <map>
using namespace std;

class edge
{
public:
    int nbr;
    double wt; // 1------2

    edge(int nbr, double wt)
    {
        this->nbr = nbr;
        this->wt = wt;
    }
};

class driver
{

public:
    string name;
    string cname;
    string phonen;
    string pnumber;
    double rate;

    driver(string name, string cname, string phonen, string pnumber, double rate)
    {
        this->name = name;
        this->cname = cname;
        this->pnumber = pnumber;
        this->phonen = phonen;
        this->rate = rate;
    }
};

class dipair
{

public:
    int val;
    double cost;
    string path;

    dipair(int val, double cost, string path)
    {
        this->val = val;
        this->cost = cost;
        this->path = path;
    }

    bool operator>(const dipair &other) const
    {
        return this->cost > other.cost;
    }
};

class dipair1
{

public:
    int val;
    double cost;
    int bitmask;

    dipair1(int val, double cost, int bitmask)
    {
        this->val = val;
        this->cost = cost;
        this->bitmask = bitmask;
    }

    bool operator>(const dipair1 &other) const
    {
        return this->cost > other.cost;
    }
};

class prims
{

public:
    int val;
    double lcost; // local cost to vertex

    prims(int val, double lcost)
    {
        this->val = val;
        this->lcost = lcost;
    }

    bool operator>(const prims &other) const
    {
        return this->lcost > other.lcost;
    }
};

vector<vector<edge>> delhi(12, vector<edge>());      // map of delhi
vector<vector<edge>> uttrakhand(12, vector<edge>()); // map of uttrakhand
vector<vector<edge>> banglore(12, vector<edge>());   // map of banglore

unordered_map<string, int> dm;     // maping for city vs node delhi
unordered_map<string, int> ukm;    // maping for city vs node uttrakhand
unordered_map<string, int> bangm;  // maping for city vs node banglore
unordered_map<int, string> dm1;    // maping for node vs city delhi
unordered_map<int, string> ukm1;   // maping for node vs city uttrakhand
unordered_map<int, string> bangm1; // maping for node vs city banglore
unordered_map<string, vector<vector<edge>>> choice;
unordered_map<string, unordered_map<string, int>> cchoice;
unordered_map<string, unordered_map<int, string>> cchoice1;

unordered_map<int, vector<driver>> m1; // delhi
unordered_map<int, vector<driver>> m2; // uttrakhand
unordered_map<int, vector<driver>> m3; // banglore
unordered_map<string, unordered_map<int, vector<driver>>> mapingdrivercity;

void makedriverinfodelhi()
{
    // making driver for delhi map
    driver d1("rakesh", "scorpio", "9988992345", "DL2CK81699", 8.88);
    driver d2("rju", "tata indica", "9988792345", "DL3C876997", 6.88);
    driver d3("Birju", "Hyundai i20", "9988922345", "DL2CT81699", 5.88);
    m1[0].push_back(d1);
    m1[0].push_back(d2);
    m1[0].push_back(d3);
    driver d4("Mahesh", "Hyundai Accent", "7988992345", "DL2TK81799", 8.88);
    driver d5("srijan", "tata Sumo", "6988992345", "DL1C876097", 7.88);
    driver d6("Ujjwal", "Tata Nano", "8988992345", "DL2FT81899", 4.58);
    m1[1].push_back(d4);
    m1[1].push_back(d5);
    m1[1].push_back(d6);
    driver d7("Hardik", "Mahindra XUV 700", "9988992345", "DL5CK81699", 12.00);
    m1[2].push_back(d7);
    driver d8("Suresh", "Hyundai i10 grand", "9966992345", "DL2TK41799", 6.00);
    driver d9("sHubhanshu", "Hyundai Creta", "7988992345", "DL1C876667", 13.00);
    m1[3].push_back(d8);
    m1[3].push_back(d9);
    driver s1("Ankur", "Wagnor Lxi", "6988992345", "DL1C859097", 9.00);
    driver s2("ankit", "Naruti Suzuki Swift", "7988992345", "DL2FU01899", 8.97);
    m1[4].push_back(s1);
    m1[4].push_back(s2);
    driver s3("Montu", "Mahindra KUV", "9955992345", "DL5CK87691", 16.00);
    m1[5].push_back(s3);
    driver s4("Suresh", "Hyundai Santro", "9999992345", "DL2TK41999", 8.12);
    driver s5("Sharat", "Celerio", "9988992388", "DL3C076667", 9.67);
    m1[6].push_back(s4);
    m1[6].push_back(s5);
    driver s6("Monty", "Mahindra TUV 300", "9954992345", "DL5CH87671", 14.00);
    m1[7].push_back(s6);
    driver s7("Suresh", "Hyundai Santro", "9990992345", "DL2TK41999", 8.12);
    driver s8("Sharat", "Celerio", "7788992345", "DL3C076667", 9.67);
    m1[8].push_back(s7);
    m1[8].push_back(s8);
    driver h1("rakesh", "scorpio", "8888992345", "DL2CK81699", 8.88);
    driver h2("rju", "tata indica", "8088992345", "DL3C876997", 6.88);
    driver h3("Birju", "Hyundai i20", "9088992345", "DL2CT81699", 5.88);
    m1[9].push_back(h1);
    m1[9].push_back(h2);
    m1[9].push_back(h3);
    driver g1("Manu", "scorpio", "7988992345", "DL2CK81699", 8.88);
    driver g2("Mandeep", "Tata Nano", "8988992345", "DL4C876907", 3.88);
    driver g3("Mukesh", "XUV 500", "7688992345", "DL2CH81689", 12.88);
    m1[10].push_back(g1);
    m1[10].push_back(g2);
    m1[10].push_back(g3);
    driver g4("Sumit", "Tata Harrier", "7766992345", "DL9CH86671", 12.00);
    m1[11].push_back(g4);
    mapingdrivercity
        ["delhi"] = m1;
}

void makedriverinfouk()
{
    // making driver for delhi map
    driver d1("rakesh", "scorpio", "9988992345", "UK2CK81699", 8.88);
    driver d2("rju", "tata indica", "9988792345", "UK3C876997", 6.88);
    driver d3("Birju", "Hyundai i20", "9988922345", "UK2CT81699", 5.88);
    m2[0].push_back(d1);
    m2[0].push_back(d2);
    m2[0].push_back(d3);
    driver d4("Mahesh", "Hyundai Accent", "7988992345", "UK2TK81799", 8.88);
    driver d5("srijan", "tata Sumo", "6988992345", "UK1C876097", 7.88);
    driver d6("Ujjwal", "Tata Nano", "8988992345", "UK2FT81899", 4.58);
    m2[1].push_back(d4);
    m2[1].push_back(d5);
    m2[1].push_back(d6);
    driver d7("Hardik", "Mahindra XUV 700", "9988992345", "UK5CK81699", 12.00);
    m2[2].push_back(d7);
    driver d8("Suresh", "Hyundai i10 grand", "9966992345", "UK2TK41799", 6.00);
    driver d9("sHubhanshu", "Hyundai Creta", "7988992345", "UK1C876667", 13.00);
    m2[3].push_back(d8);
    m2[3].push_back(d9);
    driver s1("Ankur", "Wagnor Lxi", "6988992345", "UK1C859097", 9.00);
    driver s2("ankit", "Naruti Suzuki Swift", "7988992345", "UK2FU01899", 8.97);
    m2[4].push_back(s1);
    m2[4].push_back(s2);
    driver s3("Montu", "Mahindra KUV", "9955992345", "UK5CK87691", 16.00);
    m2[5].push_back(s3);
    driver s4("Suresh", "Hyundai Santro", "9999992345", "UK2TK41999", 8.12);
    driver s5("Sharat", "Celerio", "9988992388", "UK3C076667", 9.67);
    m2[6].push_back(s4);
    m2[6].push_back(s5);
    driver s6("Monty", "Mahindra TUV 300", "9954992345", "UK5CH87671", 14.00);
    m2[7].push_back(s6);
    driver s7("Suresh", "Hyundai Santro", "9990992345", "UK2TK41999", 8.12);
    driver s8("Sharat", "Celerio", "7788992345", "UK3C076667", 9.67);
    m2[8].push_back(s7);
    m2[8].push_back(s8);
    driver h1("rakesh", "scorpio", "8888992345", "UK2CK81699", 8.88);
    driver h2("rju", "tata indica", "8088992345", "UK3C876997", 6.88);
    driver h3("Birju", "Hyundai i20", "9088992345", "UK2CT81699", 5.88);
    m2[9].push_back(h1);
    m2[9].push_back(h2);
    m2[9].push_back(h3);
    driver g1("Manu", "scorpio", "7988992345", "UK2CK81699", 8.88);
    driver g2("Mandeep", "Tata Nano", "8988992345", "UK4C876907", 3.88);
    driver g3("Mukesh", "XUV 500", "7688992345", "UK2CH81689", 12.88);
    m2[10].push_back(g1);
    m2[10].push_back(g2);
    m2[10].push_back(g3);
    driver g4("Sumit", "Tata Harrier", "7766992345", "UK9CH86671", 12.00);
    m2[11].push_back(g4);
    mapingdrivercity
        ["uttrakhand"] = m2;
}

void makedriverinfobg()
{
    // making driver for delhi map
    driver d1("rakesh", "scorpio", "9988992345", "KA2CK81699", 8.88);
    driver d2("rju", "tata indica", "9988792345", "KA3C876997", 6.88);
    driver d3("Birju", "Hyundai i20", "9988922345", "KA2CT81699", 5.88);
    m3[0].push_back(d1);
    m3[0].push_back(d2);
    m3[0].push_back(d3);
    driver d4("Mahesh", "Hyundai Accent", "7988992345", "KA2TK81799", 8.88);
    driver d5("srijan", "tata Sumo", "6988992345", "KA1C876097", 7.88);
    driver d6("Ujjwal", "Tata Nano", "8988992345", "KA2FT81899", 4.58);
    m3[1].push_back(d4);
    m3[1].push_back(d5);
    m3[1].push_back(d6);
    driver d7("Hardik", "Bajaj Auto", "9988992345", "KA5CK81699", 12.00);
    m3[2].push_back(d7);
    driver d8("Suresh", "Hyundai i10 grand", "9966992345", "KA2TK41799", 6.00);
    driver d9("sHubhanshu", "Hyundai Creta", "7988992345", "KA1C876667", 13.00);
    m3[3].push_back(d8);
    m3[3].push_back(d9);
    driver s1("Ankur", "Wagnor Lxi", "6988992345", "KA1C859097", 9.00);
    driver s2("ankit", "Naruti SuzKAi Swift", "7988992345", "KA2FU01899", 8.97);
    m3[4].push_back(s1);
    m3[4].push_back(s2);
    driver s3("Montu", "Mahindra KUV", "9955992345", "KA5CK87691", 16.00);
    m3[5].push_back(s3);
    driver s4("Suresh", "Hyundai Santro", "9999992345", "KA2TK41999", 8.12);
    driver s5("Sharat", "Celerio", "9988992388", "KA3C076667", 9.67);
    m3[6].push_back(s4);
    m3[6].push_back(s5);
    driver s6("Monty", "Mahindra TUV 300", "9954992345", "KA5CH87671", 14.00);
    m3[7].push_back(s6);
    driver s7("Suresh", "Hyundai Santro", "9990992345", "KA2TK41999", 8.12);
    driver s8("Sharat", "Celerio", "7788992345", "KA3C076667", 9.67);
    m3[8].push_back(s7);
    m3[8].push_back(s8);
    driver h1("rakesh", "scorpio", "8888992345", "KA2CK81699", 8.88);
    driver h2("rju", "tata indica", "8088992345", "KA3C876997", 6.88);
    driver h3("Birju", "Hyundai i20", "9088992345", "KA2CT81699", 5.88);
    m3[9].push_back(h1);
    m3[9].push_back(h2);
    m3[9].push_back(h3);
    driver g1("Manu", "scorpio", "7988992345", "KA2CK81699", 8.88);
    driver g2("Mandeep", "Tata Nano", "8988992345", "KA4C876907", 3.88);
    driver g3("Mahesh", "XUV 500", "7688992345", "KA2CH81689", 12.88);
    m3[10].push_back(g1);
    m3[10].push_back(g2);
    m3[10].push_back(g3);
    driver g4("Sumit", "Tata Harrier", "7766992345", "KA9CH86671", 12.00);
    m3[11].push_back(g4);
    mapingdrivercity
        ["banglore"] = m3;
}

void addedge(int v1, int v2, double weight, vector<vector<edge>> &graph)
{
    // cout<<"pp\n";
    edge e1(v2, weight);
    graph[v1].push_back(e1);
    edge e2(v1, weight);
    graph[v2].push_back(e2);
    return;
}

void makegraphs()
{
    // making delhi map
    addedge(0, 1, 2.4, delhi);
    addedge(0, 10, 12, delhi);
    addedge(0, 7, 4.7, delhi);
    addedge(0, 6, 7.5, delhi);
    addedge(1, 10, 14, delhi);
    addedge(1, 7, 13, delhi);
    // addedge(1,2,16,delhi);
    addedge(7, 8, 14, delhi);
    addedge(7, 6, 3.1, delhi);
    addedge(6, 8, 12, delhi);
    // addedge(6,5,2.8,delhi);
    addedge(6, 4, 29, delhi);
    addedge(2, 5, 21, delhi);
    addedge(2, 8, 6.4, delhi);
    addedge(2, 10, 8.8, delhi);
    // addedge(2,9,2.9,delhi);
    addedge(2, 3, 3.1, delhi);
    addedge(5, 3, 15, delhi);
    addedge(5, 4, 30, delhi);
    addedge(10, 3, 7.7, delhi);
    // addedge(10,9,8.1,delhi);
    addedge(3, 9, 2.2, delhi);
    addedge(3, 4, 17, delhi);
    addedge(4, 9, 17, delhi);
    addedge(4, 11, 20, delhi);
    addedge(9, 11, 4.2, delhi);
    // making banglore map
    addedge(0, 1, 7.7, banglore);
    addedge(0, 2, 8.5, banglore);
    addedge(1, 2, 9.9, banglore);
    addedge(1, 4, 11, banglore);
    addedge(1, 7, 36, banglore);
    addedge(2, 11, 30, banglore);
    addedge(2, 8, 6.9, banglore);
    addedge(2, 5, 17, banglore);
    addedge(2, 4, 3.8, banglore);
    addedge(2, 3, 9.2, banglore);
    addedge(3, 9, 61, banglore);
    addedge(3, 10, 45, banglore);
    addedge(5, 4, 14, banglore);
    addedge(4, 6, 7.9, banglore);
    addedge(4, 8, 8, banglore);
    addedge(8, 7, 21, banglore);
    addedge(7, 6, 40, banglore);
    addedge(6, 10, 45, banglore);
    addedge(6, 9, 63, banglore);
    addedge(9, 10, 63, banglore);
    // making uttrakhand map
    addedge(0, 1, 128, uttrakhand);
    addedge(0, 2, 147, uttrakhand);
    // addedge(0,1,147,uttrakhand);
    addedge(1, 2, 26, uttrakhand);
    addedge(1, 6, 55, uttrakhand);
    addedge(2, 3, 4, uttrakhand);
    addedge(2, 4, 63, uttrakhand);
    addedge(2, 6, 33, uttrakhand);
    addedge(2, 5, 15, uttrakhand);
    addedge(5, 10, 87, uttrakhand);
    addedge(5, 11, 275, uttrakhand);
    addedge(5, 9, 265, uttrakhand);
    addedge(4, 6, 44, uttrakhand);
    addedge(6, 8, 287, uttrakhand);
    addedge(4, 7, 87, uttrakhand);
    addedge(3, 8, 366, uttrakhand);
    addedge(3, 7, 224, uttrakhand);
    addedge(10, 3, 147, uttrakhand);
    addedge(7, 11, 132, uttrakhand);
}

void domaping()
{
    // maping for delhi begins here
    dm["Khazoorikhas"] = 1;
    dm["bhajanpura"] = 0;
    dm["Akshardham"] = 10;
    dm["Mandoli"] = 7;
    dm["IndiaGate"] = 2;
    dm["RedFort"] = 8;
    dm["DilshadGarden"] = 6;
    dm["Oldseemapuri"] = 5;
    dm["CannaughtPlace"] = 3;
    dm["Janakpuri"] = 4;
    dm["Chandichowk"] = 11;
    dm["Jantarmantar"] = 9;
    dm1[1] = "Khazoorikhas";
    dm1[0] = "bhajanpura";
    dm1[10] = "Akshardham";
    dm1[7] = "Mandoli";
    dm1[2] = "IndiaGate";
    dm1[8] = "RedFort";
    dm1[6] = "DilshadGarden";
    dm1[5] = "Oldseemapuri";
    dm1[3] = "CannaughtPlace";
    dm1[4] = "Janakpuri";
    dm1[11] = "Chandichowk";
    dm1[9] = "Jantarmantar";
    // maping for banglore begins here
    bangm["lalbaghbotanicalgarden"] = 0;
    bangm["marutinagar"] = 1;
    bangm["shivanagar"] = 2;
    bangm["iskontemple"] = 3;
    bangm["banglorepalace"] = 4;
    bangm["nehrunagar"] = 5;
    bangm["kurubarahalli"] = 6;
    bangm["bannerghatabiologicalpark"] = 7;
    bangm["tipusultansummerpalace"] = 8;
    bangm["nandihills"] = 9;
    bangm["shivagangue"] = 10;
    bangm["naityagram"] = 11;

    bangm1[0] = "lalbaghbotanicalgarden";
    bangm1[1] = "marutinagar";
    bangm1[2] = "shivanagar";
    bangm1[3] = "iskontemple";
    bangm1[4] = "banglorepalace";
    bangm1[5] = "nehrunagar";
    bangm1[6] = "kurubarahalli";
    bangm1[7] = "bannerghatabiologicalpark";
    bangm1[8] = "tipusultansummerpalace";
    bangm1[9] = "nandihills";
    bangm1[10] = "shivagangue";
    bangm1[11] = "naityagram";
    // maping for uttrakhand begins here
    ukm["haridwar"] = 0;
    ukm["kashipur"] = 1;
    ukm["jimcorbettnationalpark"] = 2;
    ukm["kalagarhdam"] = 3;
    ukm["nainital"] = 4;
    ukm["girjadevitemple"] = 5;
    ukm["chardhammandir"] = 6;
    ukm["binsar"] = 7;
    ukm["chamoli"] = 8;
    ukm["joshimath"] = 9;
    ukm["pangoot"] = 10;
    ukm["mountabbott"] = 11;
    ukm1[0] = "haridwar";
    ukm1[1] = "kashipur";
    ukm1[2] = "jimcorbettnationalpark";
    ukm1[3] = "kalagarhdam";
    ukm1[4] = "nainital";
    ukm1[5] = "girjadevitemple";
    ukm1[6] = "chardhammandir";
    ukm1[7] = "binsar";
    ukm1[8] = "chamoli";
    ukm1[9] = "joshimath";
    ukm1[10] = "pangoot";
    ukm1[11] = "mountabbott";
    // maping of city graph for user choice
    choice["delhi"] = delhi;
    choice["uttrakhand"] = uttrakhand;
    choice["banglore"] = banglore;
    // maping for city name map of particular city
    cchoice["delhi"] = dm;
    cchoice["banglore"] = bangm;
    cchoice["uttrakhand"] = ukm;
    cchoice1["delhi"] = dm1;
    cchoice1["banglore"] = bangm1;
    cchoice1["uttrakhand"] = ukm1;
}

void printAllPathsUtil(int u, int d, vector<vector<edge>> city, vector<bool> &visited, string psf, unordered_map<int, string> getcity, int &count, double distance) // int distance=0)
{

    if (u == d)
    {
        count++;
        cout << count << "  :-  " << psf << " " << distance << "\n\n";
        return;
    }

    visited[u] = true;
    for (int i = 0; i < city[u].size(); i++)
    {
        edge e1 = city[u][i];
        if (visited[e1.nbr] == false)
            printAllPathsUtil(e1.nbr, d, city, visited, (psf + "->" + getcity[e1.nbr]), getcity, count, distance + e1.wt); // distance+e1.wt;
    }

    visited[u] = false;
}

// finding all paths from source to destination

void printAllPaths(int s, int d, vector<vector<edge>> &city, unordered_map<int, string> &getcity)
{
    int V = city.size();
    vector<bool> visited(V, false);
    string psf = getcity[s] + "->";
    int count = 0;
    double distance = 0;
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, city, visited, psf, getcity, count, distance);
}

void findstoppath(int src, int des, vector<vector<edge>> &city, int nmv, unordered_map<string, int> getid, unordered_map<int, string> getcity, int bitmsk, double curdistance, vector<bool> &visited, string psf, map<double, string> &m1)
{

    if (src == des && (bitmsk == (1 << nmv) - 1))
    {

        // cout<<"path"<<"  :-  "<<psf<<" "<<distance<<"\n\n";
        // cout<<psf<<"   bitmask"<<bitmsk<<"\n";
        m1[curdistance] = psf;
        return;
    }

    visited[src] = true;
    for (int i = 0; i < city[src].size(); i++)
    {
        edge e1 = city[src][i];
        string city1 = getcity[e1.nbr];
        int newbitmask = bitmsk;
        if (visited[e1.nbr] == false)
        {

            if (getid.find(city1) != getid.end())
            {
                newbitmask = ((bitmsk) | (1 << getid[city1]));
            }

            findstoppath(e1.nbr, des, city, nmv, getid, getcity, newbitmask, curdistance + e1.wt, visited, psf + "->" + getcity[e1.nbr], m1);
        }
    }

    visited[src] = false;
}

// find shortest paths from source to destination
// dijkistra algorithm
void shortestPath(int src, int dsc, vector<vector<edge>> &city, unordered_map<int, string> &getcity)
{

    priority_queue<dipair, vector<dipair>, greater<dipair>> pq;
    dipair d1(src, 0, getcity[src]);
    vector<bool> visited(city.size(), false);
    int count = 1;
    // cout<<"p";
    pq.push(d1);
    double cost1 = INT_MAX;
    while (!pq.empty())
    {

        dipair d1 = pq.top();
        pq.pop();

        if (d1.val == dsc && d1.cost <= cost1)
        {
            cout << "Path " << count << "-: " << d1.path << " - " << d1.cost << " KM"
                 << "\n\n";
            cost1 = d1.cost;
            count++;
            continue;
        }

        if (visited[d1.val] == true)
            continue;

        visited[d1.val] = true;

        for (int i = 0; i < city[d1.val].size(); i++)
        {

            edge e1 = city[d1.val][i];

            if (visited[e1.nbr] != true)
            {

                dipair v1(e1.nbr, e1.wt + d1.cost, d1.path + "->" + getcity[e1.nbr]);
                pq.push(v1);
            }
        }
    }
}

// find shortest paths from source to destination
// prims algorithm mst

void shortestPathcity(int src, vector<vector<edge>> &city, unordered_map<int, string> &getcity)
{

    priority_queue<prims, vector<prims>, greater<prims>> pq;
    prims d1(src, 0);
    vector<bool> visited(city.size(), false);
    double count = 0;
    int visit = 0;
    // cout<<"p";
    pq.push(d1);

    cout << "\n";

    while (!pq.empty())
    {

        prims d1 = pq.top();
        pq.pop();

        if (visited[d1.val] == true)
            continue;

        count += d1.lcost;
        visit++;

        cout << getcity[d1.val] << "{ " << d1.lcost << " }"
             << "-> ";

        if (visit == city.size())
        {
            cout << "\n                TOTAL COST OF VISITING IS"
                 << "\n";
            cout << "                  " << count << " KM \n";
            break;
        }

        visited[d1.val] = true;

        for (int i = 0; i < city[d1.val].size(); i++)
        {

            edge e1 = city[d1.val][i];

            if (visited[e1.nbr] != true)
            {

                prims v1(e1.nbr, e1.wt);
                pq.push(v1);
            }
        }
    }
}

// printing details of driver info at current location

void getdriverinfo(int src, unordered_map<int, vector<driver>> d)
{

    vector<driver> d1 = d[src];
    int count = 0;

    for (int i = 0; i < d1.size(); i++)
    {
        count++;
        driver s = d1[i];
        cout << "\n";
        cout << count << "\n";
        cout << "driver name"
             << " -" << s.name << "\n";
        cout << "Driver car name"
             << " - " << s.cname << "\n";
        cout << "Driver car no plate"
             << " - " << s.pnumber << "\n";
        cout << "Driver Phone number"
             << " - " << s.phonen << "\n";
        cout << "Driver charges for per km   " << s.rate << " per km ";
    }
}

int main()
{

    cout << "       *****HERE IS OUR PROJECT**********       \n";
    cout << "       *****MAP TOUR GUIDE SYSTEM*********         \n";

    makegraphs();
    domaping();
    makedriverinfodelhi();
    makedriverinfouk();
    makedriverinfobg();

    bool b2 = true;

    while (b2)
    {
        cout << "HERE ARE THE MAPS OF THE CITIES THAT ARE AVAILABLE IN OUR DATA BASE\n";
        string k;
        cout << "   1. delhi\n";
        cout << "   2. banglore\n";
        cout << "   3. uttrakhand\n";
        cout << "choose the city among about in which you live/want to travel \n";
        cin >> k;

        if (k != "delhi" && k != "uttrakhand" && k != "banglore")
        {
            cout << "Sorry for the inconveniene caused we will soon add more city maps in our database\n";
            cout << "*********THANK YOU***************\n";
            return 0;
        }
        bool b1 = true;
        while (b1)
        {
            cout << "****Here is the list of places that you can visit in  " << k << "***"
                 << "\n";
            int i = 1;
            for (auto it : cchoice[k])
            {

                cout << "   " << i << "." << it.first << "\n";
                i++;
            }

            cout << "\n\n";
            string src;
            cout << "Enter your location"
                 << "\n";
            cin >> src;
            cout << "\n";

            cout << "Now we know which city you are residing or wanna explore now choose one of the option from given options\n";
            int ch;
            cout << "1. want to travel from your locaion to some other location\n";
            cout << "2. want to visit all the places of current city in our database\n";
            cout << "3. want a transport guidance at your current location\n press 1/2/3 to proceed \n";
            cin >> ch;

            switch (ch)
            {

            case 1:
            {
                string dsc;
                cout << "enter you destination"
                     << "\n";
                cin >> dsc;
                cout << "Here shows information about all the path from your location to the destination"
                     << "\n\n";
                printAllPaths(cchoice[k][src], cchoice[k][dsc], choice[k], cchoice1[k]);

                int c;
                cout << "Do you want to see shortest path among these paths from " << src << "  to " << dsc << " type 0/1 \n\n";
                cin >> c;
                cout << "\n";
                cout << "********HERE ARE THE SHORTEST PATHS*******\n\n";
                if (c == 1)
                {
                    shortestPath(cchoice[k][src], cchoice[k][dsc], choice[k], cchoice1[k]);
                }

                cout << "DO you want to enter Stops in between you location -: " << src << " and destination :- " << dsc << " enter 0/1\n ";
                cin >> c;
                cout << "\n";
                if (c == 1)
                {

                    unordered_map<string, int> smap;
                    cout << "Enter no of stops that you want between source and destination"
                         << "\n\n";
                    int n;
                    cin >> n;
                    int count = 0;
                    cout << "Now enter your stops that you want between your source and destination\n\n";

                    for (int i = 0; i < n; i++)
                    {
                        string s;
                        cin >> s;
                        smap[s] = count;
                        count++;
                    }

                    cout << "\nHere are the paths from source to destination including stops in increasing order of distance"
                         << "\n\n";
                    vector<bool> visited(12, false);
                    string psf = src + "-> ";
                    map<double, string> m1;
                    findstoppath(cchoice[k][src], cchoice[k][dsc], choice[k], n, smap, cchoice1[k], 0, 0, visited, psf, m1);
                    int w = 1;

                    for (auto it : m1)
                    {
                        cout << "path " << w << " -: " << it.second << "   distance-: " << it.first;
                        cout << "\n\n";
                        w++;
                    }

                    cout << "\n";
                }
            }
            break;

            case 2:
            {
                cout << "here is the shortest path visiting all the places in the given city at minimum cost\n";
                shortestPathcity(cchoice[k][src], choice[k], cchoice1[k]);
            }
            break;

            case 3:
            {
                cout << "          SO You Need Transport Guidance Dont Worry We Have Driver Information in our Database\n";
                cout << "                Here Is The Information Regarding The Drivers Available At Your Location\n";

                getdriverinfo(cchoice[k][src], mapingdrivercity[k]);
                cout << "\n    Please Contact These Drivers\n";
            }
            break;
            }

            cout << "DO you want to visit your city menu again Enter 0/1 \n";
            int t;
            cin >> t;
            if (t == 0)
                b1 = false;
        }

        cout << "DO you want to visit some other city /Exit from our data base press 0/1 \n";
        int t1;
        cin >> t1;
        if (t1 == 0)
            b2 = false;
    }
}