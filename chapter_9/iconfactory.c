#include <gtk/gtk.h>
#include <unistd.h>

#define ICON_LOCATION "icons/"

typedef struct
{
  gchar *location;
  gchar *stock_id;
  gchar *label;
} NewStockIcon;

const NewStockIcon list[] =
{
  { ICON_LOCATION"checklist.png", "check-list", "Check _List" },
  { ICON_LOCATION"calculator.png", "calculator", "_Calculator" },
  { ICON_LOCATION"camera.png", "screenshot", "_Screenshots" },
  { ICON_LOCATION"cpu.png", "cpu", "CPU _Info" },
  { ICON_LOCATION"desktop.png", "desktop", "View _Desktop" },
  { NULL, NULL, NULL }
};

static void add_stock_icon (GtkIconFactory*, gchar*, gchar*);

int main (int argc, 
          char *argv[])
{
  GtkWidget *window, *toolbar;
  GtkIconFactory *factory;
  gint i = 0;
  char curdir[256];
  getcwd (curdir, sizeof (curdir));
  char * fullpath;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Icon Factory");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (gtk_main_quit), NULL);

  factory = gtk_icon_factory_new ();
  toolbar = gtk_toolbar_new ();
  
  /* Loop through the list of items and add new stock items. */
  while (list[i].location != NULL)
  {
    GtkToolItem *item;

    fullpath = g_strconcat (curdir, "/", list[i].location, NULL);
    add_stock_icon (factory, fullpath, list[i].stock_id);
    g_free (fullpath);
    item = gtk_tool_button_new_from_stock (list[i].stock_id);
    gtk_tool_button_set_label (GTK_TOOL_BUTTON (item), list[i].label);
    gtk_tool_button_set_use_underline (GTK_TOOL_BUTTON (item), TRUE);
    gtk_toolbar_insert (GTK_TOOLBAR (toolbar), item, i);
    i++;
  }
    
  gtk_icon_factory_add_default (factory);
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_BOTH);
  gtk_toolbar_set_show_arrow (GTK_TOOLBAR (toolbar), FALSE);
  gtk_container_add (GTK_CONTAINER (window), toolbar);

  gtk_widget_show_all (window);
  gtk_main ();
  return 0;
}

/* Add a new stock icon from the given location and with the given stock id. */
static void 
add_stock_icon (GtkIconFactory *factory,
                gchar *location,
                gchar *stock_id)
{
  GtkIconSource *source;
  GtkIconSet *set;
  
  source = gtk_icon_source_new ();
  set = gtk_icon_set_new ();
  
  gtk_icon_source_set_filename (source, location);
  gtk_icon_set_add_source (set, source);
  gtk_icon_factory_add (factory, stock_id, set);
}
