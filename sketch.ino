#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <base64.h>

#define PIR_PIN 18          
#define LED_PIN 2           

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

const char* SMTP_SERVER = "smtp.gmail.com";
const uint16_t SMTP_PORT = 465;

const char* SMTP_EMAIL = "<sender's mail>";
const char* SMTP_PASSWORD = "YourEmailPassword";

const char* EMAIL_RECIPIENT = "<reciever's mail>";




void connectToWiFi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 10) {
    delay(1000);
    Serial.println("Connecting...");
    attempts++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
  } else {
    Serial.println("Failed to connect to WiFi");
  }
}





void sendEmailAlert() {
  WiFiClientSecure client;
  if (!client.connect(SMTP_SERVER, SMTP_PORT)) {
    Serial.println("Connection failed!");
    return;
  }

  if (!client.verify(SMTP_SERVER, String(SMTP_SERVER).c_str())) {
    Serial.println("Server verification failed!");
    return;
  }

  
  String login = base64::encode(String(SMTP_EMAIL) + String('\0') + SMTP_EMAIL);
  String password = base64::encode(SMTP_PASSWORD);

  
  client.println("EHLO " + String(SMTP_SERVER));
  delay(100);

  
  client.println("AUTH LOGIN");
  delay(100);

  
  client.println(login);
  delay(100);

  
  client.println(password);
  delay(100);

  
  if (!waitForResponse(client)) {
    Serial.println("Login failed!");
    return;
  }

  
  client.println("MAIL FROM:<" + String(SMTP_EMAIL) + ">");
  delay(100);

  
  client.println("RCPT TO:<" + String(EMAIL_RECIPIENT) + ">");
  delay(100);

  
  client.println("DATA");
  delay(100);

  
  client.println("From: <" + String(SMTP_EMAIL) + ">");
  client.println("To: <" + String(EMAIL_RECIPIENT) + ">");
  client.println("Subject: Intrusion Alert!");
  client.println();
  client.println("Motion detected at your premises. Please take necessary action.");
  client.println("chor ghus gya BKL!!!!!!");
  client.println(".");
  delay(100);


  client.println("QUIT");
  delay(100);

  client.stop();
  Serial.println("Email sent successfully!");
}




void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  connectToWiFi();
}





void loop() {
  int pirState = digitalRead(PIR_PIN);
  if (pirState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    sendEmailAlert();
    delay(5000);
    digitalWrite(LED_PIN, LOW);
  }
}







bool waitForResponse(WiFiClientSecure &client) {
  uint32_t timeout = millis() + 5000;
  while (!client.available() && millis() < timeout) {
    delay(100);
  }
  if (!client.available()) {
    Serial.println("No response from server!");
    return false;
  }
  return true;
}