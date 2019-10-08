/*ex8.c*/

#include <gnome.h>
void messagebox_clicked(GnomeDialog *dlg, gint button, gpointer data)
{
	switch(button)
	{
		case 1:
		{
			gpint("Apply button is pressed.\n");
			return;
		}
		case 0:

	}
}

