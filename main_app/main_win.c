//
// Created by potato_coder on 22.11.22.
//

#include "main_win.h"


#define NUM_COLS 6

GtkBuilder *ui_builder;

enum {
    COL_NAME = 1000,
    COL_AUTHOR = 1001,
    COL_YEAR = 1002,
    COL_LASTPAGE = 1003,
    COL_LANG = 1004,
    COL_TAGS = 1005
};


G_MODULE_EXPORT void on_main_table_row_activated(GtkWidget *w) {

}

G_MODULE_EXPORT void choose_file(GtkWidget *w, GtkFileChooser *file_chooser) {
    gchar *filename = gtk_file_chooser_get_filename(file_chooser);
    printf("%s", filename);
}

G_MODULE_EXPORT void on_file_submenu_open_activate(GtkWidget *w, GtkWidget *main_window) {
    //GtkFileChooserDialog *file_chooser = gtk_file_chooser_dialog_new("Выберите папку", main_window, GTK_RESPONSE_ACCEPT, "Выбрать", GTK_RESPONSE_CANCEL, "Отмена");
    //gtk_widget_show_all(file_chooser);
}

G_MODULE_EXPORT void on_quit(GtkWidget *w) {
    gtk_main_quit();
}

void main_win_set_parameteres(GtkWidget *main_window, GError *error) {
    gtk_window_set_title(GTK_WINDOW (main_window), "BookReader");
    gtk_window_set_icon_from_file(GTK_WINDOW (main_window),
                                  "/home/potato_coder/CLionProjects/BookReader/resources/icons/icon.png", &error);
    gtk_window_set_default_size(GTK_WINDOW (main_window), 1280, 720);
}

void main_win_init(GtkBuilder *builder, GError *error) {
    GtkWidget *window;
    if (!gtk_builder_add_from_file(builder,
                                   "/home/potato_coder/CLionProjects/BookReader/resources/glade_cascades/main.glade",
                                   &error)) {
        g_critical ("Не вышло загрузить файл с UI : %s", error->message);
        g_error_free(error);
    }
    ui_builder = builder;
    window = GTK_WIDGET(gtk_builder_get_object(ui_builder, "main_window"));

    main_win_set_parameteres(window, error);
    gtk_builder_connect_signals(ui_builder, NULL);
    gtk_widget_show_all(window);
    gtk_main();
}