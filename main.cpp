#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Para a função std::shuffle

using namespace std;

// Função para remover acentos e caracteres especiais de uma string
string removerAcentos(const string& str) {
    string novaStr;
    for (char c : str) {
        if (isalnum(c) || c == ' ') {
            novaStr += c;
        }
    }
    return novaStr;
}

// Estrutura para armazenar uma pergunta com suas opções e resposta correta
struct Question {
    string question;
    vector<string> options;
    char correctOption;
};

// Função para exibir uma pergunta e suas opções
void displayQuestion(const Question& q) {
    cout << q.question << endl;
    for (size_t i = 0; i < q.options.size(); ++i) {
        cout << char('A' + i) << ") " << q.options[i] << endl;
    }
}

// Função para verificar se a resposta fornecida é correta
bool checkAnswer(const Question& q, char answer) {
    return (toupper(answer) == toupper(q.correctOption));
}

int main() {
    // Inicialização do gerador de números aleatórios
    srand(time(nullptr));

    // Definição das perguntas e respostas
    vector<Question> allQuestions = {
        {"Qual e a capital do Brasil?",
         {"Rio de Janeiro", "Sao Paulo", "Brasilia", "Salvador"},
         'C'},
        {"Qual e a capital da Franca?",
         {"Madrid", "Roma", "Paris", "Berlim"},
         'C'},
        {"Qual e a capital do Japao?",
         {"Pequim", "Toquio", "Bangkok", "Manila"},
         'B'},
        {"Qual e a capital da Argentina?",
         {"Buenos Aires", "Santiago", "Montevideu", "Assuncao"},
         'A'},
        {"Qual e a capital da Australia?",
         {"Sidney", "Melbourne", "Brisbane", "Camberra"},
         'D'},
        {"Qual e a capital do Canada?",
         {"Ottawa", "Toronto", "Montreal", "Vancouver"},
         'A'},
        {"Qual e a capital da Russia?",
         {"Sao Petersburgo", "Moscou", "Kiev", "Astana"},
         'B'},
        {"Qual e a capital da China?",
         {"Xangai", "Pequim", "Hong Kong", "Cantao"},
         'B'},
        {"Qual e a capital do Mexico?",
         {"Monterrey", "Guadalajara", "Cidade do Mexico", "Puebla"},
         'C'},
        {"Qual e a capital da Italia?",
         {"Milao", "Roma", "Napoles", "Turim"},
         'B'},
        {"Qual e a capital da Espanha?",
         {"Barcelona", "Madrid", "Valencia", "Sevilha"},
         'B'},
        {"Qual e a capital da Alemanha?",
         {"Hamburgo", "Berlim", "Munique", "Colonia"},
         'B'},
        {"Qual e a capital do Reino Unido?",
         {"Manchester", "Londres", "Glasgow", "Liverpool"},
         'B'},
        {"Qual e a capital da India?",
         {"Mumbai", "Delhi", "Bangalore", "Calcuta"},
         'B'},
        {"Qual e a capital da Coreia do Sul?",
         {"Seul", "Busan", "Incheon", "Daegu"},
         'A'},
        {"Qual e a capital da Turquia?",
         {"Istambul", "Ancara", "Izmir", "Bursa"},
         'B'},
        {"Qual e a capital da Africa do Sul?",
         {"Joanesburgo", "Cidade do Cabo", "Pretoria", "Durban"},
         'C'},
        {"Qual e a capital do Egito?",
         {"Alexandria", "Cairo", "Luxor", "Giza"},
         'B'},
        {"Qual e a capital da Nigeria?",
         {"Lagos", "Abuja", "Kano", "Ibadan"},
         'B'}
    };

    int score = 0; // Pontuação inicial do jogador
    int dinheiro = 0; // Dinheiro inicial do jogador
    int erros = 0; // Número de perguntas respondidas incorretamente
    int errosRestantes = 5; // Número de respostas erradas restantes antes do jogo encerrar

    char continuar;
    vector<Question> perguntasFeitas; // Vector para armazenar as perguntas já feitas

    do {
        // Embaralhar as perguntas
        random_shuffle(allQuestions.begin(), allQuestions.end());

        // Loop para exibir cada pergunta e obter a resposta do jogador
        for (const auto& q : allQuestions) {
            system("cls"); // Limpa a tela do console (Windows)

            // Exibe todas as perguntas já feitas
            cout << "-----------------------------------------------"<< endl;
            cout << "        ------------SARAIVA-------------      " << endl;
            cout << "----------------------------------------------- "<< endl;
            cout << "        Perguntas feitas durante o jogo:" << endl;
            cout << "----------------------------------------------- "<< endl;
            cout << endl;
            for (const auto& pq : perguntasFeitas) {
                displayQuestion(pq);
                cout << endl;
            }

            displayQuestion(q);
            cout << endl;
            cout << "------------------------------------------------"<< endl;
            cout << "     Escolha uma opcao ( A, B, C, ou D ): " << endl;
            cout << "------------------------------------------------";
            cout << endl;
            char answer;
            cin >> answer;

            if (checkAnswer(q, answer)) {
                
                cout << endl;
                cout << "------------------------------------------------"<< endl;
                cout << "  -------------Resposta correta!-------------- " << endl;
                cout << "------------------------------------------------"<< endl;
                cout << "        "<< endl;
                cout << endl;
                cout << endl;
                score++; // Incrementa a pontuação
                dinheiro += 1000; // Adiciona 1000 reais ao dinheiro acumulado
            } else {
                
                cout << endl;
                cout << "------------------------------------------------"<< endl;
                cout << "  ------------Resposta incorreta!------------- " << endl;
                cout << "------------------------------------------------"<< endl;
                cout << "        "<< endl;
                cout << endl;


                erros++; // Incrementa o número de erros
                errosRestantes--; // Decrementa o número de respostas erradas restantes
            }
            cout << endl;
            cout << "------------------------------------------------"<< endl;
            cout << "    Erros restantes antes do jogo encerrar: " << errosRestantes << endl;
            
            cout << endl;
            // Adiciona a pergunta ao vetor de perguntas feitas
            perguntasFeitas.push_back(q);

            // Verifica se excedeu o limite de erros
            if (erros >= 5) {
                cout << endl;
                cout << "Voce errou 5 perguntas. Perdeu todo o dinheiro acumulado." << endl;
                dinheiro = 0; // Reseta o dinheiro acumulado
                cout << endl;
                break; // Sai do loop
            }

            cout << "           Dinheiro acumulado: R$ " << dinheiro << endl; // Mostra o dinheiro acumulado
            cout << "------------------------------------------------"<< endl;
            // Pergunta se o jogador quer continuar ou sair
            cout << endl;
            cout << endl;
            cout << "Pressione [ ENTER ] para continuar ou  [ S ]  para sair: ";
            continuar = getchar(); // Leitura da tecla ENTER ou 's'
            if (toupper(continuar) == 'S') // Se quiser sair, sair do loop
                break;

            // Limpa o buffer do teclado
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (toupper(continuar) == 'S') // Se quiser sair, sair do loop principal
            break;

    } while (true);

    // Exibição da pontuação final do jogador
    system("cls"); // Limpa a tela do console (Windows)
    cout << "Fim do quiz!" << endl;
    cout << "Sua pontuacao final e: " << score << " de " << allQuestions.size() << " perguntas." << endl;
    cout << "Dinheiro acumulado total: R$ " << dinheiro << endl;

    return 0;
}
