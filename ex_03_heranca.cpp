/*
Exercício 1  - HERANCA
Crie uma classe Animal que tenha as propriedades nome e idade, e um método que exibe informações
 básicas sobre o animal. Em seguida, crie duas subclasses: Papagaio e Gato. 
 Ambas as subclasses devem herdar da classe Animal e ter uma propriedade adicional: 
 envergadura e se é falante para Papagaio e pelagem e tamanho das garras para Gato. 
 Em seguida, crie um programa que cria objetos de ambas as subclasses e chame o método para exibir 
 informações básicas sobre os animais.
*/
#include <iostream>
#include <string.h>

using namespace std;


class animal{
    string nome;
    int idade;

public:
    animal(const string& n, int i){
        nome = n;
        idade = i;
    }
    string get_nome(){return nome;}
    int get_idade(){return idade;}

    void set_nome(string n){nome = n;}
    void set_idade(int i){idade = i;}

	void print_info() { 
		cout << "------------------ ANIMAL ----------------------" << endl;
        cout << "   Animal:" << nome << endl; 
        cout << "   Idade:" << idade << endl; 
	}
    ~animal(){
        //destrutpr
    };
};

class ave : public animal{
    float  envergadura;
    bool fala;
public:
    ave(const string& n, int i, float e, bool f):animal(n, i){
        envergadura = e;
        fala = f;
    }
    float get_envergadura(){return envergadura;}
    bool get_fala(){return fala;}

    void set_envergadura(bool e){envergadura = e;}
    void set_fala(bool f){fala = f;}
    
	void print_info() { 
        animal::print_info();
        cout << "   Envergadura:" << envergadura << endl; 
        cout << "   Fala:" << fala << endl; 
	}
    ~ave(){
        //destrutpr
    };
};

class felino : public animal{
    string pelagem;
    float garraTam;
public:
    felino(const string& n, int i, const string& p,float g):animal(n, i){
        pelagem = p;
        garraTam = g;
    }
    string get_pelagem(){return pelagem;}
    int get_garraTam(){return garraTam;}

    void set_pelagem(string p){pelagem = p;}
    void set_garraTam(float g){garraTam = g;}

    
	void print_info() { 
        animal::print_info();
        cout << "   Pelagem:" << pelagem << endl; 
        cout << "   Tamanho da garra:" << garraTam << endl; 
	}
    ~felino(){
        //destrutpr
    };
};

int main(){

    ave av1("Papagaio", 33, 0.4,1);
    felino f1("Leopardo", 3, "Amarela com pintinhas", 5);

    av1.print_info();
    f1.print_info();

    return 0;
}

