# ESP8266-ESP12E

Este projeto traz suporte ao chip ESP8266 para o ambiente Arduino IDE. Ele permite que você escreva esboços, usando funções e bibliotecas familiares do Arduino, e execute-os diretamente no ESP8266, sem a necessidade de microcontrolador externo.

## Descrição

Projeto contém programas de introdução para a área de IOT, desenvolvidos para a disciplina de Sistemas Embarcados.

## Programas Contidos

* Blynk
* Entradas/Saídas Serial, Analogica e Digital com uso de WatchDogs
* Comunicação Serial entre placas usando UART
* Bluetooth Usando Modulo Externo
* Wifi Local com pagina HTML
* Wifi Global utilizando o Blynk

## Informações do Microcontrolador

O microcontrolador ESP12, desenvolvido pela renomada empresa Espressif Systems, é uma solução altamente versátil e eficiente para projetos de Internet das Coisas (IoT). Equipado com um processador de baixo consumo de energia e uma ampla gama de recursos integrados, o ESP12 é amplamente utilizado em aplicações que exigem conectividade Wi-Fi e controle em tempo real.
O ESP12 é baseado no chip ESP8266, que combina um processador central de 32 bits, memória flash embutida, capacidade de comunicação Wi-Fi e uma série de interfaces periféricas, tudo em um único chip compacto. Com essa arquitetura poderosa, o microcontrolador ESP12 é capaz de executar tarefas complexas, como coleta de dados, processamento local e transmissão sem fio, tornando-o uma escolha popular para dispositivos IoT de baixo consumo de energia.

![image](https://github.com/Cayo-Cesar/ESP8266-ESP12E/assets/96149641/4bfb2fe2-74b6-45b7-8671-77eaa9abf9ca)

![image](https://github.com/Cayo-Cesar/ESP8266-ESP12E/assets/96149641/2b03f80b-7d03-4758-866b-08577b881753)

## Como Programar 

O ambiente de desenvolvimento utilizado na descrição da placa foi a Arduino IDE e a linguagem de programação trata-se de C/C++. Antes de tudo, é necessário conhecer alguns passos para conseguir desenvolver algum programa para essa placa nesse ambiente. Seguindo os passos descritos neste mesmo tópico, será possível configurar e programar com facilidade:

* Passo 1: Acessar o site da desenvolvedora e baixar o executável do programa. Disponível em: https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE.

* Passo 2: Executar o programa e aguardar a instalação.

* Passo 3: Ao abrir o programa, percebe-se que ele não possui suporte nativo a essa placa em específico. Para adicionar suporte, deve-se ir em Arquivo > Preferências > URLs do gerenciador de placas adicionais e adicionar a seguinte URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json. Em seguida, clique em OK.

* Passo 4: Após executar o passo 3, abrirá um pop-up no canto inferior direito da tela que pedirá para instalar os pacotes referentes à placa descrita neste documento. Clique em SIM e a instalação será feita automaticamente.

* Passo 5: Após a instalação dos pacotes, é necessário selecionar a placa para a qual deseja programar e a porta na qual ela está inserida na máquina. No caso específico da ESP12-E, escolhemos a opção de placa "NODE MCU 1.0 (ESP-12E Module)".

* Passo 6: Após todos os passos anteriores serem executados, é possível programar normalmente. Espera-se que o código compile e seja gravado na placa com sucesso.







