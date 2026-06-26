# 🌤️Trabalho Prático: Estações Meteorológicas

Trabalho prático final do curso de **Programação e Desenvolvimento de Software I**, da **Univerdade Federal de Minas Gerais**, ministrado pelo professor **Pedro Henrique Barros**. 
O projeto foi escrito manualmente, gastando aproximadamente **15 horas de trabalho**, distribuidas em arquitetura de código,estrutura de dados e implementação em C. Documentações e fóruns online foram consultados, e algumas funcionalidades externas ao funcionamento bruto do código foram importadas de terceiros(funcionalidade Makefile).

---

## 🚀Sobre o programa: 
 O Programa se consiste em um painel de controle interativo para gerenciamento de um sistema de Estações Meteorológicas. Por meio dele, é possível realizar diversas tarefas:
*Gerenciamento de Estações: É possível criar, configurar, editar e excluir estações na rede.
*Leituras climáticas: É possível inserir leituras relativas a cada estação.
*Visualização: É possível ter listar as estações de formas diferentes para filtragem.
*Análise de dados: Cálculo de estatísticas e deteccão de anomalias.
*Persistência de dados: O programa gera e lê arquivos CSV para garantir persistencia de dados.

### 📂 Estrutura do repo:
O projeto adota uma arquitetura modular para separar as responsabilidades do código:

* `source/`: Contém os arquivos de implementação do código-fonte (`.c`).
* `packages/`: Armazena as assinaturas das funções e cabeçalhos (`.h`).
* `data/`: Diretório reservado para os arquivos `.csv` de importação e exportação.
* `Makefile`: Script de automação para compilação rápida do sistema.

#### 🛠️ Como Compilar e Executar
O projeto contém funcionalidade makefile, mas também é possível compilar direto pelo terminal:
**LINUX**

*Via `make`:
make && ./programa

Terminal:
gcc source/*.c -o programa -lm && ./programa

**WINDOWS**

*Via `make`:
make && .\programa.exe

gcc source\*.c -o programa.exe && .\programa.exe
