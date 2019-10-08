/*ex4.c*/
#include <gtk/gtk.h>
#include <stdio.h>


gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	g_print("delete event occurred!\n");
	return TRUE;
}

void destroy(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}
int main(int argc, char *argv[])
{
	GtkWidget	*window;
	GtkWidget	*hbox;
	GtkWidget	*label, *entry;

	gtk_set_locale();
	gtk_init(&argc, &argv);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL)	;
	gtk_signal_connect(GTK_OBJECT(window),"destroy", GTK_SIGNAL_FUNC(destroy), NULL);

	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	hbox=gtk_hbox_new(FALSE,0);

	gtk_container_add(GTK_CONTAINER(window), hbox);
	gtk_widget_show(hbox);

	label=gtk_label_new("请输入:");
	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE,0);
	gtk_widget_show(label);

	entry=gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);
	gtk_widget_show(entry);
	
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
