void setup() {

	Serial.begin(9600);

}


void loop()
{
	while (Serial.available())
	{

		//read in a line from the Serial port
		String str = Serial.readString();

		//trim the string to remove trailing white space
		str.trim();

		//locate all the stupid commas (assuming three values)
		int firstComma = str.indexOf(",");
		int secondComma = str.indexOf(",", firstComma + 1);

		//isolate each substring
		String x_str = str.substring(0, firstComma);
		String y_str = str.substring(firstComma + 1, secondComma);
		String z_str = str.substring(secondComma + 1, str.length());

		//convert substring into integers
		int x_accel = x_str.toInt();
		int y_accel = y_str.toInt();
		int z_accel = z_str.toInt();
		
	}

}