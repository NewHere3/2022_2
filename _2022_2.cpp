#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;

struct pratimas
{
    string name = "";
    int dienos = 0;
    int t = 0;
    int Rytas = 0;
    int Diena = 0;
    int Vakaras = 0;
    bool done = 0;
};

void pavadinimu_sarasas(vector<string>& names);


int main()
{
    vector<string> names;
    vector<pratimas> pratimai;
    pavadinimu_sarasas(names);
    ifstream duom("Duomenys.txt");
    ofstream rez("Rezultatai.txt");

    for (int i = 0; i < names.size(); i++)
    {
        pratimas temp;
        temp.name = names[i];
        pratimai.push_back(temp);
    }

    int N = 0;
    duom >> N;
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < pratimai.size(); k++) { pratimai[k].done = 0; }

        int n;
        duom >> n;
        for (int j = 0; j < n; j++)
        {
            char name[15];
            char laikas[8];
            int t;
            duom.ignore(); // igore the space
            duom.get(name, 15);
            //names.push_back(name);
            duom.ignore();
            //set_names.insert(name);
            duom.get(laikas, 8);
            duom >> t;
            string s_name = name;
            string s_laikas = laikas;
            for (int k = 0; k < pratimai.size(); k++)
            {
                if (pratimai[k].name == s_name)
                {
                    pratimai[k].t += t;
                    if (s_laikas == "Rytas  "){pratimai[k].Rytas ++;}
                    else if (s_laikas == "Diena  ") { pratimai[k].Diena++; }
                    else { pratimai[k].Vakaras++; }

                    if(!pratimai[k].done)
                    {
                        pratimai[k].dienos++;
                        pratimai[k].done = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < pratimai.size(); i++)
    {
        for (int j = i+1; j < pratimai.size(); j++)
        {
            if (pratimai[i].name > pratimai[j].name)
            {
                swap(pratimai[i].name, pratimai[j].name);
            }
        }
    }

    for (int i = 0; i < names.size(); i++)
    {
        rez << pratimai[i].name << ' ' << pratimai[i].dienos << ' ' << pratimai[i].t << '\n';
        if (pratimai[i].Rytas > 0) { rez << "Rytas   " << pratimai[i].Rytas << '\n'; }
        if (pratimai[i].Diena > 0) { rez << "Diena   " << pratimai[i].Diena << '\n'; }
        if (pratimai[i].Vakaras > 0) { rez << "Vakaras " << pratimai[i].Vakaras << '\n'; }
    }

    duom.close();
    rez.close();
    return 0;
}

void pavadinimu_sarasas(vector<string>& names)
{
    ifstream duom("Duomenys.txt");
    int N;
    duom >> N;
    set<string> set_names;
    for (int i = 0; i < N; i++)
    {
        int n;
        duom >> n;
        for (int j = 0; j < n; j++)
        {
            char name[15];
            char laikas[8];
            int t;
            duom.ignore(); // igore the space
            duom.get(name, 15);
            //names.push_back(name);
            duom.ignore();
            set_names.insert(name);
            duom.get(laikas, 8);
            duom >> t;
        }
    }

    names.assign(set_names.begin(), set_names.end());

    duom.close();
}
