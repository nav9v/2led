const int red1 = 9, green1 = 10, blue1 = 11;
const int red2 = 6, green2 = 5, blue2 = 3;

void setup()
{
    Serial.begin(9600);

    pinMode(red1, OUTPUT);
    pinMode(green1, OUTPUT);
    pinMode(blue1, OUTPUT);

    pinMode(red2, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(blue2, OUTPUT);

    setColor(1, 0, 0, 0);
    setColor(2, 0, 0, 0);

    Serial.println("Control the LEDs! Type:");
    Serial.println("  1 or 2 for the LED number");
    Serial.println("  r, g, or b for the color (red, green, blue)");
}

void loop()
{
    if (Serial.available() > 0)
    {
        int ledNum = Serial.parseInt();

        delay(10);
        if (Serial.available() > 0)
        {
            String color = Serial.readStringUntil('\n');
            color.trim();

            int r = 0, g = 0, b = 0;

            switch (color.charAt(0))
            {
            case 'r':
                r = 255;
                break;
            case 'g':
                g = 255;
                break;
            case 'b':
                b = 255;
                break;
            default:
                Serial.println("Invalid. Use: r, g, or b");
                return;
            }

            setColor(ledNum, r, g, b);
            Serial.println("Next: LED (1 or 2) & color (r, g, b):");
        }
    }
}

void setColor(int led, int r, int g, int b)
{
    analogWrite((led == 1 ? red1 : red2), r);
    analogWrite((led == 1 ? green1 : green2), g);
    analogWrite((led == 1 ? blue1 : blue2), b);
}
