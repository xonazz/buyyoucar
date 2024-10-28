# 🚐🚕 SIG-Car 🚗🚙
Sistema de Gestão para uma Concessionária de Veículos

## Descrição 📝
O SIG-Car, nomeado de **BuyYourCar**, é um projeto universitário da disciplina de PROGRAMAÇÃO (DCT1106) da Universidade Federal do Rio Grande do Norte (UFRN). Escrito na linguagem de programação C, este sistema fornece uma plataforma de gestão para uma concessionária de veículos, com interfaces divididas em módulos como os de clientes, veículos, funcionários, vendas e relatórios.

## Objetivos 🎯
O principal objetivo deste projeto é auxiliar pequenas e médias empresas que buscam implementar, substituir ou aprimorar seus processos automatizados de gestão. O **BuyYourCar** visa aumentar a eficiência operacional e facilitar o gerenciamento de informações, permitindo que a empresa tenha mais controle sobre seus clientes, veículos, funcionários, vendas e relatórios.

## Compilação ⚙️
 ### Linux 🐧
Para compilar o código do projeto em um sistema Linux, siga as etapas abaixo:
1. **Abra o terminal ( Ctrl + Alt + T)**
2. **instale o compilador GCC, caso ainda não o tenha. Use o comando apropriado para sua distribuição**:
   - **Debian/Ubuntu/Mint**:
     ```sh
     sudo apt install gcc
     ```
   - **Fedora**:
     ```sh
     sudo dnf install gcc
     ```
   - **Arch Linux**:
     ```sh
     sudo pacman -S gcc
     ```
   - **openSUSE**:
     ```sh
     sudo zypper install gcc
     ```
- Caso tenha dificuldades para instalar o compilador, procure no ChatGPT ou em fóruns online
  
3. **Clone o repositório**:
   ```sh
   git clone https://github.com/xonazz/buyyoucar.git
4. **Navegue até o diretório do projeto**:
   ```sh
   cd buyyoucar
5. **Compile o código**:
   ```sh
   gcc -Wall byc_V5.01.c cliente.c veiculo.c funcionario.c venda.c relatorio.c -o buyyourcar
6. **Execute o programa**:
   ```sh
   ./buyyourcar

 ### Windows 💻
- **Observação**: O código pode apresentar problemas de compilação na interface do projeto e nas acentuações. Recomenda-se utilizar o **WSL (Windows Subsystem for Linux)**, que permite executar um ambiente Linux diretamente no Windows. Procure no YouTube, em fóruns ou no ChatGPT como instalar e configurar corretamente o WSL. Com o WSL instalado, siga o mesmo passo a passo mencionado acima para Linux.

## Funcionalidades 🚀
- **Gerenciamento de Clientes**: Permite cadastrar, exibir, pesquisar, atualizar e excluir informações de clientes no sistema.
- **Gerenciamento de Veículos**: Possibilita cadastrar, exibir, pesquisar, atualizar e excluir veículos no estoque, com informações detalhadas como placa, marca, modelo, ano, cor e valor de venda.
- **Gerenciamento de Funcionários**: Permite registrar, exibir, atualizar e excluir dados de funcionários, mantendo o controle de suas informações.
- **Controle de Vendas**: Garante o registro, exibição, atualização e cancelamento de vendas, associando clientes e veículos específicos e mantendo um histórico das transações.
- **Geração de Relatórios**: Fornece relatórios detalhados sobre vendas, estoque, clientes e funcionários, auxiliando na análise e acompanhamento dos dados do sistema.

## Tecnologias Usadas 🛠️
- **Linguagem de Programação**: C
-  **Compilador**: GCC
- **Sistemas Operacionais**: Linux, Windows (através do WSL)
- **Plataforma de Desenvolvimento**: Visual Studio Code


## Contatos 📫
Para dúvidas ou suporte, entre em contato com os desenvolvedores do SIG-Car através dos seguintes canais\
Ivyson
- GitHub: [@IvysonWNM](https://github.com/IvysonWNM)
- E-mail: [ivysonnunes@hotmail.com](mailto:ivysonnunes@hotmail.com)

Jonas
- GitHub: [@xonazz](https://github.com/xonazz)
- E-mail: [robsonjjcs@gmail.com](mailto:robsonjjcs@gmail.com)
