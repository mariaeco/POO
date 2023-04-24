/*
MESMO EXERCICIO ANTERIOR MAIS AGORA COM VETORES DE VARIOS FUNCIONARIOS E VARIOS DEPARTAMENTOS
USO AGORA PONTEIRO
*/
#include <iostream>
#include <string.h>

#define MAX_FUNC 30
#define MAX_DEP 12

using namespace std;

class funcionario{
    string nome;
    string cpf;
    float salario;
    int idade;
public:
    funcionario(const string& n, const string& c, int i, float s){//construtor
        nome = n;
        cpf = c;
        salario = s;
        idade = i;
    }
    //gets and sets
    string get_nome(){return nome;}
    string get_cpf(){return cpf;}
    float get_salario(){return salario;}
    int get_idade(){return idade;}

    void set_nome(string n){nome = n;}
    void set_cpf(string c){cpf = c;}
    void set_salario(float s){salario = s;}
    void set_idade(int i){idade = i;}
    
    void print_info(){
        cout << "\t\t\tFuncionario -----"<< endl;
        cout << "\t\t\t Nome:"<< nome << endl;
        cout << "\t\t\t C.P.F::"<< cpf << endl;
        cout << "\t\t\t Idade:"<< idade << endl;
        cout << "\t\t\t Salario: R$ "<< salario << endl;
    }
    ~funcionario(){cout << "Funcionario finalizado"<< endl;}//destrutor

};

class departamento{
    string nome;
    int codigo;
    funcionario *equipe[MAX_FUNC];// aqui coloco os varios funcionarios do departamento
    int qtd_func;
public:
    departamento(const string& ndep, int cod){
        //com ponteiro ja nao funciona a composicao no formato anterior do ex_01_comp.cpp
        nome = ndep;
        codigo = cod;
        qtd_func = 0;
    }
    //gets and sets
    string get_nome(){return nome;}
    int get_codigo(){return codigo;}

    void set_nome(string ndep){nome = ndep;}
    void set_codigo(int cod){codigo = cod;}

    //tenho que gerar uma funcao para adicionar os diversos funcionarios que desejo
    void addFuncionario(funcionario *f, int i){
        // um ponteiro para um funcionario que vou alocar no departamento i
        if(qtd_func<MAX_FUNC){
            equipe[i] = f;
            qtd_func++;
        }else{
            cout << "Departamento lotado" << endl;
        }
    }

    //tenho que ter uma funcao para pegar o funcionario
    funcionario *get_funcionario(int i){
        return equipe[i];
    }

    void aumento(float pct){//aumenta o salario
        for(int i=0; i<qtd_func;i++){
            float newsalario = equipe[i]->get_salario()*pct;
            equipe[i]->set_salario(newsalario);
        }
    }

    
    void print_info(){
        cout << "\t\t------- Departamento -----"<< endl;
        cout << "\t\t Departamento:"<< nome << endl;
        cout << "\t\t Codigo: "<< codigo << endl;
        for(int i=0; i<qtd_func;i++){
            equipe[i]->print_info();
        }
    }
    ~departamento(){cout << "Departamento finalizado"<< endl;}//destrutor


};

class empresa{
    string nome;
    string cnpj;
    departamento *setor[MAX_DEP];//aqui coloco os varios departamentos da empresa
    int qtd_dep;
public:
    empresa(const string &nemp, const string& cn){//construtor
        nome = nemp;
        cnpj = cn;
        qtd_dep = 0;
    }
    //gets and sets
    string get_nome(){return nome;}
    string get_cnpj(){return cnpj;}

    void set_nome(string nemp){nome = nemp;}
    void set_cnpj(string cn){cnpj = cn;}

        //tenho que gerar uma funcao para adicionar os diversos funcionarios que desejo
    void addDepartamento(departamento *d, int i){
        // um ponteiro para um departamento que vou alocar na empresa i
        if(qtd_dep<MAX_DEP){
            setor[i] = d;
            qtd_dep++;
        }else{
            cout << "Empresa lotada" << endl;
        }
    }    

    //tenho que ter uma funcao para pegar o codigo do departamento
    departamento *get_departamento(int i){
        return setor[i];
    }

    departamento *get_cod_dep(int d){
        for(int i=0; i<qtd_dep;i++){
            if(setor[i]->get_codigo()==d){
                return setor[i];
            }
        };
    }

    void print_info(){
        cout << "------- Empresa -----"<< endl;
        cout << "\t Nome Empresarial:"<< nome << endl;
        cout << "\t C.N.P.J: "<< cnpj << endl;
        for(int i=0; i<qtd_dep;i++){
            setor[i]->print_info();
        };
    }
    ~empresa(){cout << "Empresa finalizada"<< endl;}//destrutor
};

int main(){

    empresa e1("UFPB","24.098.477/0001-10");
    departamento d1("Departamento de Agroecologia", 9);
    departamento d2("Departamento de Ciencias da Computacao", 10);
    funcionario f1("Tiago Augusto", "123.532.761-01",38, 6583.5);
    funcionario f2("Artur Lacerda", "841.508.472-33",44, 10355.1);
    funcionario f3("Liliane", "841.508.472-33",48, 12423.4);

    e1.addDepartamento(&d1,0);//adicionando o departamento na empresa
    e1.addDepartamento(&d2,1);//adicionando o departamento na empresa

    d1.addFuncionario(&f1,0);// adicionando o funcionario ao departamento0
    d1.addFuncionario(&f2,1);// adicionando o funcionario ao departamento0
    d2.addFuncionario(&f3,0);// adicionando o funcionario ao departamento0

    cout << endl;
    e1.print_info();

    d1.aumento(1.8);// veja que ele realiza o aumento do salario
    d2.aumento(2);
    e1.print_info();// o aumento tb eh repassado na classe empresa, 

    cout << endl;
    e1.print_info();

    return 0;
}
