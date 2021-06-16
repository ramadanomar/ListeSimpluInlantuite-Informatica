#include <iostream>
/*
 Pentru o listă linjară simplu înlănţuită ale cărei elemente întregi se citesc de la tastatură să se realizeze următoarele prelucrări:
    a. Să se afişeze conţinutul listei
    b. Să se afişeze pătratele perfecte din listă
    c. Să se numere câte numere prime sunt în listă. În cazul în care lista nu conţine numere prime se Va afişa un mesaj
    d. Să se determine dacă lista este ordonată Crescător
    e. Să se determine Valoarea maximă din listă şi de câte ori apare aceasta în listă
    f. Se vor dubla elementele pentru care suma cifrelor este mai mică decât 10
*/
using namespace std;

struct lista
{
    struct lista *urm;
    int val;
};

lista *prim,*ultim;

int maxim = INT_MIN;

void creare(int x)
{
    lista *p;
    p=new lista;
    p->val=x;
    if(prim==NULL)
    {
        prim=p;
        ultim=p;
        ultim->urm=NULL;
    }
    else
    {
        ultim->urm=p;
        ultim=p;
        ultim->urm=NULL;
    }
}

void afisare(void)
{

        lista *p;
        p=prim;
        while(p!=NULL)
        {
            cout<<p->val<<" ";
            p=p->urm;
        }
}

int nr_div(int x)
{
    int nr=0;
    for(int i=1;i<=x;i++)
        if(x%i==0)
            nr++;
    return nr;
}

int este_pp(int x) // este patrat perfect
{
        if(nr_div(x)%2!=0)return 1;
        else return 0;
}

void afisarepp(void)
{

        lista *p;
        p=prim;
        while(p!=NULL)
        {
            if(este_pp(p->val))cout<<p->val<<" ";
            p=p->urm;
        }
}

int numara_prime(void)
{
    lista *p;
    p=prim;
    int nr=0;
    while(p!=NULL)
    {
        if(nr_div(p->val)==2)nr++;
        p=p->urm;
    }
    return nr;
}

int este_crescator(void)
{
    lista *p;
    p=prim;
    int este=1; // pp ca este ordonata crescator
    while((p->urm!=NULL)&&(este!=0))
    {
        if(p->val>p->urm->val)este=0;
        p=p->urm;
    }
    return este;
}

int maxim_lista(void)
{
    lista *p;
    p=prim;
    int maxi=p->val;
    p=p->urm;
    while(p!=NULL)
    {
        if(maxi<p->val)maxi=p->val;
        p=p->urm;
    }
    return maxi;
}

int numara_maxim(void)
{
        int maxi=maxim;
        lista *p;
        int nr=0;
        p=prim;
        while(p!=NULL)
        {
            if(maxi==p->val)
                nr++;
            p=p->urm;
        }
        return nr;
}

void dublare_valori(void)
{
        lista *p;
        p=prim;
        while(p!=NULL)
        {
            if(p->val<10)
                p->val=2*(p->val);
            p=p->urm;
        }
}

void InserareInceput(lista* &cap, int val) { // Alocare nod si initializare valoare
	lista *elem = new lista;
	elem->val = val;
	// legare nod in lista
	elem->urm = cap;
	// mutarea capului listei
	cap = elem;
	}

void InserareSfarsit(lista* &cap, int val) {
	// Alocare si initializare nod
	lista *elem = new lista;
	elem->val = val;
	elem->urm = NULL;
	// daca avem lista vida
	if (cap == NULL)
	// doar modificam capul listei
		cap = elem;
	else {
        // parcurgem lista pana la ultimul nod
		lista *nod = cap;
		while (nod->urm != NULL)
			nod=nod->urm;
	// adaugam elementul nou in lista
	nod->urm=elem;
	}
}

int nrCitit;

int main()
{
    int alegere;
    int n;
    cout << "Dati numarul de elemente \n";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
            cout << "Elementul cu numarul " << i+1 << ": ";
            cin>>a[i];
            if (maxim < a[i])
                maxim = a[i];
    }

    int lista=1;

    for(int i=0;i<n;i++){
        creare(a[i]);
    }

    while (lista != 0){
    cout << "***********\n";
    cout << " 1 - Afisare.\n";
    cout << " 2 - Afisarea patratelor perfecte.\n";
    cout << " 3 - Numere prime+ordonare.\n";
    cout << " 4 - Maxim si de cate ori apare.\n";
    cout << " 5 - Dublare elemente mai mici decat 10 din lista\n";
    cout << " 7 - Inserare la inceputul listei unei valori\n";
    cout << " 8 - Inserare la sfarsitul listei unei valori\n";
    cout << " 6 - Exit.\n";
    cout << " Ce doriti sa efectueze programul? \n";

    cin >> alegere;

    switch (alegere)
    {
    case 1:
    cout << "Lista!\n";

   // for(int i=0;i<n;i++){
    //        creare(a[i]);
    //    }
        cout<<endl<<"Afisarea listei : \n";
        afisare();

    break;

    case 2:
    cout << "patrate perfecte\n";
    cout<<endl<<"Afisarea patratelor perfecte: \n";
        afisarepp();

    break;

    case 3:
    cout << "prime+ordonare\n";
    if(numara_prime()==0)
            cout<<endl<<"Lista nu contine numere prime \n";
        else
            cout<<endl<<"Am gasit "<<numara_prime()<<" valori prime\n";
    if(este_crescator()==1)
            cout<<endl<<"Lista este ordonata crescator !\n";
        else
            cout<<endl<<"Lista nu este ordonata crescator !\n";

    break;

    case 4:
        cout<<endl<<"Cea mai mare valoare din lista este  "<< maxim <<" ";
        cout<<"si apare de "<<numara_maxim()<<" ori !\n";
    break;

    case 5 :
        cout<<"dublu<10\n";
        cout<<endl<<"Sunt dublate valorile mai mici decat 10 \n";

        dublare_valori();

    break;

    case 6:
    cout << "Sfarsitul Programului.\n";
    lista = 0;
    break;

    case 7:
        cout << "Ce element doriti sa adaugati? ";
        cin >> nrCitit;
        InserareInceput(prim, nrCitit);
    break;

    case 8:
        cout << "Ce element doriti sa adaugati? ";
        cin >> nrCitit;
        InserareSfarsit(prim, nrCitit);

    default:
    cout << "Nu este o alegere valida. \n";
    cout << "Alege iar.\n";
    cin >> alegere;
    break;
    }

    }
    return 0;
}
