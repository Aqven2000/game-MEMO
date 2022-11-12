#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;


//game Memory 
//game works only if size of map is even
//player needs to input cordinates of fild he wants to check
//exemple
//4 <-size of map
//1 7 2 3
//5 4 2 4
//8 4 1 7
//5 3 6 8
//after 5s
//* * * *
//* * * *
//* * * *
//* * * *
//podaj y i x pol ktore chcesz sprawdzic: 0 0 1 1
//1 * * *
//* 4 * *
//* * * *
//* * * *
// if player was wrong after 2s
//* * * *
//* * * *
//* * * *
//* * * *
// if player was right after 2s
//1 * * *
//* 4 * *
//* * * *
//* * * *
//and the game goes on
//enjoy :)

void wyswietl(int dlugosc,vector<vector<string> > &mapa){
    for (int i = 0; i < dlugosc; i++)
    {
        for (int j = 0; j < dlugosc; j++)
        {
            cout<<mapa[i][j]<<" ";
        }
        cout<<'\n';
    }
}


int main(){
    srand(time(NULL));
    int dlugosc;
    cin>>dlugosc;

    if(dlugosc % 2== 0){
        vector<vector<string> > mapa;
        vector<vector<string> > mapa_zakryta;
        int iloscLosowanych = (dlugosc*dlugosc)/2;

        for (int i = 0; i < dlugosc; i++)
        {
            vector<string> PomMapa;
            for (int j = 0; j < dlugosc; j++)
            {
               PomMapa.push_back("*");
            }
            mapa.push_back(PomMapa);
            mapa_zakryta.push_back(PomMapa);
        }


        for (int i = 1; i <= iloscLosowanych; i++)
        {
            int rand_y = rand()%(dlugosc);
            int rand_x = rand()%(dlugosc);

            int rand_2y = rand()%(dlugosc);
            int rand_2x = rand()%(dlugosc);

            if(mapa[rand_y][rand_x] == "*" && mapa[rand_2y][rand_2x] == "*" && ((rand_y != rand_2y) && ((rand_x != rand_2x)))){
                mapa[rand_y][rand_x] = to_string(i);
                mapa[rand_2y][rand_2x] = to_string(i);
            }
            else
                --i;
        }
    clock_t start;
    start = clock();
        
        wyswietl(dlugosc,mapa);

    while (((clock()-start)/(double)CLOCKS_PER_SEC) <5.0)
        {
            ;
        }
        system ("CLS");

            cout<<'\n';

    
        int zlicz_swap =0;
        while(zlicz_swap != dlugosc){
            wyswietl(dlugosc,mapa_zakryta);
            cout<<"podaj y i x pol ktore chcesz sprawdzic: ";
            int x1,y1,x2,y2;
            cin>>y1>>x1>>y2>>x2;

            system ("CLS");

            swap(mapa[y1][x1],mapa_zakryta[y1][x1]);
            swap(mapa[y2][x2],mapa_zakryta[y2][x2]);

            start = clock();
                
                wyswietl(dlugosc,mapa_zakryta);

            while (((clock()-start)/(double)CLOCKS_PER_SEC) <2.0)
            {
                ;
            }

            if(mapa_zakryta[y1][x1] != mapa_zakryta[y2][x2]){
                swap(mapa[y1][x1],mapa_zakryta[y1][x1]);
                swap(mapa[y2][x2],mapa_zakryta[y2][x2]);
            }
            else
                zlicz_swap++;

            system ("CLS");
    }
    cout<<"WYGRALES!!!"<<'\n';
      

    }

    return 0;
}