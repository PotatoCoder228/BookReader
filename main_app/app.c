#include <stdio.h>
#include "gtk-3.0/gtk/gtk.h"
#include "main_win.h"

int main(int argc, char **argv) {
    gtk_init(&argc, &argv);
    GtkBuilder *ui_builder;
    GError *error = NULL;
    ui_builder = gtk_builder_new();
    main_win_init(ui_builder, error);
    return 0;
}