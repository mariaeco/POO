/*
HERENCA: Na heranca a classe base fica no topo e abaixo as derivadas
*/
#include <iostream>
#include <string.h>

using namespace std;

class veiculo{
    string marca;
    string nome;
    string cor;
    int ano;
    float consumo;
    int tanque;
public:
    veiculo(const string& m, const string& n, const string& cr, int a, float cons,int t){
        marca = m;
        nome = n;
        cor = cr;
        ano = a;
        consumo = cons;
        tanque = t;
    }

	string get_marca() { return marca; }
	string get_nome() { return nome; }
    string get_cor() { return cor; }
    int get_ano() { return ano; }
    float get_consumo(){return consumo;}
    int get_tanque() { return tanque; }

    void set_marca(string m) { marca = m; }
	void set_nome(string n) { nome = n; }
	void set_cor(string cr) { cor = cr; }
	void set_ano(int a) { ano = a; }
    void set_consumo(int cons) { consumo = cons; }
    void set_tanque(int t) { tanque = t; }


    void kilomentragem(){
        cout << "kilometros rodados: " << consumo*tanque << "km" << endl;
    }

	void print_info() { 
		cout << "------------------Veiculo ----------------------" << endl;
        cout << "   Marca:" << marca << endl; 
        cout << "   Modelo:" << nome << endl; 
        cout << "   Cor:" << cor << endl; 
        cout << "   Ano:" << ano << endl; 
        cout << "   Consumo:" << consumo << endl; 
	}

    ~veiculo(){
        cout << "Veiculo finalizado."  << endl; 
    };
};


class automovel : public veiculo{
    float motor;//1.0, 1.6, 2.0
    int nportas;
public:
    automovel(const string& m, const string& n, const string& cr, int a, float cons, int t,
                float mt, int np):veiculo(m,n,cr,a,cons,t){
        motor = mt;
        nportas = np;
    }
    ~automovel(){cout << "Automovel finalizado."  << endl; }
    float get_motor() { return motor; }
    int get_nportas() { return nportas; }

    void set_motor(float mt) {  motor = mt; }
	void set_nportas(int np) { nportas = np; }

    void print_info() { 
        veiculo::print_info();
        cout << "   Motor:" << motor << endl; 
        cout << "   N. portas:" << nportas << endl; 
	}
};

class pickup : public automovel{
    int carga;
public:
    pickup(const string& m, const string& n, const string& cr, int a, float cons, int t,
            float mt, int np, int cg):automovel(m,n,cr,a,cons,t, mt,np){
        carga = cg;
    }
    ~pickup(){
        cout << "Pickup finalizada."  << endl;
        cout << "------------------------------------------------" << endl;
    }

    int get_carga() { return carga; }
    void set_carga(float cg) { carga = cg;}

    void grade(){
        cout << endl;
        cout << "--> Metodo apenas para pickup <--" << endl;
    }

    void print_info() { 
        automovel::print_info();
        cout << "   Carga:" << carga << endl; 
	}
};

class moto : public veiculo {
    int cilindrada;
    /// .. descrever o resto
};

class onibus : public veiculo {
    int npassageiros;
    /// .. descrever o resto
};

int main(){
//onst string& m, const string& n, const string& cr, int a, float cons,
            //float mt, int np, int cg
    pickup p1("Ford","Ranger","Vermelha",2010, 9.7,50,2.0,2,1000);
    p1.print_info();
    p1.kilomentragem();

    veiculo v1("Chevrolet","Onix","Preto",2016, 14.5,39);
    v1.print_info();
    v1.kilomentragem();

    automovel a1("Chevrolet","Celta","Verde Musco",2011, 11,39,1.0,4);
    a1.print_info();
    a1.kilomentragem();

    p1.grade();
     
    return 0;
}

