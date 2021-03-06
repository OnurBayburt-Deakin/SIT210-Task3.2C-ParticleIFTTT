int light_sensor = A0;
int light_level;
int prev_level;
int compare_level;


void setup()
{
    Serial.begin(9600);  //This allows reading input values in the serial monitor for testing
    pinMode(light_sensor, INPUT);  //Initialise the light sensor as an input connected to A0
    prev_level = 0;
}


void loop()
{
    light_level = analogRead(light_sensor);
    Serial.printlnf("%d", light_level);  //This is to see on the serial monitor if the system is working as intended
    compare_level = light_level - prev_level;
    
    if (light_level > 20)  //Sends a message when the detected light level is above the threshold
    {
        if ((compare_level * compare_level) > 50)
        {
            Particle.publish("Light_availability", "Sunny");
        }
    }
    else if (light_level <= 20)  //Sends a message when the detected light level is below the threshold
    {
        if ((compare_level * compare_level) > 50)
        {
            Particle.publish("Light_availability", "Dark");
        }
    }

    prev_level = light_level;
    delay(10000); //Length of time in ms between readings
}
