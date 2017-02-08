/*
	Sofies kodrader på papper
*/

int flowerstatus = AnalogInput(A0); //DigitalInput?
int time = 0;
int kind = 0;
display_init();
display_string(0, "Flowerstatus: ");
display_string(1, "in Computer");
display_update();
if (flowerstatus > 350){
	sendMessage(kind);
	if (time==0){
		time = startClock(); //make the clock start counting
	}
	if(time > 30){ //30 sec
		kind = 1;
		sendMessage(kind);
		delay(30); //delay 30 sec
	}
}
else{
	display_string(1, "I am happy.");
	//printf("Flower is a happy flower.\n");
	time = 0;
}
void sendMessage(int kind){
	if (kind >= 0 && kind < 5){//Nice message
		display_string(1, "I am wet, but will soon be dry.");
		//printf("I am watered, but I'd like some water soon\n");
	}

	if (kind < 0 && kind >> -5{ //Angry message
		display_string(1, "Water me, you monster.");
		//printf("Water me, you monster.\n");
	}  
}