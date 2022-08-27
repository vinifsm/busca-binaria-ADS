#include <iostream>
#include <conio.h>
#include <string.h>
#include <locale.h>
using namespace std;

struct Alunos{
	int ra;
	char nome[40];
	char endereco[50];
	char telefone[11];
	char cidade[30];
	char uf[2];
	int status;
};

struct IdxAlunos{
	int cod;
	int end;
};

struct Editoras{
	int cod;
	char nome[40];
	char endereco[50];
	char telefone[11];
	char cidade[30];
	char uf[2];
	int status;
};

struct IdxEditoras{
	int cod;
	int end;
};

struct Livros{
	int cod;
	char desc[40];
	int codEdit;
	int status;
	char statusEmp[1];
};

struct IdxLivros{
	int cod;
	int end;
};

struct Emprestimo{
	int cod;
	int codRa;
	int codLivro;
	int anoEmp;
	int mesEmp;
	int diaEmp;
	int anoDev;
	int mesDev;
	int diaDev;
	int status;
	char statusEmp[1];
};

struct IdxEmprestimo{
	int cod;
	int end;
};

void mainMenu (){
	system("cls");
	cout << "\n\nMenu";
	cout << "\n0 - Sair";
	cout << "\n1 - Alunos";
	cout << "\n2 - Editoras";
	cout << "\n3 - Livros";
	cout << "\n4 - Empréstimos";
}

void leituraIdxAlunos (struct IdxAlunos idx[], int cont){
    for (int i = 0; i < cont; i++){
        cout << "\n\nCodigo do Indice do Aluno " << (i+1) << ": ";
        cin >> idx[i].cod;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].end;
    }
}

void leituraAlunos (struct Alunos a1[], struct IdxAlunos i1[], int &cont){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nRA do Aluno " << (i+1) << ": ";
        cin >> a1[i].ra;
        if (a1[i].ra > 0){
            cout << "Nome: ";
            cin >> a1[i].nome;
            cout << "Endereco: ";
            cin >> a1[i].endereco;
            cout << "Telefone: ";
            cin >> a1[i].telefone;
            cout << "Cidade: ";
            cin >> a1[i].cidade;
            cout << "Estado: ";
            cin >> a1[i].uf;            

			a1[i].status = 0;
        }
        else saida = 0;
    }
    cont = i-1;
    leituraIdxAlunos(i1,cont);
}

void leituraEditoras (struct Editoras e1[], struct IdxEditoras i1[], int &cont){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCodigo da Editora " << (i+1) << ": ";
        cin >> e1[i].cod;
        if (e1[i].cod > 0){
            cout << "Nome: ";
            cin >> e1[i].nome;
            cout << "Endereco: ";
            cin >> e1[i].endereco;
            cout << "Telefone: ";
            cin >> e1[i].telefone;
            cout << "Cidade: ";
            cin >> e1[i].cidade;
            cout << "Estado: ";
            cin >> e1[i].uf;
			i1[i].cod = e1[i].cod;
			i1[i].end = i;
			e1[i].status = 0;
        }
        else saida = 0;
    }
    cont = i-1;
}

void leituraLivros (struct Livros l1[], struct IdxLivros i1[], int &cont){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCodigo da Editora " << (i+1) << ": ";
        cin >> l1[i].cod;
        if (l1[i].cod > 0){
            cout << "Descrição: ";
            cin >> l1[i].desc;
            cout << "Codigo da Editora: ";
            cin >> l1[i].codEdit;
            cout << "Situação: ";
            cin >> l1[i].status;
			i1[i].cod = l1[i].cod;
			i1[i].end = i;
			l1[i].status = 0;
        }
        else saida = 0;
    }
    cont = i-1;
}

void incluirAlunos (struct Alunos a1[], struct IdxAlunos i1[], int &cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = i1[m].end;
    if ((cod == i1[m].cod)){
        cout << "\n\n Aluno já existe";
        cout << "RA: ";
    	cin >> cod;
    }
    else{
    	x = 1 ;
	}
}
    cont++;
	a1[cont].ra = cod;
    cout << "Nome: ";
    cin >> a1[cont].nome;
    cout << "Endereço: ";
    cin >> a1[cont].endereco;
    cout << "Telefone: ";
    cin >> a1[cont].telefone;
    cout << "Cidade: ";
    cin >> a1[cont].cidade;
    cout << "Estado: ";
    cin >> a1[cont].uf;
    a1[cont].status = 0;
    // inclusao na area de indices
    for (i = cont - 1; i1[i].cod > cod; i--){
        i1[i+1].cod = i1[i].cod;
        i1[i+1].end = i1[i].end;
    }
    i1[i+1].cod = cod;
    i1[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void incluirEditoras (struct Editoras e1[], struct IdxEditoras i1[], int &cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = i1[m].end;
    if ((cod == i1[m].cod)){
        cout << "\n\n Editora já existe";
        cout << "\nCódigo: ";
    	cin >> cod;
    }
    else{
    	x = 1 ;
	}
	}
    cont++;
	e1[cont].cod = cod;
    cout << "Nome: ";
    cin >> e1[cont].nome;
    cout << "Endereço: ";
    cin >> e1[cont].endereco;
    cout << "Telefone: ";
    cin >> e1[cont].telefone;
    cout << "Cidade: ";
    cin >> e1[cont].cidade;
    cout << "Estado: ";
    cin >> e1[cont].uf;
    e1[i].status = 0;
    for (i = cont - 1; i1[i].cod > cod; i--){
        i1[i+1].cod = i1[i].cod;
        i1[i+1].end = i1[i].end;
    }
    i1[i+1].cod = cod;
    i1[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void incluirLivros (struct Livros l1[], struct IdxLivros i1[], int &cont, int cod){
	int i = 0, f = cont, x = 0;
    int m = (i + f) / 2;
    while (x == 0){
    for (; f >= i && cod != i1[m].cod; m = (i + f) / 2){
        if (cod > i1[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = i1[m].end;
    if ((cod == i1[m].cod)){
        cout << "\n\n Livro já existe";
        cout << "Código: ";
    	cin >> cod;
    }
    else{
    	x = 1 ;
	}
	}
    cont++;
	l1[cont].cod = cod;
    cout << "Descricao: ";
    cin >> l1[cont].desc;
    cout << "Codigo da Editora: ";
    cin >> l1[cont].codEdit;
    cout << "Status: ";
    cin >> l1[cont].status;
    l1[i].status = 0;
    for (i = cont - 1; i1[i].cod > cod; i--){
        i1[i+1].cod = i1[i].cod;
        i1[i+1].end = i1[i].end;
    }
    i1[i+1].cod = cod;
    i1[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}

void excluirLivros (struct IdxLivros idx[], struct Livros l1[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && l1[i].status == 0){
        l1[i].status = 1;
        cout << "\n\n Livro Excluido com Sucesso";
    }
    else
        cout << "Livro nao cadastrado!";
    
}

void excluirAlunos (struct IdxAlunos idx[], struct Alunos a1[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && a1[i].status == 0){
        a1[i].status = 1;
        cout << "\n\n Aluno Excluido com Sucesso";
    }
    else
        cout << "Aluno nao cadastrado !";
    
}

void excluirEditoras (struct IdxEditoras idx[], struct Editoras e1[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && e1[i].status == 0){
        e1[i].status = 1;
        cout << "\n\n Editora excluida com Sucesso";
    }
    else
        cout << "Editora nao cadastrada";
    
}

void mostrarAlunos(struct Alunos a1[], struct IdxAlunos i1[], int cont){
	int m;
	cout << "\n\nAlunos" << endl;
	for(int i=0;i<cont;i++){
		m=i1[i].end;
		if(a1[m].status==0){
		cout << "RA:" << a1[m].ra << endl;
		cout << "Nome:" << a1[m].nome << endl;
		cout << "Endereço" << a1[m].endereco << endl;
		cout << "Telefone" << a1[m].telefone << endl;
		cout << "Cidade" << a1[m].cidade << endl;
		cout << "Estado:" << a1[m].uf << endl;		
	}
}
getch();
}

void menuAlunos (struct Alunos a1[], struct IdxAlunos i1[], int &cont){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	system("cls");
	cout << "\n\nAlunos";
	cout << "\n0 - Voltar";
	cout << "\n1 - Ler Alunos";
	cout << "\n2 - Incluir Alunos";
	cout << "\n3 - Excluir Alunos";
	cout << "\n4 - Mostrar Alunos";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			leituraAlunos(a1,i1,cont);
			break;
		case 2:
			cout << "\n\nInclusão de Aluno";
			cout << "RA: ";
    		cin >> cod;
			incluirAlunos(a1,i1,cont,cod);
			break;
		case 3:
			cout << "\n\nExclusão de Aluno";
			cout << "Digite o código do aluno que deseja excluir: ";
    		cin >> cod;
			excluirAlunos(i1,a1,cont,cod);
			break;
		case 4:
			mostrarAlunos(a1,i1,cont);
			break;
		case 0:
			x=1;
			break;		
		}
	}
}

void menuEditoras (struct Editoras e1[], struct IdxEditoras i1[], int &cont){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	system("cls");
	cout << "\n\nEditoras";
	cout << "\n0 - Voltar";
	cout << "\n1 - Ler Editoras";
	cout << "\n2 - Incluir Editoras";
	cout << "\n3 - Excluir Editoras";
	cout << "\n4 - Mostrar Editoras";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			leituraEditoras(e1,i1,cont);
			break;
		case 2:
			cout << "\n\nInclusão de Editora";
			cout << "Codigo: ";
    		cin >> cod;
			incluirEditoras(e1,i1,cont,cod);
			break;
		case 3:
			cout << "\n\nExclusão de Editora";
			cout << "Digite o código da editora que deseja excluir: ";
    		cin >> cod;
			excluirEditoras(i1,e1,cont,cod);
			break;
/*		case 4:
			mostrarEditoras(e1,i1,cont);
			break;*/
		case 0:
			x=1;
			break;		
		}
	}
}

void menuLivros (struct Livros l1[], struct IdxLivros i1[], int &cont){
	int option = 0, x = 0, cod = 0;
	
	while(x == 0){
	system("cls");
	cout << "\n\nLivros";
	cout << "\n0 - Voltar";
	cout << "\n1 - Ler Livros";
	cout << "\n2 - Incluir Livros";
	cout << "\n3 - Excluir Livros";
	cout << "\n4 - Mostrar Livros";
	cout << "\n\nDigite sua opção: ";
	cin >> option;
	
	switch(option){
		case 1:
			leituraLivros(l1,i1,cont);
			break;
		case 2:
			cout << "\n\nInclusão de Livros";
			cout << "Codigo: ";
    		cin >> cod;
			incluirLivros(l1,i1,cont,cod);
			break;
		case 3:
			cout << "\n\nExclusão de Livros";
			cout << "Digite o código do Livro que deseja excluir: ";
    		cin >> cod;
			excluirLivros(i1,l1,cont,cod);
			break;
/*		case 4:
			mostrarLivros(l1,i1,cont);
			break;*/
		case 0:
			x=1;
			break;		
		}
	}
}

int main (){
	struct Alunos a1[20]; struct Editoras e1[20]; struct Livros l1[20];
	struct IdxAlunos ia1[20]; struct IdxEditoras ie1[20]; struct IdxLivros il1[20];
	int x = 1, option = 0, contA, contE, contL;
	setlocale(LC_ALL,"Portuguese");
	
	while(x == 1){
		mainMenu();
		
		cout << "\n\nDigite sua opção: ";
		cin >> option;
		
		switch(option){
			case 1:
				menuAlunos(a1,ia1,contA);
				break;
			case 2:
				menuLivros(l1,il1,contL);
				break;
			case 3:
				menuEditoras(e1,ie1,contE);
				break;
			case 0:
				x=1;
				break;
		
	}
}
getch();
}
