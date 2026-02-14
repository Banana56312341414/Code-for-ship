int PinButonStartStop = 6;
int PinButon = 9;
int PinButon2 = 7;
int PinLed = 8;

unsigned long TimpButonApasat = 0;
bool ButonApasat = false;
bool MesajActiv = false;
String mesaj = "";

String toMorse(char c) {
  c = toupper(c);
  switch (c) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    default: return "";
  }
}

String fromMorse(String code) {
  if (code == ".-") return "A";
  if (code == "-...") return "B";
  if (code == "-.-.") return "C";
  if (code == "-..") return "D";
  if (code == ".") return "E";
  if (code == "..-.") return "F";
  if (code == "--.") return "G";
  if (code == "....") return "H";
  if (code == "..") return "I";
  if (code == ".---") return "J";
  if (code == "-.-") return "K";
  if (code == ".-..") return "L";
  if (code == "--") return "M";
  if (code == "-.") return "N";
  if (code == "---") return "O";
  if (code == ".--.") return "P";
  if (code == "--.-") return "Q";
  if (code == ".-.") return "R";
  if (code == "...") return "S";
  if (code == "-") return "T";
  if (code == "..-") return "U";
  if (code == "...-") return "V";
  if (code == ".--") return "W";
  if (code == "-..-") return "X";
  if (code == "-.--") return "Y";
  if (code == "--..") return "Z";
  if (code == "-----") return "0";
  if (code == ".----") return "1";
  if (code == "..---") return "2";
  if (code == "...--") return "3";
  if (code == "....-") return "4";
  if (code == ".....") return "5";
  if (code == "-....") return "6";
  if (code == "--...") return "7";
  if (code == "---..") return "8";
  if (code == "----.") return "9";
  return "?";
}

void setup() {
  Serial.begin(9600);
  pinMode(PinButonStartStop, INPUT_PULLUP);
  pinMode(PinButon, INPUT_PULLUP);
  pinMode(PinButon2, INPUT_PULLUP);
  pinMode(PinLed, OUTPUT);
  Serial.println("Morse translation on");
}

void loop() {
  
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    Serial.print("Morse: ");
    for (int i = 0; i < input.length(); i++) {
      Serial.print(toMorse(input[i]));
      Serial.print(" ");
    }
    Serial.println();
  }

  
  static bool StartStopPrev = HIGH;
  bool StareStartStop = digitalRead(PinButonStartStop);

  if (StareStartStop == LOW && StartStopPrev == HIGH) {
    MesajActiv = !MesajActiv;
    delay(200);
  }
  StartStopPrev = StareStartStop;

  if (MesajActiv) {
    bool StareButon = digitalRead(PinButon);

    if (StareButon == LOW && !ButonApasat) {
      ButonApasat = true;
      TimpButonApasat = millis();
    }

    if (StareButon == HIGH && ButonApasat) {
      ButonApasat = false;
      unsigned long durata = millis() - TimpButonApasat;

      if (durata > 600) mesaj += "-";
      else mesaj += ".";

      Serial.print("Current message: ");
      Serial.println(mesaj);
    }

    digitalWrite(PinLed, StareButon == LOW);
  }

  
  static bool Buton2Prev = HIGH;
  bool StareButon2 = digitalRead(PinButon2);

  if (StareButon2 == LOW && Buton2Prev == HIGH) {
    if (mesaj.length() > 0) {
      Serial.println(fromMorse(mesaj));
      mesaj = "";
    }
    delay(200);
  }
  Buton2Prev = StareButon2;
}
