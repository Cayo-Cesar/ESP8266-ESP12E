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

## Exemplos:

* Blynk: O código blynk.ino trata-se de um exemplo de blink implementado na arduíno IDE em C/C++, que faz com que o LED embutido na placa Arduino pisque repetidamente. O LED é ligado por um segundo e depois desligado por um segundo, continuando esse ciclo indefinidamente. Isso cria um efeito de piscar do LED. O objetivo é demonstrar o funcionamento básico do Arduino e familiarizar-se com o controle de pinos digitais.

* Entrada/Saída Analógica, Serial e Digital com Whatchdog: O ESP 12 E possui várias portas de entrada/saída digital. Essas portas podem ser configuradas como entrada ou saída digital. Quando configuradas como entrada digital, podem detectar níveis de tensão (0V ou 3.3V) ou transições (mudanças de estado) nos pinos. Quando configuradas como saída digital, os pinos podem ser controlados para fornecer níveis de tensão (0V ou 3.3V) ou transições entre eles. No exemplo da imagem abaixo, foi usado o pino D5 (GPIO 14) ligado a um botão como entrada digital e foi utilizado o pino D1(GPIO5) ligado a um LED, o valor do botão é continuamente mapeado para que ao se tornar HIGH o LED acione. Com o intuito de garantir o acionamento imediato do LED na entrada digital do microcontrolador, foi utilizado uma interrupção com a função  attachInterrupt(), onde qualquer mudança no sinal do botão é chamada uma função que gerencia o acionamento do LED independente do que está sendo executado no microcontrolador, além disso é passado para a função o ICACHE_RAM_ATTR, que informa para o microcontrolador que a função seja executada inteiramente na memória RAM.
  Interrupções são eventos que forçam o microcontrolador a interromper a tarefa que está sendo executada, para atender exclusivamente a rotina solicitada pelo evento. Podem ser tanto interrupções externas, como geradas por um botão, quanto interrupções internas, como watchdog, o qual trata-se de um temporizador que dispara um evento de interrupção assim que um determinado limite temporal for atingido. O código 02, descrito nesta subseção ilustra bem um watchdog, na função ligaLed foi implementado um time que dispara e calcula o tempo que o botão da placa está sendo pressionado, ao ficar pressionado mais de 3 segundos e soltar o mesmo, a placa reinicia.
	A entrada analógica nos microcontroladores permite a leitura de sinais analógicos contínuos em vez de sinais digitais discretos. No ESP12E, há um conversor analógico para digital (ADC) embutido, que converte a tensão analógica aplicada a uma entrada em um valor digital correspondente. No caso do ESP12E, o ADC tem uma resolução de 10 bits, o que significa que pode representar valores entre 0 e 1023 (2^10 - 1). Essa resolução determina a precisão da leitura analógica. A entrada analógica pode ser usada para ler valores de sensores de temperatura, luminosidade, umidade, entre outros. No exemplo da imagem 02, foi usado o pino A0, que é o único pino analógico e que por sua vez possui o ADC, pra ser ligado ao potenciômetro, onde no código é mapeado o valor lido do potenciômetro (0-1023) para um valor PWM (0-255) usando a função map() é repassado pro LED o valor específico.
  O ESP12E possui um controlador UART (Universal Asynchronous Receiver/Transmitter) embutido, que permite a comunicação serial assíncrona. Isso significa que ele pode enviar e receber dados sequenciais em uma única linha. O ESP12E tem dois pinos dedicados para comunicação serial: RX (Recebimento) e TX (Transmissão). Esses pinos podem ser usados para conectar o ESP12E a outros dispositivos ou módulos que também suportem comunicação serial, como computadores, módulos GPS ou outros microcontroladores. No exemplo da figura 02, é usado a saída digital D2(GPIO4) que possui PWM, verifica-se se há dados para a comunicação serial, se houver dados, lê um número inteiro usando Serial.parseInt() e  esvazia o buffer da comunicação serial usando Serial.readString(). Se o valor estiver entre 0 e 255, armazena-o em "previousValue" para uso posterior. Se o valor estiver fora desse intervalo, imprime uma mensagem de erro na serial. Define o valor de "previousValue" como saída PWM para o LED_3 usando analogWrite(). Assim o LED irá acender na intensidade informada no monitor serial.
  O código entrada_saída.ino, ilustra o que foi descrito nos paragrafos anteriores, onde há entrada/saída digital, analógica e serial representadas por acionamento de LED através de botão com interrupção, acionamento de LED atravez de leitura analogica por um potenciômetro e acionamento de LED através de comandos do monitor serial, respectivamente. Além disso, há dentro da interrupção um watchdog implementado de forma que se o botão for pressionado por 3 segundos a placa é resetada. A figura 2, retrata como foi disposto as ligações para a realização do exemplo referente a este capítulo. Abaixo Segue foto do microcontrolador e como foi montado o circuito pra realizar o exemplo acima.

![image](https://github.com/Cayo-Cesar/ESP8266-ESP12E/assets/96149641/8a238f22-a450-4553-9ac8-76e4ec7c3109)

* Comunicação Serial UART: A comunicação serial entre microcontroladores é uma das formas mais comuns de estabelecer a troca de dados entre esses dispositivos. Essa abordagem é amplamente utilizada em uma variedade de aplicações, como sistemas embarcados, automação industrial, robótica, dispositivos IoT (Internet of Things) e muitos outros cenários onde é necessário que microcontroladores se comuniquem entre si. Existem diferentes protocolos de comunicação serial que podem ser utilizados entre microcontroladores, cada um com suas características específicas. O UART é uma comunicação serial assíncrona. Ele é relativamente simples de implementar e não requer um sinal de clock compartilhado entre os dispositivos. A comunicação UART utiliza um par de pinos, um para transmitir (TX) e outro para receber (RX), permitindo a troca bidirecional de dados entre os microcontroladores. O código desta subseção serve para as duas placas e acende um led baseado no sinal de um sensor na outra placa. Abaixo Segue foto do microcontrolador e como foi montado o circuito pra realizar o exemplo acima.

![image](https://github.com/Cayo-Cesar/ESP8266-ESP12E/assets/96149641/1d5e6a36-4b43-46fa-bd78-7fb2d15ab10f)

* Bluetooth: A placa não possui conectividade Bluetooth nativa, então foi usada um módulo externo como o mostrado na figura 03. O código 05 utiliza a biblioteca "SoftwareSerial" para permitir a comunicação entre um microcontrolador ESP12E e um módulo Bluetooth. O módulo Bluetooth permite controlar remotamente um LED por meio de comandos enviados via Bluetooth. O programa configura os pinos RX e TX para comunicação, define um pino para o LED e cria uma variável para armazenar os dados recebidos do Bluetooth. Quando um comando é recebido, o código controla o LED conforme o comando de acordo com a potência fornecida pelo usuário, além disso, é usado o sensor infravermelho para mandar informação da placa para o bluetooth com as informações de “SENSOR ATIVADO” caso seja detectado informações no sensor e “PRESENÇA DETECTADA” caso o sensor não esteja ativo.. Isso demonstra o uso de um módulo Bluetooth para habilitar a comunicação sem fio e o controle de dispositivos (neste caso, o LED) com o ESP12E. Abaixo Segue foto do microcontrolador e como foi montado o circuito pra realizar o exemplo acima.

![image](https://github.com/Cayo-Cesar/ESP8266-ESP12E/assets/96149641/9b5b48b5-a18c-404d-863d-33e53b54681a)

* Wifi Local: Este código estabelece um servidor web no módulo ESP8266 que possibilita o controle de dois LEDs: um cuja intensidade é ajustada por um potenciômetro e outro que pode ser ligado/desligado através de um botão na página web. A página web gerada possui um fundo de cor "aqua" e exibe o título "ESP 12E WEB SERVER" seguido de uma barra deslizante para controlar o LED do potenciômetro com feedback em tempo real. O código também inclui uma função para ligar/desligar o segundo LED (de cor vermelha) independentemente da barra do potenciômetro. Essa solução permite interagir com o ESP8266 por meio de uma interface web para controlar os LEDs e visualizar o estado do LED controlado pelo potenciômetro. Abaixo Segue foto do microcontrolador e como foi montado o circuito pra realizar o exemplo acima.

![image](https://github.com/Cayo-Cesar/ESP8266-ESP12E/assets/96149641/6686e9be-6376-4ca0-a422-0524d3c37fb3)

* Wifi Global: Neste projeto, exploramos a funcionalidade do aplicativo Blynk para criar uma conexão sem fio entre um dispositivo ESP8266 e um smartphone. O Blynk é uma plataforma versátil que permite o controle e monitoramento remoto de dispositivos por meio de uma interface intuitiva em dispositivos móveis. No contexto deste projeto, foi construído uma solução para controlar LEDs remotamente, usando um botão virtual para ligar e desligar os LEDs e um slider virtual para ajustar a intensidade de um deles, tudo isso através do aplicativo Blynk. O dashboard que foi criado estabelece um botão e um slider usado pra controlar o PWM dos LEDS mostrado na figura abaixo com seus datastreams mostrados na figura abaixo.
O código fornecido inicia definindo informações do template no Blynk, além de importar as bibliotecas necessárias e configurar as credenciais de conexão WiFi e o token de autenticação. Dois LEDs são definidos para os pinos correspondentes. A função setup() cuida da inicialização, estabelecendo a comunicação serial, conexão com o Blynk e configuração dos pinos dos LEDs. A função loop() mantém o funcionamento do Blynk em execução. O primeiro LED (LED_PIN) é controlado pela função BLYNK_WRITE(V0), que é ativada quando um botão virtual é pressionado ou solto. Conforme o estado do botão, o LED é ligado ou desligado.Já o segundo LED (LED_PIN1) é controlado pela função BLYNK_WRITE(V1), que é ativada quando o slider virtual é movido. O valor do slider ajusta a intensidade do LED, utilizando a função analogWrite(), todo esse funcionamento é exemplificado no wifi_global.ino.
Este projeto ilustra o poder do Blynk ao possibilitar a interação eficiente entre dispositivos e aplicativos, viabilizando o controle remoto de dispositivos de forma personalizada e prática. Certifique-se de configurar os widgets no aplicativo Blynk corretamente e conectar fisicamente os LEDs nos pinos D13 e D15 do ESP8266 para obter um funcionamento eficaz.

![image](https://github.com/Cayo-Cesar/ESP8266-ESP12E/assets/96149641/407c7685-01e5-4d12-8885-1c4e3e64cfa1)

![image](https://github.com/Cayo-Cesar/ESP8266-ESP12E/assets/96149641/fadb5ea3-63b7-47a0-af07-6b650c4e0e51)

![image](https://github.com/Cayo-Cesar/ESP8266-ESP12E/assets/96149641/1b0aef91-ce63-4843-887b-426f6b60b633)

# Considerações Finais

Baseado nos exemplos, o uso mais voltado para a placa ESP8266, como o NodeMCU ESP-12, envolve a criação de projetos de Internet das Coisas (IoT) que exigem conectividade Wi-Fi. Sua capacidade de se conectar a redes sem fio e se comunicar com servidores remotos torna-a ideal para projetos que envolvam monitoramento e controle remoto, coleta de dados de sensores, automação residencial, sistemas de segurança, exibição de informações em tempo real e muito mais. Além disso, devido à sua comunidade ativa e às bibliotecas disponíveis, a placa ESP8266 é amplamente utilizada no desenvolvimento de protótipos e soluções de IoT devido à sua facilidade de uso e acessibilidade.





















