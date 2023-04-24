/*
Classes: public, private, methods
*/
#include <iostream>
#include <string.h>

//using std::cout;
//using std::endl;
//using std::string;
using namespace std;

//crio o objeto antes do main
class Aviao{
private: // coloco os atributos como privados
    string nome;
    string porte;
    int velocidade;
public: // como public colocamos as funcoes
    // sempre defino os gets e sets para cada variavel
    // get obtem o valor atual:
    string get_nome(){ return nome;} 
    string get_porte(){return porte;}
    int get_velocidade(){ return velocidade;} 
    //set define o novo valor:
    void set_nome(string n){
        nome = n;
    }
    void set_porte(string p){
        porte = p;
    }
    void set_velocidade(int v){ 
        velocidade = v;
    }
    // preciso tambem fazer o construtor do classe
    Aviao(string n, string p, int v ){
        cout << "------- Aviao iniciado-------" << endl;
        nome = n;
        porte = p;
        velocidade = v;
    }
    // preciso tambem fazer o ~destrutor do classe
    ~Aviao(){
        cout << "------- Aviao: "<< nome <<" finalizado-------" << endl;
    }
    // para imprimir os resultados
    void print_Aviao(){
        cout << "Aviao::nome = " << nome;
        cout << endl;
        cout << "Aviao::porte = " << porte;
        cout << endl;
        cout << "Aviao::velocidade = " << velocidade;
        cout << endl;     
        cout << endl;       
    }
};


//funcoes que utiliam a classe
void mudaVelocidade(Aviao a){
    a.set_velocidade(1000);
    printf("Sem ponteiros criamos uma copia\n");
}
void mudaVelocidadePtr(Aviao *a){
    a->set_velocidade(300);
    printf("Com ponteiro Nao criamos copia\n");
}

void mudaVelocidadeRef(Aviao &a){
    int vel;
    cout << "Digite a nova velocidade: ";
    cin >> vel;
    a.set_velocidade(vel);
    //ponteiro e referencia em c eh diferente
    printf("Com endereço Nao criamos copia\n");
}

int main(){

    Aviao a1("Boeing 777",  "Grande", 920);
    a1.print_Aviao();

    a1.set_nome("Delta Air Line");
    a1.print_Aviao();

    Aviao a2("Cessna Grand Caravan","Grande", 320);
    a2.print_Aviao();

    Aviao *a3 = new Aviao("Concorde", "Medio", 2549);
    a3->print_Aviao();
    
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << endl;

    mudaVelocidade(a2);
    a2.print_Aviao();
    mudaVelocidadePtr(&a2);
    a2.print_Aviao();
    mudaVelocidadeRef(a2);
    a2.print_Aviao();
    
    //printf("Endereco main %p\n", &a);
    //cout << "[3] Valor da Referencia = " << a2.get_largura() << endl;

    delete a3;// No caso, quando uso ponteiro preciso usar o new
    // ou seja aloco dinamicamente pelo new, mas o destrutor
    // la em cima nao eh utilizado...
    // Assim preciso deleta-lo aqui.
    // observe que se vc comentar o delete a3, o aviao nao eh finalizado
    return 0;
}