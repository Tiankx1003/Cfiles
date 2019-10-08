/*ex1.c*/
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	static char *string="Hello world!";
	Display *display;
	int	screen_num;
	Window	win;	
	unsigned int width, height;
	unsigned int border_width=4;
	unsigned int display_width, display_height;
	int count;
	XEvent	report;
	GC	gc;
	unsigned long valuemask=0;
	XGCValues	values;
	char *display_name=NULL;
	if((display=XOpenDisplay(display_name))==NULL)
	{
		printf("Cannot connect to X server %s\n",XDisplayName(display_name));
		return -1;
	}
	screen_num=DefaultScreen(display);
	display_width=DisplayWidth(display, screen_num);
	display_height=DisplayHeight(display, screen_num);
	width=display_width/3;
	height=display_height/4;

	win=XCreateSimpleWindow(display,
			RootWindow(display, screen_num),
			0,0,width, height,
			border_width,
			BlackPixel(display, screen_num),
			WhitePixel(display, screen_num));
	XSelectInput(display, win, ExposureMask | KeyPressMask |
				ButtonPressMask | StructureNotifyMask);
	gc=XCreateGC(display, win, valuemask, &values);
	XMapWindow(display, win);
	while(1)
	{
		XNextEvent(display, &report);
		switch(report.type){
			case Expose:
				if(report.xexpose.count!=0) break;
				XDrawString(display, win, gc, width/2, height/2, string, strlen(string));
				break;
			case ConfigureNotify:
				width=report.xconfigure.width;
				height=report.xconfigure.height;
				break;
			case ButtonPress:
			case KeyPress:
				XFreeGC(display, gc);
				XCloseDisplay(display);
				return 1;
			default:
				break;
		}
	}
}
