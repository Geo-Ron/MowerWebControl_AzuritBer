void connectWIFI() {
  // Get configuration message
  if (SET_IP_SETTING == 0) {
    Serial.println(MSG_HEADER " Wait for settings from serial...");
    setLedSequence(ledSeq_waitForConfig);
    waitForParams();
    printParams();
    if (strlen(params[PARAMID_LOCALIP].valueStr) > 0) {
      str2IpAddr(params[PARAMID_LOCALIP].valueStr, &myIP);
      str2IpAddr(params[PARAMID_GATEWAY].valueStr, &network_gateway);
      str2IpAddr(params[PARAMID_SUBNET].valueStr, &network_subnet);
    }
    WiFi.mode(WIFI_STA);
    WiFi.begin(params[PARAMID_SSID].valueStr, params[PARAMID_PASSWD].valueStr);
    WiFi.setHostname("Ardumower");
    delay(250);
    WiFi.config(myIP, network_gateway, network_subnet);
  } else {
    Serial.println(MSG_HEADER " Connecting with programmed settings");
    WiFi.mode(WIFI_STA);
    WiFi.begin(wifi_network_ssid, wifi_network_password);
    WiFi.setHostname("Ardumower");
    delay(250);
    WiFi.config(myIP, network_gateway, network_subnet);
  }
}

void Check_WIFI() {
  // Handle AccessPoint connection
  if (WiFi.status() == WL_CONNECTED) {
    // Connected to AP
    if (!wifiConnected) {
      // Transition Disconnected => Connected
      //esp_wifi_set_ps(WIFI_PS_NONE);
      WiFi.config(myIP, network_gateway, network_subnet);
      wifiConnected = true;
      setLedSequence(ledSeq_connected);
      Serial.print(MSG_HEADER " CONNECTED! ");
      Serial.print(" IP address: ");
      Serial.println(WiFi.localIP());
    }
  } else {
    // Disconnected from AP
    if (wifiConnected) {
      // Transition Connected => Disconnected
      wifiConnected = false;
      setLedSequence(ledSeq_connecting);
      Serial.print(MSG_HEADER " DISCONNECTED");
      disconnectPFODClient();
      connectCnt = 0;
    }
    Serial.print(MSG_HEADER " Connecting ...");
    Serial.println(connectCnt);
    connectCnt++;
    delay(250);
  }
}
