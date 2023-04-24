/*
Exercício 2 - HERANCA
    MESMO EX DE ex_04_her.cpp
    Mas agora com n alunos 
 */
#include <iostream>
#include <string.h>

using namespace std;


class pessoa{
    string nome;
    int idade;
public:
    pessoa(const string& n, int i){
        nome = n;
        idade = i;
    }
    string get_nome(){return nome;}
    int get_idade(){return idade;}

    void set_nome(string n){nome = n;}
    void set_idade(int i){idade = i;}

	void print_info() { 
		cout << "------------------ PESSOA ----------------------" << endl;
        cout << "   Nome:" << nome << endl; 
        cout << "   Idade:" << idade << endl; 
	}
    ~pessoa(){
        //destrutpr
    };
};

class aluno:public pessoa{
    string curso;
public:
    aluno(const string& n, int i, const string& c):pessoa(n,i){
        curso = c;
    }
    string get_curso(){return curso;}

    void set_curso(string c){curso = c;}

	void print_info() { 
        pessoa::print_info();
        cout << "   Curso:" << curso << endl; 
	}
    ~aluno(){
        //destrutpr
    };
};

class funcionario: public pessoa{
    string cargo;
    float salario;
public:
    funcionario(const string& n, int i, const string& c, float s):pessoa(n,i){
        cargo = c;
        salario = s;
    }
    string get_cargo(){return cargo;}
    float get_salario(){return salario;}

    void set_cargo(string c){cargo = c;}
    void set_salario(float s){salario = s;}

	void print_info() { 
        pessoa::print_info();
        cout << "   Cargo:" << cargo << endl; 
        cout << "   Salario:" << salario << endl; 
	}

    void print_info2() { //para estudanteTrabalhador
        cout << "   Cargo:" << cargo << endl; 
        cout << "   Salario:" << salario << endl; 
	}
    ~funcionario(){
        //destrutpr
    };
};

class estudanteTrabalhador:public aluno,public funcionario{
    int horasTrabalhadas;
public:
    estudanteTrabalhador(const string& n, int i, 
                        const string& c,
                        const string& cg, float s, 
                        int h):aluno(n,i,c), funcionario(n,i,cg,s){
        horasTrabalhadas = h;
    }
    int get_horas(){return horasTrabalhadas;}

    void set_curso(int h){horasTrabalhadas = h;}

	void print_info() { 
        aluno::print_info();
        funcionario::print_info2();
        cout << "   Horas Trabalhadas:" << horasTrabalhadas << endl; 
	}
    ~estudanteTrabalhador(){
        //destrutpr
    };
};


int main(){

    funcionario f1("Tiago", 33, "Tecnico de Lab", 7000);
    aluno a1("Joao", 25, "Pedogia");
    estudanteTrabalhador e1("Helena", 32, "Matematica", "Tecnico Adm", 6000, 40);

    f1.print_info();
    a1.print_info();
    e1.print_info();


    return 0;
}

