#define setcursor dsetcursor

Memimage *attachscreen(char*, char*);
void	setmouse(Point);
void	setcursor(Cursor*);
void	setlabel(char*);
char*	getsnarf(void);
void	putsnarf(char*);

void	mousetrack(int, int, int, int);
void	keystroke(int);
void	kicklabel(char*);

void	servep9p(void);
void	zlock(void);
void	zunlock(void);

Rectangle mouserect;
int	mouseresized;
