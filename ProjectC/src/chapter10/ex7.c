/*ex7.c*/
#include <gnome.h>
#include <stdio.h>

void callback(GtkWidget *widget, gpointer data)
{
	g_print("Item Selected\n");
}

GnomeUIInfo file_menu[]={
	GNOMEUIINFO_ITEM_NONE("新建" ,"This is the menubar info", callback),	
	GNOMEUIINFO_ITEM_NONE("退出" ,"hello", gtk_main_quit),
	//GNOMEUIINFO_MENU_EXIT_ITEM(gtk_main_quit, NULL),
	GNOMEUIINFO_END
};

GnomeUIInfo menubar[]= {
	//GNOMEUIINFO_MENU_FILE_TREE(file_menu),
	GNOMEUIINFO_SUBTREE("_文件", file_menu),
	GNOMEUIINFO_END
};

GnomeUIInfo toolbar[]= {
	GNOMEUIINFO_ITEM_STOCK("打印", "This is another tooltip", callback, GNOME_STOCK_PIXMAP_PRINT),
	GNOMEUIINFO_ITEM_STOCK("退出", "Exit the application", gtk_main_quit, GNOME_STOCK_PIXMAP_EXIT),	
	GNOMEUIINFO_END
};

int main(int argc, char *argv[])
{
	GtkWidget 	*app;
	GtkWidget	*button;
	GtkWidget	*label;
	
	gtk_set_locale();
	gnome_init("example", "0.1", argc, argv);
	app=gnome_app_new("example", "工具栏和菜单简单示例");

	gtk_signal_connect(GTK_OBJECT(app), "delete_event", GTK_SIGNAL_FUNC(gtk_main_quit), NULL);

	gnome_app_create_menus(GNOME_APP(app),menubar);
	gnome_app_create_toolbar(GNOME_APP(app),toolbar);
	
	gtk_widget_show_all(app);
	gtk_main();

	return 0;
}
