#include <DHT.h>
#include <DHT_U.h>



#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define Type DHT11
int dhtPin = 4;
DHT HT(dhtPin, Type);
int humidity;
float tempC;
float tempF;
int dt (500);

// Wifi network station credentials
#define WIFI_SSID "PERRO"
#define WIFI_PASSWORD "Jr123456789"
// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "7873262870:AAGfyJTfoiN8z-blWuvQZbBpWh7mX4luviI"

const unsigned long BOT_MTBS = 1000; // mean time between scan messages

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime; // last time messages' scan has been done

const int ledPin = 2;
int ledStatus = 0;

void handleNewMessages(int numNewMessages)
{
  Serial.print("handleNewMessages ");
  Serial.println(numNewMessages);

  for (int i = 0; i < numNewMessages; i++)
  {
    String chat_id = bot.messages[i].chat_id;
    String text = bot.messages[i].text;
      humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);

    String from_name = bot.messages[i].from_name;
    if (from_name == "")
      from_name = "Guest";

    if (text == "/servon")
    {
      digitalWrite(ledPin, LOW); // turn the LED on (HIGH is the voltage level)
      ledStatus = 1;
      bot.sendMessage(chat_id, "El servidor esta encendido", "");
    }

    if (text == "/servoff")
    {
      ledStatus = 0;
      digitalWrite(ledPin, HIGH); // turn the LED off (LOW is the voltage level)
      bot.sendMessage(chat_id, "El servidor esta apagado", "");
    }

    if (text == "/estadoserv")
    {
      if (ledStatus)
      {
        bot.sendMessage(chat_id, "El servidor esta encendido", "");
      }
      else
      {
        bot.sendMessage(chat_id, "El servidor esta apagado", "");
      }
    }

    if (text == "/empezar")
    {
      String welcome = "Controla el encendido y apagado de tu servidor, " + from_name + ".\n";
      welcome += "presiona para empezar\n\n";
      welcome += "/servon : to switch the Led ON\n";
      welcome += "/servoff : to switch the Led OFF\n";
      welcome += "/estadoserv : Returns current status of LED\n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    }
  }
}


void setup()
{
  Serial.begin(115200);
  Serial.println();

  pinMode(ledPin, OUTPUT); // initialize digital ledPin as an output.
  delay(10);
  digitalWrite(ledPin, HIGH); // initialize pin as off (active LOW)

  // attempt to connect to Wifi network:
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);
   HT.begin();
}

void loop()
{

  if (millis() - bot_lasttime > BOT_MTBS)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    bot_lasttime = millis();
  }
}
