#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
//exemplu cuvant acceptat: bbabaaa
int main()
{
    char stari[100][100][100], caracter, cuvant[100], stariCaractere[100], cuvantVid[2]="@";
    int i,j,k, nrStari, nrStariFinale, stariFinale[100], stare1, stare2, stareCurenta, cuvantAcceptat=0, stareInitiala, nrStariCaractere;
    ifstream fin("date.txt");

    fin>>nrStari>>nrStariFinale;

    for(i=0;i<nrStari;i++)
        for(j=0;j<nrStari;j++)
            for(k=0;k<nrStari;k++)
                stari[i][j][k]=NULL;


    for(i=0;i<nrStariFinale;i++)
        fin>>stariFinale[i];

    fin>>stareInitiala;

    fin>>nrStariCaractere;

    for(int i=0;i<nrStariCaractere;i++)
        fin>>stariCaractere[i];

    while(fin>>stare1>>stare2>>caracter)
        {
            k=0;
            while(stari[stare1][stare2][k]!=NULL)
                k++;
            stari[stare1][stare2][k]=caracter;
        }

    //afisare matrice;
    for(int i=0;i<nrStari;i++)
    {
        for(int j=0;j<nrStari;j++)
            for(int k=0;k<nrStari;k++)
                cout<<stari[i][j][k]<<" ";
        cout<<endl;
    }

    stareCurenta=stareInitiala;

    cin>>cuvant;
    if(strcmp(cuvantVid,cuvant)==0)
        goto eticheta;

    for(i=0;i<strlen(cuvant);i++)
        {
            int numar=0;
            int gasit=0;
            caracter=cuvant[i];

            for(int i=0;i<nrStariCaractere;i++)
                if(caracter!=stariCaractere[i])
                    numar++;
            if(numar==nrStariCaractere)
            {
                cuvantAcceptat=0;
                goto eticheta2;
            }
            for(j=0;j<nrStari&&gasit==0;j++)
                {
                    k=0;
                    while(stari[stareCurenta][j][k]!=NULL&&gasit==0)
                    {
                        if(stari[stareCurenta][j][k]==caracter)
                        {
                            stareCurenta=j;
                            gasit=1;
                        }
                        k++;
                    }
                }
        }

    eticheta:
    for(i=0;i<nrStariFinale;i++)
        if(stareCurenta==stariFinale[i])
            cuvantAcceptat=1;
    eticheta2:
    if(cuvantAcceptat)
        cout<<"Cuvantul este acceptat!";
    else
        cout<<"Cuvantul NU este acceptat!";
    fin.close();
    return 0;
}
