// Pirminiu dvyniu paieskos algoritmas

#include "bits/stdc++.h"

using namespace std;

#define pora pair<int, int>


class Grafas {
private:
    vector<pair<int, pora> > medis; // briaunos svoris, taskas1, taskas2
    vector<pair<int, int> > minMedis; //taskas1, taskas2
    int nodes;
    int edges;
    int tikslas[1000];
    int TrumpKelioIlgis = 0;


public:
    Grafas(int a, int b)
    {
        nodes = a;
        edges = b;
    }
    void setSaka(int w, int s, int d)
    {
        medis.push_back({ w, { s, d } }); // briaunos svoris, taskas1, taskas2
    }
    void sortMedis()
    {
        sort(medis.begin(), medis.end()); //medis yra surusiuojamas pagal briaunu svori, nuo maziausio iki didziausio
    }
    void pradinisTikslas() //sudaromas masyvas nuo 0 iki 1000
    {
        for (int i = 0; i < 1000; i++)
        {
            tikslas[i] = i;
        }
    }

    int find(int a) {  //function to find the parent of the subset this a belongs to

        while (tikslas[a] != a) {

            //cout << tikslas[a] << " " << a << endl;
            tikslas[a] = tikslas[tikslas[a]];


            a = tikslas[a];

        }
        //system("pause");

        return a;

    }

    void union_(int a, int b) {  //function to merge two subsets

        int d = find(a);

        int e = find(b);

        tikslas[d] = tikslas[e];

    }

    void medzioPaieska()
    {
        for (auto i : medis) 
        {

            int a = i.second.first;

            int b = i.second.second;
            //cout << a << " " << b << endl;
            int cost = i.first;

            if (find(a) != find(b)) 
            {                           // if the two vertices are in different subsets, merge them into one

                TrumpKelioIlgis += cost;

                union_(a, b);

                minMedis.push_back({ a,b });
                //cout << TrumpKelioIlgis << endl;
                //system("pause");
            }

        }
    }
    void print()
    {
        cout << "Edges are : " << endl;

        for (auto x : minMedis) {  // printing the edges of the minimum spanning tree

            cout << x.first << " " << x.second << endl;

        }

        cout << "Total weight of MST = ";

        cout << TrumpKelioIlgis << endl;        //printing the total weight of the minimum spanning tree
    }

};


int main()
{
    ifstream in("Duomenys.txt");
    int nodes, edges;
    
    cout << "KRUSKALIO ALGORITMAS" << endl;
    in >> nodes;
    cout << "Medziu skaicius: " << nodes << endl;
    in >> edges;
    cout << "Saku skaicius: " << edges << endl;
    //g(nodes, edges);
    Grafas g(nodes, edges);

    g.setSaka(4,0,1);
    g.setSaka(8,0,7);
    g.setSaka(8,1,2);
    g.setSaka(11,1,7);
    g.setSaka(7,2,3);
    g.setSaka(2,2,8);
    g.setSaka(4,2,5);
    g.setSaka(9,3,4);
    g.setSaka(14,3,5);
    g.setSaka(10,4,5);
    g.setSaka(2,5,6);
    g.setSaka(1,6,7);
    g.setSaka(6,6,8);
    g.setSaka(7,7,8);
    
    g.sortMedis();
    g.pradinisTikslas();
    g.medzioPaieska();
    g.print();




    
    return 0;
}