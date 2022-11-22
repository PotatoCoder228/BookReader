//
// Created by potato_coder on 22.11.22.
//

#ifndef BOOKREADER_MAIN_WIN_H
#define BOOKREADER_MAIN_WIN_H

#include "gtk-3.0/gtk/gtk.h"
G_MODULE_EXPORT void on_quit(GtkWidget * w);
void main_win_init(GtkBuilder * ui_builder, GError * error);

#endif //BOOKREADER_MAIN_WIN_H
