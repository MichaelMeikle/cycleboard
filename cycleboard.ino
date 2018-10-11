
// Global variables
const int d = 200; // Delay
const int motor_input = 5; // Pin
const int motor_output = 6; // Pin
const int usb_port = 1; // Port identifier
const int aoa_protocol_version = 2; // Android Open Accessory protocol 2.0
const int usb_speed = 9600; // Baud of the serial connection to USB shield

// Establish connection via USB
// Ma is as selfless as I am.
boolean usb_connect ()
{
  char handshake[] = "2USB";
  if ( Serial.available > 0 ) {
    Serial.write(handshake);
    return true;
  }
  else {
    return false; // Failure to connect
  }
}

// Run once, at startup
void setup ()
{
  pinMode(motor_output, OUTPUT);
  pinMode(motor_input, INPUT);
  Serial.begin(usb_speed);
}

// Run continuously
void loop ()
{
  digitalWrite(motor_output, HIGH);
  delay(d);
  digitalWrite(motor_output, LOW);
  delay(d);
}

/*
Local variables:
eval: (arduino-mode)
End:
*/
