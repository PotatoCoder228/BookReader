#include <stdio.h>
#include "gtk-3.0/gtk/gtk.h"


G_MODULE_EXPORT void onClick(GtkWidget * w) {
    gtk_main_quit();
}

static void app_activate (GApplication *app, gpointer *user_data) {
    GtkWidget *win;
    GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    GtkWidget* menu_bar = gtk_menu_bar_new();
    GtkWidget* fileMenu = gtk_menu_new();
    GtkWidget *fileMi;
    GtkWidget *quitMi;

    GError * err = NULL;

    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);


    gtk_window_set_application (GTK_WINDOW (win), GTK_APPLICATION (app));
    gtk_window_set_title (GTK_WINDOW (win), "Library Manager");
    gtk_window_set_icon_from_file(GTK_WINDOW (win), "/home/potato_coder/CLionProjects/LibraryManager/icon.png", err);
    gtk_window_set_default_size (GTK_WINDOW (win), 1280, 720);
    //gtk_window_set_default(GTK_WINDOW (win), box);


    fileMi = gtk_menu_item_new_with_label("File");
    quitMi = gtk_menu_item_new_with_label("Quit");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), fileMi);
    gtk_box_pack_start(GTK_BOX(box), menu_bar, FALSE, FALSE, 0);
    gtk_container_add(win, box);
    gtk_widget_show_all(win);
}

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);
    GtkBuilder * ui_builder;
    GError * err = NULL;
    ui_builder = gtk_builder_new();
    if(!gtk_builder_add_from_file(ui_builder, "/home/potato_coder/CLionProjects/BookReader/resources/glade_cascades/main.glade", &err)) {
        g_critical ("Не вышло загрузить файл с UI : %s", err->message);
        g_error_free (err);
    }

    GtkWidget * window = GTK_WIDGET(gtk_builder_get_object(ui_builder, "main_window"));
    gtk_window_set_title (GTK_WINDOW (window), "BookReader");
    gtk_window_set_icon_from_file(GTK_WINDOW (window), "/home/potato_coder/CLionProjects/BookReader/resources/icons/icon.png", err);
    gtk_window_set_default_size (GTK_WINDOW (window), 1280, 720);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;




/*
    GtkApplication* app;
    int stat = 0;
    app = gtk_application_new("main.glade", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
    stat =g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref(app);
    */

}