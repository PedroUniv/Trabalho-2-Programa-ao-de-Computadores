/******************************************************************************

Disciplina: INF101 - Programação de Computadores I
Nome: Pedro Henrique Miranda de Carvalho
Data: 07/11/2026
Descição: Trabalho – Implementação de um Sistema de Registro e Gestão de Contas Bancárias (ETAPA 2)

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    //Variaveis

const int MAX_CONTAS = 100; // é previsto um limite máximo de 100 contas
int numeroConta[MAX_CONTAS];
string nomeCliente[MAX_CONTAS];
string cpf[MAX_CONTAS];
int tipoConta[MAX_CONTAS];
double saldo[MAX_CONTAS];
bool contaAtiva[MAX_CONTAS];
int quantidadeContas = 0;
int banco;
double valor;

int Poupanca = 1, Corrente = 2;

const int MAX_MOVIMENTACOES = 500;
int contaMovimentacao[MAX_MOVIMENTACOES];
char tipoMovimentacao[MAX_MOVIMENTACOES];
double valorMovimentacao[MAX_MOVIMENTACOES];
int quantidadeMovimentacoes = 0;

//Codigo

do{    
    cout << ("\n***************************\n");
    cout << ("**   BANCO PEDROBANK'S   **\n");
    cout << ("***************************\n");
    cout << "1 - Cadastrar Contas\n";
    cout << "2 - Listar as contas cadastradas\n";
    cout << "3 - Consultar uma conta pelo número.\n";
    cout << "4 - Realizar depósitos\n";
    cout << "5 - Realizar saques, verificando saldo suficiente\n";
    cout << "6 - Realizar transferências entre duas contas\n";
    cout << "7 - Exibir o extrato de uma conta\n";
    cout << "Escolha uma opção: ";  
    cin >> banco;  
    
    //Seguir ordem, numeroConta, nomeCliente, cpf, tipoConta (Poupança/Corrente), saldoAtual

    cin.ignore();

    switch (banco){
        
    // 1 -Cadastrar Contas
        
    case 1:
    if (quantidadeContas >= MAX_CONTAS){
        cout << ("Ja tem uma conta cadastrada com essas informações\n");
        break;
    } 
    
    cout << ("Numero da conta: ");
    cin >> numeroConta[quantidadeContas];
    if (numeroConta[quantidadeContas] <= 0){
        cout << ("Numero da conta deve ser maior que zero\n");
        break;
    }
    
    cin.ignore();
    
    cout << ("Digite seu nome completo: ");
    getline(cin, nomeCliente[quantidadeContas]);

    

    cout << ("Digite seu cpf (Sem pontuação):");
    cin >> cpf[quantidadeContas];
    
    cout << ("Tipo da conta: \n");
    cout << ("1 - Poupança \n");
    cout << ("2 - Corrente \n");
    cin >> tipoConta[quantidadeContas];
    
    switch (tipoConta[quantidadeContas]){
        case 1:
        if (Poupanca == 1){
            cout << ("Conta Poupança selecionada: ") << endl;
        } break;
        
        case 2:
        if (Corrente == 2){
            cout << ("Conta Corrente selecionada: ") << endl;
            break;
        }
     
        default:
        cout << ("Opção invalida.");
        break;
    }
    
    cout << ("Digite seu saldo atual: ");
    cin >> saldo[quantidadeContas];
    if(saldo[quantidadeContas] <= 0){
        cout << ("Saldo menor ou igual a 0 invalido!");
    }
    
    contaAtiva[quantidadeContas] = true;
    quantidadeContas++;
    break;
    
    // 2 - Listar as contas cadastradas
    
    case 2:
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada no momento.\n";
            break;
        }

        cout << "\n===== LISTA DE CONTAS CADASTRADAS =====\n";
        
        for (int i = 0; i < quantidadeContas; i++) {
            cout << "\n---- Dados da Conta " << (i + 1) << " ----\n";
            cout << "Numero da Conta: " << numeroConta[i] << "\n";
            cout << "Nome do Titular: " << nomeCliente[i] << "\n";
            cout << "CPF do Titular: " << cpf[i] << "\n";
            
            // Verifica o tipo da conta
            if (tipoConta[i] == Poupanca) {
                cout << "Tipo: Conta Poupança\n";
            } else {
                cout << "Tipo: Conta Corrente\n";  
            }
            
            cout << "Saldo da Conta: R$ " << saldo[i] << "\n";
            
            // Verifica se a conta está ativa usando o índice [i]
            if (contaAtiva[i]) {
                cout << "Status: Conta Ativa\n";
            } else {
                cout << "Status: Conta Inativa/Encerrada\n";
            }
        }
        break;    
    
    
    // 3 - Consultar uma conta pelo número
    
    case 3:
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada no momento.\n";
            break;
        }

        cout << "Digite o numero da conta que deseja consultar: ";
        cin >> banco; 

        for (int i = 0; i < quantidadeContas; i++) {
            
            if (numeroConta[i] == banco) {
                cout << "\n---- Dados da Conta ----\n";
                cout << "Numero da Conta: " << numeroConta[i] << "\n";
                cout << "Nome do Titular: " << nomeCliente[i] << "\n";
                cout << "CPF do Titular: " << cpf[i] << "\n";
                
                if (tipoConta[i] == Poupanca) {
                    cout << "Tipo: Conta Poupanca\n";
                } else {
                    cout << "Tipo: Conta Corrente\n";
                }

                cout << "Saldo da Conta: R$ " << saldo[i] << "\n";
                
                if (contaAtiva[i]) {
                    cout << "Status: Conta Ativa\n";
                } else {
                    cout << "Status: Conta Inativa\n";
                }

                banco = -1;
                break; 
            }
        }

        if (banco != -1) {
            cout << "Conta nao encontrada!\n";
        }
        break;
    
    // 4 - Realizar depósitos
    
    
    case 4:
            if (quantidadeContas == 0) {
                cout << "Nenhuma conta cadastrada no sistema.\n";
                break;
            }
    
            cout << "Digite o numero da conta para deposito: ";
            cin >> banco; 
    
            for (int i = 0; i < quantidadeContas; i++) {
                
                if (numeroConta[i] == banco) {
                    
                    if (!contaAtiva[i]) {
                        cout << "Esta conta esta inativa e nao pode receber depositos.\n";
                        banco = -1; 
                        break;
                    }
    
                    cout << "Qual valor deseja depositar? R$ ";
                    cin >> valor; 
    
                    if (valor <= 0) {
                        cout << "O valor do deposito deve ser maior que zero.\n";
                        banco = -1; 
                        break;
                    }
    
                    
                    saldo[i] = saldo[i] + valor;
    
                    
                    contaMovimentacao[quantidadeMovimentacoes] = numeroConta[i];
                    tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                    valorMovimentacao[quantidadeMovimentacoes] = valor;
                    quantidadeMovimentacoes++;
    
                    cout << "Deposito de R$ " << valor << " realizado com sucesso!\n";
                    
                    banco = -1; 
                    break; 
                }
            }
    
            if (banco != -1) {
                cout << "Conta nao encontrada!\n";
            }
            break;
        
        
    // 5 - Realizar saques, verificando saldo suficiente
    case 5:
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada no sistema.\n";
            break;
        }   
        
        cout << "Digite o numero da conta para sacar: ";
        cin >> banco; 
        
        for (int i = 0; i < quantidadeContas; i++) {
            
            if (numeroConta[i] == banco) { 
                
                
                if (!contaAtiva[i]) {
                    cout << "Esta conta esta inativa e nao pode ser feito saques.\n";
                    banco = -1; 
                    break;
                }
                
                
                cout << "Qual valor deseja sacar? R$ ";
                cin >> valor;
                
                if (valor <= 0) {
                    cout << "O valor do saque deve ser maior que zero.\n";
                    banco = -1;
                    break;
                }
                
                
                if (saldo[i] < valor) {
                    cout << "Saldo insuficiente! Saldo atual: R$ " << saldo[i] << "\n";
                    banco = -1; 
                    break;
                }
                
                
                saldo[i] = saldo[i] - valor;
                
                contaMovimentacao[quantidadeMovimentacoes] = numeroConta[i];
                tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                valorMovimentacao[quantidadeMovimentacoes] = valor;
                quantidadeMovimentacoes++;
                
                cout << "Saque de R$ " << valor << " realizado com sucesso!\n";
                cout << "Novo saldo: R$ " << saldo[i] << "\n";
                
                banco = -1; 
                break; 
            }
        }
        
        if (banco != -1) {
            cout << "Conta nao encontrada!\n";
        }
        break;
        
    // 6 - Realizar transferências entre duas contas
    
    case 6:
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada no sistema.\n";
            break;
        }   
            
        cout << "Digite o numero da sua conta: ";
        cin >> banco; // Guarda a conta de origem na variável 'banco'
        
        cout << "Digite o numero da conta que deseja transferir: ";
        cin >> contaMovimentacao[quantidadeMovimentacoes]; 
            
        for (int i = 0; i < quantidadeContas; i++) {
            
            if (numeroConta[i] == banco) { 
                
                if (!contaAtiva[i]) {
                    cout << "A conta de origem esta inativa.\n";
                    banco = -1; 
                    break;
                }
                
                cout << "Qual valor deseja transferir? R$ ";
                cin >> valor;
                
                if (valor <= 0) {
                    cout << "O valor da transferencia deve ser maior que zero.\n";
                    banco = -1;
                    break;
                }
                
                if (saldo[i] < valor) {
                    cout << "Saldo insuficiente! Saldo atual: R$ " << saldo[i] << "\n";
                    banco = -1; 
                    break;
                }
                
                for (int j = 0; j < quantidadeContas; j++) {
                    
                    if (numeroConta[j] == contaMovimentacao[quantidadeMovimentacoes]) {
                        
                        if (!contaAtiva[j]) {
                            cout << "A conta de destino esta inativa.\n";
                            banco = -1;
                            break;
                        }
                        
                        saldo[i] = saldo[i] - valor;
                        saldo[j] = saldo[j] + valor;
                        
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[i];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'T';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;
                        quantidadeMovimentacoes++;
                        
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[j];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'T'; 
                        valorMovimentacao[quantidadeMovimentacoes] = valor;
                        quantidadeMovimentacoes++;
                        
                        cout << "Transferencia de R$ " << valor << " realizada com sucesso!\n";
                        cout << "Novo saldo da origem: R$ " << saldo[i] << "\n";
                        
                        banco = -1;
                        break;
                    }
                }
                break;
            }        
        }
        
        if (banco != -1) {
            cout << "Conta de origem ou destino nao encontrada!\n";
        }
        
       // 7 - Exibir o extrato de uma conta
       
        case 7:
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada no momento.\n";
            break;
        }

        cout << "Digite o numero da conta que deseja consultar: ";
        cin >> banco; 

        for (int i = 0; i < quantidadeContas; i++) {
            
            if (numeroConta[i] == banco) {
                cout << "\n---- Dados da Conta ----\n";
                cout << "Numero da Conta: " << numeroConta[i] << "\n";
                cout << "Nome do Titular: " << nomeCliente[i] << "\n";
                cout << "CPF do Titular: " << cpf[i] << "\n";
                
                if (tipoConta[i] == Poupanca) {
                    cout << "Tipo: Conta Poupanca\n";
                } else {
                    cout << "Tipo: Conta Corrente\n";
                }

                cout << "Saldo da Conta: R$ " << saldo[i] << "\n";
                cout << "Valor total depositado: R$ " << valor << "\n";
                cout << "Valor total transferido para contas: R$ " << valorMovimentacao[quantidadeMovimentacoes] << "\n";
                
                if (contaAtiva[i]) {
                    cout << "Status: Conta Ativa\n";
                } else {
                    cout << "Status: Conta Inativa\n";
                }
                

                cout << "----------------------------------------\n";
                cout << "       HISTORICO DE MOVIMENTACOES       \n";
                cout << "----------------------------------------\n";

                // O laço 'm' percorre todas as movimentações do banco
                for (int m = 0; m < quantidadeMovimentacoes; m++) {
                    
                    // Se a movimentação for dessa conta que estamos consultando:
                    if (contaMovimentacao[m] == banco) {
                        
                        // Verifica o tipo e imprime bonitinho
                        if (tipoMovimentacao[m] == 'D') {
                            cout << "Deposito:       + R$ " << valorMovimentacao[m] << "\n";
                        } 
                        else if (tipoMovimentacao[m] == 'S') {
                            cout << "Saque:          - R$ " << valorMovimentacao[m] << "\n";
                        }
                        else if (tipoMovimentacao[m] == 'T') {
                            cout << "Transferencia:  - R$ " << valorMovimentacao[m] << "\n";
                        }
                    }
                }

                cout << "=================---====================\n";
                cout << "SALDO ATUAL: R$ " << saldo[i] << "\n";
                cout << "=================---====================\n";

                banco = -1;
                break;
            }
        }


        if (banco != -1) {
            cout << "Conta nao encontrada!\n";
        }
        break;
        
        
    default:
    cout << "Opção invalida" << "\n";
}
    
    
} while (banco != 100);

    return 0;
}