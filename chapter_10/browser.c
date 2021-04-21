#define USE_GTKBUILDER 1

#include <gtk/gtk.h>
#ifndef USE_GTKBUILDER
#include <glade/glade.h>
#endif

void on_back_clicked (GtkToolButton*);
void on_forward_clicked (GtkToolButton*);
void on_up_clicked (GtkToolButton*);
void on_refresh_clicked (GtkToolButton*);
void on_delete_clicked (GtkToolButton*);
void on_home_clicked (GtkToolButton*);
void on_info_clicked (GtkToolButton*);
void on_go_clicked (GtkButton*);
void on_location_activate (GtkEntry*);
void on_row_activated (GtkTreeView*, GtkTreePath*, GtkTreeViewColumn*);

int main (int argc,
          char *argv[])
{
  GtkWidget *window;
#ifdef USE_GTKBUILDER
  GtkBuilder * builder;
  GError * error = NULL;
#else
  GladeXML *xml;
#endif

  gtk_init (&argc, &argv);

#ifdef USE_GTKBUILDER
  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "browser.ui", &error);
  window = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
  gtk_builder_connect_signals (builder, NULL);
#else
  xml = glade_xml_new ("browser.glade", NULL, NULL);
  window = glade_xml_get_widget (xml, "window");
  glade_xml_signal_autoconnect (xml);
#endif

  gtk_widget_show_all (window);
  gtk_main ();
  
  return 0;
}

void 
on_back_clicked (GtkToolButton *item)
{
  g_print ("Back clicked\n");
}

void 
on_forward_clicked (GtkToolButton *item)
{
  g_print ("Forward clicked\n");
}

void 
on_up_clicked (GtkToolButton *item)
{
  g_print ("Up clicked\n");
}

void 
on_refresh_clicked (GtkToolButton *item)
{
  g_print ("Refresh clicked\n");
}

void 
on_delete_clicked (GtkToolButton *item)
{
  g_print ("Delete clicked\n");
}

void 
on_home_clicked (GtkToolButton *item)
{
  g_print ("Home clicked\n");
}

void 
on_info_clicked (GtkToolButton *item)
{
  g_print ("File info clicked\n");
}

void 
on_go_clicked (GtkButton *button)
{
  g_print ("Go clicked\n");
}

void 
on_location_activate (GtkEntry *entry)
{
  g_print ("Location activated\n");
}

void 
on_row_activated (GtkTreeView *treeview, 
                  GtkTreePath *path, 
                  GtkTreeViewColumn *column)
{
  g_print ("Row activated\n");
}
