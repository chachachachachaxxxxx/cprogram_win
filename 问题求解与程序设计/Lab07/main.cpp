#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;
const int MAXN = 1e8 + 10;

struct actorsFilm{
    vector<wstring> films;
    int bacon;
    vector<pair<wstring, wstring>> path;
};

map<wstring, actorsFilm> actorToFilm;
map<wstring, bool> haveIn;

struct filmsActor{
    vector<wstring> actors;
};

map<wstring, filmsActor> filmToActor;

int baconTofre[20];

void out();
void bfs();

wstring oneline;

int main(int argv, char *argc[])
{
    clock_t startTime,endTime;
    startTime = clock();

    wifstream in(argc[1]);
    // wofstream ou1(argc[2]);
    int num = 0;
    while (getline(in, oneline))
    {
        // ou1 << oneline << endl;
        if (oneline == L"")
            continue;
        unsigned long long n1 = 0;
        unsigned long long n = oneline.find(L'/');
        wstring film = oneline.substr(n1, n);
        // wcout << film << endl;
        wstring actor;
        filmsActor actors;
        n1 = n + 1;

        bool flag = false;

        while (n = oneline.find(L"/", n1))
        {
            //cout << n1 << " " << n << endl;
            actor = oneline.substr(n1, n - n1);
            if (actor == L"Bacon, Kevin")
                flag = true;
            //wcout << actor << endl;
            actors.actors.push_back(actor);

            if (actorToFilm.find(actor) != actorToFilm.end())
            {
                actorToFilm[actor].films.push_back(film);
            } else {
                actorsFilm asf;
                asf.bacon = -1;
                asf.films.push_back(film);

                actorToFilm[actor] = asf;
                haveIn[actor] = false;

               
            }
            if (n == wstring::npos)
                break;
            n1 = n + 1;
        }
        
        // if (!flag)
        //     wcout << oneline << endl;
        //if (filmToActor.find(film) == filmToActor.end())
        filmToActor[film] = actors;
        num++;
    }
    // cout << num << endl;
    // cout << filmToActor.size() << endl;
    bfs();
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    out();
    return 0;
}

void out()
{
    cout << "Bacon number\t" << "Frequency" << endl;
    cout << "-------------------------" << endl;
    int s = 0;
    for (int i = 1; baconTofre[i] != 0; i++)
    {
        cout << setw(12) << i - 1 << setw(13) << baconTofre[i] << endl;
        s += baconTofre[i];
    }

    cout << setw(12) << "infinity" << setw(13) << haveIn.size() - s << endl;

    wstring actor;
    while (getline(wcin, actor))
    {
        if (actorToFilm.find(actor) == actorToFilm.end())
            cerr << "wrong actor" << endl;
        else
        {
            wcout << actor << L" has a Bacon number of " << actorToFilm[actor].bacon << endl;
            wstring actor2 = actor;
            for (auto iter = actorToFilm[actor].path.rbegin(); iter != actorToFilm[actor].path.rend(); iter++)
            {
                wcout << actor2 << " was in \"" << iter->first << "\" with " << iter->second << endl;
                actor2 = iter->second;
            }
        }
    }
}


void bfs()
{
    wstring st= L"Bacon, Kevin";
    actorToFilm[st].bacon = 0;
    actorToFilm[st].path.clear();
    baconTofre[0 + 1] = 1;
    haveIn[st] = true;


    queue<wstring> que;
    que.push(st);
    while (!que.empty())
    {
        st = que.front();
        que.pop();

        for (auto iter = actorToFilm[st].films.begin(); iter != actorToFilm[st].films.end(); iter++)
        {
            for (auto iter2 = filmToActor[*iter].actors.begin(); iter2 != filmToActor[*iter].actors.end(); iter2++)
            {
                if (haveIn[*iter2] != true)
                {
                    que.push(*iter2);
                    actorToFilm[*iter2].bacon = actorToFilm[st].bacon + 1;

                    for (auto n: actorToFilm[st].path)
                        actorToFilm[*iter2].path.push_back(n);

                    actorToFilm[*iter2].path.push_back(make_pair(*iter, st));
                    baconTofre[actorToFilm[*iter2].bacon + 1]++;
                    haveIn[*iter2] = true;
                }
            }
        }
    }
}