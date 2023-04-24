/*
Composicao: COM PONTEIRO
*/
#include <iostream>
#include <string.h>

//using std::cout;
//using std::endl;
//using std::string;
using namespace std;

#define MAX_NOTAS 5
#define MAX_COMP 12

class desempenho{
    float nota;
    float media;
    string componente;
    int qtd_notas;
public:
    desempenho(const string& c, float n){
        componente = c;
        nota = n;
        media = 0;
        qtd_notas = 0;
        cout << "Nota inserida" << endl;
    }
    string get_componente(){return componente;}
    float get_media(){return media;}
    float get_nota(){return nota;}

	void set_componente(string c) {componente = c;}
    void set_media(float m) {media = m;}
    void set_nota(float n){nota = n;}

    void print_info() {
        cout << componente << " = " << nota << endl;
    }

    ~desempenho(){
        cout << "Nota finalizada" << endl;
    }
};

class componente{
	string nome;
	int codigo;
	desempenho* notas[MAX_NOTAS];
    int qtd_notas;
    float soma = 0;
    float media;
public:
	componente(const string& n, int c) {
		nome = n;
		codigo = c;
        qtd_notas = 0;
	}

    string get_nome() {return nome;}  
	int get_codigo() {return codigo;}
    void set_nome(int n) {
		nome = n;
	}
	void set_codigo(int c) {
		codigo = c;
	}

    void add_nota(desempenho* n, int i){
        if (qtd_notas < MAX_NOTAS) {
			notas[i] = n;
			qtd_notas++;
		} else {
			cout << "aluno::add_nota() ERROR!";
			cout << endl;
		}
    }

    desempenho* get_desempenho(int i){
		return notas[i];
	}    
    
	void calculaMedia() {
		for (int i = 0; i < qtd_notas; i++) {
			float new_n = notas[i]->get_nota();
            soma += new_n;
            media = soma/qtd_notas;
            notas[i]->set_media(media);
		}
    }

    void print_media() {
         cout << " - Media Bimestral = " << media << endl;
    }

	void print_info() {
		cout << "-------------------------------------" << endl;
		cout << "Componente: " << nome << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Quantidade notas: " << qtd_notas << endl;
		for (int i = 0; i < qtd_notas; i++) {
			notas[i]->print_info();
		}
		cout << "-------------------------------------" << endl;
	}
    ~componente(){
        cout << "Aluno Finalizado" << endl;
    }
};

class info{
    string nome;
    string matricula;
    string cpf;
    int idade;
public:
    info(const string& n, const string& m, const string& c, int i){
        nome = n;
        matricula = m;
        cpf = c;
        idade = i;
        cout << "Aluno Cadastrado" << endl;
    }
    ~info(){
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

    void print_info() {
        cout << "------- Aluno Cadastrado -------" << endl;
        cout << "Nome = " << nome << endl;
        cout << "Matricula = " << matricula << endl;
        cout << "CPF = " << cpf << endl;
        cout << "Idade = " << idade << " anos" << endl;
    }
};

class aluno{
    info estudante;
    componente* d[MAX_COMP];
    int qtd_cmp;

public:
    aluno(string n, string m, string c, int i):estudante(n,m,c,i){
        qtd_cmp = 0;
        cout << "Aluno Criado" << endl;
    }
    ~aluno(){
        delete* d;
        cout << "Aluno Finalizado" << endl;
    }

    void add_componente(componente* n, int i) {
        if (qtd_cmp < MAX_COMP) {
            d[i] = n;
			qtd_cmp++;                
        } else {
            cout << "empresa::add_departamento() ERROR!";
            cout << endl;
            }
    }

    componente* get_componente(int i) {
        return d[i];
    }

    void print_info() {
        cout << "------- Informacoes do Aluno -------" << endl;
        estudante.print_info();
        cout << "Quantidade de Componentes: " << qtd_cmp;
        cout << endl;
        for (int i = 0; i < qtd_cmp; i++) {
           d[i]->print_info();
           d[i]->calculaMedia();
           d[i]->print_media();
        }
        cout << "------------------" << endl;

    }
};

int main(){
    aluno a1("Tiago","12312-4","582.542.456-00", 13);
    componente c1("Biologia", 1);
    componente c2("Portugues", 2);
    componente c3("Matematica", 3);

    //adicionando os componentes ao perfil do aluno
    a1.add_componente(&c1,0);
    a1.add_componente(&c2,1);
    a1.add_componente(&c3,2);
    
    //adicionando as notas do componente 1 - biologia
    desempenho d1("Nota 1",7.2);
    desempenho d2("Nota 2",4.3);
    desempenho d3("Nota 3",6.5);

    c1.add_nota(&d1,0);
    c1.add_nota(&d2,1);
    c1.add_nota(&d3,2);

    //adicionando as notas do componente 2 - portugues
    desempenho d4("Nota 1",8.2);
    desempenho d5("Nota 2",7.3);
    desempenho d6("Nota 3",8.5);
    desempenho d7("Nota 4",7.0);

    c2.add_nota(&d4,0);
    c2.add_nota(&d5,1);
    c2.add_nota(&d6,2);
    c2.add_nota(&d7,3);

    //adicionando as notas do componente 3 - matematica
    desempenho d8("Nota 1",5.3);
    desempenho d9("Nota 2",6.3);
    desempenho d10("Nota 3",4.5);
    desempenho d11("Nota 4",8.0);

    c3.add_nota(&d8,0);
    c3.add_nota(&d9,1);
    c3.add_nota(&d10,2);
    c3.add_nota(&d11,3);


    a1.print_info();


    return 0;
}