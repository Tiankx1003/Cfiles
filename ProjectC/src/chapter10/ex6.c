/*ex6.c*/
#include <gnome.h>
#include <stdio.h>

void hello(GtkWidget *widget, gpointer data)
{
	g_print("Hello World!\n");
}

gint deleteevent(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	gtk_main_quit();
}
int main(int argc, char *argv[])
{
	GtkWidget *app;
	GtkWidget *mybutton;
	gtk_set_locale();
	gnome_init(" ", "0.1", argc, argv);
	mybutton=gtk_button_new_with_label("点击我");
	app=gnome_app_new("世界你好", "GNOME 你好");
	gnome_app_set_contents(GNOME_APP(app),mybutton);
	gtk_signal_connect(GTK_OBJECT(app),"delete_event", GTK_SIGNAL_FUNC(deleteevent), NULL);
	gtk_signal_connect(GTK_OBJECT(mybutton),"clicked", GTK_SIGNAL_FUNC(hello), NULL);
	gtk_widget_show_all(app);
	gtk_main();

	return 0;
}
