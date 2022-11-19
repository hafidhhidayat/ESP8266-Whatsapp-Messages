#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <UrlEncode.h>

void WhatsApp(String phoneNumber, String apiKey, String message) {
  // Data to send with HTTP POST
  String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;    
  HTTPClient http;
  http.begin(client, url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

void Facebook(String apiKey, String message) {
  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/facebook/send.php?apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;    
  HTTPClient http;
  http.begin(client, url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

// html_format : yes/no -  Default: no - Optional parameter to send the message in html format or plain text. Put "yes" when you want to send "bold" text using test (url example: &html=yes)
// link_preview : yes/no - Default: no - It will enable or disable the webpage preview that is sent together with the text message when there is an URL on it.
void Telegram(String username, String apiKey, String message) {
  https://api.callmebot.com/text.php?user=[username]&text=[text]&html=[html_format]&links=[link_preview]
  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/text.php?user=" + username + "&apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;    
  HTTPClient http;
  http.begin(client, url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

// apiKey : https://www.callmebot.com/blog/telegram-group-messages-api-easy/
// html_format : yes/no -  Default: no - Optional parameter to send the message in html format or plain text. Put "yes" when you want to send "bold" text using test (url example: &html=yes)
// link_preview : yes/no - Default: no - It will enable or disable the webpage preview that is sent together with the text message when there is an URL on it.
void TelegramGroup(String apiKey, String message, String html_format) {
  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/telegram/group.php?apikey=" + apiKey + "&text=" + message "&html=" + html_format;
  WiFiClient client;    
  HTTPClient http;
  http.begin(client, url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}