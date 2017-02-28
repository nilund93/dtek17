

void time2string( char *, int );


char * itoaconv( int num );
void quicksleep(int cyc);
void tick( unsigned int * timep );
void display_init(void);
void display_string(int line, char *s);
void display_update(void);
uint8_t spi_send_recv(uint8_t data);
int getsw(void);
void displayWelcome(void);
void initiatePorts(void);