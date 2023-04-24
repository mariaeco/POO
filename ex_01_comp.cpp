/*
Faça um programa em C++ que contenha:
- uma classe que representa um funcionário, registrando seu nome, CPF, 
salário e idade. 
- uma classe departamento que representa uma subparte de uma empresa,
contendo nome, código e um array de funcionários.
- uma classe que representa uma empresa, registrando seu nome, CNPJ e 
um array de departamentos.

Defina os atributos das classes como privados e crie métodos públicos 
para acessar e modificar os atributos. Crie também um método que exiba na 
tela todos os atributos de um objeto da classe (método print_info()).

Finalmente, faça um programa que: 
    • Crie uma empresa; 
    • Crie dois departamentos (departamento A e departamento B);
    • Crie cinco funcionários (dois para o departamento A e três para o B);
    • Solicite ao usuário o código de um departamento e realize o aumento 
      de 10% do salário dos empregados do departamento escolhido.
*/
#include <iostream>
#include <string.h>

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
    funcionario equipe;// aqui coloco o funcionario do departamento
public:
    departamento(const string& ndep, int cod, 
                    const string& n, const string& c, int i, float s):
                    equipe(n,c,i,s){//construtor
        nome = ndep;
        codigo = cod;
    }
    //gets and sets
    string get_nome(){return nome;}
    int get_codigo(){return codigo;}

    void set_nome(string ndep){nome = ndep;}
    void set_codigo(int cod){codigo = cod;}

    void aumento(float pct){//aumenta o salario
        float newsalario = equipe.get_salario()*pct;
        equipe.set_salario(newsalario);
    }

    
    void print_info(){
        cout << "\t\t------- Departamento -----"<< endl;
        cout << "\t\t Departamento:"<< nome << endl;
        cout << "\t\t Codigo: "<< codigo << endl;
        equipe.print_info();
    }
    ~departamento(){cout << "Departamento finalizado"<< endl;}//destrutor


};



class empresa{
    string nome;
    string cnpj;
    departamento setor;//aqui coloco o departamento da empresa
public:
    empresa(const string &nemp, const string& cn, 
            const string& ndep, int cod, 
            const string& n, const string& c, int i, float s):
            setor(ndep,cod,n,c,i,s){//construtor
        nome = nemp;
        cnpj = cn;
    }
    //gets and sets
    string get_nome(){return nome;}
    string get_cnpj(){return cnpj;}

    void set_nome(string nemp){nome = nemp;}
    void set_cnpj(string cn){cnpj = cn;}

    
    void print_info(){
        cout << "------- Empresa -----"<< endl;
        cout << "\t Nome Empresarial:"<< nome << endl;
        cout << "\t C.N.P.J: "<< cnpj << endl;
        setor.print_info();
    }
    ~empresa(){cout << "Empresa finalizada"<< endl;}//destrutor

};

int main(){

    empresa e1("UFPB","24.098.477/0001-10","Departamento de Agroecologia",
                9,"Tiago Augusto", "123.532.761-01",38, 6583.32);
    departamento d1("Departamento de Agroecologia", 9,"Tiago Augusto",
                     "123.532.761-01",38, 6583.32);
    funcionario f1("Tiago Augusto", "123.532.761-01",38, 6583.32);
    
    e1.print_info();
    d1.print_info();
    f1.print_info();

    d1.aumento(1.8);
    d1.print_info();
    
    return 0;
}