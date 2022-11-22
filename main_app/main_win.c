//
// Created by potato_coder on 22.11.22.
//

#include "main_win.h"

G_MODULE_EXPORT void on_quit(GtkWidget *w) {
    gtk_main_quit();
}

void main_win_set_parameteres(GtkWidget *main_window, GError *error) {
    gtk_window_set_title(GTK_WINDOW (main_window), "BookReader");
    gtk_window_set_icon_from_file(GTK_WINDOW (main_window),
                                  "/home/potato_coder/CLionProjects/BookReader/resources/icons/icon.png", &error);
    gtk_window_set_default_size(GTK_WINDOW (main_window), 1280, 720);
}

void main_win_init(GtkBuilder *ui_builder, GError *error) {
    GtkWidget *window;


    if (!gtk_builder_add_from_file(ui_builder,
                                   "/home/potato_coder/CLionProjects/BookReader/resources/glade_cascades/main.glade",
                                   &error)) {
        g_critical ("Не вышло загрузить файл с UI : %s", error->message);
        g_error_free(error);
    }
    window = GTK_WIDGET(gtk_builder_get_object(ui_builder, "main_window"));

    main_win_set_parameteres(window, error);
    gtk_builder_connect_signals(ui_builder, NULL);

    gtk_widget_show_all(window);
    gtk_main();
}