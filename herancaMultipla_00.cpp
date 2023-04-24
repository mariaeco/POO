#include <iostream>

//O correto seria usar composicao, e o erro de ambiguidade da
//funcao usar() nao aconteceria - tesoura e chave_fenda seriam
//parte de canivete suico e se externalizariam os metodos usar
//de forma nao ambigua (ex: tesoura_usar() e chave_fenda_usar()
//na classe canivete suico.

using std::cout;
using std::endl;

class tesoura {
	float tamanho_lamina;
public:
	tesoura(float tl) { tamanho_lamina = tl; }
	void usar() {
		cout << "tesoura(" << tamanho_lamina;
		cout << ")::usar() " << endl;
	}
};

class chave_fenda {
	float tamanho_fenda;
public:
	chave_fenda(float tf) { tamanho_fenda = tf; } 
	void usar() { 
		cout << "chave_fenda(" << tamanho_fenda;
		cout << ")::usar() " << endl;
	}
};

class canivete_suico : public tesoura, public chave_fenda {
	int ano_fabricacao;
public:
	canivete_suico(float tl, float tf, int af) : 
		tesoura(tl), chave_fenda(tf) {
		
		ano_fabricacao = af;
	}
	void usar() {
		cout << "canivete_suico(" << ano_fabricacao;
		cout << ")::usar() " << endl;
	}
};

int main(void) {
	canivete_suico cs1(20, 0.5, 2021);

	cs1.usar();

	cs1.tesoura::usar();
	cs1.chave_fenda::usar();
}
