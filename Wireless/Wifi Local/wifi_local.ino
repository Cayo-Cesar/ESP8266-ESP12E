#include <ESP8266WiFi.h>


const char* ssid = "CAYO"; // Nome da Rede
const char* password = "41140751"; // Password da rede


int ledPin = 13; // GPIO13 do ESP8266 e D7 do NodeMCU
int ledPin1 = 4; // GPIO2 do ESP8266 e D2 do NodeMCU
WiFiServer server(80); // Porto 80


void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(ledPin, OUTPUT); // Define o D7 como saída
  analogWrite(ledPin, 0); // Inicializa o PWM em 0 (LED desligado)
  pinMode(ledPin1, OUTPUT); // Define o D4 como saída
  analogWrite(ledPin1, 0); // Inicializa o PWM em 0 (LED desligado)


  // Comunicação com a rede WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to "); // Mensagem apresentada no monitor série
  Serial.println(ssid); // Apresenta o nome da rede no monitor série
  WiFi.begin(ssid, password); // Inicia a ligação à rede
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


  // Servidor
  server.begin();
  Serial.println("Servidor iniciado");


  // Impressão do endereço IP
  Serial.print("Use o seguinte URL para a comunicação: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}


void loop() {
  // Verificação se o cliente está conectado
  WiFiClient client = server.available();
  if (!client) {
    return;
  }


  // Espera até o cliente enviar dados
  Serial.println("Novo cliente");
  while (!client.available()) {
    delay(1);
  }


  // Ler a primeira linha do pedido
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();


  // Operação do pedido
  int value = 0;


  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin1, HIGH);
    value = 255; // Define o valor PWM máximo (LED ligado)
  }
  if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(ledPin1, LOW);
    value = 0; // Define o valor PWM mínimo (LED desligado)
  }


  if (request.indexOf("/TOGGLELED") != -1) {
    // Liga ou desliga o LED, dependendo do seu estado atual
    int currentState = digitalRead(ledPin);
    digitalWrite(ledPin, currentState == HIGH ? LOW : HIGH);
    value = currentState == HIGH ? 0 : 255;
  }


  // Solicitação PWM
  if (request.indexOf("/PWM=") != -1) {
    int pwmValue = request.substring(request.indexOf("/PWM=") + 5).toInt();
    analogWrite(ledPin1, pwmValue);
    value = pwmValue;
  }


// Inicialização da página HTML
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // Não esqueça deste
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");


  // Adicione o título
  client.println("<head><title>ESP 12E WEB SERVER</title></head>");


  // Adicione o estilo para o fundo "aqua"
  client.println("<style>");
  client.println("body { background-color: aqua; }");
  client.println("</style>");


  client.println("<body>");


  // Adicione o título como um cabeçalho
  client.println("<h1>ESP-12E WEB SERVER</h1>");


  // Adicione uma linha abaixo do título
  client.println("<hr>");


  // Barra de valores para controlar o LED com potenciômetro
  client.print("Estado do LED 1 (Azul) controlado pelo potenciometro (PWM): ");
  client.println("<span id='pwmValue'>" + String(value) + "</span>");
  client.println("<br>");
  client.println("<input type='range' min='0' max='255' step='1' value='" + String(value) + "' id='pwmSlider' onchange='updatePWM(this.value)'>");
  client.println("<br>");


  client.println("<script>");
  client.println("function updatePWM(value) {");
  client.println("  document.getElementById('pwmValue').textContent = value;");
  client.println("  var xhttp = new XMLHttpRequest();");
  client.println("  xhttp.open('GET', '/PWM=' + value, true);");
  client.println("  xhttp.send();");
  client.println("}");


  // Lógica para ligar o outro LED sem afetar a barra de potenciômetro
  client.println("function toggleLED() {");
  client.println("  var xhttp = new XMLHttpRequest();");
  client.println("  xhttp.open('GET', '/TOGGLELED', true);");
  client.println("  xhttp.send();");
  client.println("}");


  client.println("</script>");


  // Adicione uma linha abaixo do LED controlado pelo potenciômetro
  client.println("<hr>");


  // Texto acima do botão
  client.println("<p>Ligar e desligar LED 2 (Vermelho):</p>");


  // Botão para ligar/desligar o outro LED
  client.println("<button onclick='toggleLED()'>Ligar/Desligar LED 2</button><br />");


  client.println("</body></html>");
}
