/*
Composicao: Na composicao tenho o desempenho dos alunos
Tenho a classe aluno que eh composta pela subclasse informacoes do aluno
e desempenho
*/
#include <iostream>
#include <string.h>

//using std::cout;
//using std::endl;
//using std::string;
using namespace std;

#define MAX_NOTA 3

class desempenho{
    float nota1, nota2, nota3;
    float media;

public:
    desempenho(float n1, float n2, float n3){
        nota1 = n1;
        nota2 = n2;
        nota3 = n3;

        cout << "Notas inseridas" << endl;
    }
    float get_nota(){return nota1,nota2,nota3;}
    float get_media(){return media;}
    void set_nota(float n1, float n2, float n3){
        nota1 = n1;
        nota2 = n2;
        nota3 = n3;
    }
    void set_media(float m) {media = m;}

    void calculaMedia(){
        media = (nota1+nota2+nota3)/MAX_NOTA;
        cout << "Media = " << media << endl;
    }

    void print_info() {
        cout << "   Nota 1 = " << nota1 << endl;
        cout << "   Nota 2 = " << nota2 << endl;
        cout << "   Nota 3 = " << nota3 << endl;
    }

    ~desempenho(){
        cout << "Nota finalizada" << endl;
    }
};

class componente{
	string nome;
	int codigo;
	desempenho notas;
public:
	componente(const string& n, int c,float n1, float n2, float n3):
    notas(n1,n2,n3){
		nome = n;
		codigo = c;
	}

    string get_nome() {return nome;}  
	int get_codigo() {return codigo;}
    void set_nome(int n) {
		nome = n;
	}
	void set_codigo(int c) {
		codigo = c;
	}

	void print_info() {
		cout << endl;
		cout << "Componente: " << nome << endl;
		cout << "Codigo: " << codigo << endl;
        notas.print_info();
        notas.calculaMedia();
		cout << "-------------------------------------" << endl;
	}
    ~componente(){
        cout << "Aluno Finalizado" << endl;
    }
};

class aluno{
    string nome;
    string matricula;
    string cpf;
    int idade;
    componente disciplina;
public:
    aluno(const string& n, const string& m, const string& c, int i,
            const string& disc, int cod,float n1, float n2, float n3):disciplina(disc,cod,n1,n2,n3){
        nome = n;
        matricula = m;
        cpf = c;
        idade = i;
        cout << "Aluno Cadastrado" << endl;
    }
    ~aluno(){
        cout << "Aluno Finalizado" << endl;
    }
    string get_nome(){return nome;}
    string get_matricula(){return matricula;}
    string get_cpf(){return cpf;}
    int get_idade(){return idade;}
    
    void set_nome(string n){nome = n;}
    void set_matricula(string m){matricula = m;}
    void set_cpf(string c){cpf= c;}
    void set_idade(int i){idade = i;}

    void print_info(){
        cout << "------- Aluno Cadastrado -------" << endl;
        cout << "Nome = " << nome << endl;
        cout << "Matricula = " << matricula << endl;
        cout << "CPF = " << cpf << endl;
        cout << "Idade = " << idade << " anos" << endl;
        disciplina.print_info();
    }
};

int main(){
    aluno a1("Tiago Cardoso","12312-4","582.542.456-00", 13, "Biologia", 1, 7.0, 8.3, 6.8);
    aluno a2("Joana Silva","03341-7","246.384.652-31", 12, "Portugues", 1, 5.5, 7.3, 4.8);

    desempenho d1(7,4,3);

    a1.print_info();
    a2.print_info();

    d1.print_info();
    d1.calculaMedia();
    //a1.calculaMedia();// nao acha, pq nao herda --> ja em heranca herdaria

    return 0;
}